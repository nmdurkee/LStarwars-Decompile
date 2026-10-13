// Bounded original-PC perception, terrain and spline-setting handlers.
// Numeric expressions and loader-owned records have explicit projections.
using System;
namespace Recovered.Gameplay
{
 public enum PerceptionValue { ViewDistance=0, HearDistance=1, MaxViewHeight=2, MinViewHeight=3, MoveRadius=4 }
 public enum PerceptionFlag { IgnoreWallSplines, CheckWallSplines, NoTerrain, NoLosCheck, FlatTerrain, ShadowTerrain, DontUseShadowTerrain, BuiltinDontPush, CanSeeBehind, RequiresLOS, SetFullPathSearch, NoShadows }
 public sealed class PerceptionReference
 {
  public uint Flags1f8,Flags1fc;
  public short CharacterType;
  public float Radius;
  public readonly float[] Values=new float[4];
 }
 public sealed class PerceptionController
 {
  public PerceptionReference Reference;
  public uint Flags1e8;
  public byte TemplateIndex=255;
  public float MoveRadius;
 }
 public class PerceptionWorld
 {
  public float[][] Templates,CharacterDefinitions;
  public readonly bool[] DefaultCallbacks=new bool[]{true,true,true,true};
  public Func<PerceptionController,ScriptPacket,string,float> Evaluate;
  // 0x43c1a0/1c0/1e0/200: signed character -1 returns +0. Other
  // indices require valid loader records; no implicit out-of-range fallback.
  public virtual float CharacterDefault(int characterType,PerceptionValue kind)
  {
   if(characterType==-1)return 0;
   return CharacterDefinitions[characterType][(int)kind];
  }
 }
 public static class PerceptionCommands
 {
  static bool FalseToken(string[] tokens)
  {
   foreach(string raw in tokens){if(raw==null)throw new ArgumentNullException("tokens");if(SceneryText.Equal(SceneryText.C(raw),"false"))return true;}return false;
  }
  public static int SetFlag(PerceptionController controller,string[] tokens,bool firstCall,PerceptionFlag kind)
  {
   if(controller==null||!firstCall)return 1;
   bool own=kind==PerceptionFlag.IgnoreWallSplines||kind==PerceptionFlag.CheckWallSplines||kind==PerceptionFlag.RequiresLOS;
   if(!own&&controller.Reference==null)return 1;
   bool enable=!FalseToken(tokens);uint mask;
   switch(kind)
   {
    case PerceptionFlag.IgnoreWallSplines:mask=0x80;break;
    case PerceptionFlag.CheckWallSplines:mask=0x100;break;
    case PerceptionFlag.NoTerrain:mask=0x20;break;
    case PerceptionFlag.NoLosCheck:mask=0x400;break;
    case PerceptionFlag.FlatTerrain:mask=0x10;break;
    case PerceptionFlag.ShadowTerrain:mask=8;break;
    case PerceptionFlag.DontUseShadowTerrain:mask=0x40;break;
    case PerceptionFlag.BuiltinDontPush:mask=2;break;
    case PerceptionFlag.CanSeeBehind:mask=0x800;break;
    case PerceptionFlag.RequiresLOS:mask=0x20000;break;
    case PerceptionFlag.SetFullPathSearch:mask=0x80000;enable=!enable;break;
    case PerceptionFlag.NoShadows:mask=0x2000;break;
    default:throw new ArgumentOutOfRangeException("kind");
   }
   if(own){controller.Flags1e8=(controller.Flags1e8&~mask)|(enable?mask:0);if(kind==PerceptionFlag.CheckWallSplines&&enable)controller.Flags1e8|=0x80;}
   else if(kind==PerceptionFlag.NoShadows)controller.Reference.Flags1f8=(controller.Reference.Flags1f8&~mask)|(enable?mask:0);
   else controller.Reference.Flags1fc=(controller.Reference.Flags1fc&~mask)|(enable?mask:0);
   return 1;
  }
  public static int SetValue(PerceptionWorld world,PerceptionController controller,ScriptPacket packet,string[] tokens,bool firstCall,PerceptionValue kind)
  {
   if(controller==null||controller.Reference==null||!firstCall)return 1;
   if(kind==PerceptionValue.MoveRadius)controller.MoveRadius=(float)((double)controller.Reference.Radius*2);
   else
   {
    int field=(int)kind;
    controller.Reference.Values[field]=controller.TemplateIndex==255?(world.DefaultCallbacks[field]?world.CharacterDefault(controller.Reference.CharacterType,kind):1):world.Templates[controller.TemplateIndex][field];
   }
   if(tokens.Length!=0&&!SceneryText.Equal(SceneryText.C(tokens[0]),"default"))
   {
    if(world.Evaluate==null)throw new InvalidOperationException("Numeric expression resolver required.");
    float value=world.Evaluate(controller,packet,SceneryText.C(tokens[0]));
    if(kind==PerceptionValue.MoveRadius)controller.MoveRadius=value;else controller.Reference.Values[(int)kind]=value;
   }
   return 1;
  }
 }
}
