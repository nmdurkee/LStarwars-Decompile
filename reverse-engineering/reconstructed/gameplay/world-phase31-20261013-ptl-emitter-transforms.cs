using System;
namespace Recovered.Gameplay {
 public static class PtlEmitterTransforms {
  static uint At(SoundSetupImage m,uint offset,uint field){return unchecked(m.Word(0x29620a4)+offset+field);}
  static void Vector(SoundSetupImage m,uint id,uint field,uint x,uint y,uint z){unchecked{if(id==0xffffffff)return;uint off=id*0x330;m.Word(At(m,off,field),x);m.Word(At(m,off,field+4),y);m.Word(At(m,off,field+8),z);}}
  //6559a0/6559f0: ordered non-signaling binary32 argument copies; fresh base per store.
  public static void Vector1b4(SoundSetupImage m,uint id,uint x,uint y,uint z){Vector(m,id,0x1b4,x,y,z);}
  public static void Vector1a8(SoundSetupImage m,uint id,uint x,uint y,uint z){Vector(m,id,0x1a8,x,y,z);}
  static void Matrix(SoundSetupImage m,uint id,uint source,uint field,bool position){unchecked{
   if(id==0xffffffff)return;uint off=id*0x330,destination=At(m,off,field);
   // Actual REP MOVSD: arbitrary raw words and forward shifted overlap propagation.
   for(uint i=0;i<64;i+=4)m.Word(destination+i,m.Word(source+i));
   if(position){uint x=m.Word(source+0x30);m.Word(At(m,off,0x190),x);m.Word(At(m,off,0x194),m.Word(source+0x34));m.Word(At(m,off,0x198),m.Word(source+0x38));}
   m.Word(At(m,off,field+0x30),0);m.Word(At(m,off,field+0x34),0);m.Word(At(m,off,field+0x38),0);m.Word(At(m,off,0x300),0);
  }}
  //655a40 exports source translation to emitter position before clearing copied matrix translation.
  public static void PrimaryMatrixWithPosition(SoundSetupImage m,uint id,uint source){Matrix(m,id,source,0x40,true);}
  //655ad0/655b30 clear translation and300 without replacing position.
  public static void PrimaryMatrix(SoundSetupImage m,uint id,uint source){Matrix(m,id,source,0x40,false);}
  public static void SecondaryMatrix(SoundSetupImage m,uint id,uint source){Matrix(m,id,source,0x80,false);}
 }
}
