// Raw5b5430 refinement of the registered value projection. Finite prepared image domain; no duplicate address credit.
// Live REA ev_f38354640510002d99d11e38b917f3bb393f274bf46e6c66bd17f7f80454f587; original PE6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb.
using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlAffineRaw {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}

public static uint Dot(uint x,uint y,uint z,uint a,uint b,uint c,bool translate,uint t){N value=N.Add(N.Add(N.Mul(N.Word(x),N.Word(a)),N.Mul(N.Word(y),N.Word(b))),N.Mul(N.Word(z),N.Word(c)));if(translate)value=N.Add(value,N.Word(t));return value.Store();}public static uint Add32(uint a,uint b){return N.Add(N.Word(a),N.Word(b)).Store();}public static uint Multiply32(uint a,uint b){return N.Mul(N.Word(a),N.Word(b)).Store();}public static void Multiply(SoundSetupImage m,uint output,uint left,uint right){unchecked{bool temporary=output==left||output==right;uint[] values=temporary?new uint[16]:null;for(uint row=0;row<4;row++){for(uint col=0;col<3;col++){uint word=Dot(m.Word(left+row*16),m.Word(left+row*16+4),m.Word(left+row*16+8),m.Word(right+col*4),m.Word(right+col*4+16),m.Word(right+col*4+32),row==3,row==3?m.Word(right+col*4+48):0);if(temporary)values[row*4+col]=word;else m.Word(output+row*16+col*4,word);}uint end=row==3?0x3f800000u:0;if(temporary)values[row*4+3]=end;else m.Word(output+row*16+12,end);}if(temporary)for(uint i=0;i<16;i++)m.Word(output+i*4,values[i]);}}}}
