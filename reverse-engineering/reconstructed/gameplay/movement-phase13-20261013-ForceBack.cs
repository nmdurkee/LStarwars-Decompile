using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class ForceBackState
 {
  public uint Actor,Origin,Extra;
  public float Radius,RadiusSquared;
 }
 public sealed class ForceBackWorld
 {
  public OriginPathMemory Memory;
  public ScriptPacket Numbers;
  public readonly ForceBackState State=new ForceBackState();
  public Func<uint,string,uint> ResolveReference;
 }
 public static class ForceBackCommands
 {
  public static void Clear(ForceBackState s){s.Actor=s.Origin=0;}
  public static void Publish(ForceBackState s,uint actor,uint fallback,float radius,uint extra)
  {
   s.Actor=actor;s.Origin=actor!=0?unchecked(actor+0x80):fallback;s.Radius=radius;s.Extra=extra;s.RadiusSquared=PlaybackWide.Multiply(PlaybackWide.From(radius),PlaybackWide.From(radius)).Store();
  }
  static string Read(OriginPathMemory m,uint p){var s=new System.Text.StringBuilder();for(;;p++){byte b=m.U8(p);if(b==0)return s.ToString();if(b>127)throw new ArgumentException("ASCII locator table required.");s.Append((char)b);}}
  static uint Find(OriginPathMemory m,uint world,string name)
  {
   if(world==0)return 0;int j=0;while(j<unchecked((int)m.U32(world+0x24))){uint row=m.U32(world+0x28)+unchecked((uint)j*0x3c);if(String.Equals(Read(m,row),name,StringComparison.OrdinalIgnoreCase))return row;j++;}return 0;
  }
  static string Tail(string t,int at,int n){if(at+n>t.Length)throw new ArgumentException("Native token skip exceeds terminator.");return t.Substring(at+n);}
  public static bool SetForceBack(ForceBackWorld w,uint world,uint packet,uint creature,string[] tokens,bool first)
  {
   if(!first)return true;var m=w.Memory;uint actor=0,point=0,type=0;float radius=1.5f;bool enabled=true;
   if(creature!=0){uint reference=m.U32(creature+0xd0);if(reference!=0)actor=m.U32(reference);}
   if(tokens!=null)foreach(string token in tokens)
   {
    MessageNumbers.RequireAscii(token);int at;
    if((at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase))>=0){uint reference=w.ResolveReference==null?0:w.ResolveReference(world,Tail(token,at,10));actor=reference==0?0:m.U32(reference);}
    else if((at=token.IndexOf("locator=",StringComparison.OrdinalIgnoreCase))>=0){uint row=Find(m,world,Tail(token,at,8));if(row!=0)point=row+0x10;}
    else if((at=token.IndexOf("radius=",StringComparison.OrdinalIgnoreCase))>=0){if(w.Numbers!=null)for(int j=0;j<4;j++)w.Numbers.Parameters[j]=m.F32(packet+0x14+(uint)j*4);radius=MessageNumbers.Resolve(w.Numbers,Tail(token,at,7));}
    else if(String.Equals(token,"FALSE",StringComparison.OrdinalIgnoreCase))enabled=false;
    else if(String.Equals(token,"type=CHOKE",StringComparison.OrdinalIgnoreCase))type=1;
    else if(String.Equals(token,"type=DROID",StringComparison.OrdinalIgnoreCase))type=2;
    else if(String.Equals(token,"type=ComboOpponent",StringComparison.OrdinalIgnoreCase))type=3;
   }
   if(!enabled)Clear(w.State);else if(actor!=0||point!=0)Publish(w.State,actor,point,radius,type);
   return true;
  }
 }
}
