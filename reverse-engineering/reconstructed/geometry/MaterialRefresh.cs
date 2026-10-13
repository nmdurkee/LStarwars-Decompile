// Original CPU material refresh and program-service dispatch. Shader building
// and device creation remain explicit callbacks; zero-lock branch only.
using System;
namespace Recovered.Geometry
{
    public delegate uint MaterialProgramFactory(RenderPacketMemory memory,uint manager,uint runtime,uint material,uint mode,uint zeroA,uint zeroB);
    public sealed class MaterialRefreshServices
    {
        public uint Manager,DeviceState;
        public int LockToken;
        public MaterialProgramFactory Factory;
        public Func<uint,uint> ResolveDeclaration;
    }
    public static class MaterialRefresh
    {
        // Original741620: unsigned index0..400; result includes header+4.
        public static uint ProgramByIndex(uint manager,uint index)
        {return index<401?checked(manager+index*0x4d8+4):0;}
        // Original7415b0 wraps its DWORD reference count.
        public static void Release(RenderPacketMemory m,uint program)
        {m.Dword(program+4,unchecked(m.Dword(program+4)-1));}
        // Original6e27d0/6e27f0; native ECX device becomes explicit.
        public static uint FirstMode(RenderPacketMemory m,uint device)
        {return (m.Byte(device+0x654)&0x20)!=0?16U:0;}
        public static uint SecondMode(RenderPacketMemory m,uint device)
        {return (m.Byte(device+0x654)&0x20)!=0?1U:0;}
        // Original741770 and741790 call thiscall7416a0 with trailing zeros.
        public static uint RequestDefault(RenderPacketMemory m,MaterialRefreshServices s,uint runtime,uint material)
        {return RequestMode(m,s,runtime,material,0);}
        public static uint RequestMode(RenderPacketMemory m,MaterialRefreshServices s,uint runtime,uint material,uint mode)
        {if(s==null||s.Factory==null)throw new ArgumentException("Explicit shader factory service required.");return s.Factory(m,s.Manager,runtime,material,mode,0,0);}
        private static uint Color(RenderPacketMemory m,uint p)
        {
            double value=(double)BitConverter.ToSingle(m.Block(p,4),0)*255;
            if(Double.IsNaN(value)||Double.IsInfinity(value)||value<Int32.MinValue||value>Int32.MaxValue)throw new ArgumentException("Finite Int32-range color product required.");return unchecked((uint)(int)value)&255;
        }
        // Original601030 CPU state around the explicit shader factory. Valid
        // positive old shader IDs must be<=400; negative/zero IDs are skipped.
        // Callback mutations are retained: native reads the FIRST returned
        // program's WORD index only after requesting the second program.
        public static void Refresh(RenderPacketMemory m,uint material,MaterialRefreshServices s)
        {
            if(m==null||s==null||s.ResolveDeclaration==null)throw new ArgumentNullException();if(s.LockToken!=0)throw new NotSupportedException("Zero-lock refresh branch only.");
            short textureCount=unchecked((short)m.Word(material+0x74));if(textureCount>0)
            {
                m.Dword(material+0xb8,(uint)textureCount);if(m.Byte(material+0x15c)==0)m.Byte(material+0x15c,1);uint layout=m.Dword(material+0x1f0);if((layout&0x3800)==0)m.Dword(material+0x1f0,(layout&0xffffcfff)|0x800);
            }
            if((m.Dword(material+0x44)&0x800000)!=0&&m.Dword(material+0x3c)==0)m.Dword(material+0x1f0,m.Dword(material+0x1f0)|0x40000);
            for(uint off=0x1f4;off<=0x1f6;off+=2)
            {
                short index=unchecked((short)m.Word(material+off));if(index>0){uint p=ProgramByIndex(s.Manager,(uint)index);if(p==0)throw new ArgumentException("Valid old program index<=400 required.");Release(m,p);}
            }
            if((m.Dword(material+0x44)&0x800000)!=0&&m.Dword(material+0x3c)==0)
            {
                uint first=RequestDefault(m,s,material+0xb4,material);m.Word(material+0x1f4,m.Word(first));
                // The secondary index retains its previous value, despite
                // its old reference having been released above.
            }
            else
            {
                uint first=RequestMode(m,s,material+0xb4,material,FirstMode(m,s.DeviceState));uint second=RequestMode(m,s,material+0xb4,material,SecondMode(m,s.DeviceState));m.Word(material+0x1f4,m.Word(first));m.Word(material+0x1f6,m.Word(second));
            }
            m.Dword(material+0x2bc,s.ResolveDeclaration(m.Dword(material+0x1f0)));
            if(m.Word(material+0x74)==0)m.Dword(material+0xc8,0xff000000|(Color(m,material+0x5c)<<16)|(Color(m,material+0x58)<<8)|Color(m,material+0x54));
        }
    }
}
