using System;
using System.IO;
using System.Collections.Generic;
using Recovered.Geometry;

internal static class GeometryUvHarness
{
    private static void WriteOffsets(BinaryWriter writer, UvMaterial m)
    {
        foreach (UvLayer l in m.Layers) { writer.Write(l.UOffset); writer.Write(l.VOffset); }
    }
    public static int Main(string[] args)
    {
        if (args.Length != 3) { Console.Error.WriteLine("Usage: GeometryUvHarness fixtures.bin original-sine-table.f32 output.bin"); return 2; }
        NativeSineTable sine = NativeSineTable.DecodeLittleEndian(File.ReadAllBytes(args[1]));
        int cases = 0, ticks = 0;
        using (BinaryReader reader = new BinaryReader(File.OpenRead(args[0])))
        using (BinaryWriter writer = new BinaryWriter(File.Create(args[2])))
        {
            if (reader.ReadUInt32() != 0x31565547) throw new InvalidDataException("Fixture magic");
            int count = reader.ReadInt32(); writer.Write(count);
            for (int i = 0; i < count; ++i)
            {
                byte[] record = reader.ReadBytes(708); bool member = reader.ReadBoolean(); int sequences = reader.ReadInt32();
                for (int j = 0; j < sequences; ++j)
                {
                    UvMaterial material = UvMaterial.DecodeCurrentRecord(record);
                    UvScene scene = new UvScene(new UvMaterial[] { material });
                    List<UvAnimationSet> sets = new List<UvAnimationSet>();
                    if (member) sets.Add(new UvAnimationSet(scene, new int[] { 0 }));
                    float time = reader.ReadSingle(); int steps = reader.ReadInt32();
                    for (int k = 0; k < steps; ++k)
                    {
                        float delta = reader.ReadSingle();
                        MaterialUv.Advance(delta, ref time, sets, sine);
                        WriteOffsets(writer, material); writer.Write(time); ++ticks;
                    }
                }
                ++cases;
            }
            int wrappers = reader.ReadInt32(); writer.Write(wrappers);
            for (int i = 0; i < wrappers; ++i)
            {
                bool reset = reader.ReadBoolean(); float speed = reader.ReadSingle();
                UvMaterial[] materials = { new UvMaterial(), new UvMaterial() };
                UvScene[] scenes = { new UvScene(new UvMaterial[] { materials[0] }), new UvScene(new UvMaterial[] { materials[1] }) };
                scenes[1].ResetEligible = true;
                foreach (UvMaterial material in materials)
                    for (int j = 0; j < 4; ++j) { material.Layers[j].UOffset = .125f * (j * 2 + 1); material.Layers[j].VOffset = .125f * (j * 2 + 2); }
                UvClock clock = new UvClock { PhaseTime = 8, UnscaledTime = 12, SpeedScale = speed, ResetPending = reset };
                MaterialUv.Tick(.03125f, clock, new UvAnimationSet[0], scenes, sine);
                foreach (UvMaterial material in materials) WriteOffsets(writer, material);
                writer.Write(clock.PhaseTime); writer.Write(clock.UnscaledTime); writer.Write(clock.ResetPending);
            }
            if (reader.BaseStream.Position != reader.BaseStream.Length) throw new InvalidDataException("Fixture trailing bytes");
        }
        Console.WriteLine("Recovered Geometry UV: " + cases + " configurations, " + ticks + " updates.");
        return 0;
    }
}
