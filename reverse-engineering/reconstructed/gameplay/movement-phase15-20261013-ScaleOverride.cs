using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class ScaleOverrideWorld
 {
  public OriginPathMemory Memory;
  public ScriptPacket Numbers;
  public readonly ScriptRandom Random=new ScriptRandom();
  public float Delta;
 }
 public static class ScaleOverrideCommands
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static string Tail(string t,int p,int n){if(p+n>t.Length)throw new ArgumentException("Native token skip exceeds terminator.");return t.Substring(p+n);}
  static float Number(ScaleOverrideWorld w,uint packet,string text){if(w.Numbers!=null)for(int j=0;j<4;j++)w.Numbers.Parameters[j]=w.Memory.F32(packet+0x14+(uint)j*4);return MessageNumbers.Resolve(w.Numbers,text);}
  public static bool SetScaleOverride(ScaleOverrideWorld w,uint packet,uint creature,string[] tokens,bool first)
  {
   var m=w.Memory;if(creature==0)return true;uint reference=m.U32(creature+0xd0);if(reference==0)return true;uint actor=m.U32(reference);if(actor==0)return true;
   if(first)
   {
    float min=1000000000f,max=min,value=min,time=0;
    if(tokens!=null)foreach(string token in tokens){MessageNumbers.RequireAscii(token);int at;if(String.Equals(token,"reset",StringComparison.OrdinalIgnoreCase))value=1000000000f;else if((at=token.IndexOf("min=",StringComparison.OrdinalIgnoreCase))>=0)min=Number(w,packet,Tail(token,at,4));else if((at=token.IndexOf("max=",StringComparison.OrdinalIgnoreCase))>=0)max=Number(w,packet,Tail(token,at,4));else if((at=token.IndexOf("time",StringComparison.OrdinalIgnoreCase))>=0)time=Number(w,packet,Tail(token,at,5));else value=Number(w,packet,token);}
    if(min!=1000000000f&&max!=1000000000f){float r=w.Random.Next();value=((N.From(1)-N.From(r))*N.From(min)+N.From(max)*N.From(r)).Store();}
    if(time==0){m.SetFloat(actor+0x102c,value);return true;}
    m.SetFloat(packet+0x70,time);m.SetFloat(packet+0x74,((N.From(value)-N.From(m.F32(actor+0x102c)))/N.From(time)).Store());
   }
   float remaining=m.F32(packet+0x70);if(remaining<=0)return true;
   if(w.Delta<remaining){m.SetFloat(actor+0x102c,(N.From(w.Delta)*N.From(m.F32(packet+0x74))+N.From(m.F32(actor+0x102c))).Store());m.SetFloat(packet+0x70,(N.From(remaining)-N.From(w.Delta)).Store());return false;}
   m.SetFloat(actor+0x102c,(N.From(m.F32(packet+0x74))*N.From(remaining)+N.From(m.F32(actor+0x102c))).Store());m.SetFloat(packet+0x70,0);return true;
  }
 }
}
