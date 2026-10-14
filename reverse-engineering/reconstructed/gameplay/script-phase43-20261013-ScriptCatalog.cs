// Script.txt catalog driver: archive fallback, filename collection, script list publication and inheritance retries.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public abstract class ScriptCatalogServices:ScriptConditionMaterializationServices
 {
  public abstract uint Find(TakeoverReleaseMemory m,uint archive,uint name);
  public abstract ScriptArchiveData Information(TakeoverReleaseMemory m,uint archive,uint entry);
  public abstract uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode);
  public abstract uint OpenFile(TakeoverReleaseMemory m,string path,uint mode);
  public abstract uint AttachParser(TakeoverReleaseMemory m,uint handle);
  public abstract void FreeParser(TakeoverReleaseMemory m,uint parser);
  public abstract void Close(TakeoverReleaseMemory m,uint handle);
  //52c320 compiler-local filename normalized to string; custom EAXbasePath/ECXarchive retained.
  public abstract uint ParseScript(TakeoverReleaseMemory m,string name,uint basePath,uint archive,uint top,uint bottom);
 }
 public static class PreparedScriptCatalog
 {
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  //52c470 cdecl(archive,basePath,topPointer,bottomPointer,system), void.
  public static void Load(TakeoverReleaseMemory m,ScriptCatalogServices s,uint archive,uint basePath,uint top,uint bottom,uint system)
  {
   uint list=system==0?0x921ee8u:unchecked(system+0x1c),handle=0;bool fallback=archive==0;var names=new List<string>();if(archive!=0){uint entry=s.Find(m,archive,0x760448);if(entry!=0){ScriptArchiveData data=s.Information(m,archive,entry);handle=s.OpenMemory(m,data.Data,data.Length,0);if(handle==0){s.Diagnostic(m,0x512870,new uint[0]);fallback=true;}}else{s.Diagnostic(m,m.Read32(0x922248)==1?0x512870u:0x512850u,new uint[0]);fallback=true;}if(fallback&&m.Read32(0x923874)==1)s.Diagnostic(m,m.Read32(0x922248)==1?0x512860u:0x512850u,new uint[0]);}
   if(fallback){string path=PreparedConditionLoading.Text(m,basePath)+"\\script.txt";if(path.Length>=128)throw new ArgumentException("Native128-byte catalog path local required.");handle=s.OpenFile(m,path,0);}if(handle!=0){uint parser=s.AttachParser(m,handle);if(parser!=0){uint line=s.NextLine(m,parser);while(line!=0){s.NextToken(m,parser);string name=PreparedConditionLoading.Text(m,m.Read32(parser+0x510));if(name.Length>15||names.Count>=128)throw new ArgumentException("Native bounded128 filename slots with15-byte entry names required.");names.Add(name+PreparedConditionLoading.Text(m,0x75ffd8));line=s.NextLine(m,parser);}s.FreeParser(m,parser);}s.Close(m,handle);}
   foreach(string name in names){uint script=s.ParseScript(m,name,basePath,archive,top,bottom);if(script!=0){Append(m,list,script);if(system!=0)m.Write32(script+0x3c,m.Read32(script+0x3c)|1);}}if(system==0)return;uint passes=0;while(true){if(++passes>4096)throw new ArgumentException("Converging inheritance graph required; original pending cycles retry forever.");bool done=true;uint script=m.Read32(system+0x1c),budget=0;if(script==0)return;while(script!=0){if(++budget>4096)throw new ArgumentException("Bounded script list required.");if(PreparedScriptInheritance.Apply(m,s,script,top,bottom,system)==0)done=false;script=m.Read32(script);}if(done)return;}
  }
 }
}
