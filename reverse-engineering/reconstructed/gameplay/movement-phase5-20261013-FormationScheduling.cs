// Native0x51d130 uses ESI for formation. Callback args are recovered from pushes.
using System;
namespace Recovered.Gameplay
{
 public sealed class FormationScheduleWorld
 {
  public OriginPathMemory Memory;
  // code, formation, row, previous successfully processed row, current owner reference.
  public Func<uint,uint,uint,uint,uint,bool> Callback;
 }
 public static class FormationScheduling
 {
  public static void Dispatch(FormationScheduleWorld w,uint formation,uint callback)
  {
   OriginPathMemory m=w.Memory;uint previous=0;bool blocked=false;
   if(callback!=0&&(m.U32(formation+0x50)&8)!=0)
   {
    if(w.Callback==null)throw new InvalidOperationException("Formation row callback required.");
    bool reverse=(m.U32(formation+0x50)&4)!=0;
    if(reverse)
    {
     // Reverse bound is captured once; forward count below is reread each step.
     for(int index=m.U8(formation+6)-1;index>=0;index--)
     {
      uint row=formation+0x54+(uint)index*0x34;if(m.U8(row+0x2d)==0)continue;
      if(w.Callback(callback,formation,row,previous,m.U32(formation)))break;
      if((m.U8(row+0x30)&2)!=0)blocked=true;previous=row;
     }
    }
    else
    {
     for(int index=0;index<m.U8(formation+6);index++)
     {
      uint row=formation+0x54+(uint)index*0x34;if(m.U8(row+0x2d)==0)continue;
      if(w.Callback(callback,formation,row,previous,m.U32(formation)))break;
      if((m.U8(row+0x30)&2)!=0)blocked=true;previous=row;
     }
    }
   }
   uint flags=m.U32(formation+0x50);m.Set32(formation+0x50,(flags&~0x10u)|(blocked?0x10u:0));
  }
 }
}
