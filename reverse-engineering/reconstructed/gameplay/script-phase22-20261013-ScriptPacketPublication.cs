// Native packet publication: channel statistics, copy on each listener, reference lifetime.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptPacketDeliveryServices {public abstract void Deliver(TakeoverReleaseMemory m,uint callback,uint listener,ScriptRecordingPacket packet,uint first,uint second);}
 public static class PreparedScriptPacketPublication
 {
  static void Release(TakeoverReleaseMemory m,uint buffer){if(buffer==0)return;uint n=m.Read32(buffer+0x4b0);m.Write32(buffer+0x4b0,n>1?n-1:0);}
  static void Fallback(TakeoverReleaseMemory m){m.Write32(m.Read32(0x28572e0)+0x34,0xa0001000);}
  //60e590 thiscall(publisher,mode,buffer,start,end,channel), ret20. First matching low-byte channel.
  public static void Statistics(TakeoverReleaseMemory m,uint publisher,ScriptRecordingPacket packet,uint channel)
  {uint node=m.Read32(publisher+4);while(node!=0){if(m.Read8(node+0xc)==(byte)channel){uint length=packet.Buffer==0?0:unchecked(packet.End-packet.Start);m.Write32(node+0x38,m.Read32(node+0x38)+length);m.Write32(node+0x40,m.Read32(node+0x40)+1);break;}node=m.Read32(node);}Release(m,packet.Buffer);}
  //60ee80 thiscall(packet*) preserving mode/start/end. Packet struct disjoint from payload.
  public static void Clone(TakeoverReleaseMemory m,ScriptRecordingPacket packet)
  {uint next=PreparedScriptRecording.Allocate(m,packet.Start).Buffer;uint old=packet.Buffer;if(old!=0&&next!=0){uint length=unchecked(packet.End-packet.Start);if(length>0x4b0)throw new ArgumentException("Bounded packet payload required.");for(uint i=0;i<length;i++)m.Write8(unchecked(next+packet.Start+i),m.Read8(unchecked(old+packet.Start+i)));}else Fallback(m);Release(m,packet.Buffer);packet.Buffer=next;}
  //60f190 thiscall(publisher,mode,buffer,start,end,channel), ret20. Caller packet is by value.
  public static void Publish(TakeoverReleaseMemory m,ScriptPacketDeliveryServices s,uint publisher,ScriptRecordingPacket input,uint channel)
  {
   var packet=new ScriptRecordingPacket(input.Mode,input.Buffer,input.Start,input.End);uint buffer=packet.Buffer;if(buffer==0)return;
   if(unchecked((int)(packet.End-packet.Start))>0)
   {
    packet.Start=unchecked(packet.Start-1);m.Write8(unchecked(buffer+packet.Start),(byte)channel);m.Write32(buffer+0x4b0,m.Read32(buffer+0x4b0)+1);Statistics(m,publisher,new ScriptRecordingPacket(packet.Mode,buffer,packet.Start,packet.End),channel);
    uint listener=m.Read32(m.Read32(0x28fec04)+0x94);uint budget=0;
    while(listener!=0)
    {if(++budget>4096)throw new ArgumentException("Bounded acyclic listener chain required.");Clone(m,packet);buffer=packet.Buffer;if(buffer==0)Fallback(m);else m.Write32(buffer+0x4b0,m.Read32(buffer+0x4b0)+1);uint callback=m.Read32(m.Read32(listener)+0xc);s.Deliver(m,callback,listener,new ScriptRecordingPacket(packet.Mode,buffer,packet.Start,packet.End),0,0);listener=m.Read32(listener+4);}
   }
   Release(m,buffer);
  }
 }
 public sealed class RecoveredPacketRecordingServices:ScriptRecordingServices
 {
  readonly ScriptRecordingServices remaining;readonly ScriptPacketDeliveryServices listeners;public RecoveredPacketRecordingServices(ScriptRecordingServices callbacks,ScriptPacketDeliveryServices delivery){remaining=callbacks;listeners=delivery;}
  public override uint Allowed(TakeoverReleaseMemory m,uint callback){return remaining.Allowed(m,callback);}public override uint ActorIdentifier(TakeoverReleaseMemory m,uint callback,uint recorder,uint actor){return remaining.ActorIdentifier(m,callback,recorder,actor);}public override void Publish(TakeoverReleaseMemory m,uint publisher,ScriptRecordingPacket packet,uint channel){PreparedScriptPacketPublication.Publish(m,listeners,publisher,packet,channel);}
 }
}
