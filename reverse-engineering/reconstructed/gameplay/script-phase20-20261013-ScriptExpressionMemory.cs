// Raw-memory script expression environment; existing native entries, no new coverage credit.
using System;
using System.Text;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class ScriptExpressionServices
 {
  // Native9238c0(cachedCreature,cachedPacket,copiedName,localFloatOutput), integer handled return.
  public abstract uint Symbol(TakeoverReleaseMemory m,uint callback,uint creature,uint packet,string name,out uint valueBits);
  public virtual void Error(TakeoverReleaseMemory m){}
 }
 public static class PreparedScriptExpressions
 {
  const uint Creature=0x92225c,Packet=0x922260,Callback=0x9238c0,Seed=0x95e5d4;
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
  // Existing5147c0. Rereads current script pointer at each parameter name; param substring selects slot0.
  public static uint Parameter(TakeoverReleaseMemory m,uint packet,uint text){if(text==0)return 0;return ParameterName(m,packet,Text(m,text));}
  static uint ParameterName(TakeoverReleaseMemory m,uint packet,string name)
  {
   if(packet!=0){if(Contains(name,"param"))return B(F(m.Read32(packet+0x14)));if(m.Read32(packet+4)!=0)for(uint i=0;i<4;i++){uint p=m.Read32(m.Read32(packet+4)+0x18+i*8);if(p!=0&&Equal(Text(m,p),name))return B(F(m.Read32(packet+0x14+i*4)));}}return B(Number(name));
  }
  static uint Resolve(TakeoverReleaseMemory m,ScriptExpressionServices s,string name)
  {
   if(Equal(name,"Rand")){uint seed=unchecked(m.Read32(Seed)*0x19660d+0x3c6ef35f);m.Write32(Seed,seed);return B((seed&0x7fffff)/8388608f);}if(Equal(name,"false"))return 0;if(Equal(name,"true"))return 0x3f800000;if(Equal(name,"max"))return 0x7f7fffff;
   uint callback=m.Read32(Callback),value=0;if(callback!=0){uint packet=m.Read32(Packet),creature=m.Read32(Creature);if(s.Symbol(m,callback,creature,packet,name,out value)!=0)return B(F(value));}return ParameterName(m,m.Read32(Packet),name);
  }
  // Existing514850. Float output store precedes integer output; captured value survives output aliases.
  public static uint ResolveOutputs(TakeoverReleaseMemory m,ScriptExpressionServices s,uint text,uint floatOutput,uint integerOutput)
  {
   float value=F(Resolve(m,s,Text(m,text)));if(floatOutput!=0)m.Write32(floatOutput,B(value));if(integerOutput!=0){uint v=(double)value>=9223372036854775808.0||(double)value< -9223372036854775808.0?0u:unchecked((uint)(long)value);m.Write32(integerOutput,v);}return 0;
  }
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
  // Existing514920, cdecl(creature,packet,text), ST0 result. Signed-byte fast scan includes D3..FF.
  public static uint Evaluate(TakeoverReleaseMemory m,ScriptExpressionServices s,uint creature,uint packet,uint text)
  {
   bool numeric=true;uint i=0;for(;i<4096;i++){byte c=m.Read8(unchecked(text+i));if(c==0)break;int signed=unchecked((sbyte)c);if(signed< -45||signed>57||c==47){numeric=false;break;}}if(i==4096)throw new ArgumentException("Bounded expression text required.");if(numeric)return B(Number(Text(m,text)));m.Write32(Packet,packet);m.Write32(Creature,creature);uint value=new Parser(m,s,text).Run();m.Write32(Packet,0);return value;
  }
 }
 public sealed class RecoveredExpressionConditionServices:ScriptConditionServices
 {
  readonly ScriptConditionServices remaining;readonly ScriptExpressionServices expression;public RecoveredExpressionConditionServices(ScriptConditionServices predicates,ScriptExpressionServices symbols){remaining=predicates;expression=symbols;}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint a,uint b){return remaining.Predicate(m,callback,system,packet,actor,a,b);}
  public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint text){return PreparedScriptExpressions.Evaluate(m,expression,actor,packet,text);}
 }
}
