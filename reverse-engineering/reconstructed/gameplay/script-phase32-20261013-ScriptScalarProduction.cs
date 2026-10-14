// Native tokenizer count projection and script scalar declarations.
using System;
namespace Recovered.Gameplay
{
 public static class ScriptTokenResults
 {
  static bool Contains(SoundSetupImage m,uint text,byte value){if(text==0)return false;for(byte c=m.Byte(text);c!=0;c=m.Byte(++text))if(c==value)return true;return false;}
  public static uint Next(SoundSetupImage m,uint parser,Func<SoundSetupImage,uint,uint> binaryReader)
  {
   if(m.Byte(parser+0x578)!=0){return binaryReader(m,parser);}
   uint count=0;bool quoted=false,sawQuote=false;m.Word(0x88ab4c,m.Word(parser+0x520));
   if(m.Byte(m.Word(parser+0x50c)+((m.Word(parser+0x514)-1)&m.Word(parser+0x520)))!=0)
   {
    while(true)
    {
     byte c=m.Byte(m.Word(parser+0x50c)+m.Word(parser+0x520));
     if(!quoted&&Contains(m,m.Word(parser+0x580),c))
     {
      if(count==0){m.Byte(m.Word(parser+0x510),c);m.Word(parser+0x520,unchecked(m.Word(parser+0x520)+1));count=1;}break;
     }
     if(!quoted&&(Contains(m,m.Word(parser+0x57c),c)||c==9||c==32||c==44)){if(count!=0)break;}
     else if(c==34){quoted=!quoted;sawQuote=true;}
     else{m.Byte(m.Word(parser+0x510)+((m.Word(parser+0x518)-1)&count),c);count++;}
     m.Word(parser+0x520,unchecked(m.Word(parser+0x520)+1));
     if((sawQuote&&!quoted&&count==0)||m.Byte(m.Word(parser+0x50c)+((m.Word(parser+0x514)-1)&m.Word(parser+0x520)))==0)break;
    }
   }
   m.Byte(m.Word(parser+0x510)+((m.Word(parser+0x518)-1)&count),0);return count;
  }
 }
 public static class PreparedScriptScalarCommands
 {
  static Action<SoundSetupImage,uint> Binary(Func<SoundSetupImage,uint,uint> binary){return delegate(SoundSetupImage m,uint p){if(binary==null)throw new NotSupportedException("Binary token reader not supplied.");binary(m,p);};}
  //5136c0 cdecl(parser); uint slot guard and unwrapped token EAX count.
  public static void Parameter(ConditionParserMemory m,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   if(m.Read32(0x92221c)==0)return;uint slot=unchecked((uint)TextParserNumbers.ReadInteger(m.Image,parser,Binary(binary)));if(slot>3)return;if(ScriptTokenResults.Next(m.Image,parser,binary)==0)return;uint value=PreparedConditionLoading.CopyString(m,m.Read32(0x922214),m.Read32(parser+0x510),m.Read32(0x922218));m.Write32(unchecked(m.Read32(0x92221c)+0x18+slot*8),value);float number=TextParserNumbers.ReadReal(m.Image,parser,Binary(binary));m.Write32(unchecked(m.Read32(0x92221c)+0x1c+slot*8),TakeoverReleaseMemory.Bits(number));
  }
  //513730 cdecl(parser). Length warning inspects CURRENT commandtoken, then bounded strncpy32 name.
  public static void Constant(ConditionParserMemory m,uint parser,Func<SoundSetupImage,uint,uint> binary,Action<TakeoverReleaseMemory,uint,uint[]> diagnostic)
  {
   uint current=m.Read32(parser+0x510);if(PreparedConditionLoading.Text(m,current).Length>=31&&diagnostic!=null)diagnostic(m,0x512850,new uint[]{m.Read32(parser+0x510)});ScriptTokenResults.Next(m.Image,parser,binary);uint source=m.Read32(parser+0x510),target=unchecked(0x9220f0+m.Read32(0x922244)*36);for(uint i=0;i<32;i++){byte c=i==31?(byte)0:m.Read8(source+i);m.Write8(target+i,c);if(c==0)break;}float value=TextParserNumbers.ReadReal(m.Image,parser,Binary(binary));uint count=m.Read32(0x922244);m.Write32(unchecked(0x922110+count*36),TakeoverReleaseMemory.Bits(value));m.Write32(0x922244,unchecked(count+1));
  }
 }
 public sealed class RecoveredScriptScalarCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly Func<SoundSetupImage,uint,uint> binary;
  public RecoveredScriptScalarCommands(ScriptFileTransportServices ports,Func<SoundSetupImage,uint,uint> binaryToken){if(ports==null)throw new ArgumentNullException("ports");remaining=ports;binary=binaryToken;}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");if(callback==0x5136c0)PreparedScriptScalarCommands.Parameter(image,parser,binary);else if(callback==0x513730)PreparedScriptScalarCommands.Constant(image,parser,binary,Diagnostic);else remaining.Command(m,callback,parser);}
 }
}
