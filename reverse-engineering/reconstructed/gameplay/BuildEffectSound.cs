using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class EffectSoundEntry {public string Name;public short Next=-1;}
 public sealed class EffectSoundRegistry
 {
  public uint[] HashTable;
  public short[] Heads;
  public EffectSoundEntry[] Entries;
 }
 public sealed class BuildEffectSoundState {public float[] Velocity;public uint[] PositionWords;}
 public sealed class BuildEffectSoundWorld
 {
  public uint CooldownWord;
  public float[] Sine;
  public EffectSoundRegistry Sounds;
  public Action<int,uint[],float,float> Play;
 }
 public static class BuildEffectSound
 {
  //0x650430: ASCII fold before table-driven32-bit hash. Empty input needs no table.
  public static uint Hash(EffectSoundRegistry registry,string name)
  {
   if(name==null)throw new ArgumentNullException("name");name=SceneryText.C(name);uint value=0;
   foreach(char raw in name)
   {
    if(raw>127)throw new ArgumentException("Non-ASCII signed-byte hash indexing is outside this contract.");
    uint c=raw>='a'&&raw<='z'?(uint)raw-32:(uint)raw;int index=(int)(c^(value>>24));
    if(registry.HashTable==null||registry.HashTable.Length<=index)throw new ArgumentException("Missing sound hash table.");
    value=unchecked((value<<8)^registry.HashTable[index]);
   }
   return value;
  }
  static bool Equal32(string a,string b)
  {
   if(a==null||b==null)return false;a=SceneryText.C(a);b=SceneryText.C(b);
   for(int i=0;i<32;i++)
   {
    char ca=i<a.Length?a[i]:'\0',cb=i<b.Length?b[i]:'\0';
    if(ca>127||cb>127)throw new ArgumentException("ASCII sound names required.");
    if(ca>='a'&&ca<='z')ca=(char)(ca-32);if(cb>='a'&&cb<='z')cb=(char)(cb-32);
    if(ca!=cb)return false;if(ca=='\0')return true;
   }
   return true;
  }
  //0x650dc0: signed-short bucket/chain indices and first32-byte casefold match.
  public static int Find(EffectSoundRegistry registry,string name)
  {
   if(name==null||registry.Heads==null)return -1;int bucket=(int)(Hash(registry,name)&255);
   if(bucket>=registry.Heads.Length)throw new ArgumentException("Missing sound bucket backing.");
   int index=registry.Heads[bucket];
   while(index!=-1)
   {
    if(index<0||registry.Entries==null||index>=registry.Entries.Length)throw new ArgumentException("Invalid sound chain backing.");
    EffectSoundEntry entry=registry.Entries[index];if(Equal32(name,entry.Name))return index;index=entry.Next;
   }
   return -1;
  }
  //0x5c0240: finite float input; negative values clamp to positive0.
  public static float SquareRoot(float value)
  {if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite square-root input required.");return value<0?0:(float)Math.Sqrt(value);}
  //0x5bec80: x87(y*y+x*x)+z*z, explicit float store before the root.
  public static float Length(float[] vector)
  {
   if(vector==null||vector.Length<3)throw new ArgumentException("Missing effect velocity.");
   PlaybackWide x=PlaybackWide.From(vector[0]),y=PlaybackWide.From(vector[1]),z=PlaybackWide.From(vector[2]);
   float squared=PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(y,y),PlaybackWide.Multiply(x,x)),PlaybackWide.Multiply(z,z)).Store();return SquareRoot(squared);
  }
  //0x681eb0: fourth playback parameter is always1.
  public static void Play(BuildEffectSoundWorld world,int id,uint[] position,float volume){world.Play(id,position,volume,1);}
  //0x571ba0: zero/negative cooldown, nonzero speed, sine-index volume and reset.
  public static void OnBuildEffect(BuildEffectSoundWorld world,BuildEffectSoundState effect)
  {
   float cooldown=BitConverter.ToSingle(BitConverter.GetBytes(world.CooldownWord),0);if(!(cooldown<=0))return;
   float speed=Length(effect.Velocity);if(!(speed>0))return;float clamped=speed>1?1:speed;
   PlaybackWide scale=PlaybackWide.FromDouble(16384),oneMinus=PlaybackWide.Add(PlaybackWide.FromDouble(1),PlaybackWide.From(-clamped));
   int converted=PlaybackWide.Add(PlaybackWide.Multiply(oneMinus,scale),scale).TruncateInt32(),index=(converted>>1)&32767;
   if(world.Sine==null||world.Sine.Length<=index)throw new ArgumentException("Missing original sine table.");
   float volume=world.Sine[index];int sound=Find(world.Sounds,"LegoSingle");Play(world,sound,effect.PositionWords,volume);world.CooldownWord=0x3dcccccd;
  }
 }
}
