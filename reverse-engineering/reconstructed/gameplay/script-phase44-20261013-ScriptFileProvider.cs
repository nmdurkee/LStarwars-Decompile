// Original513400 file provider: EDIarchive/ESIfilename/cdeclbasepath; formatted fallback and archive attempt.
using System;
namespace Recovered.Gameplay
{
 public struct ScriptArchiveData{public uint Data,Length;public ScriptArchiveData(uint data,uint length){Data=data;Length=length;}}
 public abstract class ScriptFileProviderServices
 {
  public abstract uint Find(TakeoverReleaseMemory m,uint archive,uint fileName);
  public abstract ScriptArchiveData Information(TakeoverReleaseMemory m,uint archive,uint entry);
  public abstract uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode);
  public abstract uint AttachParser(TakeoverReleaseMemory m,uint handle);
  public abstract uint OpenFileParser(TakeoverReleaseMemory m,string path);
  public virtual void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args){}
 }
 public static class PreparedScriptFileProvider
 {
  static byte Fold(byte c){return c>=97&&c<=122||c>=224?unchecked((byte)(c-32)):c;}
  public static uint Open(TakeoverReleaseMemory m,ScriptFileProviderServices s,uint basePath,uint archive,uint fileName)
  {
   string name=PreparedConditionLoading.Text(m,fileName);if(name.Length>=64)throw new ArgumentException("Native64-byte filename local required.");bool extension=false;for(int i=0;i+4<=name.Length;i++)if(name[i]=='.'&&Fold((byte)name[i+1])=='S'&&Fold((byte)name[i+2])=='C'&&Fold((byte)name[i+3])=='P'){extension=true;break;}if(!extension)return 0;string path=PreparedConditionLoading.Text(m,basePath)+"\\"+name;if(path.Length>=128)throw new ArgumentException("Native128-byte formatted path local required.");
   if(archive!=0){uint entry=s.Find(m,archive,fileName);if(entry!=0){ScriptArchiveData data=s.Information(m,archive,entry);uint handle=s.OpenMemory(m,data.Data,data.Length,0);if(handle!=0)return s.AttachParser(m,handle);s.Diagnostic(m,0x512870,new uint[]{fileName});}else s.Diagnostic(m,m.Read32(0x922248)==1?0x512870u:0x512850u,new uint[]{fileName});if(m.Read32(0x923874)!=0)s.Diagnostic(m,m.Read32(0x922248)==1?0x512860u:0x512850u,new uint[]{fileName});}return s.OpenFileParser(m,path);
  }
 }
 public sealed class RecoveredScriptFileProviderTransport:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly ScriptFileProviderServices provider;
  public RecoveredScriptFileProviderTransport(ScriptFileTransportServices ports,ScriptFileProviderServices fileProvider){if(ports==null||fileProvider==null)throw new ArgumentNullException("ports/fileProvider");remaining=ports;provider=fileProvider;}
  // Legacyphase30 interface names wereopaque: firstargument isbasePath, secondisarchive. Position preserved.
  public override uint Open(TakeoverReleaseMemory m,uint first,uint second,uint name){return PreparedScriptFileProvider.Open(m,provider,first,second,name);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint c,uint p){remaining.Command(m,c,p);}
 }
}
