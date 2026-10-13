using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class LocatorSelectionContext
 {
  public LocatorReservationWorld Reservations;
  public float[][] Positions;
  public LocatorView View;
  public float[] ObjectMatrix;
  public ScriptRandom Random;
 }
 public static class LocatorSetSelection
 {
  // Original5b3c50 nonnull scratch branch stores differences AND final sum.
  // Keep64-bit x87 intermediate precision before the final float32 store.
  public static float Distance(float[] a,float[] b)
  {
   PlaybackWide[] d=new PlaybackWide[3];
   for(int i=0;i<3;i++)d[i]=PlaybackWide.From(PlaybackWide.Add(PlaybackWide.From(a[i]),PlaybackWide.From(-b[i])).Store());
   return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(d[0],d[0]),PlaybackWide.Multiply(d[1],d[1])),PlaybackWide.Multiply(d[2],d[2])).Store();
  }
  static bool Candidate(LocatorSelectionContext c,LocatorReservationSet set,int i,bool ignore,float radius)
  {return (!ignore||set.Owners[i]==255)&&(radius==0||LocatorViewCulling.Outside(c.View,c.Positions[set.Indices[i]],radius,c.ObjectMatrix));}
  static void Assign(LocatorReservationSet set,LocatorReservationActor actor,int index)
  {if(index<0)return;actor.SelectedLocatorIndex=set.Indices[index];set.Owners[index]=actor.OwnerId;}
  //0x51fef0: strict best distance to either reference, preserving first ties.
  public static void Nearest(LocatorSelectionContext c,LocatorReservationSet set,LocatorReservationActor actor,float range,float[] primary,float[] secondary,float radius,bool ignoreAssigned)
  {
   if(set==null||actor==null||!actor.PacketPresent||primary==null)return;
   float best=range>0?(float)((double)range*range):Single.MaxValue;int index=-1;
   if(ignoreAssigned)LocatorReservations.Refresh(c.Reservations,set);
   for(int i=0;i<set.Count;i++)if(Candidate(c,set,i,ignoreAssigned,radius))
   {
    float distance=Distance(primary,c.Positions[set.Indices[i]]);
    if(distance<best){best=distance;index=i;}
    if(secondary!=null){distance=Distance(secondary,c.Positions[set.Indices[i]]);if(distance<best){best=distance;index=i;}}
   }
   Assign(set,actor,index);
  }
  //0x520080: maximize the smaller distance when two references exist.
  public static void Farthest(LocatorSelectionContext c,LocatorReservationSet set,LocatorReservationActor actor,float range,float[] primary,float[] secondary,float radius,bool ignoreAssigned)
  {
   if(set==null||actor==null||!actor.PacketPresent)return;
   float best=0;int index=-1;
   if(ignoreAssigned)LocatorReservations.Refresh(c.Reservations,set);
   for(int i=0;i<set.Count;i++)if(Candidate(c,set,i,ignoreAssigned,radius))
   {
    float distance=Distance(primary,c.Positions[set.Indices[i]]);if(distance<=best)continue;
    if(secondary!=null){float other=Distance(secondary,c.Positions[set.Indices[i]]);if(other<=best)continue;if(other<distance)distance=other;}
    if(range==0||(double)distance<(double)range*range){best=distance;index=i;}
   }
   Assign(set,actor,index);
  }
  //0x520220: second pass deliberately differs from the first: actor position,
  // no offscreen test. The count and chosen ordinal can therefore disagree.
  public static void Random(LocatorSelectionContext c,LocatorReservationSet set,LocatorReservationActor actor,float range,float[] primary,float radius,bool ignoreAssigned)
  {
   if(set==null||actor==null||!actor.PacketPresent)return;
   float max=range>0?(float)((double)range*range):Single.MaxValue;uint count=0;
   if(ignoreAssigned)LocatorReservations.Refresh(c.Reservations,set);
   for(int i=0;i<set.Count;i++)if(Candidate(c,set,i,ignoreAssigned,radius)&&Distance(primary,c.Positions[set.Indices[i]])<=max)count++;
   if(count==0)return;
   c.Random.Next();uint choice=c.Random.State%count,ordinal=0;
   float[] own={actor.Actor.X,actor.Actor.Y,actor.Actor.Z};
   for(int i=0;i<set.Count;i++)if((!ignoreAssigned||set.Owners[i]==255)&&Distance(own,c.Positions[set.Indices[i]])<=max)
   {if(ordinal==choice){Assign(set,actor,i);return;}ordinal++;}
  }
 }
}
