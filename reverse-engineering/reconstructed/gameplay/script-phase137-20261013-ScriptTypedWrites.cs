// Original raw, string, scalar and typed file writers. See phase137 contract for x87 domain.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptTypedWrites
 {
  static void Handle(uint h){if(unchecked((int)h)>=0x1000)return;if((h>=1&&h<=64)||(h>=0x400&&h<0x414))return;throw new ArgumentException("Prepared stream/memory/CRT handle required.");}
  public static uint Raw(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint source,uint count){Handle(h);if(unchecked((int)h)>=0x1000)return RecoveredActualReleaseCrtEndpoints.Write(h-0x1000,source,count,0);if(h>=0x400)return RecoveredScriptMemoryWrite.Write(m,h,source,count);return RecoveredScriptStreamWrite.Write(m,host,h-1,source,count);}
  //4f0530 is the distinct alternate entry with the same instructions as4f04b0.
  public static uint U32Alternate(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint local){return RecoveredScriptScalarU32Write.Write(m,host,h,value,local);}
  static uint Scalar(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,int width,uint local){Handle(h);bool reverse=width>1&&m.Read32(0x91eea0)!=0;char[] data=new char[width];for(int i=0;i<width;i++)data[i]=(char)((value>>((reverse?width-1-i:i)*8))&255);return ScriptCompilerLocals.CString(m,local,new string(data),delegate(uint p){return Raw(m,host,h,p,(uint)width);});}
  //Raw exact entries4f05b0/4f0630; upper value bits are truncated before dispatch.
  public static uint U16(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint local){return Scalar(m,host,h,value,2,local);}
  public static uint U16Alternate(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint local){return Scalar(m,host,h,value,2,local);}
  //Raw exact entries4f06b0/4f0700 do not read the endian flag.
  public static uint U8(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint local){return Scalar(m,host,h,value,1,local);}
  public static uint U8Alternate(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint local){return Scalar(m,host,h,value,1,local);}
  //4f0420 contains FLD/FSTP. Prepared finite values, infinities and quiet NaNs preserve bits.
  //Signaling NaNs require a hardware-accurate x87 invalid-operation model and are excluded.
  public static uint SingleBits(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint bits,uint local){if((bits&0x7f800000)==0x7f800000&&(bits&0x007fffff)!=0&&(bits&0x00400000)==0)throw new ArgumentException("Signaling NaN is outside the prepared x87 domain.");return Scalar(m,host,h,bits,4,local);}
  //4f0750 scans before dispatch, including the release CRT branch, and excludes terminator.
  public static uint String(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint source){if(source==0)throw new ArgumentException("Readable non-null string required.");uint length=0;while(m.Read8(source+length)!=0)length++;return Raw(m,host,h,source,length);}
 }
}
