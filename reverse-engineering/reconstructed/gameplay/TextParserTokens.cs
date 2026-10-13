using System;
namespace Recovered.Gameplay
{
 public static class TextParserTokens
 {
  static bool Contains(SoundSetupImage m,uint text,byte value){if(text==0)return false;for(byte c=m.Byte(text);c!=0;c=m.Byte(++text))if(c==value)return true;return false;}
  //0x4f10e0. Native table stack depth uses signed comparison; valid depth -1..7.
  public static int PushTable(SoundSetupImage m,uint parser,uint table)
  {
   int depth=unchecked((int)m.Word(parser+0x570));if(depth>=7)return -1;depth++;
   m.Word(parser+0x570,(uint)depth);m.Word(parser+0x530+(uint)depth*4,table);
   m.Word(parser+0x550+m.Word(parser+0x570)*4,0);return unchecked((int)m.Word(parser+0x570));
  }
  //0x4f7fb0. Text branch; binary reader4f7df0 remains an explicit tail service.
  //Disjoint valid buffers, terminated byte strings, positive buffer capacities.
  public static void Next(SoundSetupImage m,uint parser,Action<SoundSetupImage,uint> binaryReader)
  {
   if(m.Byte(parser+0x578)!=0){binaryReader(m,parser);return;}
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
   m.Byte(m.Word(parser+0x510)+((m.Word(parser+0x518)-1)&count),0);
  }
 }
}
