using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class TextParserNumbers
 {
  static char At(string text,int i){return i<text.Length?text[i]:'\0';}
  static bool Digit(char c){return c>='0'&&c<='9';}
  //0x4f29a0: optional minus, digit prefix, exact32-bit wrapping; no plus/whitespace.
  public static int Decimal(string text)
  {
   int i=0;bool negative=At(text,0)=='-';if(negative)i++;uint value=0;
   while(Digit(At(text,i))){value=unchecked(value*10+(uint)(text[i++]-'0'));}return unchecked((int)(negative?0-value:value));
  }
  //0x4f8cb0: whole token hexadecimal; one invalid byte resets the result to0.
  public static uint Hexadecimal(string text)
  {
   uint value=0;for(int i=0;At(text,i)!=0;i++)
   {
    int c=text[i];if(c>255)throw new ArgumentException("Byte text required.");if((c>='a'&&c<='z')||c>=0xe0)c=(c-32)&255;int digit=c-'0';if(digit<0||digit>9){digit=c-'A'+10;if(digit<10||digit>15)return 0;}value=unchecked((value<<4)|(uint)digit);
   }return value;
  }
  static float Append(float value,int digit)
  {
   float product=PlaybackWide.Multiply(PlaybackWide.From(value),PlaybackWide.FromDouble(10)).Store();return PlaybackWide.Add(PlaybackWide.From(product),PlaybackWide.FromDouble(digit)).Store();
  }
  //0x4f28e0: float32 store after multiplication, addition, denominator scaling,
  //and final division. Finite stored intermediates; no exponent or leading plus.
  public static float Real(string text)
  {
   int i=0;bool negative=At(text,0)=='-';if(negative)i++;float value=0,divisor=negative?-1:1;
   while(Digit(At(text,i)))value=Append(value,text[i++]-'0');
   if(At(text,i)=='.'){i++;while(Digit(At(text,i))){divisor=PlaybackWide.Multiply(PlaybackWide.From(divisor),PlaybackWide.FromDouble(10)).Store();value=Append(value,text[i++]-'0');}}
   if(float.IsInfinity(value)||float.IsInfinity(divisor))throw new ArgumentException("Finite numeric parser domain required.");if(value==0)return negative?BitConverter.ToSingle(BitConverter.GetBytes(0x80000000u),0):0;
   return PlaybackWide.Divide(PlaybackWide.From(value),PlaybackWide.From(divisor)).Store();
  }
  static string Current(SoundSetupImage m,uint parser)
  {
   uint source=m.Word(parser+0x510);var s=new System.Text.StringBuilder();if(m.Byte(parser+0x578)==0){if(source!=0)for(uint i=0;m.Byte(source+i)!=0;i++)s.Append((char)m.Byte(source+i));}
   else
   {
    if(source==0)throw new ArgumentException("Native wide-token local would be uninitialized.");for(uint i=0;m.Half(source+i*2)!=0;i++)
    {
     ushort c=m.Half(source+i*2);byte b;if(c<256)b=(byte)c;else switch(c){case 0x2019:b=0x92;break;case 0x2013:b=0x96;break;case 0x2018:b=0x91;break;case 0x2026:b=0x85;break;case 0x2122:b=0x99;break;default:b=63;break;}s.Append((char)b);
    }
   }
   if(s.Length>=64)throw new ArgumentException("Native numeric local capacity exceeded.");return s.ToString();
  }
  //0x4f9e70 and0x4f8100, including actual shared token reader.
  public static int ReadInteger(SoundSetupImage m,uint parser,Action<SoundSetupImage,uint> binaryReader)
  {
   TextParserTokens.Next(m,parser,binaryReader);string text=Current(m,parser);if(At(text,0)=='$')return unchecked((int)Hexadecimal(text.Substring(1)));if(At(text,0)=='0'&&(At(text,1)=='x'||At(text,1)=='X'))return unchecked((int)Hexadecimal(text.Substring(2)));return Decimal(text);
  }
  public static float ReadReal(SoundSetupImage m,uint parser,Action<SoundSetupImage,uint> binaryReader){TextParserTokens.Next(m,parser,binaryReader);return Real(Current(m,parser));}
 }
}
