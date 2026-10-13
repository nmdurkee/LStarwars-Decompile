using System;
using Recovered.Navigation;
namespace Recovered.Gameplay
{
 public sealed class PathConnectionFlagWorld
 {
  public bool HasWorld=true,HasLevelHeader=true,LevelHeaderActive=true;
  public readonly ConnectionWorld Navigation=new ConnectionWorld();
  public uint GoodiesFlag=0x80,BaddiesFlag=0x100;
 }
 public static class PathConnectionFlagCommands
 {
  static string Tail(string t,int at,int skip){if(at+skip>t.Length)throw new ArgumentException("Native skip exceeds token.");return t.Substring(at+skip);}
  //0x4505d0 composes recovered44d870 and51adf0 including mask-token ordering.
  public static bool Set(PathConnectionFlagWorld w,string[] tokens,bool first)
  {
   if(w==null||!w.HasWorld||!w.HasLevelHeader||!w.LevelHeaderActive||!first||tokens==null||tokens.Length==0)return true;
   uint on=0,opposite=0;bool both=false,enable=true;string from=null,to=null;
   foreach(string token in tokens)
   {
    MessageNumbers.RequireAscii(token);int at=token.IndexOf("from",StringComparison.OrdinalIgnoreCase);
    if(at>=0){from=Tail(token,at,5);continue;}
    at=token.IndexOf("to",StringComparison.OrdinalIgnoreCase);if(at>=0){to=Tail(token,at,3);continue;}
    uint flag=ConnectionFlags.Lookup(token,w.Navigation.FlagDialect,w.Navigation.BigJumpFlag,w.Navigation.RequiresPermissionFlag,w.Navigation.NoDestinationCheckFlag);
    if(flag==0)
    {
     if(String.Equals(token,"bothways",StringComparison.OrdinalIgnoreCase))both=true;
     else if(String.Equals(token,"FALSE",StringComparison.OrdinalIgnoreCase))enable=false;
    }
    else
    {
     on|=flag;
     if(flag==w.GoodiesFlag)opposite|=w.BaddiesFlag;
     else if(flag==w.BaddiesFlag)opposite|=w.GoodiesFlag;
     else if(flag==0x20000000)both=true;
    }
   }
   if(from==null||to==null)return true;
   byte direction=0;NavigationConnection edge=ConnectionControllers.FindConnection(w.Navigation.DefaultPath,from,to,ref direction);if(edge==null)return true;
   if(direction==0)edge.ForwardFlags=enable?(edge.ForwardFlags|on)&~opposite:edge.ForwardFlags&~on;
   else edge.ReverseFlags=enable?(edge.ReverseFlags|on)&~opposite:edge.ReverseFlags&~on;
   if(both)
   {
    if(direction==0)edge.ReverseFlags=enable?(edge.ReverseFlags|on)&~opposite:edge.ReverseFlags&~on;
    else edge.ForwardFlags=enable?(edge.ForwardFlags|on)&~opposite:edge.ForwardFlags&~on;
   }
   return true;
  }
 }
}
