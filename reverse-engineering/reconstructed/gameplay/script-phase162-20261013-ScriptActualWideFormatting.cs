namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptWideFormattingServices:ScriptFormattingServices
 {
  readonly ScriptFormattingServices inner;readonly ScriptWideCharacterServices wide;readonly uint frame;public RecoveredScriptWideFormattingServices(ScriptFormattingServices s,ScriptWideCharacterServices w,uint f){inner=s;wide=w;frame=f;}
  public override ScriptLocaleUpdateServices LocaleServices{get{return inner.LocaleServices;}}
  public override uint Output(TakeoverReleaseMemory m,uint f,uint fmt,uint l,uint a){return inner.Output(m,f,fmt,l,a);}
  public override uint Errno(TakeoverReleaseMemory m){return inner.Errno(m);}public override void Invalid(TakeoverReleaseMemory m,uint a,uint b,uint c,uint d,uint e){inner.Invalid(m,a,b,c,d,e);}public override uint Flush(TakeoverReleaseMemory m,uint v,uint f){return inner.Flush(m,v,f);}
  public override uint Wide(TakeoverReleaseMemory m,uint result,uint buffer,uint capacity,ushort character){uint caller=frame-0x9c,child=frame-0xb4;m.Write32(caller,result);m.Write32(caller+4,buffer);m.Write32(caller+8,capacity);m.Write32(caller+12,character);return PreparedScriptWideCharacter.Standard(m,wide,caller,child,frame-0xcc);}public override uint Decode(TakeoverReleaseMemory m,uint encoded){return inner.Decode(m,encoded);}
  public override void Floating(TakeoverReleaseMemory m,uint f,uint value,uint buffer,uint capacity,int type,int precision,uint capitals,uint locale){inner.Floating(m,f,value,buffer,capacity,type,precision,capitals,locale);}public override void Alter(TakeoverReleaseMemory m,uint f,uint buffer,uint locale){inner.Alter(m,f,buffer,locale);}public override uint Allocate(TakeoverReleaseMemory m,uint capacity){return inner.Allocate(m,capacity);}public override void Release(TakeoverReleaseMemory m,uint buffer){inner.Release(m,buffer);}public override uint CountEnabled(TakeoverReleaseMemory m){return inner.CountEnabled(m);}
 }
}
