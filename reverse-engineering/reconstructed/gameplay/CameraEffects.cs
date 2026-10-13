// Bounded original-PC camera effect commands and reset. These state operations
// do not update the live view transform or render the resulting camera effect.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class GameCameraImage
    {
        public readonly byte[] Bytes;
        public GameCameraImage(byte[] bytes){if(bytes==null||bytes.Length!=0x230)throw new ArgumentException("Expected complete0x230-byte camera record.");Bytes=(byte[])bytes.Clone();}
        public uint Word(int p){return BitConverter.ToUInt32(Bytes,p);}
        public float Float(int p){return BitConverter.ToSingle(Bytes,p);}
        public void SetWord(int p,uint v){Array.Copy(BitConverter.GetBytes(v),0,Bytes,p,4);}
        public void SetFloat(int p,float v){Array.Copy(BitConverter.GetBytes(v),0,Bytes,p,4);}
    }
    public sealed class CameraEffectWorld
    {
        public GameCameraImage Camera;
        public CameraCutState Cuts;
        public bool CutActive;
        public QRandom Random;
        public byte ResetValueCb,ResetValueCc;
        // Native0x951500..0x9518fc. Loader supplies existing bytes and aliases.
        public readonly byte[] CutBindings=new byte[0x3fc];
    }
    public static class CameraEffects
    {
        static float R(double value){return MessageNumbers.Round((float)value);}
        static string Tail(string text,int at,int skip){if(at+skip>text.Length)throw new ArgumentException("Native token skip crosses the terminator.");return text.Substring(at+skip);}
        // 0x549bb0; passing null chooses the global camera record.
        public static void SetShake(CameraEffectWorld w,GameCameraImage camera,float magnitude,float time,float speed)
        {camera=camera??w.Camera;camera.SetFloat(0x1d4,magnitude);camera.SetFloat(0x1d8,time);camera.SetFloat(0x1dc,speed);}
        // 0x549de0, nonspatial branch used by JudderGameCamera. Distance attenuation
        // when the native fourth argument is nonnull is outside this projection.
        public static void SetJudder(CameraEffectWorld w,GameCameraImage camera,float value,byte axis)
        {
            camera=camera??w.Camera;float magnitude=Math.Abs(value);
            if(camera.Float(0x1c8)<magnitude){camera.SetFloat(0x1cc,magnitude);camera.SetFloat(0x1c8,magnitude);camera.Bytes[0x228]=(byte)(value<0?1:0);camera.Bytes[0x229]=axis;}
        }
        // 0x576c40. The built-in record's blend field aliases the cleared range.
        public static void ClearBindings(CameraEffectWorld w)
        {Array.Clear(w.CutBindings,0,w.CutBindings.Length);w.Cuts.Builtin.RemainingBlend=0;}
        // 0x54a2f0. Every unmentioned byte in the camera record survives.
        public static void Reset(CameraEffectWorld w,GameCameraImage camera)
        {
            camera=camera??w.Camera;
            foreach(int p in new int[]{0x1c8,0x1d0,0x1d4,0x1d8,0x1c0,0x1bc,0x1b8,0x1ec,0x1e8,0x1f4,0x1f0,0x214,0x218,0x20c,0x210,0x204,0x208})camera.SetWord(p,0);
            camera.Bytes[0x22d]=255;camera.Bytes[0x22c]=255;camera.Bytes[2]=255;camera.Bytes[3]=255;camera.Bytes[1]=255;camera.SetFloat(0x1dc,1);
            w.Cuts.Selected=null;w.CutActive=false;camera.SetFloat(0x1e0,w.ResetValueCb);camera.SetFloat(0x1e4,w.ResetValueCc);ClearBindings(w);
        }
        // 0x44d300; its first-call gate is at stack argument6.
        public static bool ResetCommand(CameraEffectWorld w,bool first){if(first)Reset(w,w.Camera);return true;}
        // 0x451c20. Each end_time is relative to elapsed cut time, not to the
        // previous requested end; end_time takes precedence within one token.
        public static bool EndCut(CameraEffectWorld w,ScriptPacket packet,string[] tokens,bool first)
        {
            if(!first||!w.CutActive)return true;
            foreach(string raw in tokens){string t=SceneryText.C(raw);int at=SceneryText.Index(t,"end_time=");if(at>=0)w.Cuts.End=R((double)MessageNumbers.Resolve(packet,Tail(t,at,9))+w.Cuts.Elapsed);else{at=SceneryText.Index(t,"blend_out_time=");if(at>=0)w.Cuts.BlendOut=MessageNumbers.Resolve(packet,Tail(t,at,15));}}
            return true;
        }
        // 0x44d210.
        public static bool Shake(CameraEffectWorld w,ScriptPacket packet,string[] tokens,bool first)
        {
            if(!first)return true;float magnitude=1,time=0,speed=1;
            foreach(string raw in tokens){string t=SceneryText.C(raw);int at=SceneryText.Index(t,"mul=");if(at>=0)magnitude=MessageNumbers.Resolve(packet,Tail(t,at,4));else if((at=SceneryText.Index(t,"time="))>=0)time=MessageNumbers.Resolve(packet,Tail(t,at,5));else if((at=SceneryText.Index(t,"speed="))>=0)speed=MessageNumbers.Resolve(packet,Tail(t,at,6));}
            SetShake(w,w.Camera,magnitude,time,speed);return true;
        }
        // 0x44d110. Only the finalZ axis draws the shared integer RNG.
        public static bool Judder(CameraEffectWorld w,ScriptPacket packet,string[] tokens,bool first)
        {
            if(!first)return true;byte axis=0;float value=.1f;
            foreach(string raw in tokens){string t=SceneryText.C(raw);int at;if(SceneryText.Index(t,"axis=x")>=0)axis=0;else if(SceneryText.Index(t,"axis=y")>=0)axis=1;else if(SceneryText.Index(t,"axis=z")>=0)axis=2;else if((at=SceneryText.Index(t,"time"))>=0)value=MessageNumbers.Resolve(packet,Tail(t,at,5));}
            if(tokens.Length!=0&&axis==2){if(w.Random==null)throw new InvalidOperationException("Missing shared QRandom.");if(w.Random.Next()<32768)value=-value;}
            SetJudder(w,w.Camera,value,axis);return true;
        }
        // 0x441c00; null world-object result covers the creature/reference/object
        // null gates. Float32 differences, then native ordered extended dot sum.
        public static float Behind(CameraEffectWorld w,CameraPoint worldObject)
        {
            if(worldObject==null)return 0;SpawnVector p=worldObject.Position;
            float x=R((double)p.X-w.Camera.Float(0x11c)),y=R((double)p.Y-w.Camera.Float(0x120)),z=R((double)p.Z-w.Camera.Float(0x124));
            PlaybackWide sum=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(w.Camera.Float(0x114)),PlaybackWide.From(y)),PlaybackWide.Multiply(PlaybackWide.From(w.Camera.Float(0x110)),PlaybackWide.From(x)));
            sum=PlaybackWide.Add(sum,PlaybackWide.Multiply(PlaybackWide.From(w.Camera.Float(0x118)),PlaybackWide.From(z)));
            // Extended negative values remain negative even if a float store
            // would underflow to-0. Exact zero in PlaybackWide has no sign.
            return(BitConverter.ToUInt32(BitConverter.GetBytes(sum.Store()),0)&0x80000000)!=0?1:0;
        }
    }
}
