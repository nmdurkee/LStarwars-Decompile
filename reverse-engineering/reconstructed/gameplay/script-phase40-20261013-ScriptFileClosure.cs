// Full per-file parser closure: raw program producers, nested INCLUDE lifecycle and final state target binding.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptFileProgramBodies:ScriptFileProgramServices
 {
  readonly ScriptFileBodyServices body;readonly uint local;
  public RecoveredScriptFileProgramBodies(ScriptFileBodyServices parser,uint localAddress){if(parser==null)throw new ArgumentNullException("parser");if(localAddress>0xfffffffbu)throw new ArgumentException("Four-byte local address must not wrap.");body=parser;local=localAddress;}
  public override uint Parse(TakeoverReleaseMemory m,uint context,uint name,uint archive,uint top,uint bottom)
  {
   ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");foreach(var region in image.Image.Regions){ulong start=region.Key,end=start+(ulong)region.Value.Length;if((ulong)local<end&&(ulong)local+4>start)throw new ArgumentException("Dedicated unaliased compiler-local address required.");}image.Image.Regions.Add(local,new byte[4]);try{PreparedScriptFileBody.Parse(image,body,local,context,name,archive,top,bottom);return image.Read32(local);}finally{image.Image.Regions.Remove(local);}
  }
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args){body.Diagnostic(m,callback,args);}
 }
 public static class PreparedScriptFileClosure
 {
  public static RecoveredTextScriptFileServices Create(ScriptFileTransportServices transport,ScriptExpressionServices symbols,ScriptParserLifecycleServices io,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Func<SoundSetupImage,uint,uint> binaryToken)
  {
   Action<SoundSetupImage,uint> token=binaryToken==null?null:(Action<SoundSetupImage,uint>)delegate(SoundSetupImage m,uint p){binaryToken(m,p);};var include=new RecoveredScriptIncludeLifecycle(io);var conditions=new RecoveredScriptConditionCommands(transport,symbols,readFile,binaryLine,token);var macros=new RecoveredScriptMacroReferenceCommands(conditions,symbols,readFile,binaryLine,binaryToken);var actions=new RecoveredScriptActionCommands(macros,readFile,binaryLine,binaryToken);var derive=new RecoveredScriptDeriveIncludeCommands(actions,include,readFile,binaryLine,binaryToken);var scalars=new RecoveredScriptScalarCommands(derive,binaryToken);var states=new RecoveredScriptStateCommands(scalars,binaryToken);var body=new RecoveredTextScriptFileServices(states,readFile,binaryLine,token);states.Bind(body);include.Bind(body);return body;
  }
  public static uint Parse(ConditionParserMemory image,RecoveredTextScriptFileServices body,uint context,uint archive,uint name,uint top,uint bottom,uint localAddress){return PreparedScriptFileProgram.Parse(image,new RecoveredScriptFileProgramBodies(body,localAddress),context,archive,name,top,bottom);}
 }
}
