using System;
namespace Recovered.Gameplay
{
    public sealed class ExpressionLoadContext
    {
        // Native DWORD globals 92224c,922250,922254. The second field tracks
        // the most recent symbol, not an accumulated unresolved-symbol flag.
        public uint SeenSymbol,LastSymbolUnresolved,RequiresRuntime;
        public ExpressionSymbolCallback GameSymbol;
        public Action ObserveError;
        public ExpressionParserState LastParser;
    }
    public static class ScriptExpressionLoading
    {
        static float Resolve(ExpressionLoadContext context,string name)
        {
            MessageNumbers.RequireAscii(name);context.SeenSymbol=1;context.LastSymbolUnresolved=1;
            float value=0;
            if(context.GameSymbol!=null&&context.GameSymbol(null,null,name,out value))context.LastSymbolUnresolved=0;
            // Unlike runtime 514850, a false callback's written value survives.
            // No reserved words or packet-parameter fallback exist here.
            return value;
        }
        // 0x513230: load-time symbol callback, optional output pointers.
        public static int ResolveOutputs(ExpressionLoadContext context,string name,float[] floatOutput,uint[] integerOutput)
        {
            float value=Resolve(context,name);
            if(floatOutput!=null){if(floatOutput.Length==0)throw new ArgumentException("Missing float output slot.");floatOutput[0]=value;}
            if(integerOutput!=null)
            {
                if(integerOutput.Length==0)throw new ArgumentException("Missing integer output slot.");
                integerOutput[0]=Single.IsNaN(value)||Single.IsInfinity(value)||(double)value>=9223372036854775808.0||(double)value< -9223372036854775808.0?0u:unchecked((uint)(long)value);
            }
            return 0;
        }
        // 0x5132a0: full grammar even for strings accepted by the runtime fast
        // path. Condition loader 52b3f0 uses RequiresRuntime to retain the text.
        public static float Evaluate(ExpressionLoadContext context,ExpressionBuffer text)
        {
            context.SeenSymbol=0;context.LastSymbolUnresolved=0;context.RequiresRuntime=0;
            float value=ScriptExpressions.Parse(text,delegate(string name){return Resolve(context,name);},context.ObserveError,out context.LastParser);
            if(context.LastSymbolUnresolved!=0)context.RequiresRuntime=1;
            return value;
        }
    }
}
