using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class LocatorIntegerState {public uint State;}
 public sealed class LocatorIntegerRandom
 {
  public readonly LocatorIntegerState Global=new LocatorIntegerState();
  //0x5b9e90. A nonnull local zero seed becomes1; a zero global seed does not.
  public uint Next(LocatorIntegerState state)
  {
   if(state==null)state=Global;else if(state.State==0)state.State=1;
   uint x=state.State^0x075bd924u;int quotient=unchecked((int)x)/0x1f31d;
   uint value=unchecked(x*0x41a7u+(uint)((long)quotient*-0x7fffffffL));
   if(unchecked((int)value)<0)value=unchecked(value+0x7fffffffu);
   state.State=value^0x075bd924u;return state.State;
  }
 }
 public sealed class DoomedLocatorWorld
 {
  public readonly LocatorWorld Locators;
  public DoomedLocatorWorld():this(new LocatorWorld()){}
  public DoomedLocatorWorld(LocatorWorld locators){Locators=locators??new LocatorWorld();}
  public readonly LocatorIntegerRandom Random=new LocatorIntegerRandom();
  public Func<string,PcObjectImage> ResolveCharacter;
  public Func<uint,string> CharacterName;
  public Func<LocatorRecord,uint> LocatorAddress;
 }
 public static class DoomedLocatorActions
 {
  static int Match(string token,string key){return token.IndexOf(key,StringComparison.OrdinalIgnoreCase);}
  static string Tail(string token,int at,int skip){if(at+skip>token.Length)throw new ArgumentException("Native skip passes terminator.");return token.Substring(at+skip);}
  static int Integer(float v){if(Single.IsNaN(v)||Single.IsInfinity(v)||(double)v< -2147483648.0||(double)v>=2147483648.0)throw new ArgumentOutOfRangeException("token");return(int)v;}
  //0x446b30: void action, first-call gated; token count0 leaves target untouched.
  public static void Set(DoomedLocatorWorld w,ScriptPacket packet,PcObjectImage self,string[] tokens,bool first)
  {
   if(!first||tokens==null||tokens.Length==0)return;
   PcObjectImage target=self;string name=null;bool personal=false,indexed=false,damage=false;int random=0;
   foreach(string token in tokens)
   {
    MessageNumbers.RequireAscii(token);int at;
    if((at=Match(token,"character="))>=0)target=w.ResolveCharacter==null?null:w.ResolveCharacter(Tail(token,at,10));
    else if((at=Match(token,"name"))>=0)name=Tail(token,at,5);
    else if(Match(token,"personal")>=0)personal=true;
    else if(Match(token,"indexed")>=0)indexed=true;
    else if(Match(token,"take_damage")>=0)damage=true;
    else if((at=Match(token,"random"))>=0)random=Integer(MessageNumbers.Resolve(packet,Tail(token,at,9)));
   }
   if(target==null)return;
   target.Set32(0xef0,target.U32(0xef0)&~0x800u);target.Set32(0xf14,0);
   if(name==null)return;
   var actor=new LocatorActor{PersonalIndex=target.I8(0x280)};uint definition=target.U32(0x54);
   if(personal&&definition!=0&&(!indexed||actor.PersonalIndex==-1)){if(w.CharacterName==null)throw new InvalidOperationException("Character definition name service required.");actor.CharacterName=w.CharacterName(definition);if(actor.CharacterName==null)throw new InvalidOperationException("Native nonnull definition has unreadable name pointer.");}
   w.Locators.NextInteger=delegate{return unchecked((int)w.Random.Next(null));};
   LocatorRecord found=w.Locators.Find(LocatorCommands.FormatName(w.Locators,actor,name,indexed,personal,random));
   if(found!=null){if(w.LocatorAddress==null)throw new InvalidOperationException("Locator address service required.");target.Set32(0xf14,w.LocatorAddress(found));target.Set32(0xef0,(target.U32(0xef0)&~0x800u)|(damage?0x800u:0));}
  }
 }
}
