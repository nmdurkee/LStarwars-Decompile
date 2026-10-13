using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class SelectedSplineRecord
 {
  public uint Address;public string Name;public ushort Flags;
 }
 public sealed class RandomSplineWorld
 {
  public bool HasWorldPointer=true,HasScene=true;
  public readonly List<SelectedSplineRecord> Splines=new List<SelectedSplineRecord>();
  public readonly List<PcObjectImage> Actors=new List<PcObjectImage>();
  public readonly QRandom Random=new QRandom();
  public SelectedSplineRecord Selected;
  public Func<uint,SelectedSplineRecord> ResolveAttachedSpline;
 }
 public static class RandomSplineSelection
 {
  static string C(string s){if(s==null)return null;MessageNumbers.RequireAscii(s);int at=s.IndexOf('\0');return at<0?s:s.Substring(0,at);}
  static int Fold(char c){return c>='a'&&c<='z'?c-32:c;}
  //0x4f8b80 bounded ASCII pointer projection, includes length0/-1/-2 and null precedence.
  public static int Compare(string a,string b,int length)
  {
   if(a==null)return -1;if(b==null)return 1;a=C(a);b=C(b);if(length==0)return 0;
   int count=length==-1?a.Length:length==-2?b.Length:length;
   int i=0;
   do
   {
    int x=Fold(i<a.Length?a[i]:'\0'),y=Fold(i<b.Length?b[i]:'\0');if(y<x)return 1;if(x<y)return -1;
    i++;count--;if(x==0||y==0)return 0;
   }while(count!=0);
   return 0;
  }
  //0x5d0690: first exact case-folded match in signed-count scene table.
  public static SelectedSplineRecord Find(RandomSplineWorld w,string name)
  {
   if(w==null||!w.HasScene)return null;
   foreach(SelectedSplineRecord s in w.Splines)if(Compare(name,s.Name,-2)==0&&C(name).Length==C(s.Name).Length)return s;
   return null;
  }
  //0x5d0740: strlen(pattern) prefix, not wildcard matching. Empty pattern compares one NUL.
  public static int FindPrefix(RandomSplineWorld w,string name,List<SelectedSplineRecord> output,int capacity)
  {
   if(capacity<=0||w==null||!w.HasScene)return 0;int count=0;
   foreach(SelectedSplineRecord s in w.Splines)if(Compare(name,s.Name,-1)==0){output.Add(s);count++;if(count>=capacity)break;}
   return count;
  }
  static SelectedSplineRecord Attached(RandomSplineWorld w,PcObjectImage actor)
  {
   uint id=actor.U32(0xe64);if(id==0)return null;
   if(w.ResolveAttachedSpline!=null)return w.ResolveAttachedSpline(id);
   foreach(SelectedSplineRecord s in w.Splines)if(s.Address==id)return s;
   throw new InvalidOperationException("Native attached spline pointer required.");
  }
  static bool Eligible(PcObjectImage a){uint f=a.U32(0x1fc);return(f&1)!=0&&(f&0x1000)!=0&&a.U8(0x28b)==0&&a.U32(0xe64)!=0;}
  static string Tail(string t,int at,int skip){if(at+skip>t.Length)throw new ArgumentException("Native skip exceeds terminator.");return t.Substring(at+skip);}
  //0x449f70. Duplicate candidates remain weighted; selection always resets on firstCall.
  public static bool Select(RandomSplineWorld w,string[] tokens,bool first)
  {
   if(!first)return true;w.Selected=null;if(tokens==null||tokens.Length==0)return true;
   bool unused=false;var candidates=new List<SelectedSplineRecord>(32);
   foreach(string token in tokens)
   {
    MessageNumbers.RequireAscii(token);int at=token.IndexOf("splines=",StringComparison.OrdinalIgnoreCase);
    if(at>=0){if(!w.HasWorldPointer)throw new InvalidOperationException("Native world pointer is null.");FindPrefix(w,Tail(token,at,8),candidates,32-candidates.Count);}
    else if((at=token.IndexOf("spline=",StringComparison.OrdinalIgnoreCase))>=0)
    {
     if(!w.HasWorldPointer)throw new InvalidOperationException("Native world pointer is null.");SelectedSplineRecord s=Find(w,Tail(token,at,7));if(s!=null&&candidates.Count<32)candidates.Add(s);
    }
    else if(token.IndexOf("unused",StringComparison.OrdinalIgnoreCase)>=0)unused=true;
   }
   if(candidates.Count==0)return true;
   if(unused)
   {
    foreach(PcObjectImage actor in w.Actors)if(Eligible(actor)){SelectedSplineRecord s=Attached(w,actor);if(s==null)throw new InvalidOperationException("Invalid attached spline memory.");s.Flags|=0x8000;}
    var remaining=new List<SelectedSplineRecord>(32);foreach(SelectedSplineRecord s in candidates)if((s.Flags&0x8000)==0)remaining.Add(s);
    // Clear only the flags on eligible attached records; preexisting bit8000 is also lost there.
    foreach(PcObjectImage actor in w.Actors)if(Eligible(actor)){SelectedSplineRecord s=Attached(w,actor);if(s==null)throw new InvalidOperationException("Invalid attached spline memory.");s.Flags=(ushort)(s.Flags&0x7fff);}
    candidates=remaining;
   }
   if(candidates.Count!=0){uint draw=w.Random.Next();int stride=65535/candidates.Count+1;w.Selected=candidates[(int)draw/stride];}
   return true;
  }
 }
}
