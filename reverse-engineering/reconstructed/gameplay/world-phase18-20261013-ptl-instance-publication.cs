using System;
namespace Recovered.Gameplay {
 public static class PtlInstancePublication {

  static uint W(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Word(m,f);}
  static byte B(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Byte(m,f);}
  static ushort H(SoundSetupImage m,ISplineFileTransport f){byte a=B(m,f),b=B(m,f);return m.Word(SplineResourceLoading.Swap)==0?(ushort)(a|(b<<8)):(ushort)(b|(a<<8));}
  static void DecodeInstance(SoundSetupImage m,uint at,int v,uint bank,ISplineFileTransport f,IParRecordBindings bindings){unchecked{
   m.Byte(at+0x51,(byte)bank);m.Word(at,W(m,f));m.Word(at+4,W(m,f));m.Word(at+8,W(m,f));
   if(v<7){m.Half(at+0x14,0);m.Half(at+0x16,0);m.Half(at+0x18,(ushort)W(m,f));m.Half(at+0x1a,(ushort)W(m,f));}
   else{m.Half(at+0x14,H(m,f));m.Half(at+0x16,H(m,f));m.Half(at+0x18,H(m,f));m.Half(at+0x1a,H(m,f));}
   m.Half(at+0x1c,v<22?(ushort)0:H(m,f));
   if(v<8)m.Word(at+0x20,0);else if(v<34)m.Word(at+0x20,BitConverter.ToUInt32(BitConverter.GetBytes((float)((int)W(m,f)/60.0)),0));else m.Word(at+0x20,W(m,f));
   SplineResourceLoading.Read(m,at+0x24,16,f);m.Word(at+0x10,99999);byte[] name=new byte[16];for(uint i=0;i<16;i++)name[i]=m.Byte(at+0x24+i);uint physical=bindings.Effect(name,bank,true);m.Word(at+0xc,physical);if(physical==0xffffffff)m.Word(0x2962a3c,m.Word(0x2962a3c)+1);
   if(v<9){m.Word(at+0x34,0);m.Word(at+0x38,0xffffffff);m.Word(at+0x3c,0);}else{m.Word(at+0x34,W(m,f));m.Word(at+0x38,W(m,f));m.Word(at+0x3c,W(m,f));}
   if(v<12){m.Half(at+0x40,0);m.Half(at+0x42,0);m.Word(at+0x44,0);}else{m.Half(at+0x40,H(m,f));m.Half(at+0x42,H(m,f));m.Word(at+0x44,W(m,f));}
   m.Word(at+0x48,v<13?0x3f666666:W(m,f));m.Half(at+0x4c,v<15?(ushort)0:H(m,f));
   if(v<27){ushort value=20000;if(physical!=0xffffffff){byte type=m.Byte(m.Word(m.Word(0x296209c)+physical*4)+0x2e);if(type==2)value=40000;else if(type==3)value=30000;else if(type==7)value=10000;}m.Half(at+0x4e,value);m.Byte(at+0x50,0);}
   else{m.Half(at+0x4e,H(m,f));m.Byte(at+0x50,B(m,f));}
   m.Byte(at+0x52,v<36?(byte)7:B(m,f));if(v<38){m.Byte(at+0x53,0);m.Half(at+0x54,0);m.Half(at+0x56,0);}else{m.Byte(at+0x53,B(m,f));m.Half(at+0x54,H(m,f));m.Half(at+0x56,H(m,f));}
  }}
  // 0x68df20 modes0/1/2/5/6; plain file transport, coherent physical/instance capacities and finite arithmetic.
  public static uint Load(SoundSetupImage m,uint path,uint mode,uint scene,uint discarded,ISplineFileTransport file,IParRecordBindings bindings,IPtlRecordServices services){unchecked{
   byte original=(byte)mode,recordMode=original;uint bank=0;
   if(original==5)bank=1;else if(original!=0){if(original==6)recordMode=1;bank=2;while(m.Word(0x2924b10+bank*4)!=0){bank++;if(bank>=8)return 0xffffffff;}}
   m.Word(SplineResourceLoading.Mode,1);if(SplineResourceLoading.OpenRead(m,path,file)==0)return 0xffffffff;int version=(int)SplineResourceLoading.Word(m,file);if(version<5||version>=42){SplineResourceLoading.CloseRead(m,file);return 0xffffffff;}
   m.Word(0x2924b10+bank*4,1);m.Word(0x2947bdc+bank*4,scene);int requested=(int)SplineResourceLoading.Word(m,file),overflow=0;
   if((int)m.Word(0x2962098)<(int)m.Word(0x2962a24)+requested){overflow=(int)m.Word(0x2962a24)-(int)m.Word(0x2962098)+requested;requested=(int)m.Word(0x2962098)-(int)m.Word(0x2962a24);m.Word(0x296293c,300);}
   int slot=1;for(int i=0;i<requested;i++){while(m.Word(m.Word(0x296209c)+(uint)slot*4)!=0)slot++;uint at=m.Word(0x29620a0)+(uint)slot*1064;PtlPhysicalRecords.Decode(m,at,version,recordMode,file,bindings);m.Byte(at+17,(byte)bank);m.Word(at+680,0);m.Word(at+684,0);m.Word(m.Word(0x296209c)+(uint)slot*4,at);services.Normalize(m,at);m.Word(0x2962a24,m.Word(0x2962a24)+1);}
   for(int i=0;i<overflow;i++)PtlPhysicalRecords.Decode(m,discarded,version,recordMode,file,bindings);
   if(original==1||original==2){int instances=(int)SplineResourceLoading.Word(m,file);if((int)m.Word(0x2962a2c)+instances>512)instances=512-(int)m.Word(0x2962a2c);m.Word(0x2962a3c,0);int row=0;for(int i=0;i<instances;i++){while(m.Word(0x2924b60+(uint)row*0x58)!=0xffffffff)row++;uint at=0x2924b50+(uint)row*0x58;DecodeInstance(m,at,version,bank,file,bindings);m.Word(0x2962a2c,m.Word(0x2962a2c)+1);}}
   SplineResourceLoading.CloseRead(m,file);services.Select(m,0x3f800000);if(original==0)m.Word(0x2962920,bank);else if(original==5)m.Word(0x8109c8,bank);else if(original==1)m.Word(0x8109cc,bank);return bank;
  }}
 }
}
