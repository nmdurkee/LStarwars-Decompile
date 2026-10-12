// Recovered PC state helpers 0x5b1220/0x5b11b0 and the transition tail of 0x491d50.
// Native subsystem implementations and actual level loading remain host adapters.
using System;
namespace Recovered.Frame
{
    public sealed class TransitionState
    {
        // Native object: argument+0, progress+0xc, phase+0x10,
        // four state pointers+0x14, selected index+0x24.
        public uint Argument;
        public float Progress;
        public int Phase;
        public int Selected = -1;
        public readonly Action[] States = new Action[4];

        public bool Select(int index, uint argument)
        {
            if (index < -1 || index >= States.Length)
                throw new ArgumentOutOfRangeException("index");
            if (index != -1 && States[index] != null)
            {
                Selected = index;
                Argument = argument;
                return true;
            }
            Selected = -1;
            return false;
        }
        public void Begin(sbyte phase)
        {
            Phase = phase;
            Progress = 0;
            if (Selected != -1)
            {
                if (Selected < 0 || Selected >= States.Length)
                    throw new InvalidOperationException("Invalid native state index.");
                Action state = States[Selected];
                if (state != null) state();
            }
        }
    }

    // Identity matters: callers must reuse the same LevelRecord instance for
    // equal native level pointers. AreaFlags is the resolved indexed area byte.
    public sealed class LevelRecord
    {
        public uint Flags;
        public sbyte AreaIndex;
        public byte AreaFlags;
    }
    public sealed class TransitionInputs
    {
        public bool Request, ActiveMode;
        public LevelRecord UpdatingLevel, GlobalLevel, Destination;
        public LevelRecord SpecialLevel, AlternateLevel, AlternateDestination;
        public int CurrentAreaIndex;
        public byte CurrentAreaFlags;
        public float Delay;
        public uint Auxiliary;
        public readonly TransitionState State = new TransitionState();
    }
    public enum TransitionResult { NoRequest, Delayed, Deferred, Begun }
    public static class FrameTransitions
    {
        // Called after the native dispatcher clears its separate output word.
        // Covers the original tail beginning0x49267a, not the whole dispatcher.
        public static TransitionResult Advance(TransitionInputs s)
        {
            if (s == null) throw new ArgumentNullException("s");
            LevelRecord target = s.Destination;
            if (!s.Request && target == null) return TransitionResult.NoRequest;
            if (s.Delay != 0) return TransitionResult.Delayed;
            if (s.UpdatingLevel != null && (s.UpdatingLevel.Flags & 0x400) != 0 &&
                s.SpecialLevel != null && target != null && target != s.SpecialLevel &&
                target.AreaIndex != -1 && (target.AreaFlags & 2) == 0)
            {
                s.Delay = 1;
                s.Auxiliary = 0;
                return TransitionResult.Deferred;
            }
            if (s.State.Selected == -1 ||
                (target != null && s.GlobalLevel != target && target == s.SpecialLevel))
            {
                LevelRecord current = s.GlobalLevel;
                bool chooseOne = current != null && target != null && current != target &&
                    (target == s.SpecialLevel || current == s.SpecialLevel ||
                     target == s.AlternateLevel || current == s.AlternateLevel ||
                     target == s.AlternateDestination ||
                     (s.ActiveMode && (current.Flags & 0x400) != 0 && (target.AreaFlags & 2) != 0));
                if (!chooseOne)
                    chooseOne = target != null && target.AreaIndex != s.CurrentAreaIndex &&
                        (!s.ActiveMode || (s.CurrentAreaFlags & 2) != 0);
                s.State.Select(chooseOne ? 1 : 2, 0);
            }
            s.State.Begin(2);
            return TransitionResult.Begun;
        }
    }
}
