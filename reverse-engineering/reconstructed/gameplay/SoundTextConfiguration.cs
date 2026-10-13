using System;
namespace Recovered.Gameplay
{
 //Composition adapter: real text line/token/numeric/dispatch/sample/group behavior.
 //File creation/closing and audio-device operations remain host services.
 public sealed class SoundTextConfiguration:ISoundConfigurationServices
 {
  readonly ISoundConfigurationServices host;
  readonly Func<SoundSetupImage,uint,uint,int,int> readFile;
  public SoundTextConfiguration(ISoundConfigurationServices hostServices,Func<SoundSetupImage,uint,uint,int,int> fileReader){host=hostServices;readFile=fileReader;}
  public uint Open(SoundSetupImage m,uint path){uint parser=host.Open(m,path);if(parser!=0&&m.Byte(parser+0x578)!=0)throw new ArgumentException("Text configuration required.");return parser;}
  public void Configure(SoundSetupImage m,uint parser,uint table){TextParserTokens.PushTable(m,parser,table);}
  public int ReadLine(SoundSetupImage m,uint parser){return unchecked((int)TextParserLines.Next(m,parser,readFile,null));}
  public void ReadToken(SoundSetupImage m,uint parser){TextParserTokens.Next(m,parser,null);}
  public void Dispatch(SoundSetupImage m,uint parser)
  {
   TextParserDispatch.Dispatch(m,parser,delegate(SoundSetupImage image,uint handler,uint context)
   {
    var tokens=new Reader(image,context);
    if(handler==0x651680)ReadHeader(image,context);
    else if(handler==0x6516a0)SoundDefinitionParser.Parse(image,tokens);
    else if(handler==0x652010)SoundGroups.Parse(image,tokens);
    else throw new ArgumentException("Handler outside the recovered Audio command table.");
   });
  }
  //0x651680: Audio header value is parsed then stored as a float32 word.
  public static void ReadHeader(SoundSetupImage m,uint parser){m.Word(0x2962030,BitConverter.ToUInt32(BitConverter.GetBytes(TextParserNumbers.ReadReal(m,parser,null)),0));}
  public void Close(SoundSetupImage m,uint parser){host.Close(m,parser);}
  public void LoadBanks(SoundSetupImage m,uint banks,uint cursor,uint opaque){host.LoadBanks(m,banks,cursor,opaque);}
  public void SetMask(SoundSetupImage m,uint mask,int words){host.SetMask(m,mask,words);}
  public void Finish(SoundSetupImage m){host.Finish(m);}
  public sealed class Reader:ISoundDefinitionTokens
  {
   readonly SoundSetupImage image;readonly uint parser;
   public Reader(SoundSetupImage m,uint context){image=m;parser=context;}
   public string Current{get{return SoundDefinitionParser.Text(image,image.Word(parser+0x510));}}
   public bool ReadNext(){TextParserTokens.Next(image,parser,null);return Current.Length!=0;}
   public void Append(string suffix){uint at=image.Word(parser+0x510)+(uint)Current.Length;foreach(char c in suffix)image.Byte(at++,(byte)c);image.Byte(at,0);}
   public int ReadInteger(){return TextParserNumbers.ReadInteger(image,parser,null);}
   public float ReadFloat(){return TextParserNumbers.ReadReal(image,parser,null);}
  }
 }
}
