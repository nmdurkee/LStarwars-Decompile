// Script action recording, not an animation setter. Packet transport remains explicit.
using System;
namespace Recovered.Gameplay
{
 public sealed class ScriptRecordingPacket {public uint Mode,Buffer,Start,End;public ScriptRecordingPacket(uint mode,uint buffer,uint start,uint end){Mode=mode;Buffer=buffer;Start=start;End=end;}}
 public abstract class ScriptRecordingServices
 {
  public abstract uint Allowed(TakeoverReleaseMemory m,uint callback);
  public abstract uint ActorIdentifier(TakeoverReleaseMemory m,uint callback,uint recorder,uint actor);
  public abstract void Publish(TakeoverReleaseMemory m,uint publisher,ScriptRecordingPacket packet,uint channel);
 }
 public static class PreparedScriptRecording
 {
  const uint First=0x28683e0,Limit=0x28febe0,Stride=0x4b4;
  //53d5d0 thiscall(output,size), ret4. First pool record with unsigned counter0 is leased.
  public static ScriptRecordingPacket Allocate(TakeoverReleaseMemory m,uint start){uint p=First;while(p!=Limit&&m.Read32(p+0x4b0)!=0)p+=Stride;if(p==Limit)p=0;else m.Write32(p+0x4b0,1);return new ScriptRecordingPacket(1,p,start,start);}
  static void Release(TakeoverReleaseMemory m,uint buffer){if(buffer==0)return;uint n=m.Read32(buffer+0x4b0);m.Write32(buffer+0x4b0,n>1?n-1:0);}
  static void Half(TakeoverReleaseMemory m,uint p,uint value,bool big){m.Write8(p,(byte)(big?value>>8:value));m.Write8(p+1,(byte)(big?value:value>>8));}
  static uint Length(TakeoverReleaseMemory m,uint p){for(uint i=0;i<4096;i++)if(m.Read8(p+i)==0)return i;throw new ArgumentException("Bounded NUL token required.");}
  //53d940 thiscall(recorder,action,actor), ret8. Sources and packet writes must not overlap.
  public static void Record(TakeoverReleaseMemory m,ScriptRecordingServices s,uint recorder,uint action,uint actor)
  {
   ScriptRecordingPacket lease=Allocate(m,0x20);uint allowed=m.Read32(0x876d88);if(allowed!=0&&s.Allowed(m,allowed)==0){Release(m,lease.Buffer);return;}
   uint callback=m.Read32(m.Read32(recorder)+0x30);uint identifier=s.ActorIdentifier(m,callback,recorder,actor)&0xffff;uint buffer=lease.Buffer,end=lease.End,descriptor=m.Read32(action+0x10);uint code=m.Read16(descriptor+0xa);byte type=m.Read8(descriptor+9),count=m.Read8(action+0xc);
   if(buffer!=0){m.Write8(buffer+end,1);end++;m.Write8(buffer+end,type);end++;Half(m,buffer+end,code,lease.Mode!=0);end+=2;Half(m,buffer+end,identifier,lease.Mode!=0);end+=2;m.Write8(buffer+end,count);end++;}
   uint i=0;while(unchecked((int)m.Read32(action+0xc))>unchecked((int)i)){uint token=m.Read32(m.Read32(action+8)+i*4);if(buffer!=0){uint length=Length(m,token);m.Write8(buffer+end,(byte)length);for(uint j=0;j<length;j++)m.Write8(buffer+end+1+j,m.Read8(token+j));end=unchecked(end+length+1);}i++;if(i>4096)throw new ArgumentException("Bounded action token count required.");}
   ScriptRecordingPacket packet=new ScriptRecordingPacket(lease.Mode,buffer,lease.Start,end);if(buffer!=0)m.Write32(buffer+0x4b0,m.Read32(buffer+0x4b0)+1);else m.Write32(m.Read32(0x28572e0)+0x34,0xa0001000);s.Publish(m,0x28572e8,packet,10);Release(m,buffer);
  }
  //53db30 cdecl(action,actor), recorder captured from9242c0 before children.
  public static void Emit(TakeoverReleaseMemory m,ScriptRecordingServices s,uint action,uint actor){uint recorder=m.Read32(0x9242c0);if(recorder!=0)Record(m,s,recorder,action,actor);}
 }
 public sealed class RecoveredRecordingDispatcherServices:ScriptDispatcherServices
 {
  readonly ScriptDispatcherServices remaining;readonly ScriptRecordingServices recording;public RecoveredRecordingDispatcherServices(ScriptDispatcherServices services,ScriptRecordingServices packets){remaining=services;recording=packets;}
  // Phase18 retained provisional name Animation for this call edge; original body records action metadata/tokens.
  public override void Animation(TakeoverReleaseMemory m,uint action,uint actor){PreparedScriptRecording.Emit(m,recording,action,actor);}
  public override uint Conditions(TakeoverReleaseMemory m,uint bank,uint system,uint list,uint actor,uint packet){return remaining.Conditions(m,bank,system,list,actor,packet);}public override uint References(TakeoverReleaseMemory m,uint system,uint actor){return remaining.References(m,system,actor);}public override void Scratch(TakeoverReleaseMemory m,uint callback,uint system,uint actor,uint packet){remaining.Scratch(m,callback,system,actor,packet);}public override uint Command(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint a,uint b,uint first,uint delta){return remaining.Command(m,callback,system,packet,actor,a,b,first,delta);}
 }
}
