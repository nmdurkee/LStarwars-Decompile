// Original4fc360 two-byte helper and4fc390 wide line reader, retaining its token-capacity mask.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptWideLines
 {
  public static uint ReadWord(SoundSetupImage m,uint parser,Func<SoundSetupImage,uint,uint,int,int> readFile){uint first=TextParserLines.ReadByte(m,parser,readFile),second=TextParserLines.ReadByte(m,parser,readFile);return(second&0xffff0000u)|((second&255)<<8)|(first&255);}
  static ushort Word(SoundSetupImage m,uint p,Func<SoundSetupImage,uint,uint,int,int> read){return (ushort)ReadWord(m,p,read);}
  public static uint Next(SoundSetupImage m,uint parser,Func<SoundSetupImage,uint,uint,int,int> readFile)
  {
   uint line=m.Word(parser+0x50c),count=0;bool quoted=false,visible=false;
  Restart:
   count=0;visible=false;m.Word(parser+0x51c,m.Word(parser+0x51c)+1);m.Word(parser+0x520,0);
   while(true)
   {
    ushort c=Word(m,parser,readFile);if(c==0)break;
    if(c==10||c==13){if(c==13)Word(m,parser,readFile);if(count!=0&&visible)break;m.Word(parser+0x51c,m.Word(parser+0x51c)+1);visible=false;continue;}
    if(c==59&&!quoted){bool discard=count==0||!visible;do{c=Word(m,parser,readFile);}while(c!=0&&c!=10&&c!=13);if(c==13)Word(m,parser,readFile);if(discard)goto Restart;break;}
    if(c==34){quoted=!quoted;visible=true;}else if(c!=9&&c!=32)visible=true;
    uint mask=unchecked((uint)((unchecked((int)m.Word(parser+0x518))>>1)-1));m.Half(line+2*(mask&count),c);count++;
   }
   m.Half(line+2*count,0);return count;
  }
 }
}
