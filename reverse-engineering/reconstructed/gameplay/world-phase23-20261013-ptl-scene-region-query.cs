using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlSceneRegionQuery {
  static float F(SoundSetupImage m,uint at){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(at)),0);}
  static float Distance(SoundSetupImage m,uint plane,uint point){return FiniteX87.Dot3PlusConstant(F(m,point),F(m,point+4),F(m,point+8),F(m,plane),F(m,plane+4),F(m,plane+8),F(m,plane+12));}
  // 0x5d9220: register ABI volume=EAX, point=ECX; low16 boolean only.
  // Plane products use PC x8764 precision, then one binary32 distance spill.
  public static ushort Contains(SoundSetupImage m,uint volume,uint point){uint count=m.Byte(volume+14);if(count==0)return 1;uint planes=m.Word(volume+4);for(uint i=0;i<count;i++)if(Distance(m,unchecked(planes+i*16),point)>0)return 0;return 1;}
  // 0x5d9290: null-safe low16 count accessor, independent of the signed32 query loop count.
  public static ushort Count(SoundSetupImage m,uint scene){return scene==0?(ushort)0:m.Half(unchecked(scene+0x74));}
  static uint Volume(SoundSetupImage m,uint scene,short index){return unchecked(m.Word(scene+0x78)+(uint)(int)index*24);}
  // 0x5d92b0: low16 scene ID; finite readable geometry, at most six matched volumes.
  // Up to six matches occupy the original12-byte temporary buffer. A seventh
  // match overwrites the original return address and is outside this memory projection.
  // Actual debug child5c12e0 is a one-byte RET with no observable effect here.
  public static ushort Select(SoundSetupImage m,uint scene,uint point){unchecked{
   if(scene==0||point==0)return 0xffff;short first=0,second=0,matches=0;int count=(int)m.Word(scene+0x74);
   for(int i=0;i<count;i++){
    if(Contains(m,Volume(m,scene,(short)i),point)==0)continue;
    uint a=Volume(m,scene,first),b=Volume(m,scene,second);
    if(matches==2){if(m.Byte(a+0x14)<m.Byte(b+0x14))first=(short)i;else second=(short)i;}
    if(matches==0)first=(short)i;else if(matches==1)second=(short)i;
    matches++;if(matches==2&&(m.Byte(a+0x10)&1)==0&&(m.Byte(b+0x10)&1)==0)break;
   }
   if(matches==0)return 0xffff;if(matches==1)return (ushort)first;
   uint va=Volume(m,scene,first);int na=m.Byte(va+15);if(na==0)return 0xffff;uint list=m.Word(va+8),vb=Volume(m,scene,second);int nb=m.Byte(vb+15);
   for(int i=0;i<na;i++){
    ushort planeId=m.Half(list+(uint)i*2);bool common=false;for(int j=0;j<nb;j++)if(planeId==m.Half(m.Word(vb+8)+(uint)j*2)){common=true;break;}if(!common)continue;
    uint plane=m.Word(scene+0x70)+(uint)(int)(short)planeId*32;return m.Half(plane+(Distance(m,plane,point)<0?0x16u:0x18u));
   }
   return 0xffff;
  }}
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> fallback){return address==0x5d92b0?Select(m,args[0],args[1]):fallback(m,address,args);}
 }
}
