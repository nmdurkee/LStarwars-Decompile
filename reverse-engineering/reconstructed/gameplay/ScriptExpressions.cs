using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class ExpressionBuffer
    {
        internal readonly char[] Characters;
        public ExpressionBuffer(string text)
        {
            if(text==null)throw new ArgumentNullException("text");MessageNumbers.RequireAscii(text);
            Characters=(text+"\0").ToCharArray();
        }
        public override string ToString(){return new string(Characters,0,Characters.Length-1);}
    }
    public delegate bool ExpressionSymbolCallback(object creature,ScriptPacket packet,string name,out float value);
    public sealed class ExpressionEnvironment
    {
        public ScriptRandom Random=new ScriptRandom();
        public ExpressionSymbolCallback GameSymbol;
        // Native globals92225c/922260; fast numeric path leaves both untouched.
        // Slow path retains Creature and clears ActivePacket after normal return.
        public object Creature;
        public ScriptPacket ActivePacket;
        public Action ObserveError;
        public ExpressionParserState LastParser;
    }
    public sealed class ExpressionParserState
    {
        public readonly ExpressionBuffer Buffer;
        public int Index,Kind;
        public float TokenValue;
        public bool HasTokenValue;
        internal bool Initialized;
        internal int Steps,Depth;
        internal readonly Func<string,float> Resolve;
        internal readonly Action Error;
        internal ExpressionParserState(ExpressionBuffer buffer,Func<string,float> resolver,Action error){Buffer=buffer;Resolve=resolver;Error=error;}
        internal void Fail(){if(Error!=null)Error();}
    }
    public static class ScriptExpressions
    {
        static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
        static float Zero(uint sign){return BitConverter.ToSingle(BitConverter.GetBytes(sign&0x80000000u),0);}
        static float Add(float a,float b){if(a==0&&b==0)return Zero(Bits(a)&Bits(b));return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float Multiply(float a,float b){if(a==0||b==0)return Zero(Bits(a)^Bits(b));return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float Divide(float a,float b){if(b==0)throw new DivideByZeroException("Nonfinite native arithmetic is outside this bounded parser.");if(a==0)return Zero(Bits(a)^Bits(b));return PlaybackWide.Divide(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static bool Digit(char c){return c>='0'&&c<='9';}
        static bool Letter(char c){return (c>='A'&&c<='Z')||(c>='a'&&c<='z');}
        //0x4f2770: byte classification also permits underscores and decimal digits.
        public static bool IdentifierCharacter(byte c){return Digit((char)c)||Letter((char)c)||c==95;}

        //0x514850 symbol resolution, shared by its optional output wrapper below.
        public static float ResolveSymbol(ExpressionEnvironment environment,string name)
        {
            MessageNumbers.RequireAscii(name);
            if(String.Equals(name,"Rand",StringComparison.OrdinalIgnoreCase))return environment.Random.Next();
            if(String.Equals(name,"false",StringComparison.OrdinalIgnoreCase))return 0;
            if(String.Equals(name,"true",StringComparison.OrdinalIgnoreCase))return 1;
            if(String.Equals(name,"max",StringComparison.OrdinalIgnoreCase))return Single.MaxValue;
            float value=0;
            if(environment.GameSymbol!=null&&environment.GameSymbol(environment.Creature,environment.ActivePacket,name,out value))return value;
            return MessageNumbers.Resolve(environment.ActivePacket,name);
        }
        //0x514850 optional output pointers: float value and low32 bits of the
        //signed64 truncation performed by native6e6b90. Invalid conversion gives
        //INT64_MIN, whose low32 bits are zero. Arrays represent writable slots.
        public static int ResolveOutputs(ExpressionEnvironment environment,string name,float[] floatOutput,uint[] integerOutput)
        {
            float value=ResolveSymbol(environment,name);
            if(floatOutput!=null){if(floatOutput.Length==0)throw new ArgumentException("Missing float output slot.");floatOutput[0]=value;}
            if(integerOutput!=null)
            {
                if(integerOutput.Length==0)throw new ArgumentException("Missing integer output slot.");
                integerOutput[0]=Single.IsNaN(value)||Single.IsInfinity(value)||(double)value>=9223372036854775808.0||(double)value< -9223372036854775808.0?0u:unchecked((uint)(long)value);
            }
            return 0;
        }

        //0x514920. Copying overload is a convenience; callers whose native text
        //persists across calls must retain ExpressionBuffer and its mutations.
        public static float Evaluate(ExpressionEnvironment environment,object creature,ScriptPacket packet,string text)
        {return Evaluate(environment,creature,packet,new ExpressionBuffer(text));}
        // Host convenience, not an additional native function mapping. Retain
        // the mutation when a recovered command evaluates an existing token.
        public static float EvaluateToken(ExpressionEnvironment environment,object creature,ScriptPacket packet,string[] tokens,int index)
        {
            ExpressionBuffer buffer=new ExpressionBuffer(tokens[index]);
            float value=Evaluate(environment,creature,packet,buffer);
            tokens[index]=buffer.ToString();return value;
        }
        public static float Evaluate(ExpressionEnvironment environment,object creature,ScriptPacket packet,ExpressionBuffer text)
        {
            bool numeric=true;foreach(char c in text.Characters){if(c==0)break;if(c>'9'||c=='/'){numeric=false;break;}}
            environment.LastParser=null;
            if(numeric)return MessageNumbers.Parse(text.ToString());
            environment.Creature=creature;environment.ActivePacket=packet;
            float value=Parse(text,delegate(string name){return ResolveSymbol(environment,name);},environment.ObserveError,out environment.LastParser);
            environment.ActivePacket=null;return value;
        }

        //0x4f88e0. Unknown initial bytes would consume uninitialized native stack
        //state; the portable entry deliberately rejects those malformed inputs.
        public static float Parse(ExpressionBuffer text,Func<string,float> resolver,Action error,out ExpressionParserState state)
        {
            state=new ExpressionParserState(text,resolver,error);NextToken(state);return Expression(state);
        }
        //0x4f8420. Numeric lexical stores differ from the simple prefix parser.
        internal static void NextToken(ExpressionParserState s)
        {
            if(++s.Steps>65536)throw new InvalidOperationException("Native expression would exceed the bounded parser budget.");
            char[] text=s.Buffer.Characters;
            while(text[s.Index]==' '||text[s.Index]=='\t')++text[s.Index];
            char c=text[s.Index];
            if(c==0){s.Kind=6;s.Initialized=true;return;}
            int kind=c=='+'?0:c=='-'?1:c=='*'?2:c=='/'?3:c=='('?4:c==')'?5:c==';'?6:-1;
            if(kind>=0){s.Kind=kind;s.Initialized=true;if(c!=';')++s.Index;return;}
            if(c=='.'||Digit(c))
            {
                s.Kind=7;s.Initialized=true;s.HasTokenValue=true;s.TokenValue=0;float fraction=0;
                while(text[s.Index]=='.'||Digit(text[s.Index]))
                {
                    c=text[s.Index++];
                    if(c=='.'){if(fraction!=0)s.Fail();fraction=.1f;}
                    else if(fraction==0)s.TokenValue=Add(Multiply(s.TokenValue,10),c-'0');
                    else
                    {
                        s.TokenValue=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(c-'0'),PlaybackWide.From(fraction)),PlaybackWide.From(s.TokenValue)).Store();
                        fraction=Divide(fraction,10);
                    }
                }
                return;
            }
            if(c=='_'||Letter(c))
            {
                int start=s.Index;while(IdentifierCharacter((byte)text[s.Index]))++s.Index;
                if(s.Index-start>255)throw new ArgumentOutOfRangeException("text","Native identifier scratch is256 bytes.");
                if(s.Resolve==null)throw new InvalidOperationException("Native identifier requires a nonnull resolver callback.");
                s.Kind=7;s.Initialized=true;s.TokenValue=0;s.HasTokenValue=true;s.TokenValue=s.Resolve(new string(text,start,s.Index-start));return;
            }
            if(!s.Initialized)throw new FormatException("Unrecognized initial token would read uninitialized native state.");
            // Otherwise unknown characters leave index, kind and value unchanged.
        }
        //0x4f8790. Lookahead intentionally precedes reading TokenValue.
        internal static float Factor(ExpressionParserState s)
        {
            if(++s.Depth>256)throw new InvalidOperationException("Bounded expression recursion exceeded.");
            float value;
            switch(s.Kind)
            {
                case 1:NextToken(s);value=-Factor(s);break;
                case 4:NextToken(s);value=Expression(s);if(s.Kind!=5)s.Fail();NextToken(s);break;
                case 6:value=1;break;
                case 8:s.Fail();NextToken(s);value=s.TokenValue;break;
                case 7:NextToken(s);value=s.TokenValue;break;
                default:s.Fail();value=0;break;
            }
            --s.Depth;return value;
        }
        //0x4f8830: stores each product/quotient tofloat32 before next iteration.
        internal static float Term(ExpressionParserState s)
        {
            float value=Factor(s);
            while(s.Kind==2||s.Kind==3){int kind=s.Kind;NextToken(s);float rhs=Factor(s);value=kind==2?Multiply(value,rhs):Divide(value,rhs);}
            return value;
        }
        //0x4f8880: stores each sum/difference before next iteration.
        internal static float Expression(ExpressionParserState s)
        {
            float value=Term(s);
            while(s.Kind==0||s.Kind==1){int kind=s.Kind;NextToken(s);float rhs=Term(s);value=Add(value,kind==0?rhs:-rhs);}
            return value;
        }
    }
}
