// Bounded PC paused presentation block; not a complete frame dispatcher.
using System;
namespace Recovered.Frame
{
    public sealed class PausedPlayerProjection
    {
        public uint RenderObject; // actor+0x7fc
        public uint Flags;        // actor+0x1fc
        public sbyte Variant;     // actor+0x280, movsx
    }
    public interface IPausedPresentationServices
    {
        void SetPresentationScale(float value); // 0x5e4e00
        void SetUpdateMask(uint value);          // 0x5d3490
        void SetPausedMode(uint value);          // 0x5d4770
        void ApplyCamera(uint[] matrix);         // 0x603cc0
        void UpdatePlayerContexts(uint address, uint mode); // 0x495310
        void PresentPlayer(uint renderObject, uint playerFlag, int variant); // 0x570a80
        void FinishPausedPresentation(uint mode); // 0x690610
    }
    public static class PausedPresentation
    {
        // @0x491d50, instructions 0x492115..0x492134. @confidence: H
        // Override is called lazily and native tests AL, not the whole EAX.
        public static bool ShouldRun(uint paused, uint forceUpdate, Func<byte> overridePause)
        {
            if (paused == 0) return false;
            if (forceUpdate != 0) return false;
            return overridePause() == 0;
        }
        // @0x491d50, instructions 0x49213a..0x4921cc. @confidence: H
        // Call only after the dispatcher chose this branch. Camera arrays are
        // raw 32-bit words so the native 64-byte copy preserves all bit patterns.
        // Source and destination must represent valid, distinct native storage.
        public static void Run(uint[] cameraWords, uint[] outputMatrix,
            PausedPlayerProjection[] players, IPausedPresentationServices services)
        {
            if (cameraWords == null || cameraWords.Length != 16 ||
                outputMatrix == null || outputMatrix.Length != 16 ||
                Object.ReferenceEquals(cameraWords, outputMatrix))
                throw new ArgumentException("Two distinct sixteen-word camera arrays required.");
            if (players == null || players.Length < 2)
                throw new ArgumentException("The two native player slots are required.");
            if (services == null) throw new ArgumentNullException("services");
            services.SetPresentationScale(0.0f);
            services.SetUpdateMask(2);
            services.SetPausedMode(1);
            for (int i = 0; i < 16; ++i) outputMatrix[i] = cameraWords[i];
            services.ApplyCamera(outputMatrix);
            services.UpdatePlayerContexts(0x9253b0, 1);
            for (int i = 0; i < 2; ++i)
            {
                PausedPlayerProjection player = players[i];
                if (player != null)
                    services.PresentPlayer(player.RenderObject, (player.Flags >> 7) & 1,
                        (int)player.Variant);
            }
            services.FinishPausedPresentation(1);
        }
    }
}
