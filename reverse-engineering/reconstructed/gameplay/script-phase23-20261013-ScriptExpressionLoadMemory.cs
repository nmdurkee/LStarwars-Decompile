// Raw load-time expression flags; callbacks alone define symbols, including reserved runtime words.
using System;
using System.Text;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptExpressionLoading
 {
  const uint Seen=0x92224c,Unresolved=0x922250,Requires=0x922254,Callback=0x9238c0;
  static float F(uint v){float f=BitConverter.ToSingle(BitConverter.GetBytes(v),0);if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("Finite expression stores required.");return f;}
  static uint B(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  static byte Fold(byte c){return (c>=97&&c<=122)||c>=224?unchecked((byte)(c-32)):c;}
  static string Text(TakeoverReleaseMemory m,uint p){var b=new StringBuilder();for(uint i=0;i<4096;i++){byte c=m.Read8(unchecked(p+i));if(c==0)return b.ToString();b.Append((char)c);}throw new ArgumentException("Bounded NUL-terminated byte text required.");}
  static bool Equal(string a,string b){if(a.Length!=b.Length)return false;for(int i=0;i<a.Length;i++)if(Fold((byte)a[i])!=Fold((byte)b[i]))return false;return true;}
  static bool Contains(string a,string b){for(int i=0;i+b.Length<=a.Length;i++){bool same=true;for(int j=0;j<b.Length;j++)if(Fold((byte)a[i+j])!=Fold((byte)b[j])){same=false;break;}if(same)return true;}return false;}
  static float Add(float a,float b){if(a==0&&b==0)return F(B(a)&B(b)&0x80000000);return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Mul(float a,float b){if(a==0||b==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static float Div(float a,float b){if(b==0)throw new DivideByZeroException("Nonfinite expression arithmetic excluded.");if(a==0)return F((B(a)^B(b))&0x80000000);return PlaybackWide.Divide(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
  static bool Digit(byte c){return c>=48&&c<=57;}static bool Letter(byte c){return c>=65&&c<=90||c>=97&&c<=122;}static bool Id(byte c){return Digit(c)||Letter(c)||c==95;}
  static float Number(string s){int i=0;float value=0,divisor=1;if(s.Length!=0&&s[0]=='-'){divisor=-1;i++;}while(i<s.Length&&Digit((byte)s[i]))value=Add(Mul(value,10),s[i++]-48);if(i<s.Length&&s[i]=='.'){i++;while(i<s.Length&&Digit((byte)s[i])){divisor=Mul(divisor,10);value=Add(Mul(value,10),s[i++]-48);}}return F(B(Div(value,divisor)));}
  static uint Resolve(TakeoverReleaseMemory m,ScriptExpressionServices s,string name)
  {m.Write32(Seen,1);m.Write32(Unresolved,1);uint value=0,callback=m.Read32(Callback);if(callback!=0&&s.Symbol(m,callback,0,0,name,out value)!=0)m.Write32(Unresolved,0);return B(F(value));}
  // Existing513230. A callback's float write survives false handled return; outputs capture localvalue.
  public static uint ResolveOutputs(TakeoverReleaseMemory m,ScriptExpressionServices s,uint text,uint floatOutput,uint integerOutput)
  {m.Write32(Seen,1);m.Write32(Unresolved,1);uint value=0,callback=m.Read32(Callback);if(callback!=0&&s.Symbol(m,callback,0,0,Text(m,text),out value)!=0)m.Write32(Unresolved,0);float f=F(value);if(floatOutput!=0)m.Write32(floatOutput,value);if(integerOutput!=0){uint integer=(double)f>=9223372036854775808.0||(double)f< -9223372036854775808.0?0:unchecked((uint)(long)f);m.Write32(integerOutput,integer);}return 0;}
  sealed class Parser
  {
   readonly TakeoverReleaseMemory m;readonly ScriptExpressionServices s;readonly uint text;uint index;int kind,steps,depth;float value;bool initialized;
   public Parser(TakeoverReleaseMemory memory,ScriptExpressionServices services,uint source){m=memory;s=services;text=source;}
   byte At(){return m.Read8(unchecked(text+index));}void Error(){s.Error(m);}
   void Next()
   {
    if(++steps>65536)throw new InvalidOperationException("Expression instruction budget exceeded.");while(At()==32||At()==9)m.Write8(unchecked(text+index),unchecked((byte)(At()+1)));byte c=At();if(c==0){kind=6;initialized=true;return;}
    int k=c==43?0:c==45?1:c==42?2:c==47?3:c==40?4:c==41?5:c==59?6:-1;if(k>=0){kind=k;initialized=true;if(c!=59)index++;return;}
    if(c==46||Digit(c)){kind=7;initialized=true;value=0;float fraction=0;while(At()==46||Digit(At())){c=At();index++;if(c==46){if(fraction!=0)Error();fraction=.1f;}else if(fraction==0)value=Add(Mul(value,10),c-48);else{value=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(c-48),PlaybackWide.From(fraction)),PlaybackWide.From(value)).Store();fraction=Div(fraction,10);}}return;}
    if(Letter(c)||c==95){var name=new StringBuilder();while(Id(At())){if(name.Length==255)throw new ArgumentException("Identifier exceeds native scratch.");name.Append((char)At());index++;}kind=7;initialized=true;value=0;value=F(Resolve(m,s,name.ToString()));return;}if(!initialized)throw new FormatException("Unknown initial token reads uninitialized native stack.");
   }
   float Factor(){if(++depth>256)throw new InvalidOperationException("Expression recursion budget exceeded.");float v;switch(kind){case 1:Next();v=-Factor();break;case 4:Next();v=Expression();if(kind!=5)Error();Next();break;case 6:v=1;break;case 8:Error();Next();v=value;break;case 7:Next();v=value;break;default:Error();v=0;break;}depth--;return v;}
   float Term(){float v=Factor();while(kind==2||kind==3){int k=kind;Next();float rhs=Factor();v=k==2?Mul(v,rhs):Div(v,rhs);}return v;}
   float Expression(){float v=Term();while(kind==0||kind==1){int k=kind;Next();float rhs=Term();v=Add(v,k==0?rhs:-rhs);}return v;}
   public uint Run(){Next();return B(F(B(Expression())));}
  }
  // Existing5132a0 always invokes grammar, no runtime numeric fastpath or contextglobals.
  public static uint Evaluate(TakeoverReleaseMemory m,ScriptExpressionServices s,uint text)
  {m.Write32(Seen,0);m.Write32(Unresolved,0);m.Write32(Requires,0);uint result=new Parser(m,s,text).Run();if(m.Read32(Unresolved)!=0)m.Write32(Requires,1);return result;}
 }
}
