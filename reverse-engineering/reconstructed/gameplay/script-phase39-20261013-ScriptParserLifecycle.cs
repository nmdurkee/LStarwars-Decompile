// Parser suspend/reopen, signed archive-handle range and observed error-register continuations.
using System;
namespace Recovered.Gameplay
{
 public struct ScriptFileErrorRegisters{public uint Eax,Ecx;public ScriptFileErrorRegisters(uint eax,uint ecx){Eax=eax;Ecx=ecx;}}
 public abstract class ScriptParserLifecycleServices
 {
  public abstract ScriptFileErrorRegisters Error(TakeoverReleaseMemory m);
  public abstract void Close(TakeoverReleaseMemory m,uint handle);
  public abstract uint Open(TakeoverReleaseMemory m,uint fileName,uint mode,uint options,uint reserved);
  public abstract void Seek(TakeoverReleaseMemory m,uint handle,uint low,uint high,uint origin);
 }
 public static class PreparedScriptParserLifecycle
 {
  static bool Archive(uint handle){int value=unchecked((int)handle);return value>=0x400&&value<0x800;}
  public static void Suspend(TakeoverReleaseMemory m,ScriptParserLifecycleServices s,uint parser){uint handle=m.Read32(parser+4);if(Archive(handle))return;if(m.Read8(parser+8)==0||handle==0)handle=s.Error(m).Eax;s.Close(m,handle);m.Write32(parser+4,0);}
  public static void Resume(TakeoverReleaseMemory m,ScriptParserLifecycleServices s,uint parser){uint handle=m.Read32(parser+4);if(Archive(handle))return;uint name=parser+8;if(m.Read8(parser+8)==0)name=s.Error(m).Eax;handle=s.Open(m,name,0,m.Read32(0x91ee88),0);m.Write32(parser+4,handle);if(handle==0)handle=s.Error(m).Ecx;uint position=m.Read32(parser+0x524);s.Seek(m,handle,position,unchecked((uint)(unchecked((int)position)>>31)),0);m.Write32(parser+0x52c,unchecked(m.Read32(parser+0x524)-1));}
 }
 public sealed class RecoveredScriptIncludeLifecycle:ScriptIncludeServices
 {
  readonly ScriptParserLifecycleServices io;ScriptFileBodyServices body;
  public RecoveredScriptIncludeLifecycle(ScriptParserLifecycleServices fileIO){if(fileIO==null)throw new ArgumentNullException("fileIO");io=fileIO;}
  public void Bind(ScriptFileBodyServices parser){if(parser==null)throw new ArgumentNullException("parser");body=parser;}
  public override void Suspend(TakeoverReleaseMemory m,uint p){PreparedScriptParserLifecycle.Suspend(m,io,p);}
  public override void Resume(TakeoverReleaseMemory m,uint p){PreparedScriptParserLifecycle.Resume(m,io,p);}
  public override void Parse(TakeoverReleaseMemory m,uint output,uint context,uint name,uint archive,uint top,uint bottom){if(body==null)throw new InvalidOperationException("Script file body not bound.");PreparedScriptFileBody.Parse(m,body,output,context,name,archive,top,bottom);}
 }
}
