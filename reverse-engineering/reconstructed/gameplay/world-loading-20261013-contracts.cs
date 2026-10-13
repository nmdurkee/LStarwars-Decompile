using System;

namespace Recovered.Gameplay
{
    // Memory abstraction preserves the original32-bit addresses; it is not a native pointer bridge.
    public interface IWorldLoadingMemory
    {
        uint ReadUInt32(uint address);
        sbyte ReadSByte(uint address);
        byte ReadByte(uint address);
        void WriteUInt32(uint address, uint value);
        void Clear(uint address, int size);
        string ReadCString(uint address);
        void WriteCString(uint address, string value);
    }

    // All five callees are external contracts. They may update memory through their implementation.
    public interface IWorldLoadingCalls
    {
        void Invoke(uint nativeEntry, params uint[] arguments);
    }

    public static class WorldLoadingContracts
    {
        public const uint FirstWorld = 0x93d858, SecondWorld = 0x942a04;
        public const int WorldBytes = 0x51ac;
        static uint Add(uint address, int delta) { return unchecked(address + (uint)delta); }
        static uint Other(uint world) { return world == FirstWorld ? SecondWorld : FirstWorld; }
        static uint Read(IWorldLoadingMemory m, uint world, int offset) { return m.ReadUInt32(Add(world, offset)); }
        static void Write(IWorldLoadingMemory m, uint world, int offset, uint value) { m.WriteUInt32(Add(world, offset), value); }
        static uint Table(IWorldLoadingMemory m, uint global, int index, int stride)
        { return Add(m.ReadUInt32(global), unchecked(index * stride)); }

        //0x55ffb0. Return1 requests rebuilding; +110 is cleared and is not a success result.
        //Native paths are unchecked. This fragment requires both strings to fit their128-byte slots.
        public static uint Initialize(IWorldLoadingMemory m, IWorldLoadingCalls calls, uint world, int level)
        {
            bool loaded = Read(m, world, 0x110) != 0;
            calls.Invoke(0x566630, 0);
            if (loaded)
            {
                if (unchecked((int)Read(m, world, 0x11c)) == level &&
                    m.ReadSByte(Add(Table(m, 0x951b78, level, 0x130), 0xa3)) != -1 &&
                    m.ReadUInt32(0x87b71c) == 0) return 0;
                calls.Invoke(0x55f6c0, world);
            }
            if (m.ReadUInt32(0x87b71c) != 0)
            {
                uint other = Other(world);
                if (Read(m, other, 0x110) != 0 && unchecked((int)Read(m, other, 0x11c)) == level)
                    calls.Invoke(0x55f6c0, other);
            }
            uint end = Read(m, world, 0x108), start = Read(m, world, 0x100);
            m.Clear(world, WorldBytes);
            Write(m, world, 0x108, end);
            Write(m, world, 0x100, start);
            Write(m, world, 0x104, start);
            int size = unchecked((int)(end - start));
            if (size > 0) m.Clear(start, size);
            Write(m, world, 0x11c, unchecked((uint)level));
            Write(m, world, 0x120, uint.MaxValue);
            Write(m, world, 0x124, uint.MaxValue);
            if (level != -1)
            {
                uint record = Table(m, 0x951b78, level, 0x130);
                Write(m, world, 0x128, record);
                int area = m.ReadSByte(Add(record, 0xa3));
                Write(m, world, 0x120, unchecked((uint)area));
                if (area != -1)
                {
                    uint areaRecord = Table(m, 0x951354, area, 0x9c);
                    Write(m, world, 0x12c, areaRecord);
                    Write(m, world, 0x124, unchecked((uint)m.ReadSByte(Add(areaRecord, 0x86))));
                }
                foreach (int offset in new[] { 0x2a98, 0x2aa0, 0x2aa4, 0x2aa8, 0x2a9c })
                    Write(m, world, offset, uint.MaxValue);
                int slot = m.ReadSByte(Add(record, 0xc8));
                //The native lower bound excludes exactly-1. Other negative values compute a pointer before the base.
                Write(m, world, 0x130, slot == -1 || slot >= 12 ? 0 : Table(m, 0x87b2cc, slot, 0x2e28));
                string directory = m.ReadCString(0x75a208) + m.ReadCString(record);
                string basePath = directory + m.ReadCString(0x75a204) + m.ReadCString(Add(record, 0x40));
                if (directory.Length >= 128 || basePath.Length >= 128)
                    throw new ArgumentException("Prepared native ASCII paths must fit128-byte slots.");
                m.WriteCString(world, directory);
                m.WriteCString(Add(world, 0x80), basePath);
                calls.Invoke(0x547ba0, world);
            }
            return 1;
        }

        //0x55f500. The opposite fixed world is selected even if the input is not either fixed address.
        public static uint OtherCachedLevel(IWorldLoadingMemory m, uint world)
        {
            uint other = Other(world);
            return Read(m, other, 0x110) != 0 ? Read(m, other, 0x11c) : uint.MaxValue;
        }

        //0x55f470. End-address comparisons are unsigned (JAE/JBE); endpoint arithmetic wraps32 bits.
        public static void AssignArenaEnds(IWorldLoadingMemory m, int area, int previousArea)
        {
            bool flag8 = area != -1 && (m.ReadByte(Add(Table(m, 0x951354, area, 0x9c), 0x7a)) & 8) != 0;
            if (flag8 && area != previousArea)
            {
                m.WriteUInt32(0x802c58, FirstWorld);
                m.WriteUInt32(0x802c54, FirstWorld);
                uint first = Read(m, FirstWorld, 0x108), second = Read(m, SecondWorld, 0x108);
                if (first < second)
                {
                    Write(m, SecondWorld, 0x108, first);
                    Write(m, FirstWorld, 0x108, unchecked(second - m.ReadUInt32(0x9248b4)));
                }
                return;
            }
            if (flag8) return;
            uint end1 = Read(m, FirstWorld, 0x108), end2 = Read(m, SecondWorld, 0x108);
            if (end1 > end2)
            {
                Write(m, FirstWorld, 0x108, end2);
                Write(m, SecondWorld, 0x108, unchecked(end1 + m.ReadUInt32(0x9248b4)));
            }
        }

        //0x560630. The expensive resource loader0x48ce00 remains an explicit external callback.
        public static void Stage(IWorldLoadingMemory m, IWorldLoadingCalls calls)
        {
            calls.Invoke(0x6df940);
            uint staging = m.ReadUInt32(0x802c58);
            int area = unchecked((int)m.ReadUInt32(0x803784));
            if (staging == m.ReadUInt32(0x802c54) &&
                (area == -1 || (m.ReadByte(Add(Table(m, 0x951354, area, 0x9c), 0x7a)) & 8) == 0))
            {
                staging = Other(staging);
                m.WriteUInt32(0x802c58, staging);
            }
            int level = unchecked((int)m.ReadUInt32(0x93d848));
            if (Initialize(m, calls, staging, level) != 0)
            {
                staging = m.ReadUInt32(0x802c58);
                m.WriteUInt32(0x93d84c, m.ReadUInt32(0x93d848));
                calls.Invoke(0x48ce00, staging);
            }
            staging = m.ReadUInt32(0x802c58);
            m.WriteUInt32(0x93d84c, uint.MaxValue);
            if (Read(m, staging, 0x110) != 0) m.WriteUInt32(0x802c68, m.ReadUInt32(0x93d848));
        }
    }
}
