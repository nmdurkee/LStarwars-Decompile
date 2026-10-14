using System;
namespace Recovered.Gameplay {
 public static class PtlDeclarationActivation {
  const uint Rows=0x2924b50,Emitters=0x29620a4;
  static uint At(SoundSetupImage m,uint index,uint field){return unchecked(m.Word(Emitters)+index*0x330+field);}
  // 0x655f30: readable signed-index backing and mutable scene query5d92b0.
  public static void Attach(SoundSetupImage m,uint index,uint scene,Func<SoundSetupImage,uint,uint[],uint> call){unchecked{
   uint offset=index*0x330;
   if(scene!=0){uint result=call(m,0x5d92b0,new uint[]{scene,m.Word(Emitters)+offset+0x190});m.Half(m.Word(Emitters)+offset+0x2f2,(ushort)result);uint live=m.Word(Emitters);m.Word(live+offset+0x2fc,m.Half(live+offset+0x2f2)!=0xffff?scene:0);}
   else{m.Half(m.Word(Emitters)+offset+0x2f2,0xffff);m.Word(m.Word(Emitters)+offset+0x2fc,0);}
  }}
  // 0x68e4f0: declared512rows; constructor, orientation and timer bodies remain explicit mutable services.
  public static void Activate(SoundSetupImage m,IParRecordBindings bindings,Func<SoundSetupImage,uint,uint[],uint> call){unchecked{
   for(uint at=Rows;at<Rows+0xb000;at+=0x58){uint marker=at+16;if(m.Word(marker)==0xffffffff)continue;
    m.Word(marker,0xffffffff);byte[] name=new byte[16];for(uint i=0;i<16;i++)name[i]=m.Byte(at+0x24+i);uint physical=bindings.Effect(name,0,false);
    uint z=m.Word(at+8);m.Word(at+12,physical);uint y=m.Word(at+4),x=m.Word(at);
    call(m,0x684ee0,new uint[]{marker,physical,x,y,z});uint id=m.Word(marker);
    if(id==0xffffffff)m.Word(marker,99999);
    else{
     m.Byte(At(m,id,0x2f9),0);
     uint second=m.Half(at+0x16),first=m.Half(at+0x14);call(m,0x684640,new uint[]{m.Word(marker),first,second});
     uint third=m.Half(at+0x1c);second=m.Half(at+0x1a);first=m.Half(at+0x18);call(m,0x6846a0,new uint[]{m.Word(marker),first,second,third});
     id=m.Word(marker);uint delay=m.Word(at+0x20);call(m,0x655c30,new uint[]{At(m,id,0),delay});
     id=m.Word(marker);uint capturedFloat=m.Word(at+0x3c),capturedWord=m.Word(at+0x38);
     if(id!=0xffffffff){m.Word(At(m,id,0x2d0),m.Word(at+0x34));m.Word(At(m,id,0x2d4),capturedWord);m.Word(At(m,id,0x2d8),capturedFloat);}
     uint firstFloat=m.Word(at+0x44);id=m.Word(marker);uint secondFloat=m.Word(at+0x48),capturedShort=m.Half(at+0x42);
     if(id!=0xffffffff){m.Half(At(m,id,0x2dc),m.Half(at+0x40));m.Half(At(m,id,0x2de),(ushort)capturedShort);m.Word(At(m,id,0x2e0),firstFloat);m.Word(At(m,id,0x2e4),secondFloat);}
     third=m.Half(at+0x56);second=m.Half(at+0x54);first=m.Byte(at+0x53);call(m,0x684720,new uint[]{m.Word(marker),first,second,third});
     id=m.Word(marker);if(id!=0xffffffff)m.Half(At(m,id,0x2f0),m.Half(at+0x4c));
     int bank=(sbyte)m.Byte(at+0x51);uint scene=m.Word(0x2947bdc+(uint)bank*4);Attach(m,m.Word(marker),scene,call);
    }
    int activeBank=(sbyte)m.Byte(at+0x51);m.Word(0x2948eb0+(uint)activeBank*4,1);
   }
   m.Word(0x810ad8,0xffffffff);PtlEmitterRuntime.Select(m,1.0f);
  }}
 }
}
