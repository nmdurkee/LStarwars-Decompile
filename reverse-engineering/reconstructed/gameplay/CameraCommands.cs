// Reconstructed PC CameraCut argument/target selection. Record loading and live
// camera movement remain host responsibilities. See native-camera-command-contract.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class CameraNamedPoint { public string Name; public CameraPoint Point; }
    public sealed class CameraSceneObject
    {
        public string Name;
        public CameraPoint Position,OverridePosition;
        public bool OverrideIsMinusOne;
    }
    public sealed class CameraScene
    {
        public bool Dynamic;
        public readonly List<CameraSceneObject> Objects=new List<CameraSceneObject>();
    }
    public sealed class CameraSceneReference { public CameraScene Scene; public CameraSceneObject Static,Dynamic; }
    public static class CameraSceneLookup
    {
        // 0x5cf510: normal lookup; diagnostic global0x97388c must be disabled.
        public static bool FindDynamic(CameraScene scene,CameraSceneReference output,string name)
        {
            if(scene==null)return false;
            foreach(CameraSceneObject item in scene.Objects)if(SceneryText.Equal(SceneryText.C(item.Name),SceneryText.C(name))){output.Scene=scene;output.Static=null;output.Dynamic=item;return true;}
            output.Scene=null;output.Static=null;output.Dynamic=null;return false;
        }
        // 0x5cf5b0. Dynamic display takes precedence over static records.
        public static bool Find(CameraScene scene,CameraSceneReference output,string name)
        {
            if(scene!=null&&name!=null)
            {
                if(scene.Dynamic)return FindDynamic(scene,output,name);
                foreach(CameraSceneObject item in scene.Objects)if(SceneryText.Equal(SceneryText.C(item.Name),SceneryText.C(name))){output.Scene=scene;output.Static=item;output.Dynamic=null;return true;}
            }
            output.Scene=null;output.Static=null;output.Dynamic=null;return false;
        }
        // 0x5cf9e0; static instances require a valid backing transform.
        public static CameraPoint Position(CameraSceneReference reference)
        {
            CameraSceneObject item=reference.Dynamic;
            if(item!=null)return item.OverridePosition==null||item.OverrideIsMinusOne?item.Position:item.OverridePosition;
            item=reference.Static;if(item==null)return null;
            if(item.OverrideIsMinusOne)throw new ArgumentException("Static -1 transform pointer is not a valid native position.");
            return item.OverridePosition??item.Position;
        }
    }
    public sealed class CameraCommandWorld
    {
        public CameraCutState State=new CameraCutState();
        public CameraPoint CurrentCamera;
        public CameraScene Scene;
        public readonly List<CameraNamedPoint> Locators=new List<CameraNamedPoint>();
        public ActorStateWorld Actors;
        // The position at actor+0x80 is distinct from actor+0x5c used by movement.
        public readonly Dictionary<ActorStateRecord,CameraPoint> ActorOrigins=new Dictionary<ActorStateRecord,CameraPoint>();
        public float[] SineTable;
        public CameraPoint FindLocator(string name)
        {foreach(CameraNamedPoint l in Locators)if(SceneryText.Equal(SceneryText.C(l.Name),SceneryText.C(name)))return l.Point;return null;}
    }
    public static class CameraCommands
    {
        static float R(double v){return MessageNumbers.Round((float)v);}
        static int Angle(float value,bool negate)
        {
            int whole=PlaybackWide.From(value).TruncateInt32();if(negate)whole=unchecked(-whole);
            // Exact stored PC binary64 constant at0x7578a0, not65536/360.
            return PlaybackWide.Multiply(PlaybackWide.FromDouble(whole),PlaybackWide.FromDouble(182.04444885253906)).TruncateInt32();
        }
        static float SumProducts(float a,float b,float c,float d)
        {
            float v=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.Multiply(PlaybackWide.From(c),PlaybackWide.From(d))).Store();
            return v==0?R((double)a*b+(double)c*d):v;
        }
        // 0x5b35a0. Original32768-entry sine table, aliased input/output safe.
        public static SpawnVector RotateX(SpawnVector v,int angle,float[] table)
        {if(table==null||table.Length!=32768)throw new ArgumentException("Complete native sine table required.");float s=table[(angle>>1)&32767],c=table[(unchecked(angle+16384)>>1)&32767];return new SpawnVector(v.X,SumProducts(c,v.Y,-s,v.Z),SumProducts(s,v.Y,c,v.Z));}
        static SpawnVector RotateY(SpawnVector v,int angle,float[] table)
        {float s=table[(angle>>1)&32767],c=table[(unchecked(angle+16384)>>1)&32767];return new SpawnVector(SumProducts(s,v.Z,c,v.X),v.Y,SumProducts(c,v.Z,-s,v.X));}
        static SpawnVector Add(SpawnVector a,SpawnVector b){return new SpawnVector(R((double)a.X+b.X),R((double)a.Y+b.Y),R((double)a.Z+b.Z));}
        static bool Match(string t,string k,out string tail){int a=SceneryText.Index(t,k);tail=a<0?null:t.Substring(a+k.Length);return a>=0;}
        static bool Complete(SpawnVector p){return p.X!=1e9f&&p.Y!=1e9f&&p.Z!=1e9f;}
        // 0x4509d0. Bool return models native1; first-call false is a no-op.
        public static bool Cut(CameraCommandWorld w,ScriptPacket packet,ActorStateRecord selfReference,string[] tokens,bool first)
        {
            if(!first)return true;
            float start=0,end=1e9f,blendIn=0,blendOut=0,range=1;int rx=0,ry=0;
            bool current=false,follow=false;uint borders=1;string locator=null,character=null,obj=null,camLocator=null;
            SpawnVector targetValue=new SpawnVector(1e9f,1e9f,1e9f),cameraValue=targetValue,delta=new SpawnVector();
            if(tokens!=null)foreach(string raw in tokens)
            {
                string t=SceneryText.C(raw),s;
                if(SceneryText.Equal(t,"Reset")){CameraState.Configure(w.State,null,null,0,0,0,0,0,false,false,0);return true;}
                if(SceneryText.Equal(t,"use_current_campos"))current=true;
                else if(Match(t,"start_time=",out s))start=MessageNumbers.Resolve(packet,s);
                else if(SceneryText.Equal(t,"end_time=infinite"))end=1e9f;
                else if(Match(t,"end_time=",out s))end=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"blend_in_time=",out s))blendIn=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"blend_out_time=",out s))blendOut=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"tgt_locator=",out s))locator=s;
                else if(Match(t,"tgt_character=",out s))character=s;
                else if(Match(t,"tgt_obj=",out s))obj=s;
                else if(Match(t,"cam_locator=",out s))camLocator=s;
                else if(Match(t,"range=",out s))range=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"roty=",out s))ry=Angle(MessageNumbers.Resolve(packet,s),false);
                else if(Match(t,"rotx=",out s))rx=Angle(MessageNumbers.Resolve(packet,s),true);
                else if(SceneryText.Equal(t,"FollowTgt"))follow=true;
                else if(Match(t,"dcampos_x=",out s))delta.X=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"dcampos_y=",out s))delta.Y=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"dcampos_z=",out s))delta.Z=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"campos_x=",out s))cameraValue.X=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"campos_y=",out s))cameraValue.Y=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"campos_z=",out s))cameraValue.Z=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"tgtpos_x=",out s))targetValue.X=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"tgtpos_y=",out s))targetValue.Y=MessageNumbers.Resolve(packet,s);
                else if(Match(t,"tgtpos_z=",out s))targetValue.Z=MessageNumbers.Resolve(packet,s);
                else if(SceneryText.Equal(t,"no_borders"))borders=0;
            }
            CameraPoint target;
            if(locator!=null)target=w.FindLocator(locator);
            else if(character!=null)
            {
                ActorStateRecord reference=selfReference!=null&&SceneryText.Equal(character,"myself")?selfReference:w.Actors!=null&&w.Actors.NameCallback?w.Actors.FindReference(character):null;
                ActorStateRecord actor=reference==null?null:reference.WorldObject;
                if(actor==null)return true;
                if(!w.ActorOrigins.TryGetValue(actor,out target))throw new InvalidOperationException("Missing actor+0x80 position binding.");
            }
            else if(obj!=null){CameraSceneReference r=new CameraSceneReference();if(!CameraSceneLookup.Find(w.Scene,r,obj))return true;target=CameraSceneLookup.Position(r);}
            else
            {
                if(!Complete(targetValue))return true;
                if(follow)throw new ArgumentException("Following an explicit target keeps a native stack pointer; its post-call lifetime is outside this contract.");
                target=new CameraPoint{Position=targetValue};
            }
            if(target==null)return true;
            if(current){if(w.CurrentCamera==null)throw new InvalidOperationException("PC current camera is a fixed nonnull record.");cameraValue=Add(w.CurrentCamera.Position,delta);}
            else if(!Complete(cameraValue))
            {
                CameraPoint camera=camLocator==null?null:w.FindLocator(camLocator);
                cameraValue=camera!=null?camera.Position:Add(RotateY(RotateX(new SpawnVector(0,0,range),rx,w.SineTable),ry,w.SineTable),target.Position);
            }
            CameraState.Configure(w.State,new CameraPoint{Position=cameraValue},target,0,start,end,blendIn,blendOut,follow,false,borders);return true;
        }
    }
}
