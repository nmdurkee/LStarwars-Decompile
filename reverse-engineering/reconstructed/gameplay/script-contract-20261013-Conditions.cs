// Bounded PC script conditions. Reports/script-contract-20261013-contract.json.
// World fields and prepared scene/registry records are host-owned inputs.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class ScriptContractRigidAnimation { public float Frame4c; }
 public sealed class ScriptContractRigidAttachment { public ScriptContractRigidAnimation Animation48; }
 public sealed class ScriptContractRigidRecord { public string Name44; public ScriptContractRigidAttachment Attachment40; }
 public sealed class ScriptContractRigidScene
 {
  public bool RequiresIndexedResolver;
  public int Count;
  public readonly List<ScriptContractRigidRecord> Records=new List<ScriptContractRigidRecord>();
 }
 public sealed class ScriptContractBuildObject { public byte Completion6d; }
 public sealed class ScriptContractBuildReference { public ScriptContractBuildObject Target; }
 public sealed class ScriptContractBuildBucket
 {
  public int Count;
  public readonly List<ScriptContractBuildReference> Records=new List<ScriptContractBuildReference>();
 }
 public sealed class ScriptContractBuildRegistry
 {
  public int TypeCount;
  public Func<ScriptContractBuildReference,string>[] NameAccessors;
  public ScriptContractBuildBucket[] Buckets;
 }
 public sealed class ScriptContractCreature { public uint Flags1e8; }
 public sealed class ScriptContractPacket { public byte SetIdB0; }
 public sealed class ScriptContractConditionWorld
 {
  public int PartyUnderCoverValue;
  public ScriptContractRigidScene RigidScene;
  public ScriptContractBuildRegistry BuildRegistry;
  public int BuildTypeIndex;
  // Reads the native 0x876847+index byte. Allocation size and population are external.
  public Func<byte,byte> ReadAliveCount;
 }
 public static class ScriptContractConditions
 {
  static string C(string value)
  {
   if(value==null)return null;int end=value.IndexOf('\0');if(end>=0)value=value.Substring(0,end);
   foreach(char c in value)if(c>127)throw new ArgumentException("This bounded contract accepts ASCII native names.");return value;
  }
  static bool Equal(string a,string b){return a!=null&&b!=null&&String.Equals(C(a),C(b),StringComparison.OrdinalIgnoreCase);}
  // 0x442cf0 reads the complete global dword, rather than a single byte or bit.
  public static float PartyUnderCover(ScriptContractConditionWorld world)
  {if(world==null)throw new ArgumentNullException("world");return world.PartyUnderCoverValue!=0?1f:0f;}
  // 0x442dc0 reads the script-creature field, not a world-object flags field.
  public static float CannotReachDestination(ScriptContractCreature creature)
  {return creature!=null&&(creature.Flags1e8&0x400000u)!=0?1f:0f;}
  // 0x4425e0 composed with the static linear branch of 0x5cf5b0,
  // 0x5cfac0 and 0x5d0420. Dynamic/indexed scene resolution is outside scope.
  public static ScriptContractRigidAnimation BindRigidAnimFrame(ScriptContractConditionWorld world,string operand)
  {
   if(world==null)throw new ArgumentNullException("world");operand=C(operand);ScriptContractRigidScene scene=world.RigidScene;
   if(scene==null||operand==null)return null;
   if(scene.RequiresIndexedResolver)throw new InvalidOperationException("Native indexed/dynamic scene resolver is outside this contract.");
   for(int i=0;i<scene.Count;i++)
   {
    if(i>=scene.Records.Count)throw new ArgumentException("Missing prepared native rigid scene record.");
    ScriptContractRigidRecord record=scene.Records[i];
    if(Equal(operand,record.Name44))
    {
     if(record.Attachment40==null)throw new ArgumentException("Native matched rigid record requires a valid +0x40 attachment.");
     return record.Attachment40.Animation48;
    }
   }
   return null;
  }
  // 0x442630 deliberately returns one when initialization did not resolve an animation.
  public static float RigidAnimFrame(ScriptContractRigidAnimation initialized)
  {return initialized==null?1f:initialized.Frame4c;}
  static ScriptContractBuildReference ScanBuild(ScriptContractBuildRegistry registry,int type,string operand)
  {
   if(type>=registry.NameAccessors.Length||registry.Buckets==null||type>=registry.Buckets.Length)
    throw new ArgumentException("Prepared build registry lacks the native indexed bucket/type slot.");
   Func<ScriptContractBuildReference,string> accessor=registry.NameAccessors[type];if(accessor==null)return null;
   ScriptContractBuildBucket bucket=registry.Buckets[type];if(bucket==null)throw new ArgumentException("Missing prepared native build bucket.");
   for(int i=0;i<bucket.Count;i++)
   {
    if(i>=bucket.Records.Count)throw new ArgumentException("Missing prepared native build record.");
    ScriptContractBuildReference record=bucket.Records[i];if(Equal(accessor(record),operand))return record;
   }
   return null;
  }
  // 0x4415e0: registry world+0x2ac8 and type global 0x804e44 before
  // tail lookup 0x55a020. Native type==count takes the indexed path.
  public static ScriptContractBuildReference BindBuildItComplete(ScriptContractConditionWorld world,string operand)
  {
   if(world==null)throw new ArgumentNullException("world");operand=C(operand);ScriptContractBuildRegistry registry=world.BuildRegistry;
   if(registry==null||registry.NameAccessors==null||operand==null)return null;
   int type=world.BuildTypeIndex;
   if(type<0||registry.TypeCount<type)
   {
    for(int i=0;i<registry.TypeCount;i++){ScriptContractBuildReference found=ScanBuild(registry,i,operand);if(found!=null)return found;}return null;
   }
   return ScanBuild(registry,type,operand);
  }
  // 0x441610: the retained registry reference can acquire/lose its target later.
  public static float BuildItComplete(ScriptContractBuildReference initialized)
  {return initialized!=null&&initialized.Target!=null&&initialized.Target.Completion6d==2?1f:0f;}
  // Shared initializer 0x441f90, also already recovered for NumInSetAlive.
  public static int BindIsSetAlive(string operand)
  {
   operand=C(operand);if(operand==null)return 0;if(Equal(operand,"myset"))return -1;
   int i=0,v=0;bool negative=operand.Length!=0&&operand[0]=='-';if(negative)i++;
   unchecked {while(i<operand.Length&&operand[i]>='0'&&operand[i]<='9'){v=v*10+operand[i]-'0';i++;}if(negative)v=-v;}
   return v>=1&&v<=16?v:0;
  }
  // 0x441fd0: initialized -1 selects the packet's unchecked byte set ID.
  public static float IsSetAlive(ScriptContractConditionWorld world,ScriptContractPacket packet,int initializedSelector)
  {
   int index=initializedSelector;
   if(index==-1){if(packet==null)throw new ArgumentNullException("packet");index=packet.SetIdB0;}
   else if(index<0||index>16)throw new ArgumentOutOfRangeException("initializedSelector","Not produced by the bounded native initializer.");
   if(index==0)return 0f;if(world==null||world.ReadAliveCount==null)throw new InvalidOperationException("Alive-count read adapter required.");
   return world.ReadAliveCount((byte)index)!=0?1f:0f;
  }
 }
}
