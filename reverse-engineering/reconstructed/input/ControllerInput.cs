// Recovered PC controller contracts. No input-device or Unity dependency.
// Raw mapping is restricted to the two built-in Xbox profiles with zero smoothing.
using System;
namespace Recovered.Input
{
    public static class ControllerInput
    {
        // Input has already passed native raw-staging/circle-to-square processing.
        // Physical bits0..9: A B X Y LB RB Back Start L3 R3; bits10..13: U R D L.
        public static byte[] MapDefaultXbox(ushort physical, short lx, short ly,
            short rx, short ry, byte leftTrigger, byte rightTrigger)
        {
            uint[] masks={0x40,0x20,0x80,0x10,4,8,0x100,0x800,0x200,0x400,0x1000,0x2000,0x4000,0x8000};
            byte[] mapped=new byte[12];short[] axes={lx,ly,rx,ry};
            for(int i=0;i<4;i++)mapped[i]=(byte)((axes[i]+32768)>>8);
            mapped[4]=(physical&(1<<4))!=0?(byte)255:(byte)0;mapped[5]=leftTrigger;
            mapped[6]=(physical&(1<<5))!=0?(byte)255:(byte)0;mapped[7]=rightTrigger;
            uint held=0;for(int i=0;i<masks.Length;i++)if((physical&(1<<i))!=0)held|=masks[i];
            if(leftTrigger>=64)held|=1;if(rightTrigger>=64)held|=2;WriteUInt(mapped,8,held);return mapped;
        }
        public static void CircleToSquare(ref short x,ref short y)
        {
            int maximum=Math.Max(Math.Abs((int)x),Math.Abs((int)y));
            float magnitude=(float)Math.Sqrt((float)((double)x*x+(double)y*y));
            float ratio=maximum==0?1f:(float)(32767.0/maximum);
            float scaled=(float)((double)ratio*magnitude);float scale=(float)((double)scaled/32768.0);
            x=(short)Math.Truncate(Math.Min(32767,Math.Max(-32767,(float)((double)x*scale))));
            y=(short)Math.Truncate(Math.Min(32767,Math.Max(-32767,(float)((double)y*scale))));
        }
        public static int ScaledAxis(int value,int deadzone)
        {
            if(deadzone<0||deadzone>=128)throw new ArgumentOutOfRangeException("deadzone");
            if(value < -128 || value > 128)throw new ArgumentOutOfRangeException("value");
            if(value>=deadzone)return ((value-deadzone+1)*127)/(128-deadzone);
            return value < -deadzone?((value+deadzone)*127)/(128-deadzone):0;
        }
        public static void Deadzone(ref int x,ref int y,int deadzone,bool scaled)
        {
            if(deadzone<0||deadzone>=128)throw new ArgumentOutOfRangeException("deadzone");
            if(x < -128 || x > 128 || y < -128 || y > 128)throw new ArgumentOutOfRangeException("x");
            if(scaled){x=ScaledAxis(x,deadzone);y=ScaledAxis(y,deadzone);return;}
            float a=Math.Min(1,Math.Max(-1,(float)(x/127.0)));
            float b=Math.Min(1,Math.Max(-1,(float)(y/127.0)));
            float sum=(float)((double)a*a+(double)b*b);
            float magnitude=(float)Math.Sqrt(sum);
            if(magnitude < (float)(deadzone/127.0)){x=0;y=0;}
        }
        public static float DirectionResponse(float progress)
        {
            if(float.IsNaN(progress))throw new ArgumentException("NaN response outside validated domain.");if(progress<=0)return 0;if(progress<=.5f)return .1f;
            if(progress<=.75f)return .25f;if(progress<=.85f)return .5f;return 1;
        }
        // Returns the original unwrapped32-bit sum. Wrap explicitly to ushort
        // only at the later consumer that stores a16-bit game angle.
        public static uint MovementAngle(bool playerFlag,sbyte socketIndex,bool socketFlag40,
            ushort stickAngle,uint cameraYaw,ushort objectYaw,ushort socketYaw)
        {
            return unchecked((uint)stickAngle+(playerFlag&&socketIndex!=-1&&socketFlag40?
                (uint)objectYaw+socketYaw:cameraYaw));
        }
        public static void ProcessPad(byte[] pad,bool scaledDeadzone,float frameScalar)
        {
            if(pad==null||pad.Length!=0x84)throw new ArgumentException("Expected132-byte PC pad state.");
            Finite(frameScalar);uint held=ReadUInt(pad,0x10),previous=ReadUInt(pad,0x1c),changed=held^previous;
            WriteUInt(pad,0x14,held&changed);WriteUInt(pad,0x18,previous&changed);WriteUInt(pad,0x1c,held);
            int[] axis={pad[8]-128,128-pad[9],pad[10]-128,128-pad[11]};int d=unchecked((int)ReadUInt(pad,0x34));
            if(d!=0)
            {
                Deadzone(ref axis[0],ref axis[1],d,scaledDeadzone);Deadzone(ref axis[2],ref axis[3],d,scaledDeadzone);
                pad[8]=unchecked((byte)(axis[0]+128));pad[9]=unchecked((byte)(128-axis[1]));
                pad[10]=unchecked((byte)(axis[2]+128));pad[11]=unchecked((byte)(128-axis[3]));
            }
            int[] normalizedOffsets={0x38,0x3c,0x58,0x5c};
            for(int i=0;i<4;i++)
            {
                WriteUInt(pad,0x24+4*i,unchecked((uint)axis[i]));float value=axis[i]/128f,bias=ReadFloat(pad,0x48+4*i);Finite(bias);
                if(value>0)value=Math.Max(0,(float)((double)value-bias));
                if(value<0)value=Math.Min(0,(float)((double)value+bias));
                WriteFloat(pad,normalizedOffsets[i],value);
            }
            uint flags=ReadUInt(pad,0x20);
            if((flags&1)!=0)Array.Copy(pad,0x7c,pad,0x78,4);
            else
            {
                uint[] masks={0x1000,0x4000,0x8000,0x2000};float step=(float)(frameScalar/30.0);
                for(int i=0;i<4;i++)
                {
                    int offset=0x68+4*i;float value=ReadFloat(pad,offset);if(float.IsNaN(value))throw new ArgumentException("NaN ramp outside validated domain.");
                    value=(held&masks[i])!=0?Math.Min(1,(float)((double)value+step)):0;WriteFloat(pad,offset,value);
                }
                int[] rampOffsets={0x70,0x74,0x68,0x6c};
                for(int i=0;i<4;i++)pad[0x78+i]=(byte)(DirectionResponse(ReadFloat(pad,rampOffsets[i]))*255.0);
            }
            pad[0x82]=(flags&2)!=0?pad[0x80]:(byte)127;pad[0x83]=(flags&2)!=0?pad[0x81]:(byte)127;
        }
        static void Finite(float value){if(float.IsNaN(value)||float.IsInfinity(value))throw new ArgumentOutOfRangeException("value");}
        static uint ReadUInt(byte[] data,int offset){return (uint)(data[offset]|data[offset+1]<<8|data[offset+2]<<16|data[offset+3]<<24);}
        static void WriteUInt(byte[] data,int offset,uint value){for(int i=0;i<4;i++)data[offset+i]=(byte)(value>>(8*i));}
        static float ReadFloat(byte[] data,int offset){return BitConverter.ToSingle(BitConverter.GetBytes(ReadUInt(data,offset)),0);}
        static void WriteFloat(byte[] data,int offset,float value){WriteUInt(data,offset,BitConverter.ToUInt32(BitConverter.GetBytes(value),0));}
    }
}
