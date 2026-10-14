// Origin-position action516ac0. Preserves callback success bypass and sequential DWORD copies.
namespace Recovered.Gameplay
{
 public static class PreparedScriptOriginPosition
 {
  // cdecl(system,unusedPacket,actor), integer success1 even when guarded no-op.
  public static uint Execute(TakeoverReleaseMemory m,ScriptOriginServices origins,uint system,uint actor)
  {
   if(actor==0||system==0)return 1;uint source=0,callback=m.Read32(0x923908);
   if(callback!=0)source=origins.Origin(m,callback,system,actor);
   uint controller=m.Read32(actor+0xd0);
   if(source==0){if(controller==0||(m.Read32(controller+0x1f8)&0x400)==0)return 1;byte selector=m.Read8(actor+0x138);if(selector==255)return 1;source=unchecked(m.Read32(system+0x18)+(uint)selector*0xa4+0x20);}
   uint output=unchecked(controller+0x5c);
   m.Write32(output,m.Read32(source));m.Write32(output+4,m.Read32(source+4));m.Write32(output+8,m.Read32(source+8));return 1;
  }
 }
}
