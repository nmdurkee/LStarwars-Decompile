// Original display-mode CPU selection/mutation and finite aspect classifier.
using System;
using W=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
 public sealed class AspectClassificationResult
 {
  public readonly uint Mode,WidthStackWord,HeightStackWord;
  public AspectClassificationResult(uint mode,float best,float last){Mode=mode;WidthStackWord=BitConverter.ToUInt32(BitConverter.GetBytes(best),0);HeightStackWord=BitConverter.ToUInt32(BitConverter.GetBytes(last),0);}
 }
 public static class DisplayModeCpuSelection
 {
  static uint Read(byte[] b,int offset){if(b==null||offset<0||offset>b.Length-4)throw new ArgumentException("Resolved backend/mode-table bytes required.");return(uint)b[offset]|(uint)b[offset+1]<<8|(uint)b[offset+2]<<16|(uint)b[offset+3]<<24;}
  static int Signed(byte[] b,int offset){return unchecked((int)Read(b,offset));}
  static void Write(byte[] b,int offset,int value){uint word=unchecked((uint)value);b[offset]=(byte)word;b[offset+1]=(byte)(word>>8);b[offset+2]=(byte)(word>>16);b[offset+3]=(byte)(word>>24);}
  static int Distance(int candidate,int requested){int delta=unchecked(candidate-requested),sign=delta>>31;return unchecked((delta^sign)-sign);}
  // Original0x6e1b70. The pointer at backend61c is resolved as a stable,
  // disjoint mode image. Count618 is captured once. Record stride is16 bytes.
  // Signed wrapping distances,10000 sentinels and latest equal ties are exact.
  public static uint Select(byte[] backend,byte[] modes,int width,int height,int refresh)
  {
   uint rawCount=Read(backend,0x618);if(modes==null||Object.ReferenceEquals(backend,modes)||rawCount>(uint)(modes.Length/16)||backend.Length<=0x65c)throw new ArgumentException("Stable disjoint resolved mode table and count required.");if((rawCount!=0||backend[0x65c]!=0)&&Read(backend,0x61c)==0)throw new ArgumentException("Original mode pointer must resolve before table access.");int count=(int)rawCount,chosen=0,bestWidth=10000,bestHeight=10000,bestRefresh=10000;
   for(int i=0;i<count;++i){int value=Signed(modes,i*16);if(Distance(value,width)<=Distance(bestWidth,width)){chosen=i;bestWidth=value;}}
   for(int i=0;i<count;++i)if(Signed(modes,i*16)==bestWidth){int value=Signed(modes,i*16+4);if(Distance(value,height)<=Distance(bestHeight,height)){chosen=i;bestHeight=value;}}
   if(refresh!=0)for(int i=0;i<count;++i)if(Signed(modes,i*16)==bestWidth&&Signed(modes,i*16+4)==bestHeight){int value=Signed(modes,i*16+8);if(Distance(value,refresh)<=Distance(bestRefresh,refresh)){chosen=i;bestRefresh=value;}}
   if(backend[0x65c]!=0){if(chosen>modes.Length/16-1)throw new ArgumentException("Mutable selected record must resolve even for count0.");int at=chosen*16;if(Signed(modes,at)!=width)Write(modes,at,width);if(Signed(modes,at+4)!=height)Write(modes,at+4,height);}
   return(uint)chosen;
  }
  static float Difference(float ratio,float target){return Math.Abs(W.Add(W.From(ratio),W.From(-target)).Store());}
  // Original0x6e1d00. Unsigned dimensions enter x87 exactly, then ratio and
  // each difference spillfloat32. The qword targets are widened float32 values.
  // Expose overwritten argument words as explicit diagnostics, not a claim
  // about managed caller-stack storage or later original stack residue lifetime.
  public static AspectClassificationResult ClassifyRaw(uint width,uint height)
  {
   if(height==0)throw new ArgumentException("Nonzero unsigned height required for finite classifier domain.");float ratio=W.Divide(W.FromDouble((double)width),W.FromDouble((double)height)).Store(),best=1000;
   uint mode=0;float difference=Difference(ratio,1.3333334f);if(difference<1000)best=difference;difference=Difference(ratio,1.7777778f);if(difference<best){best=difference;mode=1;}difference=Difference(ratio,1.6f);return new AspectClassificationResult(difference<best?2:mode,best,difference);
  }
 }
}
