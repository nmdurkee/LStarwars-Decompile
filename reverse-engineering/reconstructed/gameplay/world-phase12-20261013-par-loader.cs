using System;
namespace Recovered.Gameplay {
 public interface IParRuntimeServices {
  void Activate(SoundSetupImage m,int instance,uint startBits);
  void Select(SoundSetupImage m,uint distanceBits);
 }
 public static class ParResourceLoading {
  public const uint Banks=0x292089c,Scenes=0x29208d0,SceneBanks=0x291f688,Records=0x2913a58,Instances=0x291f7a8,RecordCount=0x2920a94,InstanceCount=0x2920a98;
  static uint W(SoundSetupImage m,ISplineFileTransport f){return SplineResourceLoading.Word(m,f);}
  static ushort H(SoundSetupImage m,ISplineFileTransport f){byte a=SplineResourceLoading.Byte(m,f),b=SplineResourceLoading.Byte(m,f);return m.Word(SplineResourceLoading.Swap)==0?(ushort)(a|(b<<8)):(ushort)(b|(a<<8));}
  // 0x64c300. Whole own-state PAR loader; activation/selection and asset bindings are explicit services.
  // discardRecord supplies readable376-byte temporary backing, corresponding to the native stack record.
  public static uint Load(SoundSetupImage m,uint path,uint mode,uint sceneList,int sceneCount,uint discardRecord,ISplineFileTransport file,IParRecordBindings bindings,IParRuntimeServices runtime){unchecked{
   byte kind=(byte)mode;uint bank=0;
   if(kind!=0){bank=1;while(m.Word(Banks+bank*4)!=0){bank++;if(bank>7)return 0xffffffff;}}
   int slot=0;
   for(int i=0;i<sceneCount;i++){
    uint scene=m.Word(sceneList+(uint)i*4);if(scene==0)continue;
    while(m.Word(Scenes+(uint)slot*4)!=0){if(slot>31)break;slot++;}
    if(slot<32){m.Word(Scenes+(uint)slot*4,scene);m.Word(SceneBanks+(uint)slot*4,bank);}
   }
   m.Word(SplineResourceLoading.Mode,1);
   if(SplineResourceLoading.OpenRead(m,path,file)==0)return 0xffffffff;
   int version=(int)W(m,file);
   if(version<1||version>16){SplineResourceLoading.CloseRead(m,file);return 0xffffffff;}
   int requested=(int)W(m,file),overflow=0;
   if((int)m.Word(RecordCount)+requested>128){overflow=(int)m.Word(RecordCount)+requested-128;requested-=overflow;}
   int recordSlot=0;
   for(int i=0;i<requested;i++){
    uint at=Records+(uint)recordSlot*376;while(m.Byte(at)!=0){recordSlot++;at+=376;}
    ParPhysicalRecords.Decode(m,at,version,bank,file,bindings);
    if(m.Byte(at)!=0){m.Word(RecordCount,m.Word(RecordCount)+1);m.Byte(at+178,(byte)bank);m.Byte(at+179,kind);}
   }
   for(int i=0;i<overflow;i++)ParPhysicalRecords.Decode(m,discardRecord,version,bank,file,bindings);
   requested=(int)W(m,file);if((int)m.Word(InstanceCount)+requested>40)requested=40-(int)m.Word(InstanceCount);
   int instanceSlot=0;
   for(int i=0;i<requested;i++){
    uint at=Instances+(uint)instanceSlot*108;while(m.Word(at+12)!=0xffffffff){instanceSlot++;at+=108;}
    m.Word(at,W(m,file));m.Word(at+4,W(m,file));m.Word(at+8,W(m,file));SplineResourceLoading.Read(m,at+16,16,file);
    uint id=WorldParameterBank.Resolve(m,at+16,bank);m.Word(at+12,id);
    m.Half(at+48,H(m,file));m.Half(at+46,H(m,file));m.Half(at+44,H(m,file));
    if(version<11){m.Half(at+68,0);m.Half(at+70,0);}else{m.Half(at+68,H(m,file));m.Half(at+70,H(m,file));}
    m.Byte(at+50,(byte)bank);m.Byte(at+60,0);
    // Original computes this through id=-1 too; prepared prefix backing is required.
    uint record=Records+id*376;for(uint sound=0;sound<4;sound++)if(m.Word(record+328+sound*4)!=0xffffffff&&m.Byte(record+344+sound)!=0){m.Byte(at+60,1);break;}
    if(id!=0xffffffff){m.Word(InstanceCount,m.Word(InstanceCount)+1);runtime.Activate(m,instanceSlot,0);m.Byte(at+61,1);}
   }
   SplineResourceLoading.CloseRead(m,file);runtime.Select(m,0x3f800000);m.Word(Banks+bank*4,1);if(bank==0)m.Word(0x2913a2c,1);
   if(kind==0)m.Word(0x296292c,bank);else if(kind==1)m.Word(0x8109d0,bank);return bank;
  }}
 }
}
