// Complete GoToNodeRandom536190. RNG count product stays exact until native integer truncation.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptRandomNode
 {
  // Null names still traverse live rows; original4F8B10 returns unequal without dereferencing a null query.
  public static uint Find(TakeoverReleaseMemory m,uint system,uint path,uint name)
  {
   if(name!=0)return PreparedScriptPathLookup.Find(m,system,path,name);
   if(path==0){if(system==0)return 0;uint r=m.Read32(system+0x10);if(r==0||m.Read8(r)==0)return 0;path=m.Read32(r+8);if(path==0)return 0;}
   if(m.Read8(path+0x10)==0)return 0;for(uint i=0,offset=0;;i++,offset+=0x5c){m.Read32(m.Read32(path+0x7c)+offset);if(i+1>=m.Read8(path+0x10))return 0;}
  }
  public static uint Execute(TakeoverReleaseMemory m,ScriptFollowServices intent,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first)
  {
   if(actor==0||m.Read32(actor+0xd0)==0||m.Read32(actor+0x158)==0||m.Read32(actor+0x15c)==0)return 1;
   if(first==0)return PreparedScriptNodeActions.Go(m,intent,tokens,symbols,system,packet,actor,args,count,0);
   if(count==0)return 0;uint seed=PreparedScriptFormationRandomRow.Draw(m);int choice=(int)(((long)(seed&0x7fffff)*count)/8388608L);if(choice>=count)choice=unchecked(count-1);
   uint name=m.Read32(unchecked(args+(uint)choice*4)),node=Find(m,system,m.Read32(actor+0x158),name);m.Write32(packet+0x6c,node);if(node==0||m.Read8(node+0x28)==0)return 1;
   uint path=m.Read32(actor+0x158);int index=unchecked((int)(node-m.Read32(path+0x7c)))/0x5c;m.Write32(packet+0x84,path);uint edge=m.Read32(m.Read32(node+0x34));m.Write32(packet+0x88,edge);m.Write32(packet+0x94,m.Read8(edge+0x10)==index?0u:0x3f800000);m.Write16(packet+0x92,(ushort)(m.Read16(packet+0x92)|1));m.Write32(packet+0x98,0);m.Write8(packet+0x8c,0);PreparedScriptFollow.SetIntent(m,intent,actor,node+4,0,packet+0x84,1,m.Read32(actor+0x180));return 0;
  }
 }
}
