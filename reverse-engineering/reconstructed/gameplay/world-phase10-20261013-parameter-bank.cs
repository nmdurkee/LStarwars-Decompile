using System;
namespace Recovered.Gameplay {
 public interface IParameterBankBackend {int Exists(SoundSetupImage m,string path);uint Load(SoundSetupImage m,string path,uint mode,uint scene);}
 public static class WorldParameterBank {
  public const uint Records=0x2913a58;public const uint Stride=376;public const int RecordCount=128;
  static bool Equal16(SoundSetupImage m,uint query,uint name,bool folded){for(uint i=0;i<16;i++){byte a=m.Byte(query+i),b=m.Byte(name+i);if(folded){if(a>=97&&a<=122)a-=32;if(b>=97&&b<=122)b-=32;}if(a!=b)return false;if(a==0||b==0)return true;}return true;}
  // 0x64b020. Preferred bank1..7 uses case-folded16-byte comparison; bank0 fallback is case-sensitive.
  public static uint Resolve(SoundSetupImage m,uint query,uint preferred){unchecked{if(query==0||m.Byte(query)==0)return 0xffffffff;
   if(preferred-1<7)for(int i=0;i<RecordCount;i++){uint record=Records+(uint)i*Stride;if((sbyte)m.Byte(record+178)==(int)preferred&&Equal16(m,query,record,true))return (uint)i;}
   for(int i=0;i<RecordCount;i++){uint record=Records+(uint)i*Stride;if(m.Byte(record+178)==0&&Equal16(m,query,record,false))return (uint)i;}return 0xffffffff;
  }}
  static void Copy(SoundSetupImage m,uint target,uint source){unchecked{byte v;do{v=m.Byte(source++);m.Byte(target++,v);}while(v!=0);}}
  // 0x571890. End reference unused; null authored name table skips explicit rows while retaining header count.
  public static uint CreateCache(SoundSetupImage m,uint cursorRef,uint endRef,int capacity,int explicitCount,uint names,uint preferred){unchecked{
   uint header=(m.Word(cursorRef)+15)&0xfffffff0;m.Word(cursorRef,header+12);if(header==0)return 0;
   m.Word(header+8,0);m.Word(header,(uint)explicitCount);m.Word(header+4,(uint)capacity);uint rows=(m.Word(cursorRef)+15)&0xfffffff0;m.Word(header+8,rows);m.Word(cursorRef,rows+(uint)capacity*20);if(rows==0)return 0;
   for(uint i=0;i<(uint)capacity*20;i++)m.Byte(rows+i,255);int written=0;
   if(names!=0)while(written<(int)m.Word(header)){uint at=m.Word(header+8)+(uint)written*20;Copy(m,at+4,m.Word(names+(uint)written*4));m.Word(at,0xffffffff);m.Word(m.Word(header+8)+(uint)written*20,Resolve(m,m.Word(header+8)+(uint)written*20+4,preferred));written++;}
   for(int i=0;i<RecordCount&&written<(int)m.Word(header+4);i++){uint record=Records+(uint)i*Stride;uint at=m.Word(header+8)+(uint)written*20;m.Word(at,0xffffffff);
    if((sbyte)m.Byte(record+176)>0){Copy(m,at+4,record);m.Word(m.Word(header+8)+(uint)written*20,Resolve(m,m.Word(header+8)+(uint)written*20+4,preferred));written++;}
   }
   while(written<(int)m.Word(header+4)){m.Word(m.Word(header+8)+(uint)written*20,0xffffffff);written++;}return header;
  }}
  static string Text(SoundSetupImage m,uint p){string s="";for(byte v=m.Byte(p);v!=0;v=m.Byte(++p))s+=(char)v;return s;}
  // 0x571a50. Real PAR payload remains explicit; cache/lookup/particle-handle binding execute recovered behavior.
  public static void Load(SoundSetupImage m,uint world,IParameterBankBackend backend){
   m.Word(world+0x2a9c,0xffffffff);m.Word(0x8101b8,m.Word(world+0x2a98));
   if((m.Byte(m.Word(world+0x128)+100)&224)!=0)return;
   string path=Text(m,world+128)+".par";if(backend.Exists(m,path)>0)m.Word(world+0x2a9c,backend.Load(m,path,1,m.Word(world+0x13c)));
   m.Word(world+0x138,CreateCache(m,world+0x104,world+0x108,64,unchecked((int)m.Word(0x950ff8)),m.Word(0x950ffc),m.Word(world+0x2a9c)));
  }
 }
}
