using System;
namespace Recovered.Gameplay {
 public static class ParLoadedAssets {
  static sbyte Fold(byte value){if((byte)(value+0x9f)<26||value>0xdf)value=unchecked((byte)(value-32));return unchecked((sbyte)value);}
  static bool Equal(SoundSetupImage m,uint record,byte[] query){for(uint i=0;;i++){sbyte a=Fold(m.Byte(record+i)),b=Fold(query[i]);if(a!=b)return false;if(a==0||b==0)return true;}}
  static bool Active(SoundSetupImage m,int group){return m.Word(unchecked(0x2924b10u+(uint)(group*4)))!=0;}
  // Original 0x658330/0x658490 binding semantics; these entries are already mapped elsewhere.
  public static uint Particle(SoundSetupImage m,byte[] query,uint preferred,bool fast,int excluded){unchecked{
   if(query==null)return 0xffffffff;byte wanted=(byte)preferred;
   for(int pass=0;pass<(fast?2:3);pass++){
    if(pass==0&&(wanted>=8||!Active(m,wanted)))continue;
    for(int i=1;i<(int)m.Word(0x2962098);i++){
     if(!fast&&i==excluded)continue;uint record=m.Word(m.Word(0x296209c)+(uint)i*4);if(record==0)continue;byte group=m.Byte(record+17);
     bool eligible=pass==0?group==wanted:pass==1?(group==0||group==1)&&Active(m,group):Active(m,(sbyte)group);
     if(eligible&&Equal(m,record,query))return (uint)i;
    }
   }return 0xffffffff;
  }}
  static int Length(byte[] value){int i=0;while(value[i]!=0)i++;return i;}
  // 0x4f8b80 composition: null precedence, dynamic -1/-2 lengths and signed full-byte folding.
  public static int Compare(SoundSetupImage m,byte[] query,uint name,int length){
   if(query==null)return -1;if(name==0)return 1;if(length==0)return 0;
   int remaining=length;if(length==-1)remaining=Length(query);else if(length==-2){remaining=0;while(m.Byte(name+(uint)remaining)!=0)remaining++;}
   uint i=0;do{sbyte a=Fold(query[i]),b=Fold(m.Byte(name+i));if(a>b)return 1;if(a<b)return -1;i++;remaining--;if(a==0||b==0)return 0;}while(remaining!=0);return 0;
  }
  // 0x650e40: every one of the 1600 name-pointer rows is eligible; missing diagnostic is a native RET-only no-op.
  public static uint Sound(SoundSetupImage m,byte[] query,int length){unchecked{
   for(uint i=0;i<1600;i++)if(Compare(m,query,m.Word(m.Word(0x2947b74)+i*64),length)==0)return i;return 0xffffffff;
  }}
 }
 public sealed class ParLoadedAssetBindings:IParRecordBindings {
  public readonly SoundSetupImage Image;public ParLoadedAssetBindings(SoundSetupImage image){Image=image;}
  public int Sprite(byte[] name,uint scene){return ParSpriteLookup.Find(Image,name,scene);}
  public uint Effect(byte[] name,uint bank,bool fast){return ParLoadedAssets.Particle(Image,name,bank,fast,0);}
  public uint Sound(byte[] name,int bound){return ParLoadedAssets.Sound(Image,name,bound);}
 }
}
