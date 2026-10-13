using System;
using System.Collections.Generic;
namespace Recovered.Gameplay {
 public static class PublishedSplineCatalog {
  static string Text(SoundSetupImage m,uint p){if(p==0)return null;string text="";for(byte v=m.Byte(p);v!=0;v=m.Byte(++p))text+=(char)v;return text;}
  static RandomSplineWorld Scene(SoundSetupImage m,uint scene){RandomSplineWorld w=new RandomSplineWorld();w.HasScene=scene!=0;if(scene==0)return w;
   int count=unchecked((int)m.Word(scene+0x30));uint records=m.Word(scene+0x34);
   for(int i=0;i<count;i++){uint at=unchecked(records+(uint)i*12);w.Splines.Add(new SelectedSplineRecord{Address=at,Flags=m.Half(at),Name=Text(m,m.Word(at+4))});}return w;
  }
  // 0x5b2110: external SPL catalog wins; original5d0690 is the scene fallback.
  public static uint Find(SoundSetupImage m,uint scene,uint query){
   string name=Text(m,query);uint catalog=m.Word(SplineResourceLoading.Base);int count=unchecked((int)m.Word(SplineResourceLoading.Count));
   if(catalog!=0)for(int i=0;i<count;i++){uint at=unchecked(catalog+(uint)i*12);if(name!=null&&SceneryText.Equal(Text(m,m.Word(at+4)),name))return at;}
   SelectedSplineRecord match=RandomSplineSelection.Find(Scene(m,scene),name);return match==null?0:match.Address;
  }
  // 0x5b21f0: published entries precede scene entries; duplicate names/pointers retain their weight.
  public static int FindPrefix(SoundSetupImage m,uint scene,uint query,uint output,int capacity){
   if(capacity<1)return 0;string name=Text(m,query);uint catalog=m.Word(SplineResourceLoading.Base);int count=unchecked((int)m.Word(SplineResourceLoading.Count));int written=0;
   if(catalog!=0)for(int i=0;i<count;i++){uint at=unchecked(catalog+(uint)i*12);if(RandomSplineSelection.Compare(name,Text(m,m.Word(at+4)),-1)==0){m.Word(output+(uint)written*4,at);if(++written>=capacity)return written;}}
   List<SelectedSplineRecord> matches=new List<SelectedSplineRecord>();RandomSplineSelection.FindPrefix(Scene(m,scene),name,matches,capacity-written);
   foreach(SelectedSplineRecord record in matches)m.Word(output+(uint)(written++)*4,record.Address);return written;
  }
  static int Fold(char c){return c>='a'&&c<='z'?c-32:c;}
  // ASCII projection of4f8a70: empty haystack never matches, even an empty needle.
  static bool Contains(string haystack,string needle){if(needle==null||haystack==null)throw new ArgumentException("Native substring operands must be readable.");
   for(int i=0;i<haystack.Length;i++){int j=0;while(j<needle.Length&&i+j<haystack.Length&&Fold(haystack[i+j])==Fold(needle[j]))j++;if(j==needle.Length)return true;}return false;
  }
  // 0x5b22a0: case-folded substring search, same published-first capacity/order.
  public static int FindContaining(SoundSetupImage m,uint scene,uint query,uint output,int capacity){
   if(capacity<1)return 0;string name=Text(m,query);uint catalog=m.Word(SplineResourceLoading.Base);int count=unchecked((int)m.Word(SplineResourceLoading.Count));int written=0;
   if(catalog!=0)for(int i=0;i<count;i++){uint at=unchecked(catalog+(uint)i*12);if(Contains(Text(m,m.Word(at+4)),name)){m.Word(output+(uint)written*4,at);if(++written>=capacity)return written;}}
   if(scene!=0){count=unchecked((int)m.Word(scene+0x30));uint records=m.Word(scene+0x34);for(int i=0;i<count;i++){uint at=unchecked(records+(uint)i*12);if(Contains(Text(m,m.Word(at+4)),name)){m.Word(output+(uint)written*4,at);if(++written>=capacity)return written;}}}return written;
  }
 }
}
