using System;
using System.IO;
using System.IO.Compression;
using System.Runtime.InteropServices;
using Recovered.Animation;

internal static class AnimationDifferentialHarness
{
    private static float F(uint value) { return PcObjectImage.FromBits(value); }
    private static PlaybackClip[] ReadControlClips(BinaryReader r)
    {
        PlaybackClip[] clips = new PlaybackClip[233]; int count = r.ReadInt32();
        for (int i = 0; i < count; ++i)
        {
            int id = r.ReadInt32(); clips[id] = new PlaybackClip { Flags = r.ReadUInt32(), EndFrame = r.ReadSingle(),
                BlendIn = r.ReadSingle(), BlendOut = r.ReadSingle(), FramesPerSecond = r.ReadSingle(), MovementReference = r.ReadSingle(), RateCap = r.ReadSingle() };
        }
        return clips;
    }
    private static int VerifyControl(string file, out int errors)
    {
        errors = 0;
        using (BinaryReader r = new BinaryReader(new GZipStream(File.OpenRead(file), CompressionMode.Decompress)))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "ACTRL001") throw new Exception("Control oracle signature mismatch");
            int count = r.ReadInt32();
            for (int c = 0; c < count; ++c)
            {
                int kind = r.ReadInt32(), argLength = r.ReadInt32(); byte[] args = r.ReadBytes(argLength);
                int beforeLength = r.ReadInt32(), expectedLength = r.ReadInt32(); byte[] before = r.ReadBytes(beforeLength), expected = r.ReadBytes(expectedLength);
                int expectedReturn = r.ReadInt32(), result = 0; byte[] actual;
                using (BinaryReader a = new BinaryReader(new MemoryStream(args)))
                {
                    if (kind == 0 || kind == 1)
                    {
                        byte[] miniBytes = new byte[36], fullBytes = new byte[72]; Array.Copy(before, 0, miniBytes, 0, 36); Array.Copy(before, 36, fullBytes, 0, 72);
                        MiniAnimationPacket mini = new MiniAnimationPacket(miniBytes); AnimationPacket full = new AnimationPacket(fullBytes);
                        if (kind == 0) AnimationControl.ExpandMini(mini, full); else AnimationControl.CompactFull(full, mini);
                        actual = new byte[108]; Array.Copy(mini.Bytes, 0, actual, 0, 36); Array.Copy(full.Bytes, 0, actual, 36, 72);
                    }
                    else if (kind == 2)
                    {
                        float step = a.ReadSingle(), speed = a.ReadSingle(), blend = a.ReadSingle(); int mode = a.ReadInt32(); PlaybackClip[] clips = ReadControlClips(a);
                        MiniAnimationPacket mini = new MiniAnimationPacket(before); AnimationControl.UpdateMini(mini, clips, step, speed, blend, mode); actual = mini.Bytes;
                    }
                    else if (kind == 3)
                    {
                        int source = a.ReadInt32(), target = a.ReadInt32(); bool present = a.ReadUInt32() != 0; uint mask = a.ReadUInt32(); bool[] available = new bool[6];
                        for (int i = 0; i < 6; ++i) available[i] = (mask & (1u << i)) != 0;
                        AnimationPacket p = new AnimationPacket(before); result = AnimationControl.IsBlendingFromTo(p, source, target, present, available) ? 1 : 0; actual = p.Bytes;
                    }
                    else if (kind == 4)
                    { AnimationPacket p = new AnimationPacket(before); result = AnimationControl.CurrentAction(p); actual = p.Bytes; }
                    else if (kind == 5)
                    {
                        PlayerAnimationInputs inputs = new PlayerAnimationInputs { Seconds = a.ReadSingle(), InputMagnitude = a.ReadSingle(), MovementSpeed = a.ReadSingle(),
                            BackwardsMultiplier = a.ReadSingle(), GameCharacterFlags = a.ReadUInt32(), BlendMode = a.ReadInt32() };
                        PlaybackClip[] clips = ReadControlClips(a); PcObjectImage o = new PcObjectImage(before); AnimationControl.AdvancePlayerWithoutEvents(o, clips, inputs); actual = o.Bytes;
                    }
                    else throw new Exception("Unknown control case type");
                    if (a.BaseStream.Position != a.BaseStream.Length) throw new Exception("Trailing control argument bytes");
                }
                if (!Equal(actual, expected) || result != expectedReturn) { ++errors; if (errors <= 10) Console.Error.WriteLine("Control mismatch " + c); }
            }
            if (r.BaseStream.ReadByte() != -1) throw new Exception("Trailing control oracle bytes");
            return count;
        }
    }
    private static int VerifyIdle(string file, out int errors)
    {
        errors = 0;
        using (BinaryReader r = new BinaryReader(File.OpenRead(file)))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "AIDLE001") throw new Exception("Idle oracle signature mismatch");
            int count = r.ReadInt32();
            for (int c = 0; c < count; ++c)
            {
                int kind = r.ReadInt32(), action = r.ReadInt32(), mode = r.ReadInt32(); uint random = r.ReadUInt32();
                float step = r.ReadSingle(), blend = r.ReadSingle();
                IdleContext context = new IdleContext { Variant = (byte)r.ReadUInt32(), CharacterFlags = r.ReadUInt32(),
                    ThrowHeld = r.ReadUInt32() != 0, DurationLookupValid = r.ReadUInt32() != 0, ModelPresent = r.ReadUInt32() != 0 };
                int clipCount = r.ReadInt32(); IdleClip[] clips = new IdleClip[233];
                for (int i = 0; i < clipCount; ++i)
                {
                    int id = r.ReadInt32(); IdleClip clip = new IdleClip { Flags = r.ReadUInt32(), MinimumRepetitions = r.ReadByte(), MaximumRepetitions = r.ReadByte() };
                    r.ReadUInt16(); clip.EndFrame = r.ReadSingle(); clip.FramesPerSecond = r.ReadSingle(); clip.BlendOut = r.ReadSingle(); clips[id] = clip;
                }
                PcObjectImage o = new PcObjectImage(r.ReadBytes(PcObjectImage.Size)); byte[] expected = r.ReadBytes(PcObjectImage.Size);
                int expectedReturn = r.ReadInt32(); uint expectedRandom = r.ReadUInt32(), expectedBlend = r.ReadUInt32(); int result = 0;
                if (kind == 0) result = IdleScheduling.SelectBaseIdleAction(o, clips, context);
                else if (kind == 1) IdleScheduling.ResetIdleSchedule(o, clips, context, mode, action, ref random, ref blend);
                else if (kind == 2) IdleScheduling.ChooseIdleVariation(o, clips, context, action, ref random, ref blend);
                else if (kind == 3) IdleScheduling.FinalizeIdleSelection(o, clips, context, step, ref random, ref blend);
                else throw new Exception("Unknown idle oracle kind");
                if (!Equal(o.Bytes, expected) || (kind == 0 && result != expectedReturn) || random != expectedRandom || PcObjectImage.ToBits(blend) != expectedBlend)
                { ++errors; if (errors <= 10) Console.Error.WriteLine("Idle mismatch " + c); }
            }
            if (r.BaseStream.Position != r.BaseStream.Length) throw new Exception("Trailing idle oracle bytes");
            return count;
        }
    }
    private static int VerifyPlayback(string file, out int errors)
    {
        errors = 0;
        using (BinaryReader r = new BinaryReader(File.OpenRead(file)))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "APLAY001") throw new Exception("Playback oracle signature mismatch");
            int count = r.ReadInt32();
            for (int c = 0; c < count; ++c)
            {
                float step = r.ReadSingle(), speed = r.ReadSingle(), blend = r.ReadSingle(), multiplier = r.ReadSingle();
                int mode = r.ReadInt32(); PlaybackClip[] clips = new PlaybackClip[6];
                for (int i = 0; i < clips.Length; ++i)
                {
                    bool present = r.ReadUInt32() != 0;
                    PlaybackClip clip = new PlaybackClip { Flags = r.ReadUInt32(), EndFrame = r.ReadSingle(), BlendIn = r.ReadSingle(),
                        BlendOut = r.ReadSingle(), FramesPerSecond = r.ReadSingle(), MovementReference = r.ReadSingle(), RateCap = r.ReadSingle() };
                    if (present) clips[i] = clip;
                }
                AnimationPacket packet = new AnimationPacket(r.ReadBytes(72)); byte[] expected = r.ReadBytes(72);
                AnimationPlayback.UpdatePacket(packet, clips, step, speed, blend, multiplier, mode);
                if (!Equal(packet.Bytes, expected)) { ++errors; if (errors <= 10) Console.Error.WriteLine("Playback mismatch " + c); }
            }
            if (r.BaseStream.Position != r.BaseStream.Length) throw new Exception("Trailing playback bytes");
            return count;
        }
    }
    private static bool Equal(byte[] a, byte[] b)
    {
        if (a.Length != b.Length) return false;
        for (int i = 0; i < a.Length; ++i) if (a[i] != b[i]) return false;
        return true;
    }
    private static int VerifyResetMoves(string file, out int errors)
    {
        errors = 0;
        using (BinaryReader r = new BinaryReader(File.OpenRead(file)))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "ARSMV001") throw new Exception("Reset oracle signature mismatch");
            int count = r.ReadInt32();
            for (int c = 0; c < count; ++c)
            {
                uint random = r.ReadUInt32(); float distance = r.ReadSingle();
                CharacterResetParameters tuning = new CharacterResetParameters { ResetDistance = distance,
                    BaseRadius = r.ReadSingle(), Radius = r.ReadSingle(), Bottom = r.ReadSingle(), Top = r.ReadSingle(), Scale = r.ReadSingle() };
                bool coinEnabled = r.ReadUInt32() != 0;
                PcObjectImage o = new PcObjectImage(r.ReadBytes(PcObjectImage.Size)); byte[] expected = r.ReadBytes(PcObjectImage.Size);
                byte[] pad = r.ReadBytes(96), expectedPad = r.ReadBytes(96), coin = r.ReadBytes(16), expectedCoin = r.ReadBytes(16);
                uint expectedRandom = r.ReadUInt32();
                RespawnState.ResetMovesWithoutClips(o, pad, coinEnabled ? coin : null, tuning, ref random);
                if (!Equal(o.Bytes, expected) || !Equal(pad, expectedPad) || !Equal(coin, expectedCoin) || random != expectedRandom)
                {
                    ++errors;
                    if (errors <= 10) Console.Error.WriteLine("ResetMoves mismatch in case " + c);
                }
            }
            if (r.BaseStream.Position != r.BaseStream.Length) throw new Exception("Trailing reset oracle bytes");
            return count;
        }
    }
    private static int VerifySpawnPointers(string file, out int errors)
    {
        errors = 0;
        using (BinaryReader r = new BinaryReader(File.OpenRead(file)))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "ASPAWN01") throw new Exception("Spawn oracle signature mismatch");
            int count = r.ReadInt32();
            for (int c = 0; c < count; ++c)
            {
                sbyte slot = r.ReadSByte(); byte fallback = r.ReadByte(); r.ReadUInt16(); uint[] pointers = new uint[8];
                for (int i = 0; i < 8; ++i) pointers[i] = r.ReadUInt32();
                uint expected = r.ReadUInt32();
                if (CharacterContexts.SelectStartPositionPointer(slot, fallback, pointers) != expected) ++errors;
            }
            if (r.BaseStream.Position != r.BaseStream.Length) throw new Exception("Trailing spawn oracle bytes");
            return count;
        }
    }
    private static ClipSet Clips(uint[] p, int offset, float frames, float fps, float blend, uint flags)
    {
        ClipSet result = new ClipSet(233);
        for (int id = 0; id < 233; ++id)
            result.Actions[id] = new ClipInfo { Present = (p[offset + id / 32] & (1u << (id % 32))) != 0,
                FrameCount = frames, FramesPerSecond = fps, BlendOutSeconds = blend, Flags = flags };
        return result;
    }
    public static int Main(string[] args)
    {
        if (args.Length != 2) { Console.Error.WriteLine("Usage: AnimationDifferentialHarness cases.bin results.json"); return 2; }
        if (Marshal.SizeOf(typeof(PcCharacterKnownFields)) != PcObjectImage.Size ||
            Marshal.OffsetOf(typeof(PcCharacterKnownFields), "Context").ToInt32() != 0x7b5 ||
            Marshal.OffsetOf(typeof(PcCharacterKnownFields), "TerrainImpactSpeed").ToInt32() != 0x1030)
            throw new Exception("Recovered field layout mismatch");
        int[] counts = new int[8], errors = new int[8]; int total = 0, mismatches = 0; string examples = "";
        using (BinaryReader r = new BinaryReader(File.OpenRead(args[0])))
        {
            if (System.Text.Encoding.ASCII.GetString(r.ReadBytes(8)) != "ANIMCS01") throw new Exception("Case file signature mismatch");
            int caseCount = r.ReadInt32();
            for (int c = 0; c < caseCount; ++c)
            {
                int kind = r.ReadInt32(), length = r.ReadInt32(); uint[] p = new uint[length];
                for (int i = 0; i < length; ++i) p[i] = r.ReadUInt32();
                PcObjectImage o = new PcObjectImage(r.ReadBytes(PcObjectImage.Size)); byte[] expected = r.ReadBytes(PcObjectImage.Size);
                uint expectedResult = r.ReadUInt32(), expectedRandom = r.ReadUInt32(), result = 0, random = 0;
                if (kind == 1) CharacterContexts.ResetWithoutMoves(o);
                else if (kind == 2) result = (uint)CharacterContexts.AdvanceHitContext(o, Clips(p, 5, F(p[1]), F(p[2]), F(p[3]), p[4]), F(p[0]));
                else if (kind == 3) CharacterContexts.SelectMovementAnimation(o, Clips(p, 7, 61, 30, 0, 0), F(p[0]), p[1] != 0, p[2] != 0, F(p[3]), F(p[4]), F(p[5]), p[6] != 0);
                else if (kind == 4) CharacterContexts.SelectJumpAnimation(o, Clips(p, 2, 61, 30, 0, 0), F(p[0]), F(p[1]));
                else if (kind == 5) { random = p[0]; result = CharacterContexts.SelectBlockAnimation(o, Clips(p, 1, 61, 30, 0, 0), ref random) ? 1u : 0; }
                else if (kind == 6) CharacterContexts.StartBlockJump(o, (int)p[0], F(p[1]));
                else if (kind == 7) result = PcObjectImage.ToBits(CharacterContexts.DurationSeconds(new ClipInfo { Present = true, FrameCount = F(p[0]), FramesPerSecond = F(p[1]), BlendOutSeconds = F(p[2]) }, F(p[3]), F(p[4]), p[5] != 0));
                else throw new Exception("Unknown case type");
                int firstByte = -1;
                for (int i = 0; i < expected.Length; ++i) if (expected[i] != o.Bytes[i]) { firstByte = i; break; }
                ++total; ++counts[kind];
                if (firstByte != -1 || expectedResult != result || expectedRandom != random)
                {
                    ++mismatches; ++errors[kind];
                    if (mismatches <= 20) examples += (examples.Length == 0 ? "" : ",") + "{\"case\":" + c + ",\"kind\":" + kind + ",\"firstByte\":" + firstByte + ",\"result\":" + result + ",\"expectedResult\":" + expectedResult + "}";
                }
            }
            if (r.BaseStream.Position != r.BaseStream.Length) throw new Exception("Trailing case bytes");
        }
        int resetErrors, spawnErrors, playbackErrors, idleErrors, controlErrors;
        int resetCases = VerifyResetMoves(Path.Combine(Path.GetDirectoryName(args[0]), "animation-reset-moves-cases.bin"), out resetErrors);
        int spawnCases = VerifySpawnPointers(Path.Combine(Path.GetDirectoryName(args[0]), "animation-spawn-pointer-cases.bin"), out spawnErrors);
        int playbackCases = VerifyPlayback(Path.Combine(Path.GetDirectoryName(args[0]), "animation-playback-cases.bin"), out playbackErrors);
        int idleCases = VerifyIdle(Path.Combine(Path.GetDirectoryName(args[0]), "animation-idle-cases.bin"), out idleErrors);
        int controlCases = VerifyControl(Path.Combine(Path.GetDirectoryName(args[0]), "animation-control-cases.bin.gz"), out controlErrors);
        total += resetCases + spawnCases + playbackCases + idleCases + controlCases; mismatches += resetErrors + spawnErrors + playbackErrors + idleErrors + controlErrors;
        string contractJson = "";
        for (int i = 1; i < 8; ++i) contractJson += (i == 1 ? "" : ",") + "\"" + i + "\":{\"cases\":" + counts[i] + ",\"mismatches\":" + errors[i] + "}";
        string json = "{\"method\":\"Compiled dependency-free C# compared byte-for-byte with original PC function outputs; complete object/packet images, return/effect value and RNG state.\",\"cases\":" + total + ",\"mismatches\":" + mismatches + ",\"contracts\":{" + contractJson + "},\"resetMoves\":{\"cases\":" + resetCases + ",\"mismatches\":" + resetErrors + "},\"spawnPointers\":{\"cases\":" + spawnCases + ",\"mismatches\":" + spawnErrors + "},\"playback\":{\"cases\":" + playbackCases + ",\"mismatches\":" + playbackErrors + "},\"examples\":[" + examples + "]}";
        json = json.Substring(0, json.Length - 1) + ",\"idleScheduling\":{\"cases\":" + idleCases + ",\"mismatches\":" + idleErrors + "}}";
        json = json.Substring(0, json.Length - 1) + ",\"animationControl\":{\"cases\":" + controlCases + ",\"mismatches\":" + controlErrors + "}}";
        File.WriteAllText(args[1], json); Console.WriteLine(json); return mismatches == 0 ? 0 : 1;
    }
}
