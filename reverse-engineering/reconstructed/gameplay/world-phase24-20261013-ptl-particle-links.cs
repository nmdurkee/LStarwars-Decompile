using System;
namespace Recovered.Gameplay {
 public static class PtlParticleLinks {
  static int Type(SoundSetupImage m,uint packet){return (sbyte)m.Byte(unchecked(m.Word(packet+4)+0x2e));}
  static float Time(SoundSetupImage m,uint node){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(unchecked(node+4))),0);}
  // 0x5ffea0: last command terminates with byte52/link0; reverse preceding commands use byte4e and fresh next-pointer reads.
  // No count<=0 guard exists: a readable preceding table entry is still written for zero/negative counts.
  public static void Commands(SoundSetupImage m,uint table,int count){unchecked{
   uint last=m.Word(table+(uint)count*4-4);m.Byte(last,0x52);m.Word(last+4,0);
   for(int i=count-2;i>=0;i--){uint p=m.Word(table+(uint)i*4);m.Byte(p,0x4e);m.Word(p+4,m.Word(table+(uint)(i+1)*4));}
  }}
  // 0x654e00: descending unsigned16 priority; ties use ascending signed physical type, new exact ties prepend.
  public static void Priority(SoundSetupImage m,uint packet,uint headPointer){unchecked{
   m.Word(packet+0x5c,0);m.Word(packet+0x58,0);uint previous=m.Word(headPointer);if(previous==0){m.Word(headPointer,packet);return;}
   ushort priority=m.Half(previous+0x60);uint next=m.Word(previous+0x5c);ushort incoming=m.Half(packet+0x60);
   if(incoming>priority||(incoming==priority&&Type(m,packet)<=Type(m,previous))){m.Word(packet+0x5c,previous);m.Word(previous+0x58,packet);m.Word(headPointer,packet);return;}
   while(next!=0){ushort p=m.Half(next+0x60);if(incoming<p||(incoming==p&&Type(m,packet)>Type(m,next))){previous=next;next=m.Word(next+0x5c);}else break;}
   m.Word(previous+0x5c,packet);m.Word(packet+0x58,previous);if(next!=0){m.Word(packet+0x5c,next);m.Word(next+0x58,packet);}
  }}
  // 0x6551d0: ascending stored binary32 time, ties/unordered comparisons insert before current node. Fresh cursor reloads and final store order retain aliases.
  public static void Timed(SoundSetupImage m,uint node,uint headPointer){unchecked{
   uint cursor=headPointer;if(m.Word(cursor)!=0)for(;;){uint current=m.Word(cursor);if(!(Time(m,current)<Time(m,node)))break;cursor=current+0x10;if(m.Word(cursor)==0)break;}
   uint old=m.Word(cursor);m.Word(node+0x10,old);m.Word(cursor,node);
  }}
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> fallback){if(address==0x5ffea0){Commands(m,args[0],unchecked((int)args[1]));return 0;}if(address==0x654e00){Priority(m,args[0],args[1]);return 0;}if(address==0x6551d0){Timed(m,args[0],args[1]);return 0;}return fallback(m,address,args);}
 }
}
