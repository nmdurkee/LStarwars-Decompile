// Standalone verification harness. The core has no System.Web dependency.
using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayMessageVerify
{
    static int checks, failures;
    static readonly List<object> errors = new List<object>();
    static Dictionary<string, object> Obj(object value) { return (Dictionary<string, object>)value; }
    static object[] Arr(object value) { return (object[])value; }
    static uint UInt(object value) { return Convert.ToUInt32(value); }
    static uint Bits(float value) { return BitConverter.ToUInt32(BitConverter.GetBytes(value), 0); }
    static string[] Tokens(object value)
    {
        object[] input = Arr(value); string[] result = new string[input.Length];
        for (int i = 0; i < input.Length; ++i) result[i] = (string)input[i];
        return result;
    }
    static void Check(string kind, object actual, object expected, object context)
    {
        ++checks;
        if (!Object.Equals(actual, expected)) { ++failures; if (errors.Count < 20) errors.Add(new { kind, actual, expected, context }); }
    }
    static void Run(Dictionary<string, object> input, bool shipped, ScriptPacket packet)
    {
        string command = (string)input["command"]; string[] tokens = Tokens(input["tokens"]);
        uint initial = shipped ? Bits(1.25f) : input.ContainsKey("initialBits") ? UInt(input["initialBits"]) : 0;
        MessageRegistry registry = new MessageRegistry(new uint[] { initial, initial, initial, initial, initial, initial, initial, initial });
        bool first = !input.ContainsKey("first") || Convert.ToBoolean(input["first"]);
        MessageRegistry supplied = input.ContainsKey("registry") && !Convert.ToBoolean(input["registry"]) ? null : registry;
        if (command == "SetMessage") Check("command-result", MessageCommands.Set(supplied, packet, tokens, first), true, input);
        else if (command == "SetAIMessage") MessageCommands.SetAI(supplied, tokens);
        else if (command == "CopyMessage")
        {
            if (!shipped) registry.Resolve("source", null).ValueBits = UInt(input["sourceBits"]);
            Check("copy-result", MessageCommands.Copy(supplied, tokens, first), true, input);
        }
        else if (command == "Message") Check("condition-live-read", Bits(MessageCommands.Read(MessageCommands.Bind(registry, true, tokens[0]))), initial, input);
        else throw new InvalidOperationException(command);
        object[] expected = Arr(input["native"]);
        Check("active-count", registry.Active.Count, expected.Length, input);
        for (int i = 0; i < Math.Min(expected.Length, registry.Active.Count); ++i)
        {
            Dictionary<string, object> record = Obj(expected[i]);
            Check("active-name", registry.Active[i].Name, (string)record["name"], input);
            Check("active-value-bits", registry.Active[i].ValueBits, UInt(record["bits"]), input);
        }
    }
    public static int Main(string[] args)
    {
        checks = failures = 0; errors.Clear();
        JavaScriptSerializer json = new JavaScriptSerializer(); json.MaxJsonLength = 64 * 1024 * 1024;
        Dictionary<string, object> data = Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        ScriptPacket packet = new ScriptPacket { Script = new ScriptDefinition() };
        for (int i = 0; i < 4; ++i)
        {
            packet.Parameters[i] = Convert.ToSingle(Arr(data["parameters"])[i]);
            packet.Script.ParameterNames[i] = (string)Arr(data["parameterNames"])[i];
        }
        foreach (object input in Arr(data["cases"])) Run(Obj(input), false, packet);
        foreach (object input in Arr(data["shipped"])) Run(Obj(input), true, packet);
        string output = json.Serialize(new { checks, mismatches = failures, errors, method = "Compiled C# comparison against captured original-PC message fixtures." });
        if (args.Length > 1) File.WriteAllText(args[1], output);
        Console.WriteLine(output);
        return failures == 0 ? 0 : 1;
    }
}
