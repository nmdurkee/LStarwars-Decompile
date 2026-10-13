using System;
namespace Recovered.Gameplay {
 public static class PtlPhysicalRecords {
  static uint W(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Word(m,f);}
  static byte B(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Byte(m,f);}
  static ushort H(SoundSetupImage m,ISplineFileTransport f){byte a=B(m,f),b=B(m,f);return m.Word(SplineResourceLoading.Swap)==0?(ushort)(a|(b<<8)):(ushort)(b|(a<<8));}
  static float F(SoundSetupImage m,uint at){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(at)),0);}
  static void Store(SoundSetupImage m,uint at,double value){m.Word(at,BitConverter.ToUInt32(BitConverter.GetBytes((float)value),0));}
  static byte Color(uint bits){float v=BitConverter.ToSingle(BitConverter.GetBytes(bits),0);if(Single.IsNaN(v)||Single.IsInfinity(v)||(double)v< -2147483648.0||(double)v>=2147483648.0)return 0;return unchecked((byte)(int)Math.Truncate(v));}
  static void Floats(SoundSetupImage m,uint at,int count,ISplineFileTransport f){for(int i=0;i<count;i++)m.Word(at+(uint)i*4,W(m,f));}
  // 0x66a190: physical 1064-byte PTL record, accepted loader versions5..41 and finite raw float fields.
  public static void Decode(SoundSetupImage m,uint r,int v,byte mode,ISplineFileTransport f,IParRecordBindings bindings){unchecked{
   SplineResourceLoading.Read(m,r,16,f);m.Byte(r+16,mode);short rate=(short)H(m,f);m.Half(r+22,(ushort)(v<28?(rate>0?rate*60:rate<0?-60/rate:0):rate));m.Half(r+20,H(m,f));
   for(uint off=24;off<=40;off+=4){if(v<28)Store(m,r+off,(short)H(m,f)/60.0);else m.Word(r+off,W(m,f));}
   rate=(short)m.Half(r+22);if(rate!=0){float minimum=(float)(1.0/rate);if(F(m,r+28)<minimum)Store(m,r+28,minimum);}
   m.Byte(r+44,B(m,f));m.Byte(r+45,B(m,f));m.Byte(r+18,v<35?(byte)0:B(m,f));m.Byte(r+19,0);m.Byte(r+46,B(m,f));if(v<39)B(m,f);m.Byte(r+47,1);m.Byte(r+1042,v<40?(byte)0:B(m,f));
   m.Word(r+48,W(m,f));if(v<6){m.Word(r+52,0);m.Word(r+56,0x41c80000);}else Floats(m,r+52,2,f);m.Word(r+60,v<10?0:W(m,f));m.Word(r+64,v<23?0:W(m,f));m.Word(r+68,v<24?0x3f000000:W(m,f));
   if(v<7){W(m,f);W(m,f);}Floats(m,r+72,4,f);if(v<18)for(int i=0;i<3;i++)W(m,f);Floats(m,r+88,3,f);if(v<18)for(int i=0;i<3;i++)W(m,f);
   if((v==18||v==19)&&m.Byte(r+44)==6){Store(m,r+84,(double)F(m,r+84)*2);Store(m,r+96,(double)F(m,r+96)*2);}
   if(v<29){m.Word(r+100,0);m.Word(r+104,0);m.Word(r+108,0);}else Floats(m,r+100,3,f);Floats(m,r+112,14,f);m.Half(r+168,H(m,f));m.Byte(r+170,B(m,f));m.Byte(r+171,B(m,f));Floats(m,r+172,5,f);
   for(uint i=0;i<8;i++){uint at=r+192+i*8;m.Word(at,W(m,f));if(v<33){m.Byte(at+4,Color(W(m,f)));m.Byte(at+5,Color(W(m,f)));m.Byte(at+6,Color(W(m,f)));}else for(uint c=0;c<4;c++)m.Byte(at+4+c,B(m,f));}
   Floats(m,r+256,16,f);if(v<21){m.Word(r+320,0x3e000000);m.Word(r+324,0x3e000000);}else Floats(m,r+320,2,f);Floats(m,r+328,2,f);
   foreach(uint start in new uint[]{336,400})Floats(m,r+start,16,f);Floats(m,r+464,2,f);foreach(uint start in new uint[]{472,536,600})Floats(m,r+start,16,f);Floats(m,r+664,4,f);Floats(m,r+688,16,f);m.Byte(r+752,B(m,f));m.Byte(r+753,v<17?(byte)0:B(m,f));if(m.Byte(r+46)==7)m.Byte(r+753,2);m.Byte(r+754,v<31?(byte)3:B(m,f));
   if(v<32){m.Byte(r+755,0);m.Word(r+760,0x3f800000);m.Word(r+764,0x3f800000);m.Word(r+768,0x3f800000);}else{m.Byte(r+755,B(m,f));Floats(m,r+760,3,f);}
   if(v<36)m.Word(r+756,0x40800000);else{m.Word(r+756,W(m,f));if(v==36&&F(m,r+756)<4)m.Word(r+756,0x40800000);}
   if(v<30){m.Word(r+772,0x3f800000);m.Word(r+776,0x3dcccccd);m.Word(r+780,0);foreach(uint start in new uint[]{784,848,912}){m.Word(r+start,0);m.Word(r+start+4,0);m.Word(r+start+8,0x3f800000);m.Word(r+start+12,0x3f800000);}}
   else{Floats(m,r+772,3,f);foreach(uint start in new uint[]{784,848,912})Floats(m,r+start,16,f);}
   for(uint i=0;i<4;i++)m.Word(r+976+i*4,0xffffffff);
   if(v<23){for(uint i=0;i<4;i++){uint at=r+992+i*12;m.Word(at,v<11?0xffffffff:W(m,f));m.Word(at+4,v<11?0:W(m,f));m.Word(at+8,v<11?0:W(m,f));}}
   else{int count=(int)W(m,f);for(int i=0;i<count;i++){byte[] name=new byte[16];for(int j=0;j<16;j++)name[j]=B(m,f);uint at=r+992+(uint)i*12;m.Word(at,bindings.Sound(name,16));m.Word(at+4,W(m,f));m.Word(at+8,W(m,f));}for(int i=count;i<4;i++)m.Word(r+992+(uint)i*12,0xffffffff);}
   if(v<16){m.Byte(r+1040,0);m.Word(r+1044,0);}else{m.Byte(r+1040,v<41?(byte)W(m,f):B(m,f));m.Word(r+1044,W(m,f));}
   if(v<25){m.Byte(r+1041,5);m.Word(r+1052,0x3f000000);}else{m.Byte(r+1041,v<41?(byte)W(m,f):B(m,f));m.Word(r+1052,W(m,f));}m.Word(r+1048,v<26?0:W(m,f));m.Word(r+1056,0x3f800000);m.Word(r+1060,0);
  }}
 }
 public interface IPtlRecordServices {void Normalize(SoundSetupImage m,uint record);void Select(SoundSetupImage m,uint thresholdBits);}
 public static class PtlRecordPublication {
  // Bounded 0x68df20 record-bank paths for original modes0/5/6; modes1/2 emitter records remain separate.
  public static uint Load(SoundSetupImage m,uint path,uint mode,uint scene,uint discarded,ISplineFileTransport file,IParRecordBindings bindings,IPtlRecordServices services){unchecked{
   byte original=(byte)mode,recordMode=original;uint bank=0;
   if(original==5)bank=1;else if(original!=0){if(original==6)recordMode=1;bank=2;while(m.Word(0x2924b10+bank*4)!=0){bank++;if(bank>=8)return 0xffffffff;}}
   m.Word(SplineResourceLoading.Mode,1);if(SplineResourceLoading.OpenRead(m,path,file)==0)return 0xffffffff;int version=(int)SplineResourceLoading.Word(m,file);if(version<5||version>=42){SplineResourceLoading.CloseRead(m,file);return 0xffffffff;}
   m.Word(0x2924b10+bank*4,1);m.Word(0x2947bdc+bank*4,scene);int requested=(int)SplineResourceLoading.Word(m,file),overflow=0;
   if((int)m.Word(0x2962098)<(int)m.Word(0x2962a24)+requested){overflow=(int)m.Word(0x2962a24)-(int)m.Word(0x2962098)+requested;requested=(int)m.Word(0x2962098)-(int)m.Word(0x2962a24);m.Word(0x296293c,300);}
   int slot=1;for(int i=0;i<requested;i++){while(m.Word(m.Word(0x296209c)+(uint)slot*4)!=0)slot++;uint at=m.Word(0x29620a0)+(uint)slot*1064;PtlPhysicalRecords.Decode(m,at,version,recordMode,file,bindings);m.Byte(at+17,(byte)bank);m.Word(at+680,0);m.Word(at+684,0);m.Word(m.Word(0x296209c)+(uint)slot*4,at);services.Normalize(m,at);m.Word(0x2962a24,m.Word(0x2962a24)+1);}
   for(int i=0;i<overflow;i++)PtlPhysicalRecords.Decode(m,discarded,version,recordMode,file,bindings);
   SplineResourceLoading.CloseRead(m,file);services.Select(m,0x3f800000);if(original==0)m.Word(0x2962920,bank);else if(original==5)m.Word(0x8109c8,bank);return bank;
  }}
 }
}
