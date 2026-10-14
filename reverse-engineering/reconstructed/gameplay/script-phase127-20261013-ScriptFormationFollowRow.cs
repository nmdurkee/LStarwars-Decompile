// Actual registered game-origin callback43c3a0, with finite x87 stores and live cache flags.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptFormationFollowRow
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite prepared origin arithmetic required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Product(float a,float b){if(a==0||b==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Products(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();}

  static int Angle(TakeoverReleaseMemory m,uint p){return unchecked((short)m.Read16(p));}
  static int Turn(int value,int cap){if(value>cap)return cap;if(value< -cap)return -cap;return value;}
  static float Difference(float a,float b){if(a==0&&b==0)return F(B(a)&(B(b)^0x80000000)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();}
  static float[] Rotate(TakeoverReleaseMemory m,float[] vector,int heading){float sine=F(m.Read32(0x29899a0+((uint)(heading>>1)&0x7fff)*4)),cosine=F(m.Read32(0x29899a0+((uint)(unchecked(heading+0x4000)>>1)&0x7fff)*4));return new float[]{Products(sine,vector[2],cosine,vector[0]),vector[1],Products(cosine,vector[2],F(B(sine)^0x80000000),vector[0])};}
  static float[] Add(TakeoverReleaseMemory m,float[] vector,uint position){return new float[]{Sum(vector[0],F(m.Read32(position))),Sum(vector[1],F(m.Read32(position+4))),Sum(vector[2],F(m.Read32(position+8)))};}
  static float SquaredXZ(TakeoverReleaseMemory m,uint first,uint second){float x=Difference(F(m.Read32(first)),F(m.Read32(second))),z=Difference(F(m.Read32(first+8)),F(m.Read32(second+8)));return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(x)),PlaybackWide.From(0)),PlaybackWide.Multiply(PlaybackWide.From(z),PlaybackWide.From(z))).Store();}
  sealed class Local:TakeoverReleaseMemory{readonly TakeoverReleaseMemory parent;readonly byte[] bytes=new byte[12];const uint Base=0xfff00000;public Local(TakeoverReleaseMemory p,float[] vector){parent=p;for(int i=0;i<3;i++){uint bits=B(vector[i]);for(int j=0;j<4;j++)bytes[i*4+j]=(byte)(bits>>(j*8));}}public override byte Read8(uint p){return p>=Base&&p<Base+12?bytes[p-Base]:parent.Read8(p);}public override void Write8(uint p,byte value){if(p>=Base&&p<Base+12)bytes[p-Base]=value;else parent.Write8(p,value);}public uint Address{get{return Base;}}}
  static float Line(TakeoverReleaseMemory m,uint first,uint second,float[] point){var local=new Local(m,point);return F(PreparedScriptLine.WithoutProjection(local,first,second,local.Address));}
  public static uint Nudge(TakeoverReleaseMemory m,ScriptFormationStepServices step,uint formation,uint row,uint owner)
  {
   uint edge=m.Read32(row+4);int desired=Angle(m,edge+0x12);if(m.Read8(row+8)!=0)desired=PathCornerMath.AddAngles(desired,0x8000);int heading=unchecked((int)m.Read32(row+0x24));int turn=Turn(PathCornerMath.DifferenceAngles(desired,heading),Angle(m,formation+4));m.Write32(row+0x24,unchecked((uint)PathCornerMath.AddAngles(turn,heading)));
   float distance=0;uint callback=m.Read32(0x9238c4);if(callback!=0)distance=F(step.Step(m,callback,owner));float[] delta=Rotate(m,new float[]{0,0,distance},unchecked((int)m.Read32(row+0x24)));for(uint i=0;i<3;i++)m.Write32(row+0x18+i*4,B(Sum(F(m.Read32(row+0x18+i*4)),delta[i])));m.Write32(row+0x1c,m.Read32(owner+0x60));return 0;
  }
  static uint Reverse(TakeoverReleaseMemory m,uint formation)
  {
   for(uint i=0;i<m.Read8(formation+6);i++){uint row=formation+0x54+i*0x34;m.Write32(row+0x28,0);m.Write32(row+0x24,unchecked((uint)PathCornerMath.AddAngles(unchecked((int)m.Read32(row+0x24)),0x8000)));m.Write8(row+8,(byte)(m.Read8(row+8)==0?1:0));}
   m.Write32(formation+0x50,m.Read32(formation+0x50)^4);m.Write32(formation,0);
   if((m.Read32(formation+0x50)&4)!=0){for(int i=m.Read8(formation+7)-1;i>=0;i--){uint entry=m.Read32(formation+0xc+(uint)i*4);if(entry!=0&&(m.Read32(entry+0x1fc)&0x1001)==0x1001&&m.Read8(entry+0x28b)==0){m.Write32(formation,m.Read32(formation+0xc+(uint)i*4));return 1;}}}
   else{for(uint i=0;i<m.Read8(formation+7);i++){uint entry=m.Read32(formation+0xc+i*4);if(m.Read32(entry)!=0&&(m.Read32(entry+0x1fc)&0x1001)==0x1001&&m.Read8(entry+0x28b)==0){m.Write32(formation,m.Read32(formation+0xc+i*4));return 1;}}}
   return 1;
  }
  // Shared own-body tail of51CBC0/51C6A0; no separate address credit.
  public static uint Continue(TakeoverReleaseMemory m,ScriptFormationStepServices step,uint formation,uint row,uint owner)
  {
   float lateral=F(m.Read32(formation+0x124));if((m.Read8(row+0x30)&1)!=0)lateral=F(B(lateral)^0x80000000);float[] side=new float[]{lateral,0,0};float[] probe=Add(m,Rotate(m,side,unchecked((int)m.Read32(row+0x24))),row+0x18);
   if((m.Read8(row+0x30)&2)==0)
   {
    uint next=m.Read32(row+0x28),edge=m.Read32(row+4),path=m.Read32(row);
    if(next==edge){byte end=m.Read8(edge+(m.Read8(row+8)==0?0x11u:0x10u));uint node=m.Read32(path+0x7c)+(uint)end*0x5c;if(SquaredXZ(m,row+0x18,node+4)<F(m.Read32(node+0x14)))return Reverse(m,formation);}
    else{uint nodes=m.Read32(path+0x7c);float distance=Line(m,nodes+(uint)m.Read8(next+0x10)*0x5c+4,nodes+(uint)m.Read8(next+0x11)*0x5c+4,probe);float width=F(m.Read32(formation+0x124));if((double)distance<=(double)width*width)m.Write32(row+0x30,m.Read32(row+0x30)|2);}
    if((m.Read8(row+0x30)&2)==0){if((m.Read8(formation+0x50)&0x10)!=0)return 0;return Nudge(m,step,formation,row,owner);}
   }
   int desired=Angle(m,m.Read32(row+0x28)+0x12);if(m.Read8(row+0x2c)!=0)desired=PathCornerMath.AddAngles(desired,0x8000);int old=unchecked((int)m.Read32(row+0x24)),difference=PathCornerMath.DifferenceAngles(desired,old),cap=Angle(m,formation+4),turn=Turn(difference,cap);
   if(difference<=cap&&difference>= -cap){m.Write32(row+0x30,m.Read32(row+0x30)&0xfffffffd);m.Write32(row+4,m.Read32(row+0x28));m.Write8(row+8,m.Read8(row+0x2c));m.Write32(row+0x28,0);turn=difference;}
   int heading=PathCornerMath.AddAngles(turn,old);m.Write32(row+0x24,unchecked((uint)heading));float[] delta=Rotate(m,side,heading);for(uint i=0;i<3;i++)m.Write32(row+0x18+i*4,B(Difference(probe[i],delta[i])));return 0;
  }
  public static uint Execute(TakeoverReleaseMemory m,ScriptFormationStepServices step,uint formation,uint row,uint previous,uint owner)
  {
   uint edge=m.Read32(row+4);if(edge==0)return 0;byte end=m.Read8(edge+(m.Read8(row+8)==0?0x11u:0x10u)),wanted=end;
   if(m.Read32(row+0x28)==0)
   {
    if(previous!=0){uint value=m.Read32(previous+4);if(m.Read32(row+4)==value)value=m.Read32(previous+0x28);m.Write32(row+0x28,value);}
    else{uint reference=m.Read32(formation);if(reference!=0){uint actor=m.Read32(reference+4),path=m.Read32(row);if(m.Read32(actor+0x84)==path){uint actorEdge=m.Read32(actor+0x88);wanted=m.Read8(actorEdge+(F(m.Read32(actor+0x94))<=.5f?0x10u:0x11u));uint neighbors=m.Read32(m.Read32(path+0x84)+(uint)end*4);byte selection=m.Read8(neighbors+wanted);if(selection!=255){uint table=m.Read32(m.Read32(path+0x7c)+(uint)end*0x5c+0x34),candidate=m.Read32(table+(uint)selection*4);m.Write32(row+0x28,candidate);if(m.Read32(candidate+(m.Read8(candidate+0x10)!=end?4u:0u))!=0)m.Write32(row+0x28,0);}}}}
    uint next=m.Read32(row+0x28);if(next!=0&&m.Read32(next+(m.Read8(next+0x10)!=wanted?4u:0u))==0){int a=Angle(m,m.Read32(row+4)+0x12);if(m.Read8(row+8)!=0)a=PathCornerMath.AddAngles(0x8000,a);byte current=m.Read8(m.Read32(row+4)+(m.Read8(row+8)==0?0x11u:0x10u));int b=Angle(m,next+0x12);if(current==m.Read8(next+0x10))m.Write8(row+0x2c,0);else{m.Write8(row+0x2c,1);b=PathCornerMath.AddAngles(0x8000,b);}int turn=PathCornerMath.DifferenceAngles(b,a);m.Write32(row+0x30,turn<0?m.Read32(row+0x30)|1:m.Read32(row+0x30)&0xfffffffe);}
    if(m.Read32(row+0x28)==0){float progress=F(m.Read32(row+0x10));if(m.Read8(row+8)==0?progress>1:progress<0)return 1;return Nudge(m,step,formation,row,owner);}
   }
   return Continue(m,step,formation,row,owner);
  }
 }
 public abstract class ScriptFormationStepServices{public abstract uint Step(TakeoverReleaseMemory m,uint callback,uint ownerReference);}
}
