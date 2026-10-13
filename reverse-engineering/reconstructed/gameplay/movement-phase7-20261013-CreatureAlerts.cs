using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class CreatureAlertWorld
 {
  public Func<string,PcObjectImage> ResolveCharacter;
  // Reads definition+0x24 then nestedtype+0x90, preserving pointer validity/faults.
  public Func<uint,uint> TypeFlags;
  public uint SourceActor,DurationBits;
  public readonly uint[] PositionBits=new uint[3];
  public uint RuntimeDurationBits;
 }
 public static class CreatureAlerts
 {
  //0x4399e0. Null actor still emits a position-only alert with source0.
  public static void Produce(CreatureAlertWorld w,uint actorAddress,PcObjectImage actor,uint[] position)
  {
   bool accept=actor==null;
   if(actor!=null)
   {
    uint flags=actor.U32(0x1fc);
    if((flags&1)!=0&&(flags&0x1000)!=0&&(actor.U8(0x1f8)&5)==0)
    {
     if(w.TypeFlags==null)throw new InvalidOperationException("Definition/type chain required.");
     accept=(w.TypeFlags(actor.U32(0x54))&0x8000)==0;
    }
   }
   if(!accept)return;
   if(position==null||position.Length<3)throw new InvalidOperationException("Native alert position pointer required.");
   w.SourceActor=actor==null?0:actorAddress;Array.Copy(position,w.PositionBits,3);w.DurationBits=w.RuntimeDurationBits;
  }
  //0x454150. First-call-only target selection; returns1 even when no alert emits.
  public static bool Alert(CreatureAlertWorld w,uint selfAddress,PcObjectImage self,string[] tokens,bool first,Func<PcObjectImage,uint> address)
  {
   if(first)
   {
    PcObjectImage target=self;
    if(tokens!=null)foreach(string token in tokens)
    {
     MessageNumbers.RequireAscii(token);int at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase);
     if(at>=0){if(at+10>token.Length)throw new ArgumentException("Native token skip exceeds terminator.");target=w.ResolveCharacter==null?null:w.ResolveCharacter(token.Substring(at+10));}
    }
    if(target!=null){uint id=Object.ReferenceEquals(target,self)?selfAddress:address==null?0:address(target);if(id==0)throw new InvalidOperationException("Actor address required.");Produce(w,id,target,new uint[]{target.U32(0x80),target.U32(0x84),target.U32(0x88)});}
   }
   return true;
  }
 }
}
