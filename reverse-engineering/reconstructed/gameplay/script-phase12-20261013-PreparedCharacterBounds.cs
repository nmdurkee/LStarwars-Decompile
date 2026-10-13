// Prepared-memory composition of existing numeric55d2b0 recovery.
// Native hydration and fault order are retained; no new distinct-address credit.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedCharacterBounds
 {
  static uint Add(uint p,int offset){return unchecked(p+(uint)offset);}
  static sbyte Point(TakeoverReleaseMemory m,uint type,uint field){sbyte slot=unchecked((sbyte)m.Read8(type+field));if(slot!=-1&&(slot<0||slot>=16))throw new ArgumentOutOfRangeException("Prepared point slot must be -1 or0..15.");return slot;}
  static PcObjectImage Image(TakeoverReleaseMemory m,uint actor){byte[] b=new byte[PcObjectImage.Size];for(uint i=0;i<b.Length;i++)b[i]=m.Read8(actor+i);return new PcObjectImage(b);}
  static void Commit(TakeoverReleaseMemory m,uint actor,PcObjectImage image){for(uint i=0;i<image.Bytes.Length;i++)m.Write8(actor+i,image.Bytes[i]);}
  // 55d2b0 prepared bridge. Numeric body remains CharacterPredictedBounds.Update.
  public static void Refresh(TakeoverReleaseMemory m,uint actor)
  {
   // This write precedes even invalid definition/model chains in original55d2b0.
   m.Write32(actor+0x1f8,m.Read32(actor+0x1f8)|0x100);
   var environment=new CharacterBoundsEnvironment{PredictionSeconds=m.Float(0x925018),PrimaryPoint=-1,FallbackPoint=-1,PointEnabledSlots=new uint[16],ContextFlags=0};
   if(m.Read8(actor+0x1079)!=0)
   {
    uint type=m.Read32(m.Read32(actor+0x54)+0x24);environment.PrimaryPoint=Point(m,type,0x10f);uint model=m.Read32(actor+0x50);bool primary=false;
    if(environment.PrimaryPoint!=-1&&model!=0){int slot=environment.PrimaryPoint;environment.PointEnabledSlots[slot]=m.Read32(model+0x14+(uint)slot*4);primary=environment.PointEnabledSlots[slot]!=0;}
    if(!primary&&m.Float(actor+0xd30)==1)
    {
     environment.FallbackPoint=Point(m,type,0x10d);
     if(environment.FallbackPoint!=-1){int slot=environment.FallbackPoint;environment.PointEnabledSlots[slot]=m.Read32(model+0x14+(uint)slot*4);}
    }
   }
   PcObjectImage input=Image(m,actor),preContext=new PcObjectImage(input.Bytes);
   // The verified numeric source also includes the context tail. Disable only that
   // tail on the owned temporary image, then restore all input bits and query copy.
   // This commits exact pre-context outputs before the original late table lookup.
   uint d7c=preContext.U32(0xd7c),floor=preContext.U32(0x21c),offset=preContext.U32(0xb4);
   preContext.Set32(0xd7c,0);preContext.Set32(0x21c,0);preContext.Set32(0xb4,0);
   CharacterPredictedBounds.Update(preContext,environment);
   preContext.Set32(0xd7c,d7c);preContext.Set32(0x21c,floor);preContext.Set32(0xb4,offset);
   for(int i=0;i<3;i++)preContext.Set32(0x414+i*4,preContext.U32(0x1a8+i*4));Commit(m,actor,preContext);
   int context=unchecked((sbyte)m.Read8(actor+0x7b5));uint registry=m.Read32(0x7fb0e4);environment.ContextFlags=m.Read32(Add(registry,context*16+8));
   // Reuse the same frozen input/model projection with the now-resolved context.
   // There are no callbacks in the numeric body. This preserves all lazy final gates.
   PcObjectImage final=new PcObjectImage(input.Bytes);CharacterPredictedBounds.Update(final,environment);Commit(m,actor,final);
  }
 }
}
