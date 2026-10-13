// Reconstructed original-PC cut selection state. This does not update a live camera.
using System;
namespace Recovered.Gameplay
{
    public sealed class CameraPoint { public SpawnVector Position; }
    public sealed class CameraCutRecord
    {
        public uint Identity;
        public float Duration, RemainingBlend;
        public ushort Kind, VectorBytes;
        public uint PositionStorage, Extra;
    }
    public sealed class CameraCutState
    {
        public CameraCutRecord Current, Selected;
        public readonly CameraCutRecord Builtin=new CameraCutRecord { Identity=0x9514f0 };
        public readonly CameraPoint StoredCamera=new CameraPoint(), StoredTarget=new CameraPoint();
        public CameraPoint FollowTarget, FollowCamera;
        public float Progress, Start, End, BlendIn, BlendOut, Elapsed, BorderAmount;
        public float WorldPrevious, WorldCurrent;
        public uint Flags, Borders;
        public bool SuppressFlags;
        public ushort TransitionWord;
        public byte TransitionByte, WorldMode;
    }
    public static class CameraState
    {
        static float F(double value){return MessageNumbers.Round((float)value);}
        // PC0x5765b0. Compare the un-stored difference before rounding to float.
        // Inputs are finite float32. For this subtraction and comparison against
        // another float32, binary64 gives the same observable branch/store result
        // as the native extended intermediate, including the huge-value range.
        public static void FinishCurrent(CameraCutState s)
        {
            CameraCutRecord r=s.Current;if(r==null)return;
            float duration=Object.ReferenceEquals(r,s.Builtin)?BitConverter.ToSingle(BitConverter.GetBytes(r.PositionStorage),0):r.Duration;
            if(duration!=0){double end=(double)duration-0.5;if(s.Progress<end)s.Progress=F(end);}
            r.RemainingBlend=0;
        }
        // PC0x577790. Null record leaves all state unchanged.
        public static void Select(CameraCutState s,CameraCutRecord record,float start,float end,float blendIn,float blendOut,uint borders,uint flags)
        {
            if(record==null)return;
            s.Start=start;s.End=end;s.Flags=s.SuppressFlags?0:flags;s.Elapsed=0;
            s.Selected=record;s.BlendIn=blendIn;s.TransitionWord=0;s.BlendOut=blendOut;
            s.FollowTarget=null;s.FollowCamera=null;s.Borders=borders;
            if(borders!=0&&start==0&&blendIn<=0)s.BorderAmount=1;
            if(start<=0&&blendIn<=0){s.WorldMode=255;s.WorldPrevious=s.WorldCurrent;}
            FinishCurrent(s);s.TransitionByte=0;
        }
        // PC0x577880. Null positions retain stored vector values; follow pointers
        // are installed after Select. FinishCurrent preserves the built-in record
        // union: its vector pointer occupies the ordinary duration field.
        public static void Configure(CameraCutState s,CameraPoint camera,CameraPoint target,uint extra,float start,float end,float blendIn,float blendOut,bool followTarget,bool followCamera,uint borders)
        {
            s.Builtin.Kind=2;s.Builtin.VectorBytes=12;s.Builtin.PositionStorage=0x9518fc;s.Builtin.Extra=extra;
            if(camera!=null)s.StoredCamera.Position=camera.Position;
            if(target!=null)s.StoredTarget.Position=target.Position;
            Select(s,s.Builtin,start,end,blendIn,blendOut,borders,0);
            if(target!=null&&followTarget)s.FollowTarget=target;
            if(camera!=null&&followCamera)s.FollowCamera=camera;
        }
    }
}
