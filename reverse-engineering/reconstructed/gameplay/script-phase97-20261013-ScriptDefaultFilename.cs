// Concrete default-provider filename formatting with real byte copy/append/path normalization children.
using System;
using System.Text;
namespace Recovered.Gameplay
{
 public static class PreparedScriptDefaultFilename
 {
  static string Ascii(TakeoverReleaseMemory m,uint p){StringBuilder s=new StringBuilder();for(uint i=0;i<4096;i++){byte c=m.Read8(p+i);if(c==0)return s.ToString();if(c>127)throw new ArgumentException("Prepared ASCII filename prefix comparison required.");s.Append((char)c);}throw new ArgumentException("Prepared bounded filename required.");}
  //4ff130 cdecl(provider,output,input,capacity), private512-byte assembled path unaliased.
  public static uint Format(ConditionParserMemory m,uint provider,uint output,uint input,uint capacity,uint privatePath)
  {
   uint prefix=provider+0x34,length=PreparedScriptByteStrings.Length(m,prefix);
   return ScriptCompilerLocals.CString(m,privatePath,new string('\0',511),delegate(uint assembled){
    if(PreparedHierarchicalScriptContainerIndex.Substring(m,input,0x75c044)!=0)PreparedScriptByteStrings.Copy(m,assembled,input);
    else if(RandomSplineSelection.Compare(Ascii(m,input),Ascii(m,prefix),unchecked((int)length))==0)
    {
     uint tail=unchecked(input+PreparedScriptByteStrings.Length(m,prefix));byte first=m.Read8(tail);
     if(first==92||first==47)PreparedScriptByteStrings.Copy(m,assembled,input);
     else{PreparedScriptByteStrings.Copy(m,assembled,provider+0x4c);PreparedScriptByteStrings.Append(m,assembled,provider+0xac);PreparedScriptByteStrings.Append(m,assembled,tail);}
    }
    else{PreparedScriptByteStrings.Copy(m,assembled,provider+0x4c);PreparedScriptByteStrings.Append(m,assembled,provider+0xac);PreparedScriptByteStrings.Append(m,assembled,input);}
    uint baseLength=PreparedScriptByteStrings.Length(m,provider+0x4c);PreparedScriptContainerIndex.Normalize(m,provider,unchecked(assembled+baseLength));PreparedScriptPathCompaction.Compact(m,provider,assembled);
    uint finalLength=PreparedScriptByteStrings.Length(m,assembled);if(unchecked((int)finalLength)>=unchecked((int)capacity))return 0;PreparedScriptByteStrings.Copy(m,output,assembled);return 1;
   });
  }
 }
 public sealed class RecoveredDefaultGameOpenServices:ScriptGameOpenServices
 {
  readonly ScriptGameOpenServices remaining;readonly uint pathLocal;public RecoveredDefaultGameOpenServices(ScriptGameOpenServices r,uint local){remaining=r;pathLocal=local;}
  public override void Format(TakeoverReleaseMemory m,uint callback,uint provider,uint output,uint input,uint capacity){if(callback!=0x4ff130){remaining.Format(m,callback,provider,output,input,capacity);return;}ConditionParserMemory p=m as ConditionParserMemory;if(p==null)throw new ArgumentException("Shared condition image required.");PreparedScriptDefaultFilename.Format(p,provider,output,input,capacity,pathLocal);}
  public override void EnterCriticalSection(TakeoverReleaseMemory m,uint p){remaining.EnterCriticalSection(m,p);}
  public override void LeaveCriticalSection(TakeoverReleaseMemory m,uint p){remaining.LeaveCriticalSection(m,p);}
  public override uint Open(TakeoverReleaseMemory m,uint p,uint mode,uint c,uint r){return remaining.Open(m,p,mode,c,r);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint[] args){remaining.Diagnostic(m,args);}
  public override uint CrtOpen(TakeoverReleaseMemory m,uint a,uint b,uint p,uint mode,uint r){return remaining.CrtOpen(m,a,b,p,mode,r);}
 }
}
