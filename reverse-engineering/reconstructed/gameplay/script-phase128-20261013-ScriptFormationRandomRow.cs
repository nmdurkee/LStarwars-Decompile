// Complete random formation row51C6A0 and its full-word RNG5B9E30.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptFormationRandomRow
 {
  static float F(uint bits){float x=BitConverter.ToSingle(BitConverter.GetBytes(bits),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite formation widths required.");return x;}
  static int Angle(TakeoverReleaseMemory m,uint p){return unchecked((short)m.Read16(p));}
  public static uint Draw(TakeoverReleaseMemory m){uint seed=unchecked(m.Read32(0x95e5d4)*0x19660d+0x3c6ef35f);m.Write32(0x95e5d4,seed);return seed;}
  public static uint Execute(TakeoverReleaseMemory m,ScriptFormationStepServices step,uint formation,uint row,uint previous,uint owner)
  {
   uint edge=m.Read32(row+4);if(edge==0)return 0;byte end=m.Read8(edge+(m.Read8(row+8)==0?0x11u:0x10u));uint node=unchecked(m.Read32(m.Read32(row)+0x7c)+(uint)end*0x5c);
   if(m.Read32(row+0x28)==0)
   {
    if(previous!=0){uint value=m.Read32(previous+4);if(edge==value)value=m.Read32(previous+0x28);m.Write32(row+0x28,value);}
    else
    {
     uint capacity=m.Read8(node+0x28),random=Draw(m),start=random%capacity,index=0;
     for(;index<m.Read8(node+0x28);index++)
     {
      capacity=m.Read8(node+0x28);uint candidate=m.Read32(m.Read32(node+0x34)+((index+start)%capacity)*4);m.Write32(row+0x28,candidate);bool valid=false;
      if(candidate!=m.Read32(row+4))
      {
       byte category=m.Read8(m.Read32(owner+4)+0x13c);ulong bit=category<64?1UL<<category:0;
       if(category==255||((ulong)m.Read16(candidate+0x14)&bit)!=0||((ulong)m.Read16(node+0x5a)&bit)!=0)
       {
        bool reverse=m.Read8(candidate+0x10)!=end;byte opposite=m.Read8(candidate+(reverse?0x10u:0x11u));uint targetNode=unchecked(m.Read32(m.Read32(row)+0x7c)+(uint)opposite*0x5c);
        valid=F(m.Read32(formation+0x124))<F(m.Read32(targetNode+0x10))&&m.Read32(candidate+(reverse?4u:0u))==0;
       }
      }
      if(valid)break;m.Write32(row+0x28,0);
     }
     if(m.Read32(row+0x28)==0)m.Write32(row+0x28,m.Read32(row+4));
    }
    uint next=m.Read32(row+0x28);if(next!=0&&m.Read32(next+(m.Read8(next+0x10)!=end?4u:0u))==0)
    {
     int a=Angle(m,m.Read32(row+4)+0x12);if(m.Read8(row+8)!=0)a=PathCornerMath.AddAngles(0x8000,a);byte current=m.Read8(m.Read32(row+4)+(m.Read8(row+8)==0?0x11u:0x10u));int b=Angle(m,next+0x12);if(current==m.Read8(next+0x10))m.Write8(row+0x2c,0);else{m.Write8(row+0x2c,1);b=PathCornerMath.AddAngles(0x8000,b);}int difference=PathCornerMath.DifferenceAngles(b,a);m.Write32(row+0x30,difference<0?m.Read32(row+0x30)|1:m.Read32(row+0x30)&0xfffffffe);
    }
    if(m.Read32(row+0x28)==0)return 0;
   }
   return PreparedScriptFormationFollowRow.Continue(m,step,formation,row,owner);
  }
 }
}
