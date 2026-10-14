using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlParticleMath {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide value,bool sign){v=value;double d=value.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  // 5b3830: cached scalar, ordered component stores with fresh source reads.
  public static void Scale(SoundSetupImage m,uint destination,uint source,uint scale){N s=N.Word(scale);for(uint i=0;i<3;i++)m.Word(destination+i*4,N.Mul(N.Word(m.Word(source+i*4)),s).Store());}
  // Private-stack value refinement used by original callers; no separate entry credit.
  public static uint[] ScaleWords(SoundSetupImage m,uint source,uint scale){N s=N.Word(scale);uint[] a=new uint[3];for(uint i=0;i<3;i++)a[i]=N.Mul(N.Word(m.Word(source+i*4)),s).Store();return a;}
  static N Product(SoundSetupImage m,uint a,uint word){return N.Mul(N.Word(m.Word(a)),N.Word(word));}
  public static uint[] TransformWords(SoundSetupImage m,uint[] point,uint matrix){uint[] result=new uint[3];for(uint axis=1;axis<3;axis++){N sum=N.Add(Product(m,matrix+axis*4,point[0]),Product(m,matrix+16+axis*4,point[1]));sum=N.Add(sum,Product(m,matrix+32+axis*4,point[2]));result[axis]=N.Add(sum,N.Word(m.Word(matrix+48+axis*4))).Store();}N x=N.Add(Product(m,matrix+16,point[1]),Product(m,matrix,point[0]));x=N.Add(x,Product(m,matrix+32,point[2]));result[0]=N.Add(x,N.Word(m.Word(matrix+48))).Store();return result;}
  // 5c11d0: compute and spill Y/Z first, compute X, then commit X/Y/Z; sources may overlap output.
  public static void Transform(SoundSetupImage m,uint destination,uint source,uint matrix){uint[] result=TransformWords(m,new uint[]{m.Word(source),m.Word(source+4),m.Word(source+8)},matrix);for(uint i=0;i<3;i++)m.Word(destination+i*4,result[i]);}
 }
}
