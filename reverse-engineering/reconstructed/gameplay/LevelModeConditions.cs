using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class MissionModeState {public byte Enabled1d;public object Mission4;}
 public sealed class LevelModeWorld
 {
  public MissionModeState CurrentMission;
  public int MiniCut855de0,SecondaryMiniCut9514e4;
  public short HubArea87b460;
  public bool ChapterPresent;
  public byte ChapterCount;
  public short[] ChapterLevelIds;
  public readonly List<string> LevelNames=new List<string>();
  public readonly List<uint> VisitedFlags=new List<uint>();
 }
 public static class LevelModeConditions
 {
  static readonly string[] HubNames={"MAINROOM","EPISODE1","EPISODE2","EPISODE3","EPISODE4","EPISODE5","EPISODE6","JUNKYARD","BONUS","BOUNTY"};
  //0x58a900: null explicit state selects global9553d4.
  public static object ResolveMission(LevelModeWorld world,MissionModeState explicitState)
  {MissionModeState state=explicitState??world.CurrentMission;return state==null||state.Enabled1d==0?null:state.Mission4;}
  //0x442aa0.
  public static float MissionMode(LevelModeWorld world){return ResolveMission(world,null)!=null?1f:0f;}
  //0x442bb0: fourth condition argument gates secondary mini-cut global.
  public static float InMiniCut(LevelModeWorld world,bool fourthArgumentPresent){return world.MiniCut855de0!=0||(fourthArgumentPresent&&world.SecondaryMiniCut9514e4!=0)?1f:0f;}
  //0x491b30: fixed native table7fab24, ten case-insensitive names.
  public static int BindHubArea(string name)
  {if(name==null)return -1;name=SceneryText.C(name);for(int i=0;i<HubNames.Length;i++)if(SceneryText.Equal(name,HubNames[i]))return i;return -1;}
  //0x491b70: sign-extended 16-bit global compared to full32-bit bound.
  public static float InHubArea(LevelModeWorld world,int bound){return world.HubArea87b460==bound?1f:0f;}
  //0x442320: chapter-local ordinal, not global level index.
  public static int BindVisitedLevel(LevelModeWorld world,bool systemPresent,string name)
  {
   if(name==null||!systemPresent||!world.ChapterPresent)return -1;name=SceneryText.C(name);
   for(int i=0;i<world.ChapterCount;i++)
   {
    if(world.ChapterLevelIds==null||i>=world.ChapterLevelIds.Length)throw new ArgumentException("Native chapter list requires readable backing.");int index=world.ChapterLevelIds[i];
    if(index<0||index>=world.LevelNames.Count||world.LevelNames[index]==null)throw new ArgumentException("Native inline level name requires readable backing.");
    if(SceneryText.Equal(name,SceneryText.C(world.LevelNames[index])))return i;
   }
   return -1;
  }
  //0x4423b0: saved chapter-local record stride2e28, DWORD+2800 bit0.
  public static float BeenToLevel(LevelModeWorld world,int bound)
  {if(bound==-1)return 0;if(bound<0||bound>=world.VisitedFlags.Count)throw new ArgumentException("Native save-record read requires backing.");return(world.VisitedFlags[bound]&1)!=0?1f:0f;}
 }
}
