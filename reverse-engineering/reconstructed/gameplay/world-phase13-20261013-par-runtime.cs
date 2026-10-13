using System;
namespace Recovered.Gameplay {
 public static class ParInstanceRuntime {
  public const uint Records=0x2913a58,Instances=0x291f7a8,Time=0x2920a90,RandomState=0x8102e8,Selected=0x2920888,SelectedInstance=0x292096c,SelectedRecord=0x2920970,Origin=0x291f714;
  static float F(SoundSetupImage m,uint at){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(at)),0);}
  static float Round(double value){return BitConverter.ToSingle(BitConverter.GetBytes((float)value),0);}
  static void Store(SoundSetupImage m,uint at,double value){m.Word(at,BitConverter.ToUInt32(BitConverter.GetBytes(Round(value)),0));}
  static int Truncate(double value){return (int)Math.Truncate(value);}
  static float RandomFraction(SoundSetupImage m,uint state){uint value=m.Word(state);float result=SoundPlayback.RandomFraction(ref value);m.Word(state,value);return result;}
  // 0x64ae50. Finite, bounded timing projection; positive rate, positive periodic duration and nonnegative gap.
  // Original x87 intermediates have greater precision; exceptional or extreme inputs are outside this projection.
  public static void Activate(SoundSetupImage m,int instance,float start){unchecked{
   if(instance==-1)return;uint at=Instances+(uint)instance*108;int id=(int)m.Word(at+12);if(id==-1)return;uint record=Records+(uint)id*376;
   float now=F(m,Time),duration=F(m,record+236),variation=F(m,record+240),interval=F(m,record+244),intervalVariation=F(m,record+248);
   if(variation==0&&intervalVariation==0){
    float period=Round((double)interval+duration);float cycle=Round((double)period*Truncate((double)now/period));float begin=Round((double)cycle+start);Store(m,at+36,begin);Store(m,at+40,(double)begin+duration);
    if(begin<now){while(F(m,at+40)<now){if(F(m,at+40)<=F(m,at+36))Store(m,at+40,(double)duration+F(m,at+36));else Store(m,at+36,(double)F(m,at+40)+interval);if(!(F(m,at+36)<now))break;}}
   }else{Store(m,at+36,now);float fraction=RandomFraction(m,RandomState);Store(m,at+40,(double)duration+F(m,at+36)+(double)fraction*variation);}
   float step=Round(1.0/F(m,record+204));if(F(m,at+40)<now)Store(m,at+32,(double)F(m,at+36)-step);else Store(m,at+32,(double)step*Truncate((double)now/step));Store(m,at+56,now);
  }}
  static float Distance(SoundSetupImage m,uint at){float x=Round((double)F(m,Origin)-F(m,at)),y=Round((double)F(m,Origin+4)-F(m,at+4)),z=Round((double)F(m,Origin+8)-F(m,at+8));return Round((double)y*y+(double)x*x+(double)z*z);}
  // 0x644000. Stable first-match ties, strict squared-distance threshold, and zero-distance early return.
  public static void Select(SoundSetupImage m,float threshold){unchecked{
   int selected=(int)m.Word(Selected);if(selected!=-1){uint current=Instances+(uint)selected*108;if(m.Word(current+12)!=0xffffffff&&Distance(m,current)==0)return;}
   selected=-1;m.Word(Selected,0xffffffff);
   for(int i=0;i<40;i++){uint at=Instances+(uint)i*108;if(m.Word(at+12)==0xffffffff)continue;float distance=Distance(m,at);if(threshold<0||distance<threshold){selected=i;m.Word(Selected,(uint)i);threshold=distance;}}
   m.Word(SelectedInstance,0);m.Word(SelectedRecord,0);if(selected!=-1){uint at=Instances+(uint)selected*108;m.Word(SelectedInstance,at);uint id=m.Word(at+12);if(id!=0xffffffff)m.Word(SelectedRecord,Records+id*376);}
  }}
 }
 public sealed class ParRecoveredRuntimeServices:IParRuntimeServices {
  public void Activate(SoundSetupImage m,int instance,uint startBits){ParInstanceRuntime.Activate(m,instance,BitConverter.ToSingle(BitConverter.GetBytes(startBits),0));}
  public void Select(SoundSetupImage m,uint distanceBits){ParInstanceRuntime.Select(m,BitConverter.ToSingle(BitConverter.GetBytes(distanceBits),0));}
 }
}
