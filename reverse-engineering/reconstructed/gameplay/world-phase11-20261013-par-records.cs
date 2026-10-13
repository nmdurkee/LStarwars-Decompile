using System;
namespace Recovered.Gameplay {
 public interface IParRecordBindings {
  int Sprite(byte[] name,uint scene);
  uint Effect(byte[] name,uint bank,bool fast);
  uint Sound(byte[] name,int bound);
 }
 public static class ParPhysicalRecords {
  static byte B(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Byte(m,f);}
  static uint W(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Word(m,f);}
  static ushort H(SoundSetupImage m,ISplineFileTransport f){byte a=B(m,f),b=B(m,f);return m.Word(SplineResourceLoading.Swap)==0?(ushort)(a|(b<<8)):(ushort)(b|(a<<8));}
  static byte[] Name(SoundSetupImage m,ISplineFileTransport f){byte[] b=new byte[16];for(int i=0;i<16;i++)b[i]=B(m,f);return b;}
  static void Put(SoundSetupImage m,uint at,byte[] b){for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}
  static uint EffectName(SoundSetupImage m,byte[] name,IParRecordBindings bindings){uint bank=m.Word(0x8101b8);return bindings.Effect(name,bank==0xffffffff?0:bank,bank!=0xffffffff);}
  static uint Effect(SoundSetupImage m,ISplineFileTransport f,IParRecordBindings bindings){return EffectName(m,Name(m,f),bindings);}
  static bool Equal16(SoundSetupImage m,uint a,uint b){for(uint i=0;i<16;i++){byte x=m.Byte(a+i),y=m.Byte(b+i);if(x>=97&&x<=122)x-=32;if(y>=97&&y<=122)y-=32;if(x!=y)return false;if(x==0||y==0)return true;}return true;}
  // 0x64ba10: complete own-state versioned376-byte PAR record decoder; asset binding is explicit.
  public static void Decode(SoundSetupImage m,uint record,int version,uint group,ISplineFileTransport file,IParRecordBindings bindings){unchecked{
   Put(m,record,Name(m,file));
   if(version<6){m.Byte(record+160,version<2?(byte)0:B(m,file));for(uint i=1;i<8;i++)m.Byte(record+160+i,255);}
   else for(uint i=0;i<8;i++)m.Byte(record+160+i,B(m,file));
   int sprites=version<6?1:8;
   for(int slot=0;slot<sprites;slot++){
    byte[] name=Name(m,file);Put(m,record+16+(uint)slot*16,name);uint indexAt=record+144+(uint)slot*2;m.Half(indexAt,65535);byte selector=m.Byte(record+160+(uint)slot);
    if(selector==0||selector==1){uint wanted=selector==0?group:0;
     for(int i=0;i<32;i++){if(m.Word(0x291f688+(uint)i*4)==wanted)m.Half(indexAt,(ushort)bindings.Sprite(name,m.Word(0x29208d0+(uint)i*4)));
      if((short)m.Half(indexAt)!=-1){m.Byte(record+168+(uint)slot,(byte)i);break;}
     }
    }
    if((short)m.Half(indexAt)==-1&&name[0]!=0)m.Half(indexAt,9998);
   }
   byte count=0;for(uint i=0;i<8;i++){short id=(short)m.Half(record+144+i*2);if(id!=-1&&id!=9999)count++;}m.Byte(record+176,count);m.Byte(record+177,version<6?(byte)0:B(m,file));
   m.Word(record+180,version<16?0x3f800000:W(m,file));m.Word(record+184,version<16?0x3f800000:W(m,file));m.Word(record+188,W(m,file));m.Word(record+192,version<14?0:W(m,file));
   for(uint at=196;at<=204;at+=4)m.Word(record+at,W(m,file));m.Word(record+208,version<8?0x3f400000:W(m,file));
   for(uint at=212;at<=248;at+=4)m.Word(record+at,W(m,file));
   for(uint at=252;at<=272;at+=4)m.Word(record+at,version<13?(uint)(int)(short)H(m,file):W(m,file));
   uint flags=W(m,file);if((short)m.Half(record+144)==9999)flags|=16;m.Word(record+276,flags);
   m.Word(record+280,0xffffffff);m.Word(record+284,0xffffffff);m.Word(record+296,0xffffffff);
   if(version<3){m.Word(record+288,0x42700000);m.Word(record+292,0x42700000);}
   else if(version<5){byte selector=B(m,file);byte[] name=Name(m,file);if(selector==0)m.Word(record+280,EffectName(m,name,bindings));else if(selector==1)m.Word(record+296,EffectName(m,name,bindings));m.Word(record+288,W(m,file));m.Word(record+292,0x42700000);}
   else if(version<9){m.Word(record+280,Effect(m,file,bindings));m.Word(record+296,Effect(m,file,bindings));m.Word(record+288,W(m,file));m.Word(record+292,0x42700000);}
   else{m.Word(record+280,Effect(m,file,bindings));m.Word(record+284,Effect(m,file,bindings));m.Word(record+296,Effect(m,file,bindings));m.Word(record+288,W(m,file));m.Word(record+292,W(m,file));}
   if(version<4){m.Word(record+300,0xffffffff);m.Word(record+324,0xffffffff);}
   else{m.Word(record+324,Effect(m,file,bindings));m.Word(record+300,Effect(m,file,bindings));}
   uint linked=0xffffffff;if(version<12)m.Byte(record+308,0);else{Put(m,record+308,Name(m,file));if(m.Byte(record+308)!=0)for(int i=0;i<128;i++)if(Equal16(m,record+308,0x2913a58+(uint)i*376)){linked=(uint)i;break;}}m.Word(record+304,linked);
   if(version<7){for(uint i=0;i<4;i++){m.Word(record+328+i*4,0xffffffff);m.Byte(record+344+i,0);}}
   else{for(uint i=0;i<4;i++)m.Word(record+328+i*4,bindings.Sound(Name(m,file),16));for(uint i=0;i<4;i++)m.Byte(record+344+i,B(m,file));}
   m.Word(record+348,version<10?0x41c80000:W(m,file));for(uint at=352;at<=360;at+=4)m.Word(record+at,version<15?0x3f800000:W(m,file));
   m.Word(record+368,0x3f800000);m.Word(record+372,0);
  }}
 }
}
