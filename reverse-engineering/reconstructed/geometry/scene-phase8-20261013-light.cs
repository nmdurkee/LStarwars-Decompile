// Finite original PC camera/light orientation producer through raw cache packing.
using System;
using Recovered.Animation;
using Recovered.Gameplay;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class LightNumericGlobals
 {
  public uint[] DirectionWords,ColorWords,IdentityWords;
  public float[] Aim;
 }
 public static class LightNumericProduction
 {
  static bool Negative(float v){return(PcObjectImage.ToBits(v)&0x80000000u)!=0;}
  static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
  static float Store(W v,bool negativeZero){float result=v.Store();NativeFrustum.Finite(result);return result==0&&negativeZero?PcObjectImage.FromBits(0x80000000u):result;}
  static W Sub(W a,W b){return W.Add(a,W.Multiply(b,W.From(-1)));}
  static float Product(float a,float b){return Store(W.Multiply(W.From(a),W.From(b)),Negative(a)!=Negative(b));}
  static float Divide(float a,float b){return Store(W.Divide(W.From(a),W.From(b)),Negative(a)!=Negative(b));}
  static float[] Floats(uint[] words,int length){if(words==null||words.Length!=length)throw new ArgumentException("Resolved raw numeric words required.");float[] result=new float[length];for(int i=0;i<length;++i){result[i]=PcObjectImage.FromBits(words[i]);NativeFrustum.Finite(result[i]);}return result;}
  static W DotWide(float[] a,float[] b,bool yFirst)
  {int first=yFirst?1:0,second=yFirst?0:1;return W.Add(W.Add(W.Multiply(W.From(a[first]),W.From(b[first])),W.Multiply(W.From(a[second]),W.From(b[second]))),W.Multiply(W.From(a[2]),W.From(b[2])));}
  static float Dot(float[] a,float[] b,bool yFirst)
  {bool allZero=true,allNegative=true;for(int i=0;i<3;++i){allZero=allZero&&(a[i]==0||b[i]==0);allNegative=allNegative&&(Negative(a[i])!=Negative(b[i]));}return Store(DotWide(a,b,yFirst),allZero&&allNegative);}
  static float[] Normalize(float[] vector)
  {float length=BuildEffectSound.SquareRoot(Dot(vector,vector,true)),reciprocal=length>0?Divide(1,length):0;return new[]{Product(reciprocal,vector[0]),Product(reciprocal,vector[1]),Product(reciprocal,vector[2])};}
  static float Blend(float basis,float remaining,float direction,float weight)
  {bool zeros=(basis==0||remaining==0)&&(direction==0||weight==0),negative=(Negative(basis)!=Negative(remaining))&&(Negative(direction)!=Negative(weight));return Store(W.Add(W.Multiply(W.From(basis),W.From(remaining)),W.Multiply(W.From(direction),W.From(weight))),zeros&&negative);}
  // Original 0x5ff840. Optional prefix copies are integer words; only the
  // consumed direction/template/aim/camera numeric domain is finite.
  public static LightRenderInputs Produce(LightNumericGlobals globals,float[] camera,uint[] optionalDirection,uint[] optionalColor)
  {
   if(globals==null||camera==null||camera.Length!=30||globals.DirectionWords==null||globals.DirectionWords.Length!=3||globals.ColorWords==null||globals.ColorWords.Length!=4||globals.Aim==null||globals.Aim.Length!=3)throw new ArgumentException("Resolved light globals and camera required.");foreach(float value in camera)NativeFrustum.Finite(value);foreach(float value in globals.Aim)NativeFrustum.Finite(value);
   if(optionalDirection!=null){if(optionalDirection.Length!=3)throw new ArgumentException("Three direction words required.");globals.DirectionWords=(uint[])optionalDirection.Clone();}if(optionalColor!=null){if(optionalColor.Length!=4)throw new ArgumentException("Four color words required.");globals.ColorWords=(uint[])optionalColor.Clone();}float[] direction=Floats(globals.DirectionWords,3),matrix=Floats(globals.IdentityWords,16),inverse=new float[3];
   for(int axis=0;axis<3;++axis)inverse[axis]=Dot(direction,new[]{camera[axis*4],camera[axis*4+1],camera[axis*4+2]},axis==0);float[] lerp=new float[3];for(int i=0;i<3;++i)lerp[i]=Store(W.Add(W.Multiply(Sub(W.From(inverse[i]),W.From(globals.Aim[i])),W.From(.5f)),W.From(globals.Aim[i])),false);float[] transformed=new float[3];for(int axis=0;axis<3;++axis)transformed[axis]=Dot(lerp,new[]{camera[axis],camera[axis+4],camera[axis+8]},axis==0);float[] t=Normalize(transformed),world=Normalize(direction);float factor=Dot(new[]{Neg(camera[8]),Neg(camera[9]),Neg(camera[10])},world,true),horizontal=BuildEffectSound.SquareRoot(Store(W.Add(W.Multiply(W.From(t[0]),W.From(t[0])),W.Multiply(W.From(t[2]),W.From(t[2]))),false));float x=t[0],y=t[1],z=t[2];
   if(horizontal>PcObjectImage.FromBits(0x00800000u)){matrix[0]=Divide(z,horizontal);matrix[1]=0;matrix[2]=Divide(x,horizontal);matrix[4]=Store(W.Divide(W.Multiply(W.From(x),W.From(y)),W.From(horizontal)),Negative(x)!=Negative(y));matrix[5]=horizontal;matrix[6]=Store(W.Divide(W.Multiply(W.From(Neg(y)),W.From(z)),W.From(horizontal)),Negative(Neg(y))!=Negative(z));matrix[8]=Neg(x);matrix[9]=y;matrix[10]=z;}
   else{matrix[10]=matrix[5]=0;matrix[9]=y;matrix[6]=Neg(y);}matrix[12]=matrix[13]=.5f;
   if(factor<0){float weight=factor;for(int i=0;i<5;++i)weight=Product(weight,weight);float remaining=Store(Sub(W.From(1),W.From(weight)),false);for(int column=0;column<2;++column){float[] basis={matrix[column],matrix[column+4],matrix[column+8]};bool positive=DotWide(basis,world,true).StoreDouble()>=0;for(int row=0;row<3;++row)matrix[column+row*4]=Blend(basis[row],remaining,positive?world[row]:Neg(world[row]),weight);}}
   uint[] matrixWords=new uint[16],vectorWords=new uint[3],colorWords=new uint[3];for(int i=0;i<16;++i)matrixWords[i]=PcObjectImage.ToBits(matrix[i]);for(int i=0;i<3;++i){vectorWords[i]=PcObjectImage.ToBits(Neg(inverse[i]));colorWords[i]=globals.ColorWords[i];}return new LightRenderInputs{MatrixWords=matrixWords,VectorWords=vectorWords,ColorWords=colorWords};
  }
  public static int Apply(CameraRenderCache sharedCounter,LightRenderCache cache,LightNumericGlobals globals,float[] camera,uint[] optionalDirection,uint[] optionalColor)
  {return LightRenderCacheProduction.Update(sharedCounter,cache,Produce(globals,camera,optionalDirection,optionalColor));}
  // Camera 0x5ed540 passes both optional source pointers as null.
  public static Action<CameraPlaneState> CameraCallback(CameraRenderCache sharedCounter,LightRenderCache cache,LightNumericGlobals globals)
  {return delegate(CameraPlaneState camera){if(camera==null)throw new ArgumentNullException("camera");Apply(sharedCounter,cache,globals,camera.Current,null,null);};}
 }
}
