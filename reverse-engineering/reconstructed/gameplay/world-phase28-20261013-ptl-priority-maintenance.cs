using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlPacketPriorityMaintenance {
  const uint Heads=0x292fd30,RepairCursor=0x29620bc,UpdateCursor=0x29620c0;
  static uint Head(int bank){return unchecked(Heads+(uint)bank*4);}
  static int Type(SoundSetupImage m,uint node){return (sbyte)m.Byte(unchecked(m.Word(node+4)+0x2e));}
  static int Choose(SoundSetupImage m,uint cursor){unchecked{int bank=(int)m.Word(cursor),start=bank;if(m.Word(Head(bank))==0){do{bank++;if(bank>=5)bank=0;if(bank==start)break;}while(m.Word(Head(bank))==0);m.Word(cursor,(uint)bank);}return bank;}}
  // 0x654ef0: six-call countdown; picks a nonempty bank only when current bank is empty.
  // Repairs the first adjacent inversion by actual removal and priority reinsertion, then returns.
  public static void Repair(SoundSetupImage m){unchecked{
   int left=(int)(m.Word(0x810960)-1);m.Word(0x810960,(uint)left);if(left>0)return;m.Word(0x810960,6);int bank=Choose(m,RepairCursor);uint head=Head(bank),current=m.Word(head);
   while(current!=0){uint next=m.Word(current+0x5c);if(next==0)return;ushort a=m.Half(current+0x60),b=m.Half(next+0x60);if(a<b||(a==b&&Type(m,current)>Type(m,next))){PtlParticleUnlinks.Priority(m,next,head);PtlParticleLinks.Priority(m,next,head);return;}current=next;}
  }}
  static ushort DistancePriority(ushort size,uint distanceWord){
   float distance=BitConverter.ToSingle(BitConverter.GetBytes(distanceWord),0);if(float.IsNaN(distance)||float.IsNegativeInfinity(distance))return 0;if(float.IsPositiveInfinity(distance))return 0xffff;
   PlaybackWide v=PlaybackWide.Add(PlaybackWide.FromDouble(size),PlaybackWide.Multiply(PlaybackWide.From(distance),PlaybackWide.FromDouble(25)));float stored=v.Store();if(stored>65535)stored=65535;
   double value=stored;if(double.IsNaN(value)||double.IsInfinity(value)||value<int.MinValue||value>int.MaxValue)return 0;return unchecked((ushort)(int)value);
  }
  // 0x654fa0: update cursor is independently selected, but original traversal uses RepairCursor.
  // Active emitter contributes stored float(size+25*distance), upper-clamped65535 then
  // FISTP signed32 truncation; invalid conversion low16 is zero. Owner-zero snapshots keep prior priority.
  public static void Recompute(SoundSetupImage m){unchecked{
   int left=(int)(m.Word(0x810964)-1);m.Word(0x810964,(uint)left);if(left>0)return;m.Word(0x810964,6);int selected=Choose(m,UpdateCursor);if(m.Word(Head(selected))==0)return;
   uint node=m.Word(Head((int)m.Word(RepairCursor)));while(node!=0){uint owner=m.Word(node+8);if(owner!=0){ushort size=m.Half(owner+0x328);ushort priority=m.Byte(owner+0x2f8)==0?size:DistancePriority(size,m.Word(owner+0x31c));m.Half(node+0x60,priority);}node=m.Word(node+0x5c);}
  }}
 }
}
