using System;
namespace Recovered.Gameplay
{
 public static class TextParserLines
 {
  //0x4fc2d0. The original returns meaningful low8bits plus preserved offset bits.
  //Positive, bounded refill results and valid buffer backing are host requirements.
  public static uint ReadByte(SoundSetupImage m,uint parser,Func<SoundSetupImage,uint,uint,int,int> readFile)
  {
   int end=unchecked((int)m.Word(parser+0x52c));uint result=unchecked((uint)(end+1));
   if(unchecked((int)m.Word(parser+0x524))>end)
   {
    int total=unchecked((int)m.Word(parser+0x574));if(unchecked((int)result)>total)return result&0xffffff00u;
    int requested=unchecked(total-(end<0?0:end));if(requested>4096)requested=4096;
    int read=readFile(m,m.Word(parser+4),m.Word(parser),requested);uint prior=m.Word(parser+0x52c);
    m.Word(parser+0x528,unchecked(prior+1));m.Word(parser+0x52c,unchecked(prior+(uint)read));if(read==0)return 0;
   }
   uint position=m.Word(parser+0x524),offset=unchecked(position-m.Word(parser+0x528));
   byte value=m.Byte(unchecked(m.Word(parser)+offset));m.Word(parser+0x524,unchecked(position+1));return(offset&0xffffff00u)|value;
  }
  //0x4fc5b0. Text lines compose actual byte-reader behavior; binary line reader
  //4fc390 and file-read4fb550 remain explicit services. Semicolon comments are
  //recognized only outside quotes; carriage return always consumes one more byte.
  public static uint Next(SoundSetupImage m,uint parser,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine)
  {
   if(m.Byte(parser+0x578)!=0)return binaryLine(m,parser);
   uint count=0;bool quoted=false,visible=false;byte c;
  Restart:
   count=0;m.Word(parser+0x51c,unchecked(m.Word(parser+0x51c)+1));m.Word(parser+0x520,0);
   while(true)
   {
    c=(byte)ReadByte(m,parser,readFile);
    if(c==0)break;
    if(c==10||c==13)
    {
     if(c==13)ReadByte(m,parser,readFile);
     if(count!=0&&visible)break;m.Word(parser+0x51c,unchecked(m.Word(parser+0x51c)+1));visible=false;continue;
    }
    if(c==59&&!quoted)
    {
     bool discard=count==0||!visible;
     do{c=(byte)ReadByte(m,parser,readFile);}while(c!=0&&c!=10&&c!=13);
     if(c==13)ReadByte(m,parser,readFile);
     if(discard){visible=false;goto Restart;}break;
    }
    if(c==34){quoted=!quoted;visible=true;}
    else if(c!=9&&c!=32)visible=true;
    m.Byte(m.Word(parser+0x50c)+((m.Word(parser+0x514)-1)&count),c);count++;
   }
   m.Byte(m.Word(parser+0x50c)+count,0);return count;
  }
 }
}
