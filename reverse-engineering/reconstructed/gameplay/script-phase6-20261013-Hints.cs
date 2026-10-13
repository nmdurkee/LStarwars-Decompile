// Original PC hint request/activation producers with explicit prepared state.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class Phase6Hint
 {
  public short Id;
  public byte Flags2,Complete14;
  public uint Cooldown0cBits,Timer18Bits;
  public float Timer18{get{return BitConverter.ToSingle(BitConverter.GetBytes(Timer18Bits),0);}}
 }
 public sealed class Phase6HintWorld
 {
  public List<Phase6Hint> Records;
  public Phase6Hint Active;
  public Func<int,bool> Registered;
  public uint[] DoneWords;
  public int DoneWordCount;
  public uint PresentationC8Bits,PresentationCcBits;
  public byte LastVariantBd;
  public QRandom Random;
 }
 public static class Phase6HintCommands
 {
  static string C(string s)
  {if(s==null)return null;int z=s.IndexOf('\0');if(z>=0)s=s.Substring(0,z);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native operands must be ASCII.");return s;}
  // Shared original0x576480 ordered signed-short/sentinel list semantics.
  static Phase6Hint Find(Phase6HintWorld world,int id)
  {
   if(world.Records==null)return null;foreach(Phase6Hint row in world.Records){if(row.Id==-1)return null;if(row.Id==id)return row;}
   throw new ArgumentException("Prepared native hint list needs a -1 terminator.");
  }
  // 0x5766e0 marks first equal-ID ordinal, not target pointer identity.
  public static void MarkDone(Phase6HintWorld world,Phase6Hint target)
  {
   if(world==null)throw new ArgumentNullException("world");if(world.Records==null||world.DoneWords==null)return;
   int ordinal=0;foreach(Phase6Hint row in world.Records)
   {
    if(row.Id==-1)return;if(target==null)throw new ArgumentException("Native completion bitmap path dereferences a null target ID.");
    if(row.Id==target.Id)
    {
     int word=ordinal>>5;if(word<world.DoneWordCount){if(word>=world.DoneWords.Length)throw new ArgumentException("Missing native done-word backing.");world.DoneWords[word]|=1u<<(ordinal&31);}return;
    }
    ++ordinal;
   }
   throw new ArgumentException("Prepared native hint list needs a -1 terminator.");
  }
  // 0x576860: payload/timer/bitmap updates and original QRAND rejection loop.
  public static void Activate(Phase6HintWorld world,Phase6Hint target,bool forceDisplay,bool ignoreDone)
  {
   if(world==null)throw new ArgumentNullException("world");if(world.Active!=null&&Object.ReferenceEquals(world.Active,target))return;
   if(target==null){world.Active=null;return;}
   float timer=target.Timer18;
   if(!forceDisplay&&((target.Complete14!=0&&!ignoreDone)||!(timer<=0f||Single.IsNaN(timer))))return;
   world.PresentationC8Bits=0;world.PresentationCcBits=0;world.Active=target;
   if(!forceDisplay&&(target.Flags2&1)!=0){target.Complete14=1;MarkDone(world,target);}
   if(world.Random==null)throw new InvalidOperationException("Hint activation requires prepared shared QRAND state.");
   uint variant;do{variant=world.Random.Next()/16384u;}while(variant==world.LastVariantBd);
   world.LastVariantBd=(byte)variant;world.PresentationCcBits=0;target.Timer18Bits=target.Cooldown0cBits;
  }
  // 0x576910: active same-ID request is a no-op; unregistered/negative clears
  // only active pointer; registered but missing list ID preserves current hint.
  public static void Request(Phase6HintWorld world,int id,bool forceDisplay,bool ignoreDone)
  {
   if(world==null)throw new ArgumentNullException("world");if(world.Active!=null&&world.Active.Id==id)return;
   if(id<0){world.Active=null;return;}if(world.Registered==null)throw new InvalidOperationException("Prepared registration dword backing required.");
   if(!world.Registered(id)){world.Active=null;return;}Phase6Hint target=Find(world,id);if(target!=null)Activate(world,target,forceDisplay,ignoreDone);
  }
  // 0x44d470 searches substring'id' anywhere then skips three bytes. The key
  // is not restricted to'id='; ignore_done_flag only checked when id was absent.
  public static int SetHint(Phase6HintWorld world,ScriptPacket packet,string[] tokens,bool firstCall)
  {
   if(!firstCall)return 1;int id=-1;bool ignoreDone=false;
   foreach(string raw in tokens)
   {
    if(raw==null)throw new ArgumentException("Native SetHint substring matcher dereferences a null token.");string token=C(raw);int at=token.IndexOf("id",StringComparison.OrdinalIgnoreCase);
    if(at>=0)
    {
     if(at+3>token.Length)throw new ArgumentException("Native id+3 operand points beyond token terminator.");float number=MessageNumbers.Resolve(packet,token.Substring(at+3));
     if(Single.IsNaN(number)||Single.IsInfinity(number)||number<-2147483648f||number>=2147483648f)throw new ArgumentOutOfRangeException("tokens","Numeric conversion outside bounded finite int32 range.");id=(int)number;
    }
    else if(token!=null&&token.IndexOf("ignore_done_flag",StringComparison.OrdinalIgnoreCase)>=0)ignoreDone=true;
   }
   Request(world,id,false,ignoreDone);return 1;
  }
  public static int CurrentHintIdValue(Phase6HintWorld world)
  {if(world==null)throw new ArgumentNullException("world");return world.Active==null?-1:world.Active.Id;}
  public static float CurrentHintId(Phase6HintWorld world){return CurrentHintIdValue(world);}
 }
}
