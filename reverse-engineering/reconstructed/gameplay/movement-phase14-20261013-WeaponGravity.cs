using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class WeaponGravityWorld
 {
  public OriginPathMemory Memory;
  public ScriptPacket Numbers;
  public readonly ScriptRandom Random=new ScriptRandom();
  public Func<uint,string,uint> ResolveReference;
 }
 public static class WeaponGravityCommands
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static uint Actor(OriginPathMemory m,uint creature){if(creature==0)return 0;uint reference=m.U32(creature+0xd0);return reference==0?0:m.U32(reference);}
  static string Tail(string t,int p,int n){if(p+n>t.Length)throw new ArgumentException("Native token skip exceeds terminator.");return t.Substring(p+n);}
  static float Number(WeaponGravityWorld w,uint packet,string text){if(w.Numbers!=null)for(int j=0;j<4;j++)w.Numbers.Parameters[j]=w.Memory.F32(packet+0x14+(uint)j*4);return MessageNumbers.Resolve(w.Numbers,text);}
  public static bool SnapWeaponOut(WeaponGravityWorld w,uint world,uint creature,string[] tokens,bool first)
  {
   if(!first)return true;var m=w.Memory;uint actor=Actor(m,creature);bool enabled=true;int keep=-1;
   if(tokens!=null)foreach(string token in tokens){MessageNumbers.RequireAscii(token);int at;if((at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase))>=0){uint reference=w.ResolveReference==null?0:w.ResolveReference(world,Tail(token,at,10));actor=reference==0?0:m.U32(reference);}else if((at=token.IndexOf("keep_out=",StringComparison.OrdinalIgnoreCase))>=0)keep=String.Equals(Tail(token,at,9),"TRUE",StringComparison.OrdinalIgnoreCase)?1:0;else if(String.Equals(token,"FALSE",StringComparison.OrdinalIgnoreCase))enabled=false;}
   if(actor!=0){if(enabled){m.Set32(actor+0xe20,m.U32(actor+0xe20)|0x10000);m.SetFloat(actor+0xd3c,1);if(keep!=-1)m.Set32(actor+0xeec,(m.U32(actor+0xeec)&~0x10u)|((uint)keep<<4));}else{m.Set32(actor+0xe20,m.U32(actor+0xe20)&~0x10000u);m.Set32(actor+0xeec,m.U32(actor+0xeec)&~0x10u);m.SetFloat(actor+0xd3c,0);}}
   return true;
  }
  public static bool SetGravityHeight(WeaponGravityWorld w,uint packet,uint creature,string[] tokens,bool first)
  {
   uint actor=Actor(w.Memory,creature);if(actor==0||!first)return true;var m=w.Memory;m.Set32(actor+0xeec,m.U32(actor+0xeec)&0x7fffffff);m.SetFloat(actor+0x1028,1000000000f);float min=1000000000f,max=min;
   if(tokens!=null)foreach(string token in tokens){MessageNumbers.RequireAscii(token);int at;if(String.Equals(token,"reset",StringComparison.OrdinalIgnoreCase))continue;if((at=token.IndexOf("min=",StringComparison.OrdinalIgnoreCase))>=0)min=Number(w,packet,Tail(token,at,4));else if((at=token.IndexOf("max=",StringComparison.OrdinalIgnoreCase))>=0)max=Number(w,packet,Tail(token,at,4));else m.SetFloat(actor+0x1028,Number(w,packet,token));}
   if(min!=1000000000f&&max!=1000000000f){float r=w.Random.Next();N a=(N.From(1)+N.From(-1)*N.From(r))*N.From(min),b=N.From(max)*N.From(r);m.SetFloat(actor+0x1028,(a+b).Store());}
   return true;
  }
 }
}
