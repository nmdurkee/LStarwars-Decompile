using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class SoundPlayback
 {
  static float F(SoundSetupImage m,uint a){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(a)),0);}
  static uint Bits(float x){return BitConverter.ToUInt32(BitConverter.GetBytes(x),0);}
  static PlaybackWide W(float x){return PlaybackWide.From(x);}
  static PlaybackWide I(int x){return PlaybackWide.FromDouble(x);}
  static PlaybackWide Add(PlaybackWide a,PlaybackWide b){return PlaybackWide.Add(a,b);}
  static PlaybackWide Mul(PlaybackWide a,PlaybackWide b){return PlaybackWide.Multiply(a,b);}
  static PlaybackWide Sub(PlaybackWide a,PlaybackWide b){return Add(a,Mul(b,W(-1)));}
  static float Product(float a,float b,float c,float divisor)
  {
   var wide=PlaybackWide.Divide(Mul(Mul(W(a),W(b)),W(c)),W(divisor));float value=wide.Store();if(value==0&&wide.StoreDouble()==0)value=BitConverter.ToSingle(BitConverter.GetBytes((Bits(a)^Bits(b)^Bits(c)^Bits(divisor))&0x80000000),0);return value;
  }
  //0x5b9d90. The mantissa produces a uniformly spaced23-bit fraction.
  public static float RandomFraction(ref uint state){SoundGroups.StepRandom(ref state);return (state&0x7fffff)/8388608f;}
  //0x696be0 and0x6951c0: explicit global/virtual-address inputs.
  public static uint Listener(SoundSetupImage m){uint p=m.Word(0x2972c38);return p==0?0x9736e8u:p;}
  public static float ContextVolume(SoundSetupImage m){uint p=m.Word(0x2962b8c);return p==0?1:F(m,p+0x1ac);}
  static float NextFraction(SoundSetupImage m){uint s=m.Word(0x810364);float r=RandomFraction(ref s);m.Word(0x810364,s);return r;}
  static int Pitch(int value,float scale){return PlaybackWide.Divide(Mul(Mul(W(scale),I(value)),W(3763)),W(44100)).TruncateInt32();}
  static uint U(int value){return unchecked((uint)value);}
  //0x650f20. Finite stored inputs/intermediates and signed32-bit conversions.
  //Only final audio-device entrypoints are mutable services. Native virtual
  //addresses in argument packets remain offsets into the supplied owned images.
  public static void Play(SoundSetupImage m,int id,uint position,float volume,float pitchScale,Action<SoundSetupImage,uint,uint[]> backend)
  {
   if(id==-1)return;uint record=unchecked(m.Word(0x2947b74)+(uint)id*64);uint flags=m.Word(record+4);if((flags&0xc0000)!=0)return;int priority=unchecked((sbyte)m.Byte(record+12)),group=unchecked((short)m.Half(record+0x14));
   if(group!=-1)id=SoundGroups.Select(m,group,(int)((flags>>16)&1));uint offset=unchecked((uint)id*64);record=m.Word(0x2947b74)+offset;flags=m.Word(record+4);int bank=unchecked((int)(flags<<17))>>17;int pitch=Pitch(unchecked((int)m.Word(record+8)),1);float pan=F(m,record+0x18);uint buzz=m.Word(record+0x2c),strength=m.Word(record+0x30),sustain=m.Word(record+0x34),release=m.Word(record+0x38);bool loop=(flags&0x8000)!=0;float oldNear=0,oldFar=0;
   if(F(m,record+0x24)!=0||F(m,record+0x28)!=0)
   {
    oldNear=F(m,0x810d9c);oldFar=F(m,0x810d98);m.Word(0x810d9c,Bits(Product(oldNear,F(m,record+0x24),.5f,1)));m.Word(0x810d98,Bits(Product(F(m,record+0x28),oldFar,1,15)));
   }
   uint listener=Listener(m);bool audible=true;
   if(position!=0)
   {
    PlaybackWide y=Sub(W(F(m,position+4)),W(F(m,listener+0x34))),x=Sub(W(F(m,position)),W(F(m,listener+0x30))),z=Sub(W(F(m,position+8)),W(F(m,listener+0x38)));PlaybackWide distance=Add(Add(Mul(x,x),Mul(y,y)),Mul(z,z)),far=W(F(m,0x810d98));audible=Sub(distance,Mul(far,far)).StoreDouble()<=0;
   }
   if(audible)
   {
    record=m.Word(0x2947b74)+offset;if(pitchScale!=1)pitch=Pitch(unchecked((int)m.Word(record+8)),pitchScale);
    float amplitude=Mul(W(volume>1?1:volume),I(unchecked((short)m.Half(record+0x12)))).Store();
    if((m.Word(record+4)&0x400000)==0){amplitude=Mul(W(F(m,0x81046c)),W(amplitude)).Store();amplitude=Mul(W(ContextVolume(m)),W(amplitude)).Store();}
    int gain=Mul(W(F(m,0x810468)),W(amplitude)).TruncateInt32();record=m.Word(0x2947b74)+offset;
    if(F(m,record+0x1c)!=0)
    {
     float amount=Mul(W(NextFraction(m)),W(F(m,record+0x1c))).Store();uint state=m.Word(0x810364);SoundGroups.StepRandom(ref state);m.Word(0x810364,state);float factor=((state&1)!=0?Add(W(1),W(amount)):Sub(W(1),Mul(W(amount),W(.5f)))).Store();pitch=Mul(I(pitch),W(factor)).TruncateInt32();if((m.Word(m.Word(0x2947b74)+offset+4)&0x8000)!=0)pitch=unchecked(-pitch);
    }
    record=m.Word(0x2947b74)+offset;if(F(m,record+0x20)!=0){float factor=Add(Mul(W(NextFraction(m)),W(F(m,record+0x20))),W(1)).Store();gain=Mul(W(factor),I(gain)).TruncateInt32();}
    if(unchecked((uint)bank)<1600)
    {
     int left=gain,right=gain;if(position==0){if(pan>=0)left=Mul(Sub(W(1),W(pan)),I(gain)).TruncateInt32();if(pan<=0)right=Mul(Add(W(pan),W(1)),I(gain)).TruncateInt32();}
     if(position==0&&loop)
     {
      listener=Listener(m);float[] at={F(m,listener+0x30),F(m,listener+0x34),F(m,listener+0x38)},forward={F(m,listener+0x20),F(m,listener+0x24),F(m,listener+0x28)};float[] sum=CharacterPredictedBounds.AddVectors(at,forward);for(uint i=0;i<3;i++)m.Word(0x2962b3c+i*4,Bits(sum[i]));backend(m,0x698260,new uint[]{0x2962b3c,U(bank),U(left),U(right),U(pitch),buzz,strength,sustain,release});
     }
     else if(position==0){if(priority==0)backend(m,0x6980c0,new uint[]{U(bank),U(left),U(right),U(pitch),buzz,strength,sustain,release});else backend(m,0x698040,new uint[]{U(bank),U(left),U(right),U(pitch),buzz,strength,sustain,release,U(priority)});}
     else if(loop)backend(m,0x698260,new uint[]{position,U(bank),U(gain),U(gain),U(pitch),buzz,strength,sustain,release});
     else if(priority==0)backend(m,0x698210,new uint[]{position,U(bank),U(gain),U(gain),U(pitch),buzz,strength,sustain,release});
     else backend(m,0x698100,new uint[]{position,U(bank),U(gain),U(gain),U(pitch),buzz,strength,sustain,release,U(priority)});
    }
   }
   record=m.Word(0x2947b74)+offset;if(F(m,record+0x24)!=0||F(m,record+0x28)!=0){m.Word(0x810d9c,Bits(oldNear));m.Word(0x810d98,Bits(oldFar));}
  }
 }
}
