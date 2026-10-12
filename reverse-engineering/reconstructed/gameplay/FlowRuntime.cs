// Reconstructed from the PC image identified in gameplay-git-runtime-contract.json.
// Handwritten portable implementation, not recovered original source.
// C# 5 / .NET Framework compatible; no Unity, filesystem, renderer or native dependencies.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public enum FlowKind : byte { Gizmo, Condition, Action }
    public enum FlowCondition : byte { All, Any, None, Sum, Loop, Exactly }

    // Implement these callbacks to connect physical objects. Graph code controls callback order.
    // Null callbacks represent an absent native registered callback, not a successful operation.
    public sealed class GizmoCallbacks
    {
        public Func<byte, bool, bool> Output;
        public Action<bool> Activate;
        public Func<bool, int, bool> Reverse;
        public Action<bool> Visibility;
        public void SetActive(bool value)
        {
            if (Activate == null) return;
            if (value && Visibility != null) Visibility(true);
            Activate(value);
        }
        public void SetVisible(bool value)
        {
            if (Visibility == null) return;
            if (!value && Activate != null) Activate(false);
            Visibility(value);
        }
        public void SetReverse(bool reverse, bool visibility)
        {
            int command = visibility ? 6 : 2;
            if (Reverse == null || !Reverse(reverse, command | 1)) return;
            Reverse(reverse, command);
            if (visibility) SetVisible(!reverse);
        }
    }

    public sealed class QRandom
    {
        public uint State;
        public uint Next() { State = unchecked(State * 0x24cdu + 1u) & 65535u; return State; }
        public static int PercentDraw(uint state)
        {
            if (state > 65535) throw new ArgumentOutOfRangeException("state");
            // Exact integer equivalent of the original x87 floor(state*C*100)+1,
            // for the entire 16-bit state domain. Avoids double-rounding at the top endpoint.
            return Math.Max(1, (int)((state * 100u + 65534u) / 65535u));
        }
    }

    public sealed class FlowTimer
    {
        public float Duration, Remaining;
        public byte Flags;
        public QRandom Random;
        public FlowTimer(float duration, QRandom random) { Duration = Remaining = duration; Random = random; }
        public void Update(float delta) { if (Remaining >= 0) Remaining = (float)(Remaining - delta); }
        public void Activate(bool value)
        {
            if ((Flags & 2) != 0)
            {
                if (Random == null) throw new InvalidOperationException("Randomized timers require shared QRAND state.");
                Remaining = (float)(Random.Next() * 1.5259021893143654e-5 * (double)Duration);
            }
            else Remaining = Duration;
            Flags = (byte)((Flags & ~1) | (value ? 1 : 0));
        }
        public bool Output(byte index, bool includeInactive) { return (Flags & 1) != 0 && Remaining <= 0; }
        public GizmoCallbacks Callbacks() { return new GizmoCallbacks { Activate = Activate, Output = Output }; }
    }

    public sealed class FlowRandom
    {
        public int[] Weights = new int[0];
        public int Selected = -1;
        public byte Flags;
        public QRandom Random;
        public void Activate(bool value)
        {
            if (!value) { Flags = (byte)(Flags & ~1); return; }
            if (Weights.Length > 8) throw new InvalidOperationException("PC GizRandom supports eight weights.");
            if (Random == null) throw new InvalidOperationException("GizRandom requires shared QRAND state.");
            Flags |= 1; Selected = -1;
            int draw = QRandom.PercentDraw(Random.Next()), low = 0;
            for (int i = 0; i < Weights.Length; ++i)
            {
                int high = unchecked(low + Weights[i]);
                if (low <= draw && draw <= high) { Selected = i; return; }
                low = high;
            }
        }
        public bool Output(byte index, bool includeInactive) { return (Flags & 1) != 0 && Selected == index; }
        public GizmoCallbacks Callbacks() { return new GizmoCallbacks { Activate = Activate, Output = Output }; }
    }

    public struct FlowInput
    {
        public int Node;
        public byte Output;
        public FlowInput(int node, byte output) { Node = node; Output = output; }
    }
    public sealed class FlowNode
    {
        public FlowKind Kind;
        public FlowCondition Condition;
        public byte Threshold, LoopInputs, Generation, ResetGeneration;
        public ushort Flags;
        public string Name;
        public readonly List<FlowInput> Parents = new List<FlowInput>();
        public readonly List<int> Children = new List<int>();
        public readonly List<GizmoCallbacks> Gizmos = new List<GizmoCallbacks>();
        public readonly List<Action<FlowGraph, FlowNode>> Actions = new List<Action<FlowGraph, FlowNode>>();
    }

    public sealed class FlowGraph
    {
        public readonly List<FlowNode> Nodes = new List<FlowNode>();
        public byte Generation, ResetGeneration;
        // Corresponds to whether PC DAT_0093b2a4 is nonzero. Do not infer a mode name here.
        public bool AlternateMode;
        // Host safety boundary, not a native rule. Cycles must yield through outputs/timers.
        public int MaxOperations = 100000;
        int operations;
        void Step() { if (++operations > MaxOperations) throw new InvalidOperationException("Flow operation budget exceeded."); }
        bool Enabled(FlowNode n) { return ((n.Flags & 0x4000) != 0 || AlternateMode) && ((n.Flags & 0x2000) != 0 || !AlternateMode); }
        bool AllParents(FlowNode n)
        {
            foreach (FlowInput p in n.Parents) if (!ReadOutput(p.Node, p.Output)) return false;
            return true;
        }
        public bool Output(int index, byte output)
        {
            operations = 0;
            return ReadOutput(index, output);
        }
        bool ReadOutput(int index, byte output)
        {
            Step(); FlowNode n = Nodes[index];
            if (n.Kind == FlowKind.Gizmo)
            {
                if (!Enabled(n)) return true;
                bool result = true;
                foreach (GizmoCallbacks g in n.Gizmos)
                    if (g.Output == null || !g.Output(output, (n.Flags & 0x1000) != 0)) result = false;
                return result;
            }
            if (n.Kind == FlowKind.Condition && (n.Flags & 0x200) != 0)
            {
                ushort old = n.Flags; n.Flags |= 0x400;
                bool result = ConditionProcess(index);
                n.Flags = (ushort)((n.Flags & ~0x400) | (old & 0x400));
                return result;
            }
            return (n.Flags & 2) != 0;
        }
        bool ConditionProcess(int index)
        {
            FlowNode n = Nodes[index]; int total = 0;
            foreach (FlowInput p in n.Parents)
            {
                bool yes = ReadOutput(p.Node, p.Output);
                if (n.Condition == FlowCondition.All && !yes) return false;
                if (n.Condition == FlowCondition.None && yes) return false;
                if (yes) ++total;
            }
            bool result;
            switch (n.Condition)
            {
                case FlowCondition.Any: result = total >= 1; break;
                case FlowCondition.None: result = total == 0; break;
                case FlowCondition.Sum: result = total >= n.Threshold; break;
                case FlowCondition.Exactly: result = total == n.Threshold; break;
                case FlowCondition.Loop: result = total >= n.Parents.Count - ((n.Flags & 0x400) != 0 ? n.LoopInputs : 0); break;
                default: result = true; break;
            }
            if (result && n.Condition == FlowCondition.Loop)
                foreach (int child in n.Children) { ResetGeneration = unchecked((byte)(ResetGeneration + 1)); ResetWalk(index, child, ResetGeneration); }
            return result;
        }
        void ResetWalk(int owner, int index, byte stamp)
        {
            Step(); FlowNode n = Nodes[index];
            if (owner == index || n.ResetGeneration == stamp) return;
            n.ResetGeneration = stamp;
            if (n.Kind == FlowKind.Gizmo && (n.Flags & 0x1000) == 0) foreach (GizmoCallbacks g in n.Gizmos) g.SetActive(false);
            foreach (int child in n.Children) ResetWalk(owner, child, stamp);
        }
        void Cleanup(int current)
        {
            Step();
            foreach (FlowInput input in Nodes[current].Parents)
            {
                FlowNode parent = Nodes[input.Node];
                if ((parent.Flags & 0x20) == 0) continue;
                bool release = true;
                foreach (int childIndex in parent.Children)
                {
                    FlowNode child = Nodes[childIndex];
                    bool ready = (child.Flags & 0xc0) != 0 ? (child.Flags & 2) != 0 && (child.Flags & 0x100) == 0 : (child.Flags & 1) == 0 || childIndex == current;
                    if (!ready) { release = false; break; }
                }
                if (!release) continue;
                if ((parent.Flags & 8) != 0) foreach (GizmoCallbacks g in parent.Gizmos) g.SetVisible(false);
                else if ((parent.Flags & 0x10) != 0) foreach (GizmoCallbacks g in parent.Gizmos) g.SetActive(false);
                if ((parent.Flags & 0x40) != 0) { parent.Flags = (ushort)(parent.Flags & ~0x100); Cleanup(input.Node); }
                parent.Flags = (ushort)(parent.Flags & ~0x20);
            }
        }
        void Monitor(FlowNode n)
        {
            bool reverse = false;
            // The original monitor routine uses the first output-index byte for every parent.
            byte output = n.Parents.Count == 0 ? (byte)0 : n.Parents[0].Output;
            foreach (FlowInput p in n.Parents) if (!ReadOutput(p.Node, output)) { reverse = true; break; }
            foreach (GizmoCallbacks g in n.Gizmos) g.SetReverse(reverse, (n.Flags & 0x80) != 0);
        }
        void Process(int index)
        {
            Step(); FlowNode n = Nodes[index];
            if ((n.Flags & 0x100) != 0) Monitor(n);
            if ((n.Flags & 1) == 0) return;
            if (n.Kind == FlowKind.Condition) { if (!ConditionProcess(index)) return; }
            else
            {
                if (!AllParents(n)) return;
                if (n.Kind == FlowKind.Gizmo)
                {
                    Cleanup(index);
                    if ((n.Flags & 0x1000) == 0 && Enabled(n)) foreach (GizmoCallbacks g in n.Gizmos) g.SetActive(true);
                }
                else foreach (Action<FlowGraph, FlowNode> action in n.Actions) if (action != null) action(this, n);
            }
            if ((n.Flags & 0xc00) == 0xc00) n.Flags = (ushort)(n.Flags & ~0x400);
            n.Flags = (ushort)((n.Flags & ~1) | 0x802);
            if (n.Kind == FlowKind.Gizmo)
            {
                if ((n.Flags & 0x18) != 0)
                {
                    if (n.Children.Count == 0)
                    {
                        if ((n.Flags & 8) != 0) foreach (GizmoCallbacks g in n.Gizmos) g.SetVisible(false);
                        else foreach (GizmoCallbacks g in n.Gizmos) g.SetActive(false);
                        n.Flags = (ushort)(n.Flags & ~0x20);
                    }
                    else n.Flags |= 0x20;
                }
                if ((n.Flags & 0xc0) != 0)
                {
                    n.Flags |= 0x120;
                    foreach (FlowInput p in n.Parents)
                    {
                        FlowNode parent = Nodes[p.Node];
                        if (parent.Kind == FlowKind.Condition) parent.Flags |= 0x200;
                        if (parent.Kind == FlowKind.Gizmo && (parent.Flags & 0x40) != 0) parent.Flags |= 0x120;
                    }
                }
            }
            else Cleanup(index);
            foreach (int childIndex in n.Children)
            {
                FlowNode child = Nodes[childIndex]; child.Flags |= 1;
                if (child.Generation != Generation || n.Kind == FlowKind.Condition) { child.Generation = Generation; Process(childIndex); }
            }
        }
        public void Tick()
        {
            operations = 0; Generation = unchecked((byte)(Generation + 1));
            for (int i = 0; i < Nodes.Count; ++i)
            {
                FlowNode n = Nodes[i];
                if (n.Generation != Generation && (n.Flags & 0x101) != 0) Process(i);
                n.Generation = Generation;
            }
        }
        int ReturnWalk(int root, int index, int total, byte stamp)
        {
            Step(); FlowNode n = Nodes[index];
            if (root == index) { n.ResetGeneration = unchecked((byte)(n.ResetGeneration - 1)); return total + 1; }
            foreach (int child in n.Children)
                if (Nodes[child].ResetGeneration != stamp) { Nodes[child].ResetGeneration = stamp; total = ReturnWalk(root, child, total, stamp); }
            return total;
        }
        byte CountLoopInputs(int root)
        {
            ResetGeneration = unchecked((byte)(ResetGeneration + 1)); int total = 0;
            foreach (int child in Nodes[root].Children) total = ReturnWalk(root, child, total, ResetGeneration);
            return unchecked((byte)total);
        }
        // Adapter must resolve source names to Gizmos before this call; this does not parse GIT text.
        public void Initialize(uint[] saved)
        {
            operations = 0; Generation = 0;
            if (saved != null && saved.Length != 81) throw new ArgumentException("PC flow state is 81 words.");
            if (saved != null && saved[0] != 0 && Nodes.Count > 512) throw new ArgumentException("Saved flow state capacity is 512 nodes.");
            for (int i = 0; i < Nodes.Count; ++i)
            {
                FlowNode n = Nodes[i]; n.Flags = (ushort)(n.Flags & ~0x20); n.Generation = 0;
                bool loop = n.Kind == FlowKind.Condition && n.Condition == FlowCondition.Loop;
                if (saved != null && saved[0] != 0)
                {
                    int[] offsets = { 1, 0x21, 0x31, 0x41 }; ushort[] masks = { 1, 2, 0x20, 0x400 };
                    for (int j = 0; j < 4; ++j) n.Flags = (ushort)((n.Flags & ~masks[j]) | ((saved[offsets[j] + (i >> 5)] & (1u << (i & 31))) != 0 ? masks[j] : 0));
                    if (loop) n.LoopInputs = CountLoopInputs(i);
                    continue;
                }
                n.Flags &= 0xfedd;
                if (loop) { n.LoopInputs = CountLoopInputs(i); n.Flags |= 0x400; if (n.Parents.Count == n.LoopInputs) n.Flags |= 0x801; else n.Flags = (ushort)(n.Flags & ~1); }
                else n.Flags = (ushort)((n.Flags & ~1) | (n.Parents.Count == 0 ? 1 : 0));
                if (n.Kind == FlowKind.Gizmo)
                {
                    if ((n.Flags & 0x1000) == 0) foreach (GizmoCallbacks g in n.Gizmos) g.SetActive(false);
                    if (!Enabled(n) || ((n.Flags & 1) == 0 && (n.Flags & 4) != 0)) foreach (GizmoCallbacks g in n.Gizmos) g.SetVisible(false);
                }
            }
        }
        public uint[] Save()
        {
            if (Nodes.Count > 512) throw new InvalidOperationException("PC flow save capacity is 512 nodes.");
            uint[] words = new uint[81]; words[0] = 1; ushort[] masks = { 1, 0x100, 2, 0x20, 0x400 };
            for (int i = 0; i < Nodes.Count; ++i) for (int p = 0; p < 5; ++p) if ((Nodes[i].Flags & masks[p]) != 0) words[1 + 16 * p + (i >> 5)] |= 1u << (i & 31);
            return words;
        }
        public void TurnOnFlowBox(params string[] arguments)
        {
            string name = null; bool active = true;
            foreach (string argument in arguments)
            {
                int offset = argument.IndexOf("name=", StringComparison.OrdinalIgnoreCase);
                if (offset >= 0) name = argument.Substring(offset + 5);
                else if (String.Equals(argument, "FALSE", StringComparison.OrdinalIgnoreCase)) active = false;
            }
            if (name == null) return;
            foreach (FlowNode node in Nodes) if (String.Equals(node.Name, name, StringComparison.OrdinalIgnoreCase)) node.Flags = (ushort)((node.Flags & ~1) | (active ? 1 : 0));
        }
    }
}
