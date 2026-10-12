// Portable reconstruction of PC 0x5ae450, 0x5ae4a0 and 0x5ae520.
using System;

namespace Recovered.Gameplay
{
    // Scene loading, animation evaluation, rendering and collision updates belong to the host.
    // Play must preserve the host's native-equivalent end/start and playback rules.
    public interface ISceneAnimation
    {
        void JumpToStart();
        void Play(float speed, bool evaluate);
        void Stop();
        void SetVisibility(bool visible);
    }

    public sealed class SpecialGizmo
    {
        public byte Flags; // 1 reversed, 2 active; other bits preserved.
        public readonly ISceneAnimation Animation;
        public SpecialGizmo(ISceneAnimation animation)
        {
            if (animation == null) throw new ArgumentNullException("animation");
            Animation = animation;
        }
        public void Activate(bool active)
        {
            if (active)
            {
                Animation.JumpToStart(); Animation.Play(1, true); Flags |= 2;
            }
            else { Animation.Stop(); Flags = (byte)(Flags & ~2); }
        }
        public bool Reverse(bool reversed, int mode)
        {
            if ((mode & 1) != 0) return ((Flags & 1) != 0) != reversed;
            Animation.Play(reversed ? -1 : 1, true);
            Flags = (byte)((Flags & ~1) | (reversed ? 1 : 0));
            return true;
        }
        public GizmoCallbacks Callbacks(Func<byte, bool, bool> output)
        {
            return new GizmoCallbacks { Activate = Activate, Reverse = Reverse, Visibility = Animation.SetVisibility, Output = output };
        }
    }
}
