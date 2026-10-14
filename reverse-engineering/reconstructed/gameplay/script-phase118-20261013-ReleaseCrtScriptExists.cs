// Full existence fallback for container-free original type1 providers.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredReleaseCrtScriptExists
 {
  sealed class Files:ScriptExistsServices
  {
   readonly uint filename,formatter;public Files(uint name,uint format){filename=name;formatter=format;}
   public override uint Find(TakeoverReleaseMemory m,uint c,uint p){throw new ArgumentException("Prepared container-free existence required.");}
   public override uint Open(TakeoverReleaseMemory m,uint path,uint mode,uint container,uint reserved){ConditionParserMemory image=(ConditionParserMemory)m;uint provider=PreparedScriptContainerIndex.Provider(image,path);if(provider==0)provider=m.Read32(0x800478);if(container!=0||m.Read32(provider)!=1||m.Read32(provider+0x22c)!=0x4ff130)throw new ArgumentException("Prepared original type1 provider required.");return PreparedScriptGameOpen.Open(image,new RecoveredReleaseCrtGameOpenServices(formatter),null,null,null,path,mode,container,reserved,filename);}
  }
  public static uint Exists(ConditionParserMemory m,uint path,uint privateFilename,uint privateFormatter,bool transport){if(m.Read32(0x91ee88)!=0)throw new ArgumentException("Prepared container-free context required.");Files files=new Files(privateFilename,privateFormatter);RecoveredReleaseScriptCloseServices close=new RecoveredReleaseScriptCloseServices(null);return transport?PreparedScriptExists.Transport(m,files,close,path):PreparedScriptExists.Exists(m,files,close,path);}
 }
}
