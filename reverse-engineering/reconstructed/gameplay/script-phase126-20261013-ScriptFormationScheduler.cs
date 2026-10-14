// Raw scheduler51D130 refinement and FollowPlayer composition. Native formation argument is implicit ESI.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptFormationRowServices{public abstract uint Row(TakeoverReleaseMemory m,uint callback,uint formation,uint row,uint previous,uint ownerReference);}
 public static class PreparedScriptFormationScheduler
 {
  public static void Dispatch(TakeoverReleaseMemory m,ScriptFormationRowServices services,uint formation,uint callback)
  {
   uint previous=0;bool blocked=false;
   if(callback!=0&&(m.Read32(formation+0x50)&8)!=0)
   {
    bool reverse=(m.Read32(formation+0x50)&4)!=0;
    if(reverse){for(int index=m.Read8(formation+6)-1;index>=0;index--){uint row=unchecked(formation+0x54+(uint)index*0x34);if(m.Read8(row+0x2d)==0)continue;if(services.Row(m,callback,formation,row,previous,m.Read32(formation))!=0)break;if((m.Read8(row+0x30)&2)!=0)blocked=true;previous=row;}}
    else{for(uint index=0;index<m.Read8(formation+6);index++){uint row=unchecked(formation+0x54+index*0x34);if(m.Read8(row+0x2d)==0)continue;if(services.Row(m,callback,formation,row,previous,m.Read32(formation))!=0)break;if((m.Read8(row+0x30)&2)!=0)blocked=true;previous=row;}}
   }
   uint flags=m.Read32(formation+0x50);m.Write32(formation+0x50,(flags&~0x10u)|(blocked?0x10u:0));
  }
 }
 public sealed class RecoveredScriptFollowScheduler:ScriptFollowServices
 {
  readonly ScriptFormationRowServices rows;readonly Func<TakeoverReleaseMemory,uint> formation;
  // Resolver supplies the captured ESI formation at each Schedule entry, before any row callback mutation.
  public RecoveredScriptFollowScheduler(ScriptFormationRowServices callbacks,Func<TakeoverReleaseMemory,uint> implicitFormation){if(implicitFormation==null)throw new ArgumentNullException("implicitFormation");rows=callbacks;formation=implicitFormation;}
  public override void Schedule(TakeoverReleaseMemory m,uint callback){PreparedScriptFormationScheduler.Dispatch(m,rows,formation(m),callback);}
 }
}
