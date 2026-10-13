// Prepared managed replay of saved original-PC trigger observations. Compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class GameplayTriggerVerify
{
    static readonly JavaScriptSerializer Json = new JavaScriptSerializer { MaxJsonLength = Int32.MaxValue };
    static int checks, failures;
    static readonly List<object> errors = new List<object>();
    static Dictionary<string, object> M(object value) { return (Dictionary<string, object>)value; }
    static object[] A(object value) { return (object[])value; }
    static int I(object value) { return Convert.ToInt32(value, CultureInfo.InvariantCulture); }
    static uint U(object value) { return Convert.ToUInt32(value, CultureInfo.InvariantCulture); }
    static float F(object value) { return Convert.ToSingle(value, CultureInfo.InvariantCulture); }
    static bool B(object value) { return Convert.ToBoolean(value, CultureInfo.InvariantCulture); }
    static uint Bits(float value) { return BitConverter.ToUInt32(BitConverter.GetBytes(value), 0); }
    static void Check(string group, object actual, object expected, object input)
    {
        ++checks;
        if (Json.Serialize(actual) == Json.Serialize(expected)) return;
        ++failures; if (errors.Count < 16) errors.Add(new { group, actual, expected, input });
    }
    static bool Compare(float value, float threshold, string op)
    {
        switch (op) { case "==": return value == threshold; case "!=": return value != threshold; case "<": return value < threshold; case ">": return value > threshold; case "<=": return value <= threshold; case ">=": return value >= threshold; default: throw new ArgumentException(op); }
    }
    static void Condition(Dictionary<string, object> row)
    {
        var c = M(row["input"]); var masks = A(c["masks"]); TriggerObject[] objects = new TriggerObject[3];
        for (int i = 0; i < 3; ++i) { var v = A(masks[i]); objects[i] = new TriggerObject { MaskLow = U(v[0]), MaskHigh = U(v[1]) }; }
        TriggerArea bound = B(c["initialized"]) ? new TriggerArea { HasOwner = B(c["owner"]), OwnerIndex = I(c["index"]) } : null;
        TriggerArea fallback = B(c["fallback"]) ? new TriggerArea { HasOwner = B(c["owner"]), OwnerIndex = I(c["fallbackIndex"]) } : null;
        TriggerSystem system = B(c["system"]) ? new TriggerSystem { Areas = B(c["areaTable"]) ? new TriggerArea[0] : null, Player1 = B(c["player1"]) ? objects[0] : null, Player2 = B(c["player2"]) ? objects[1] : null } : null;
        float actual; string command = (string)row["command"];
        switch (command)
        {
            case "InTriggerArea": actual = TriggerConditions.InTriggerArea(B(c["creature"]) && B(c["object"]) ? objects[2] : null, fallback, bound); break;
            case "PlayerInTriggerArea": actual = TriggerConditions.PlayerInTriggerArea(system, fallback, bound); break;
            case "Player2InTriggerArea": actual = TriggerConditions.Player2InTriggerArea(system, fallback, bound); break;
            case "EitherPlayerInTriggerArea": actual = TriggerConditions.EitherPlayerInTriggerArea(system, fallback, bound); break;
            default: throw new ArgumentException(command);
        }
        Check(command, Bits(actual), U(row["nativeBits"]), row);
        if (row.ContainsKey("comparison")) { var cmp = M(row["comparison"]); Check("comparison", Compare(actual, F(cmp["threshold"]), (string)cmp["operator"]), B(cmp["native"]), row); }
    }
    static void Lookup(Dictionary<string, object> row)
    {
        var names = A(row["names"]); TriggerArea[] areas = new TriggerArea[names.Length];
        for (int i = 0; i < areas.Length; ++i) areas[i] = new TriggerArea { Name = (string)names[i], HasOwner = true, OwnerIndex = i };
        TriggerSystem system = B(row["system"]) ? new TriggerSystem { Areas = areas, AreaCount = I(row["count"]) } : null;
        TriggerArea got = (string)row["reader"] == "find" ? TriggerConditions.FindArea(system, (string)row["operand"]) : TriggerConditions.BindArea(system, (string)row["operand"]);
        Check("lookup", got == null ? -1 : Array.IndexOf(areas, got), I(row["nativeIndex"]), row);
    }
    static void Producer(Dictionary<string, object> row, float[] sine)
    {
        var a = M(row["area"]); var pos = A(a["position"]); var extent = A(a["extent"]);
        TriggerArea area = new TriggerArea { X = F(pos[0]), Y = F(pos[1]), Z = F(pos[2]), HalfWidth = F(extent[0]), Height = F(extent[1]), HalfDepth = F(extent[2]), Yaw = (short)I(a["yaw"]), State = (byte)I(a["state"]) };
        var raw = A(row["objects"]); TriggerObject[] objects = new TriggerObject[raw.Length];
        for (int i = 0; i < raw.Length; ++i)
        {
            var o = M(raw[i]); var p = A(o["position"]); var mask = A(o["mask"]);
            objects[i] = new TriggerObject { X = F(p[0]), Y = F(p[1]), Z = F(p[2]), EligibilityFlags = U(o["flags"]), StateFlags = U(o["stateFlags"]), Restricted = (byte)I(o["restricted"]), RestrictedTimer = F(o["timer"]), MaskLow = U(mask[0]), MaskHigh = U(mask[1]) };
        }
        TriggerConditions.UpdateArea(area, I(a["index"]), objects, sine);
        uint[][] masks = new uint[objects.Length][];
        for (int i = 0; i < objects.Length; ++i) masks[i] = new uint[] { objects[i].MaskLow, objects[i].MaskHigh };
        Check("producer", new object[] { (int)area.State, masks }, new object[] { I(row["nativeState"]), row["nativeMasks"] }, row);
    }
    // Arguments: original oracle .json.gz, sine-table .f32, output report .json.
    // The shared verifier can call this entrypoint without launching another process.
    public static int Main(string[] args)
    {
        if (args.Length != 3) throw new ArgumentException("<oracle.json.gz> <sine-table.f32> <output.json>");
        checks = failures = 0; errors.Clear(); Dictionary<string, object> input;
        using (var file = File.OpenRead(args[0])) using (var gzip = new GZipStream(file, CompressionMode.Decompress)) using (var text = new StreamReader(gzip)) input = M(Json.DeserializeObject(text.ReadToEnd()));
        byte[] bytes = File.ReadAllBytes(args[1]); if (bytes.Length != 32768 * 4) throw new ArgumentException("Sine table length");
        float[] sine = new float[32768]; for (int i = 0; i < sine.Length; ++i) sine[i] = BitConverter.ToSingle(bytes, i * 4);
        foreach (object row in A(input["conditions"])) Condition(M(row));
        foreach (object row in A(input["lookups"])) Lookup(M(row));
        foreach (object row in A(input["producers"])) Producer(M(row), sine);
        File.WriteAllText(args[2], Json.Serialize(new { checks, failures, errors }));
        return failures == 0 ? 0 : 1;
    }
}
