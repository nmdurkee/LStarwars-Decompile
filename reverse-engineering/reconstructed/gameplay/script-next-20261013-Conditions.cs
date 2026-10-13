// Original PC SCP predicates; exact evidence in script-next-20261013-contract.json.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class NextScriptPlaybackGroup { public int State0c; }
 public sealed class NextScriptForceTarget { public uint FlagsA0; public bool HasUser3c; public NextScriptPlaybackGroup Group28; }
 public sealed class NextScriptActor { public sbyte Context7b5; public uint DefinitionFlags4,ClassFlags90,ClassFlags94; }
 public sealed class NextScriptReference { public NextScriptActor WorldObject; }
 public sealed class NextScriptCreature { public uint Flags1e8; public NextScriptReference SelfD0,OpponentE4; }
 public sealed class NextScriptCategory { public string Name; public uint DefinitionMask,ClassMask; }
 public sealed class NextScriptHint { public short Id; public byte Complete14; public float Timer18; }
 public sealed class NextScriptConditionWorld
 {
  // Required only for named Force target initialization. Host composes already
  // recovered registry lookup 0x55a020 and registry-record first-pointer binding.
  public Func<int,string,NextScriptForceTarget> ResolveForceTarget;
  public int ForceType;
  public NextScriptActor PrimaryPlayer;
  public bool CategoryTablePresent=true;
  public int CategoryCount;
  public readonly List<NextScriptCategory> Categories=new List<NextScriptCategory>();
  // Null = absent native global 0x9514b4. Prepared lists terminate with Id -1.
  public List<NextScriptHint> Hints;
  public short? ActiveHintId;
  // Reads dword presence at native [[0x926c20] + id*4]; allocation/population external.
  public Func<int,bool> HintRegistered;
 }
 public static class NextScriptConditions
 {
  static string C(string s)
  {if(s==null)return null;int zero=s.IndexOf('\0');if(zero>=0)s=s.Substring(0,zero);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native names must be ASCII.");return s;}
  static bool Equal(string a,string b){return a!=null&&b!=null&&String.Equals(C(a),C(b),StringComparison.OrdinalIgnoreCase);}
  // 0x440df0: threat status bit belongs to the script creature.
  public static float OpponentIsAThreat(NextScriptCreature creature)
  {return creature!=null&&(creature.Flags1e8&0x800u)!=0?1f:0f;}
  // 0x440ff0 and 0x441570 share this bounded named initializer behavior.
  public static NextScriptForceTarget BindForceTarget(NextScriptConditionWorld world,string operand)
  {if(world==null)throw new ArgumentNullException("world");operand=C(operand);return operand==null||world.ResolveForceTarget==null?null:world.ResolveForceTarget(world.ForceType,operand);}
  // 0x441300: flags bit or user-link pointer presence; no actor/player test.
  public static float ForceBeingUsed(NextScriptForceTarget bound)
  {return bound!=null&&((bound.FlagsA0&0x200000u)!=0||bound.HasUser3c)?1f:0f;}
  // 0x4415c0 / 0x467860; differs from the more restrictive ForceComplete.
  public static bool IsForcePlaybackFinished(NextScriptForceTarget bound)
  {return bound==null||bound.Group28==null||bound.Group28.State0c==((bound.FlagsA0&0x40u)!=0?0:2);}
  public static float ForceFinished(NextScriptForceTarget bound)
  {return bound!=null&&IsForcePlaybackFinished(bound)?1f:0f;}
  // 0x440c00 and 0x55bc20: table/system/name gates and first matching row.
  public static int BindPlayerCategory(NextScriptConditionWorld world,bool systemPresent,string operand)
  {
   if(world==null)throw new ArgumentNullException("world");operand=C(operand);if(!systemPresent||operand==null||!world.CategoryTablePresent)return -1;
   for(int i=0;i<world.CategoryCount;i++){if(i>=world.Categories.Count)throw new ArgumentException("Missing category row.");if(Equal(world.Categories[i].Name,operand))return i;}return -1;
  }
  // 0x440c70 / 0x55bc80: definition bit8 additionally excludes class flag8000.
  public static float PlayerCategoryIs(NextScriptConditionWorld world,int initialized)
  {
   if(world==null)throw new ArgumentNullException("world");if(initialized==-1||world.PrimaryPlayer==null)return 0f;
   if(initialized<0||initialized>=world.CategoryCount)return 0f;
   if(!world.CategoryTablePresent||initialized>=world.Categories.Count)throw new ArgumentException("Native category backing required.");
   NextScriptCategory row=world.Categories[initialized];NextScriptActor actor=world.PrimaryPlayer;uint mask=row.DefinitionMask;
   if(mask!=0&&(((mask&8)!=0&&(actor.ClassFlags94&0x8000u)!=0)||(actor.DefinitionFlags4&mask)!=mask))return 0f;
   return(actor.ClassFlags90&row.ClassMask)==row.ClassMask?1f:0f;
  }
  // 0x442060: unknown/missing names select context100, rather than failure.
  public static int BindContext(string operand)
  {
   operand=C(operand);string[] names={"DEACTIVATED","FORCEDBACK","GRAB","EAT","FORCEPUSHED","FORCEPUSH","GETIN","BALLOONING","STUNNED","FLOAT","GRAPPLE"};
   int[] values={23,34,56,63,28,27,60,93,90,75,70};for(int i=0;i<names.Length;i++)if(Equal(operand,names[i]))return values[i];return 100;
  }
  // 0x442180: guarded self-reference/object, signed byte compared to full int.
  public static float InContext(NextScriptCreature creature,int initialized)
  {return creature!=null&&creature.SelfD0!=null&&creature.SelfD0.WorldObject!=null&&creature.SelfD0.WorldObject.Context7b5==initialized?1f:0f;}
  // 0x4421b0 lacks the self-reader's world-object null check.
  public static float OpponentContext(NextScriptCreature creature,int initialized)
  {
   if(creature==null||creature.OpponentE4==null)return 0f;if(creature.OpponentE4.WorldObject==null)throw new ArgumentException("Native OpponentContext requires a nonnull referenced world object.");
   return creature.OpponentE4.WorldObject.Context7b5==initialized?1f:0f;
  }
  // 0x442a20: native decimal prefix parser wraps int32; null initializes0.
  public static int BindHint(string operand)
  {
   operand=C(operand);if(operand==null)return 0;int i=0,value=0;bool neg=operand.Length!=0&&operand[0]=='-';if(neg)i++;
   unchecked {while(i<operand.Length&&operand[i]>='0'&&operand[i]<='9'){value=value*10+operand[i]-'0';i++;}if(neg)value=-value;}return value;
  }
  // 0x576480: signed-short IDs, first match, terminator-1.
  public static NextScriptHint FindHint(NextScriptConditionWorld world,int id)
  {
   if(world==null)throw new ArgumentNullException("world");if(world.Hints==null)return null;
   foreach(NextScriptHint record in world.Hints){if(record.Id==-1)return null;if(record.Id==id)return record;}
   throw new ArgumentException("Prepared native hint list needs a -1 terminator.");
  }
  // 0x5764b0: x87 parity branch accepts unordered NaN timer as well as<=0.
  public static bool IsHintAvailable(NextScriptConditionWorld world,int id)
  {
   if(world==null)throw new ArgumentNullException("world");if((world.ActiveHintId.HasValue&&world.ActiveHintId.Value==id)||id<0)return false;
   if(world.HintRegistered==null)throw new InvalidOperationException("Native hint registration backing required.");if(!world.HintRegistered(id))return false;
   NextScriptHint record=FindHint(world,id);return record!=null&&record.Complete14==0&&(record.Timer18<=0f||Single.IsNaN(record.Timer18));
  }
  // 0x576500 returns the entire unsigned completion byte, not merely a boolean.
  public static byte ReadHintComplete(NextScriptConditionWorld world,int id)
  {NextScriptHint record=FindHint(world,id);return record==null?(byte)0:record.Complete14;}
  // SCP wrappers add id!=0, so helper ID0 behavior must not be promoted to commands.
  public static float HintAvailable(NextScriptConditionWorld world,int initialized)
  {return initialized!=0&&IsHintAvailable(world,initialized)?1f:0f;}
  public static float HintComplete(NextScriptConditionWorld world,int initialized)
  {return initialized!=0&&ReadHintComplete(world,initialized)!=0?1f:0f;}
 }
}
