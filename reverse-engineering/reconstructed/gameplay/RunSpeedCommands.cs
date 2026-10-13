using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class RunSpeedActor
 {
  public float DefaultSpeed,OverrideSpeed=1000000000f;
 }
 public sealed class RunSpeedPacket
 {
  public ScriptPacket Numbers;
  public float SeekRate,TargetSpeed;
 }
 public static class RunSpeedCommands
 {
  static float SignedStore(PlaybackWide value,double approximation){float f=value.Store();return f==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximation)<0?0x80000000u:0u):f;}
  static float Product(float a,float b){return SignedStore(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),(double)a*b);}
  //0x54fb40 stores rate*delta before capping above1; negative factors survive.
  public static float Seek(float current,float target,float rate,float delta)
  {
   float step=Product(rate,delta);if(step>1)step=1;
   PlaybackWide diff=PlaybackWide.Add(PlaybackWide.From(target),PlaybackWide.From(-current));
   return SignedStore(PlaybackWide.Add(PlaybackWide.From(current),PlaybackWide.Multiply(PlaybackWide.From(step),diff)),(double)current+step*((double)target-current));
  }
  static float Clamp(float value,float minimum,float maximum)
  {
   if(value>=0){if(value>maximum)return maximum;if(minimum<maximum&&value<minimum)return minimum;}
   else{if(value<-maximum)return -maximum;if(minimum<maximum&&value>-minimum)return -minimum;}
   return value;
  }
  //0x44ac40. The actor projection is the creature reference's world object.
  public static int Set(RunSpeedActor actor,RunSpeedPacket packet,float primaryDefaultSpeed,string[] tokens,bool firstCall,float delta)
  {
   if(actor==null)return 1;
   if(firstCall)
   {
    float requested=1000000000f,multiplier=1,maximum=1000000000f,minimum=0;bool multiply=false;
    foreach(string raw in tokens)
    {
     string text=SceneryText.C(raw);int at;
     if((at=text.IndexOf("multiply=",StringComparison.OrdinalIgnoreCase))>=0){multiplier=MessageNumbers.Resolve(packet.Numbers,text.Substring(at+9));multiply=true;}
     else if(SceneryText.Equal(text,"max=default"))maximum=actor.DefaultSpeed;
     else if(SceneryText.Equal(text,"default"))requested=actor.DefaultSpeed;
     else if(SceneryText.Equal(text,"clear")){}
     else if((at=text.IndexOf("max=",StringComparison.OrdinalIgnoreCase))>=0)maximum=MessageNumbers.Resolve(packet.Numbers,text.Substring(at+4));
     else if((at=text.IndexOf("min=",StringComparison.OrdinalIgnoreCase))>=0)minimum=MessageNumbers.Resolve(packet.Numbers,text.Substring(at+4));
     else if((at=text.IndexOf("seek=",StringComparison.OrdinalIgnoreCase))>=0)packet.SeekRate=MessageNumbers.Resolve(packet.Numbers,text.Substring(at+5));
     else if(text.IndexOf("player_run_speed",StringComparison.OrdinalIgnoreCase)>=0)requested=primaryDefaultSpeed;
     else requested=MessageNumbers.Resolve(packet.Numbers,text);
    }
    minimum=Math.Abs(minimum);maximum=Math.Abs(maximum);
    if(packet.SeekRate==0)
    {
     if(!multiply){actor.OverrideSpeed=requested;return 1;}
     if(actor.OverrideSpeed==1000000000f)actor.OverrideSpeed=actor.DefaultSpeed;
     actor.OverrideSpeed=Clamp(Product(multiplier,actor.OverrideSpeed),minimum,maximum);return 1;
    }
    if(multiply)
    {
     if(actor.OverrideSpeed==1000000000f)packet.TargetSpeed=actor.DefaultSpeed;
     packet.TargetSpeed=Clamp(Product(multiplier,packet.TargetSpeed),minimum,maximum);
    }
    else packet.TargetSpeed=requested;
   }
   if(packet.SeekRate>0&&actor.OverrideSpeed<1000000000f)
   {
    actor.OverrideSpeed=Seek(actor.OverrideSpeed,packet.TargetSpeed,packet.SeekRate,delta);
    float difference=PlaybackWide.Add(PlaybackWide.From(actor.OverrideSpeed),PlaybackWide.From(-packet.TargetSpeed)).Store();
    if(Math.Abs(difference)<.01f){actor.OverrideSpeed=packet.TargetSpeed;return 1;}
    return 0;
   }
   return 1;
  }
 }
}
