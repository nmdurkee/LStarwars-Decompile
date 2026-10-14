// Shared virtual memory binds recovered file-backed text parsing to condition production.
using System;
namespace Recovered.Gameplay
{
 public sealed class ConditionParserMemory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image;public ConditionParserMemory(SoundSetupImage image){if(image==null)throw new ArgumentNullException("image");Image=image;}public override byte Read8(uint address){return Image.Byte(address);}public override void Write8(uint address,byte value){Image.Byte(address,value);}}
 public sealed class RecoveredTextConditionServices:ScriptConditionMaterializationServices
 {
  readonly Func<SoundSetupImage,uint,uint,int,int> readFile;readonly Func<SoundSetupImage,uint,uint> binaryLine;readonly Action<SoundSetupImage,uint> binaryToken;readonly Action<TakeoverReleaseMemory,uint,uint[]> diagnostic;
  public RecoveredTextConditionServices(Func<SoundSetupImage,uint,uint,int,int> fileReader,Func<SoundSetupImage,uint,uint> binaryLineReader,Action<SoundSetupImage,uint> binaryTokenReader,Action<TakeoverReleaseMemory,uint,uint[]> observeDiagnostic){if(fileReader==null)throw new ArgumentNullException("fileReader");readFile=fileReader;binaryLine=binaryLineReader;binaryToken=binaryTokenReader;diagnostic=observeDiagnostic;}
  static SoundSetupImage Image(TakeoverReleaseMemory m){ConditionParserMemory raw=m as ConditionParserMemory;if(raw==null)throw new ArgumentException("Shared condition/parser image required.");return raw.Image;}
  // Existing4fc5b0 fully recovered reader, including4fc2d0 refill/line state. Final4fb550 file transport supplied.
  public override uint NextLine(TakeoverReleaseMemory m,uint parser){return TextParserLines.Next(Image(m),parser,readFile,delegate(SoundSetupImage image,uint p){if(binaryLine==null)throw new NotSupportedException("Binary line reader not supplied.");return binaryLine(image,p);});}
  // Existing4f7fb0 fully recovered tokenizer; samebyte arrays used by producer and symbol callbacks.
  public override void NextToken(TakeoverReleaseMemory m,uint parser){TextParserTokens.Next(Image(m),parser,delegate(SoundSetupImage image,uint p){if(binaryToken==null)throw new NotSupportedException("Binary token reader not supplied.");binaryToken(image,p);});}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){if(diagnostic!=null)diagnostic(m,callback,arguments);}
 }
 public static class PreparedTextConditionMaterialization
 {public static void Load(ConditionParserMemory m,RecoveredTextConditionServices parser,ScriptExpressionServices symbols,uint parserPointer){PreparedConditionMaterialization.Load(m,parser,symbols,parserPointer);}}
}
