using System;
namespace Recovered.Gameplay {
 public static class ParSpriteLookup {
  public static uint Count(SoundSetupImage m,uint scene){uint backend=m.Word(scene+0x110);return backend!=0?m.Word(backend+0x6c):m.Word(scene+0x24);}
  // Signed upper-bound comparisons; negative indices are accepted when readable prefix backing exists.
  public static void Build(SoundSetupImage m,uint destination,uint scene,int index){unchecked{
   if(scene!=0&&destination!=0){uint backend=m.Word(scene+0x110);if(backend!=0&&index<(int)m.Word(backend+0x6c)){m.Word(destination+4,0);m.Word(destination,scene);backend=m.Word(scene+0x110);m.Word(destination+8,(uint)index*208+m.Word(backend+0x70));return;}
    if(index<(int)m.Word(scene+0x24)){m.Word(destination,scene);uint pointer=(uint)index*76+m.Word(scene+0x28);m.Word(destination+8,0);m.Word(destination+4,pointer);return;}}
   m.Word(destination,0);m.Word(destination+4,0);m.Word(destination+8,0);
  }}
  public static uint Valid(SoundSetupImage m,uint handle){return handle!=0&&(m.Word(handle+4)!=0||m.Word(handle+8)!=0)?1u:0u;}
  public static uint Name(SoundSetupImage m,uint handle){if(handle==0)return 0;uint record=m.Word(handle+8);if(record!=0)return m.Word(record+180);record=m.Word(handle+4);return record!=0?m.Word(record+68):0;}
  static bool Equal(SoundSetupImage m,byte[] name,uint other){for(uint i=0;i<16;i++){byte a=name[i],b=m.Byte(other+i);if(a!=b)return false;if(a==0)return true;}return true;}
  static bool Special(byte[] name){byte[] marker=new byte[]{78,85,76,76,32,105,110,115,116,97,110,99,101,0};for(int i=0;i<marker.Length;i++)if(name[i]!=marker[i])return false;return true;}
  public static int Find(SoundSetupImage m,uint name,uint scene){byte[] bytes=new byte[16];for(uint i=0;i<16;i++)bytes[i]=m.Byte(name+i);return Find(m,bytes,scene);}
  // 0x6488e0. Exact case-sensitive 16-byte comparison, fixed initial count, first matching proxy.
  public static int Find(SoundSetupImage m,byte[] name,uint scene){unchecked{
   if(name[0]==0)return -1;if(Special(name))return 9999;if(scene==0)return -1;int count=(int)Count(m,scene);
   for(int i=0;i<count;i++){uint backend=m.Word(scene+0x110),legacy=0,modern=0;
    if(backend!=0&&i<(int)m.Word(backend+0x6c))modern=(uint)i*208+m.Word(backend+0x70);else if(i<(int)m.Word(scene+0x24))legacy=(uint)i*76+m.Word(scene+0x28);
    if(legacy==0&&modern==0)continue;uint pointer=modern!=0?m.Word(modern+180):m.Word(legacy+68);if(Equal(m,name,pointer))return i;
   }return -1;
  }}
 }
 public sealed class ParLoadedSpriteBindings:IParRecordBindings {
  public readonly SoundSetupImage Image;public readonly IParRecordBindings Other;
  public ParLoadedSpriteBindings(SoundSetupImage image,IParRecordBindings other){Image=image;Other=other;}
  public int Sprite(byte[] name,uint scene){return ParSpriteLookup.Find(Image,name,scene);}
  public uint Effect(byte[] name,uint bank,bool fast){return Other.Effect(name,bank,fast);}
  public uint Sound(byte[] name,int bound){return Other.Sound(name,bound);}
 }
}
