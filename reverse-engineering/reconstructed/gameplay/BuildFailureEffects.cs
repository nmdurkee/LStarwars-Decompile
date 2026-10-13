using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class BuildFailureNode
 {
  public int Id;
  public BuildFailureNode Next;
  public uint[] Matrix;
 }
 public sealed class BuildFailureGroup {public BuildFailureNode Head;}
 public sealed class BuildFailureObject {public BuildFailureGroup Group;}
 public sealed class BuildFailureEffect
 {
  public uint LifetimeWord;public byte Flags20a;
  public float Lifetime{get{return BitConverter.ToSingle(BitConverter.GetBytes(LifetimeWord),0);}set{LifetimeWord=BitConverter.ToUInt32(BitConverter.GetBytes(value),0);}}
 }
 public sealed class BuildFailureRequest
 {
  //Copied200-byte template; process-pointer slots0,2,9 are cleared and
  //represented by Matrix, Origin and Node. Callback words remain native IDs.
  public uint[] Words,Matrix,Origin;
  public BuildFailureNode Node;
 }
 public sealed class BuildFailureWorld
 {
  public uint[] Template,DefaultOrigin;
  public uint TimeWord;
  public QRandom Random;
  public Func<BuildFailureRequest,BuildFailureEffect> Allocate;
 }
 public static class BuildFailureEffects
 {
  //0x571c50. Only flag bit0 affects lifetime.
  public static void ResetLifetime(BuildFailureEffect effect){effect.Lifetime=(effect.Flags20a&1)!=0?2.5f:5f;}
  //0x571c80 uses unsigned frame modulo6; NaN lifetime takes the visible path.
  public static int Visible(BuildFailureEffect effect,uint frame)
  {return effect.Lifetime>0&&frame%6>=3&&effect.Lifetime<((effect.Flags20a&1)!=0?1f:2f)?0:1;}
  static void Check(uint[] words,int count,string name)
  {if(words==null||words.Length<count)throw new ArgumentException("Missing "+name+" backing.");}
  //0x590690, allocation and callback571ba0's later effects remain external.
  public static void Create(BuildFailureWorld world,BuildFailureObject buildIt)
  {
   if(buildIt==null||buildIt.Group==null)return;
   Check(world.DefaultOrigin,3,"origin");uint[] origin=new uint[3];Array.Copy(world.DefaultOrigin,origin,3);
   for(BuildFailureNode node=buildIt.Group.Head;node!=null;node=node.Next)
   {
    Check(world.Template,50,"template");Check(node.Matrix,16,"matrix");
    uint[] words=new uint[50],matrix=new uint[16];Array.Copy(world.Template,words,50);Array.Copy(node.Matrix,matrix,16);
    words[0]=0;words[2]=0;words[9]=0;words[5]=0x3e4ccccd;words[6]=0x3e4ccccd;words[7]=0xc0800000;words[11]=0x90;
    words[15]=0x571ba0;words[19]=0x571c50;words[21]=0x571c80;words[35]=world.TimeWord;words[49]=(words[49]&0xffffff00u)|1;
    BuildFailureEffect effect=world.Allocate(new BuildFailureRequest{Words=words,Matrix=matrix,Origin=origin,Node=node});
    if(effect!=null)
    {
     uint draw=world.Random.Next();PlaybackWide term=PlaybackWide.Multiply(PlaybackWide.FromDouble(draw),PlaybackWide.FromDouble(BitConverter.Int64BitsToDouble(0x3ef0001000000000L)));
     effect.Lifetime=PlaybackWide.Add(PlaybackWide.Add(term,term),PlaybackWide.FromDouble(7)).Store();
    }
   }
  }
 }
}
