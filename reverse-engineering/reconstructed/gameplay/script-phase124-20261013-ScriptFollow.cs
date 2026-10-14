// Actual registered game-origin callback43c3a0, with finite x87 stores and live cache flags.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptFollow
 {
  static float F(uint v){float x=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite prepared origin arithmetic required.");return x;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static float Product(float a,float b){if(a==0||b==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Sum(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Products(float a,float b,float c,float d){if((a==0||b==0)&&(c==0||d==0))return F((B(a)^B(b))&(B(c)^B(d))&0x80000000);return PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();}

  static float[] Rotate(TakeoverReleaseMemory m,float x,float y,float z,int heading){uint si=(uint)(heading>>1)&0x7fff,ci=(uint)(unchecked(heading+0x4000)>>1)&0x7fff;float sine=F(m.Read32(0x29899a0+si*4)),cosine=F(m.Read32(0x29899a0+ci*4));return new float[]{Products(sine,z,cosine,x),y,Products(cosine,z,F(B(sine)^0x80000000),x)};}
  static float[] Add(TakeoverReleaseMemory m,float[] value,uint source){return new float[]{Sum(value[0],F(m.Read32(source))),Sum(value[1],F(m.Read32(source+4))),Sum(value[2],F(m.Read32(source+8)))};}
  public static void Formation(TakeoverReleaseMemory m,uint actor)
  {
   uint formation=m.Read32(actor+0x144);byte rowIndex=m.Read8(actor+0x14a);if(m.Read8(formation+6)<=rowIndex)return;uint row=unchecked(formation+0x54+(uint)rowIndex*0x34);float x;
   if((m.Read8(actor+0x1eb)&1)!=0)x=(m.Read8(formation+8)&1)!=0?0:F(B(Product(F(m.Read32(formation+0x128)),.5f))^0x80000000);
   else{byte column=m.Read8(actor+0x149);x=Product(F(m.Read32(formation+0x128)),(column+1)/2);if((column&1)!=0)x=F(B(x)^0x80000000);}
   if((m.Read8(formation+0x50)&4)!=0)x=F(B(x)^0x80000000);
   float[] position=Add(m,Rotate(m,x,0,0,unchecked((int)m.Read32(row+0x24))),row+0x18);
   m.Write32(actor+0x1e8,m.Read32(actor+0x1e8)|8);uint current=m.Read32(actor+0x144),mode=current!=0&&(m.Read8(current+0x50)&8)!=0?1u:5u;
   for(uint i=0;i<3;i++)m.Write32(actor+0x1b4+i*4,B(position[i]));for(uint i=0;i<5;i++)m.Write32(actor+0x1cc+i*4,m.Read32(row+i*4));uint sixth=m.Read32(row+20);
   m.Write32(actor+0x1c0,0);m.Write32(actor+0x1e0,sixth);m.Write32(actor+0x1c4,0);m.Write32(actor+0x78,0);m.Write32(actor+0x7c,0);m.Write32(actor+0x80,0x42c80000);m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&~7u)|mode);
   float[] facing=Rotate(m,F(m.Read32(actor+0x78)),F(m.Read32(actor+0x7c)),F(m.Read32(actor+0x80)),unchecked((int)m.Read32(row+0x24)));for(uint i=0;i<3;i++)m.Write32(actor+0x78+i*4,B(facing[i]));for(uint i=0;i<3;i++)m.Write32(actor+0x78+i*4,B(Sum(F(m.Read32(actor+0x78+i*4)),F(m.Read32(row+0x18+i*4)))));m.Write32(actor+0x1e4,actor+0x78);
  }
  public static void SetIntent(TakeoverReleaseMemory m,ScriptFollowServices services,uint actor,uint point,uint radius,uint words,uint mode,uint goal)
  {
   uint formation=m.Read32(actor+0x144);if(formation!=0&&(m.Read8(formation+0x50)&8)!=0){if(mode==1||mode==4){if(m.Read32(formation)==m.Read32(actor+0xd0))services.Schedule(m,mode==1?0x51cbc0u:0x51c6a0u);Formation(m,actor);return;}if(mode==5)mode=1;}
   if(point!=0)for(uint i=0;i<3;i++)m.Write32(actor+0x1b4+i*4,m.Read32(point+i*4));if(words!=0)for(uint i=0;i<6;i++)m.Write32(actor+0x1cc+i*4,m.Read32(words+i*4));m.Write32(actor+0x1c0,B(F(radius)));m.Write32(actor+0x1e8,(m.Read32(actor+0x1e8)&~7u)|(mode&7));m.Write32(actor+0x1c4,B(F(goal)));
  }
  public static void Intent(TakeoverReleaseMemory m,ScriptFollowServices services,uint actorReference,uint targetReference,uint flags,uint goal)
  {
   uint target,point,mode=1;
   if((flags&1)==0){target=m.Read32(targetReference+4);point=target+0x170;}
   else
   {
    uint actor=m.Read32(actorReference+4),path=m.Read32(actor+0x158);target=m.Read32(targetReference+4);bool off=path==0||path!=m.Read32(target+0x158);
    if(!off)
    {
     uint from=m.Read32(actor+0x15c),to=m.Read32(target+0x15c);off=(m.Read8(target+0x166)&1)==0&&from==to||from==0||to==0||(m.Read32(actor+0x1e8)&0x100000)!=0;
     if(!off){byte destination=m.Read8(to+0x10),start=m.Read8(from+0x10);uint table=m.Read32(path+0x84),next=m.Read32(table+(uint)start*4);off=m.Read8(next+destination)==255&&start!=destination;}
    }
    mode=off?7u:1u;point=target+(off?0x14cu:0x170u);
   }
   uint radius=(flags&2)!=0?0:B(F(m.Read32(target+0x120)));SetIntent(m,services,m.Read32(actorReference+4),point,radius,target+0x158,mode,B(F(goal)));
  }
  public static uint Player(TakeoverReleaseMemory m,ScriptFollowServices services,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint system,uint packet,uint actor,uint args,int count,uint first)
  {
   if(actor==0)return 1;if(first!=0)for(int index=0;index<count;index++){uint i=(uint)index,callback=m.Read32(0x9238b0);if(callback!=0&&tokens.Token(m,callback,m.Read32(args+i*4),actor+0x13f)!=0)continue;if(PreparedScriptByteLookup.Equal(m,m.Read32(args+i*4),0x758218))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|2));else if(PreparedScriptByteLookup.Equal(m,m.Read32(args+i*4),0x758208))m.Write8(packet+0x68,(byte)(m.Read8(packet+0x68)|1));else m.Write32(actor+0x180,PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,m.Read32(args+i*4)));}
   uint target=m.Read32(system+0x138c);if(target!=0&&m.Read32(target+4)!=0)Intent(m,services,m.Read32(actor+0xd0),target,m.Read8(packet+0x68),m.Read32(actor+0x180));return 0;
  }
 }
 public abstract class ScriptFollowServices{public abstract void Schedule(TakeoverReleaseMemory m,uint callback);}
}
