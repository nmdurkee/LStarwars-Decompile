// Bounded PC visibility commands; renderer/object lifetime stays host-owned.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class SceneVisibilityItem
    {
        public string Name;
        public bool Dynamic, HasSecondary = true;
        public uint Flags, SecondaryFlags;
        public void SetVisible(bool visible)
        {
            uint mask = Dynamic ? 0x202u : 0x200u;
            Flags = (Flags & ~mask) | (visible ? mask : 0);
            if (HasSecondary) SecondaryFlags = (SecondaryFlags & ~1u) | (visible ? 1u : 0);
        }
    }
    public sealed class SceneVisibilityRegistry
    {
        // The host selects static or dynamic records for the current scene, in
        // native order. Dynamic fallback 0x5c1300 is deliberately not simulated.
        public readonly List<SceneVisibilityItem> Items = new List<SceneVisibilityItem>();
        public SceneVisibilityItem Find(string name)
        {
            if (name == null) return null;
            foreach (SceneVisibilityItem item in Items)
                if (String.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase)) return item;
            return null;
        }
    }
    public sealed class NamedGizmo
    {
        public string Name;
        public GizmoCallbacks Callbacks;
    }
    public sealed class NamedGizmoType
    {
        public string Name;
        public bool HasNameLookup = true;
        public readonly List<NamedGizmo> Items = new List<NamedGizmo>();
    }
    public sealed class NamedGizmoRegistry
    {
        public readonly List<NamedGizmoType> Types = new List<NamedGizmoType>();
        public int FindType(string name)
        {
            // Original type helper uses case-sensitive comparison. Failure -1
            // intentionally becomes an all-type search in the name lookup.
            if (name != null)
                for (int i = 0; i < Types.Count; ++i)
                    if (String.Equals(name, Types[i].Name, StringComparison.Ordinal)) return i;
            return -1;
        }
        public NamedGizmo Find(int typeIndex, string name)
        {
            if (name == null) return null;
            // This index cannot be produced by FindType. Native direct calls at
            // index == count read past the table, so reject that domain explicitly.
            if (typeIndex == Types.Count) throw new ArgumentOutOfRangeException("typeIndex");
            bool all = typeIndex < 0 || typeIndex > Types.Count;
            for (int i = 0; i < Types.Count; ++i)
                if ((all || i == typeIndex) && Types[i].HasNameLookup)
                    foreach (NamedGizmo item in Types[i].Items)
                        if (String.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase)) return item;
            return null;
        }
    }
    public static class VisibilityCommands
    {
        public static void Scene(SceneVisibilityRegistry scene, string[] tokens)
        {
            SceneVisibilityItem selected = null; bool visible = true;
            if (tokens != null)
                foreach (string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);
                    int at = token.IndexOf("name=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0) selected = scene == null ? null : scene.Find(token.Substring(at + 5));
                    else if (token.IndexOf("FALSE", StringComparison.OrdinalIgnoreCase) >= 0) visible = false;
                }
            if (selected != null) selected.SetVisible(visible);
        }
        public static bool SceneScript(SceneVisibilityRegistry scene, string[] tokens, bool firstCall)
        {
            if (firstCall) Scene(scene, tokens);
            return true;
        }
        public static void Gizmo(NamedGizmoRegistry registry, string[] tokens)
        {
            string name = null; bool visible = true; int type = -1;
            if (tokens != null)
                foreach (string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);
                    int at = token.IndexOf("name=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0) name = token.Substring(at + 5);
                    else
                    {
                        at = token.IndexOf("type=", StringComparison.OrdinalIgnoreCase);
                        if (at >= 0) type = registry == null ? -1 : registry.FindType(token.Substring(at + 5));
                        else if (token.IndexOf("FALSE", StringComparison.OrdinalIgnoreCase) >= 0) visible = false;
                    }
                }
            NamedGizmo selected = registry == null ? null : registry.Find(type, name);
            if (selected != null && selected.Callbacks != null) selected.Callbacks.SetVisible(visible);
        }
        public static bool GizmoScript(NamedGizmoRegistry registry, string[] tokens, bool firstCall)
        {
            if (!firstCall) return true;
            NamedGizmo selected = null; bool visible = true;
            if (tokens != null)
                foreach (string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);
                    int at = token.IndexOf("name=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0) selected = registry == null ? null : registry.Find(-1, token.Substring(at + 5));
                    else if (String.Equals(token, "FALSE", StringComparison.OrdinalIgnoreCase)) visible = false;
                }
            if (selected != null && selected.Callbacks != null) selected.Callbacks.SetVisible(visible);
            return true;
        }
    }
}
