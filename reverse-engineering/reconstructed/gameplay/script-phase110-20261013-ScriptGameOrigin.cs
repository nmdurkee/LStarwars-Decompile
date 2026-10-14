// Actual registered game-origin callback43c3a0, with finite x87 stores and live cache flags.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptGameOrigin
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite prepared origin arithmetic required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Product(float a,float b){if(a==0||b==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Products(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();}
  // cdecl(system,actor), returns actor+F8 after a single lazy computation, or zero for missing system/actor/selector.
  public static uint Resolve(TakeoverReleaseMemory m,uint system,uint actor)
  {
   if(system==0||actor==0)return 0;byte selector=m.Read8(actor+0x138);if(selector==255)return 0;
   if((m.Read8(actor+0x1ec)&8)==0)
   {
    uint record=unchecked(m.Read32(system+0x18)+(uint)selector*0xa4);byte column=m.Read8(actor+0x149);
    float x=Product((column+1)/2,F(m.Read32(record+0x5c)));if((column&1)!=0)x=F(B(x)^0x80000000);
    float z=Product(m.Read8(actor+0x14a),F(m.Read32(record+0x60)^0x80000000));
    int angle=unchecked((int)m.Read32(record+0x2c));uint ci=(uint)(unchecked(angle+0x4000)>>1)&0x7fff,si=(uint)(angle>>1)&0x7fff;
    float cosine=F(m.Read32(0x29899a0+ci*4)),sine=F(m.Read32(0x29899a0+si*4));
    float rx=Products(sine,z,cosine,x),rz=Products(cosine,z,F(B(sine)^0x80000000),x);
    m.Write32(actor+0xf8,B(Sum(rx,F(m.Read32(record+0x20)))));
    m.Write32(actor+0xfc,B(Sum(0,F(m.Read32(record+0x24)))));
    m.Write32(actor+0x100,B(Sum(rz,F(m.Read32(record+0x28)))));
    m.Write32(actor+0x1ec,m.Read32(actor+0x1ec)|8);
   }
   return unchecked(actor+0xf8);
  }
 }
 public sealed class RecoveredScriptGameOriginServices:ScriptOriginServices
 {
  readonly ScriptOriginServices remaining;public RecoveredScriptGameOriginServices(ScriptOriginServices other){remaining=other;}
  public override uint Origin(TakeoverReleaseMemory m,uint callback,uint system,uint actor){if(callback==0x43c3a0)return PreparedScriptGameOrigin.Resolve(m,system,actor);if(remaining==null)throw new NotSupportedException("Custom origin callback required.");return remaining.Origin(m,callback,system,actor);}
 }
}
