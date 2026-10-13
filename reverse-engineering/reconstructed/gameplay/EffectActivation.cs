using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class EffectActivationEntry
 {
  public string Name;
  public byte Group,Activation;
 }
 public sealed class EffectDisabledNames
 {
  public readonly byte[] Bytes;
  public EffectDisabledNames(byte[] bytes){if(bytes==null||bytes.Length!=192)throw new ArgumentException("Expected12 fixed16-byte slots.");Bytes=bytes;}
  public string Name(int slot)
  {
   int start=slot*16,end=start;while(end<start+16&&Bytes[end]!=0)end++;
   if(end==start+16)throw new ArgumentException("Native save slot must be terminated.");
   char[] chars=new char[end-start];for(int i=0;i<chars.Length;i++)chars[i]=(char)Bytes[start+i];return new string(chars);
  }
 }
 public sealed class EffectActivationWorld
 {
  public readonly List<EffectActivationEntry> Entries=new List<EffectActivationEntry>();
  public int Count;
  public readonly bool[] LoadedGroups=new bool[8];
  public byte CurrentGroup;
  public EffectDisabledNames Disabled;
 }
 public static class EffectActivation
 {
  //0x658490: skip reserved index0, prefer current loaded group, then0/1.
  public static int Find(EffectActivationWorld world,string name,byte group)
  {
   if(name==null)return -1;name=SceneryText.C(name);
   if(group<8&&world.LoadedGroups[group])for(int i=1;i<world.Count;i++)
   {EffectActivationEntry e=world.Entries[i];if(e!=null&&e.Group==group&&SceneryText.Equal(SceneryText.C(e.Name),name))return i;}
   for(int i=1;i<world.Count;i++)
   {EffectActivationEntry e=world.Entries[i];if(e!=null&&e.Group<2&&world.LoadedGroups[e.Group]&&SceneryText.Equal(SceneryText.C(e.Name),name))return i;}
   return -1;
  }
  //0x655340/0x655320. Existing emitter state byte+2f, no allocation here.
  public static void Enable(EffectActivationWorld world,int index){if(index!=-1)world.Entries[index].Activation=2;}
  public static void Disable(EffectActivationWorld world,int index){if(index!=-1)world.Entries[index].Activation=0;}
  //0x5a8280.
  public static void Set(EffectActivationWorld world,string name,bool enabled)
  {int index=Find(world,name,world.CurrentGroup);if(index!=-1){if(enabled)Enable(world,index);else Disable(world,index);}}
  //0x48a060. Removal clears only byte0; writes preserve unused slot padding.
  public static int SaveDisabled(EffectDisabledNames record,string name,bool enabled)
  {
   if(record==null||name==null)return 0;name=SceneryText.C(name);MessageNumbers.RequireAscii(name);if(name.Length>=16)return 0;
   for(int i=0;i<12;i++)if(SceneryText.Equal(record.Name(i),name)){if(enabled){record.Bytes[i*16]=0;return 2;}return 3;}
   if(enabled)return 0;
   for(int i=0;i<12;i++)if(record.Bytes[i*16]==0){for(int j=0;j<name.Length;j++)record.Bytes[i*16+j]=(byte)name[j];record.Bytes[i*16+name.Length]=0;break;}
   return 1;
  }
  //0x464360: last effect substring wins; any whole FALSE token latchesoff.
  public static void Activate(EffectActivationWorld world,string[] tokens)
  {
   string name=null;bool enabled=true;
   foreach(string raw in tokens)
   {
    string text=SceneryText.C(raw);int at=text.IndexOf("effect",StringComparison.OrdinalIgnoreCase);
    if(at>=0){if(at+7>text.Length)throw new ArgumentException("Effect operand extends past terminator.");name=text.Substring(at+7);}
    else if(SceneryText.Equal(text,"FALSE"))enabled=false;
   }
   if(name!=null){Set(world,name,enabled);SaveDisabled(world.Disabled,name,enabled);}
  }
 }
}
