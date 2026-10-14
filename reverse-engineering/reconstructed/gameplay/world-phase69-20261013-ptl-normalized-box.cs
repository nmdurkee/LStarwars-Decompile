using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlNormalizedBox {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
static uint Reciprocal(uint bits){return (bits&0x7fffffff)==0?(bits&0x80000000)|0x7f800000:N.Divide(N.Integer(1),N.Word(bits)).Store();}public static void Prepare(SoundSetupImage m,uint size){if(m.Word(0x96e53c)==0)for(uint i=0;i<16;i++)m.Word(0x97acd0+i*4,m.Word(0x9736e8+i*4));uint[] input=new uint[]{m.Word(size),m.Word(size+4),m.Word(size+8)};N[,] product=new N[3,3];for(uint axis=0;axis<3;axis++)for(uint row=0;row<3;row++)product[axis,row]=N.Mul(N.Word(m.Word(0x97acd0+row*16+axis*4)),N.Word(input[row]));uint[] minimum=new uint[3],maximum=new uint[3];for(uint corner=0;corner<8;corner++){N x=N.Word(m.Word(0x80bfa8+corner*12)),y=N.Word(m.Word(0x80bfac+corner*12)),z=N.Word(m.Word(0x80bfb0+corner*12));for(uint axis=0;axis<3;axis++){N value=N.Add(N.Mul(x,product[axis,0]),N.Word(m.Word(0x97ad00+axis*4)));value=N.Add(value,N.Mul(y,product[axis,1]));value=N.Add(value,N.Mul(z,product[axis,2]));uint stored=value.Store();if(corner==0){minimum[axis]=stored;maximum[axis]=stored;}else {if(F(stored)<F(minimum[axis]))minimum[axis]=stored;if(F(stored)>F(maximum[axis]))maximum[axis]=stored;}}}m.Word(0x9715ac,input[2]);m.Word(0x9715a8,input[1]);m.Word(0x9715a4,input[0]);N half=N.Word(0x3f000000);for(uint axis=0;axis<3;axis++){N midpoint=N.Mul(N.Add(N.Word(maximum[axis]),N.Word(minimum[axis])),half),offset=N.Mul(N.Word(input[axis]),half);m.Word(0x96d9c4+axis*4,N.Sub(midpoint,offset).Store());}for(uint axis=0;axis<3;axis++)m.Word(0x971584+axis*4,Reciprocal(input[axis]));}}}
