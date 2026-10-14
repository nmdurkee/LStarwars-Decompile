// Close the qualified locator-name formatting boundary through actual recovered sprintf and its full parser.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptLocatorFormattingServices:ScriptLocatorServices
 {
  readonly ScriptLocatorServices completion;readonly ScriptFormattingServices formatting;readonly uint workspace;
  public RecoveredScriptLocatorFormattingServices(ScriptLocatorServices c,ScriptFormattingServices f,uint privateWorkspace){completion=c;formatting=f;workspace=privateWorkspace;}
  sealed class PrivateMemory:TakeoverReleaseMemory
  {
   readonly TakeoverReleaseMemory outer;readonly uint start;readonly byte[] bytes=new byte[0x10000];public PrivateMemory(TakeoverReleaseMemory m,uint baseAddress){outer=m;start=baseAddress;}
   public override byte Read8(uint p){uint i=unchecked(p-start);return i<bytes.Length?bytes[i]:outer.Read8(p);}public override void Write8(uint p,byte value){uint i=unchecked(p-start);if(i<bytes.Length)bytes[i]=value;else outer.Write8(p,value);}
  }
  // Prepared formats are literal/%% with0 arguments or original %s_%d/%s_%s with2 arguments; output fits63 bytes and original byte classification has no lead bytes in these names.
  public override byte[] Format(TakeoverReleaseMemory m,uint format,uint first,uint second,int arguments)
  {
   if(arguments!=0&&arguments!=2)throw new ArgumentException("Prepared locator formatter argument count required.");var p=new PrivateMemory(m,workspace);uint output=workspace+0xf000,varargs=workspace+0xe00c,file=workspace+0xdfdc,frame=workspace+0xddc4;if(arguments==2){p.Write32(varargs,first);p.Write32(varargs+4,second);}PreparedScriptSprintf.Execute(p,new RecoveredScriptSprintfFormattingServices(formatting,frame),output,format,varargs,file);int length=0;while(p.Read8(output+(uint)length)!=0){if(length==63)throw new ArgumentException("Prepared locator name must fit64 byte local buffer.");length++;}byte[] value=new byte[length];for(int i=0;i<length;i++)value[i]=p.Read8(output+(uint)i);return value;
  }
  public override uint Complete(TakeoverReleaseMemory m,uint callback,uint controller,uint point){return completion.Complete(m,callback,controller,point);}
 }
}
