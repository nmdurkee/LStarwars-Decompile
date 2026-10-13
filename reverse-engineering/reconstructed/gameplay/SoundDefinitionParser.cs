using System;
namespace Recovered.Gameplay
{
 public interface ISoundDefinitionTokens
 {
  bool ReadNext(); string Current {get;} void Append(string suffix); int ReadInteger(); float ReadFloat();
 }
 public static class SoundDefinitionParser
 {
  static uint Record(SoundSetupImage m){return m.Word(0x2947b74)+m.Word(0x296201c)*64;}
  static uint Bits(float x){return BitConverter.ToUInt32(BitConverter.GetBytes(x),0);}
  public static string Text(SoundSetupImage m,uint p){var s=new System.Text.StringBuilder();for(byte c=m.Byte(p);c!=0;c=m.Byte(++p))s.Append((char)c);return s.ToString();}
  static void CopyText(SoundSetupImage m,uint p,string s,int capacity){s=SceneryText.C(s);int n=Math.Min(s.Length,capacity-1);for(int i=0;i<n;i++){if(s[i]>127)throw new ArgumentException("ASCII sound text required.");m.Byte(p+(uint)i,(byte)s[i]);}m.Byte(p+(uint)n,0);}
  static uint Hash(SoundSetupImage m,string name){uint h=0;foreach(char raw in name){uint c=raw>='a'&&raw<='z'?(uint)raw-32:raw;h=unchecked((h<<8)^m.Word(m.Word(0x2947d80)+4*(c^(h>>24))));}return h;}
  static int Clamp(int v,int low,int high){return v<low?low:v>high?high:v;}
  static float Clamp(float v,float low,float high){if(float.IsNaN(v)||float.IsInfinity(v))throw new ArgumentException("Finite numeric token required.");return v<low?low:v>high?high:v;}
  static void Flag(SoundSetupImage m,uint flag){uint r=Record(m);m.Word(r+4,m.Word(r+4)|flag);}
  static void FileName(SoundSetupImage m,ISoundDefinitionTokens tokens)
  {
   tokens.ReadNext();tokens.Append(".wav");string name=tokens.Current;uint r=Record(m),flags=m.Word(r+4),bank=0;bool disabled=(flags&0xc0000)!=0;
   if(disabled)m.Word(r+4,flags|0x7fff);
   while(unchecked((int)bank)<unchecked((int)m.Word(0x2962014)))
   {
    uint entry=m.Word(0x2947d70)+bank*28;if(String.Equals(Text(m,m.Word(entry)),name,StringComparison.OrdinalIgnoreCase))
    {
     if(!disabled)m.Word(r+4,(m.Word(r+4)&~0x7fffu)|(bank&0x7fff));m.Word(r+0x3c,m.Word(entry));m.Word(0x2921888+bank*4,unchecked(m.Word(0x2921888+bank*4)+1));return;
    }
    bank++;
   }
   if(bank!=m.Word(0x2962014))return;
   uint target=0x2948f10+m.Word(0x2962018)*64;
   if(disabled)
   {
    m.Word(0x2962018,unchecked(m.Word(0x2962018)+1));CopyText(m,target,name,64);m.Word(r+0x3c,unchecked(0x2948ed0+m.Word(0x2962018)*64));return;
   }
   uint at=m.Word(0x2947d70)+m.Word(0x2962014)*28;m.Word(at,target);m.Word(at+4,0x75a);m.Word(at+12,unchecked(bank-m.Word(0x296202c)+0x1000));m.Word(at+8,0);m.Word(0x2962018,unchecked(m.Word(0x2962018)+1));CopyText(m,target,name,64);
   uint index=m.Word(0x2962014);m.Word(0x2921888+index*4,1);m.Word(r+0x3c,m.Word(m.Word(0x2947d70)+index*28));m.Word(r+4,(m.Word(r+4)&~0x7fffu)|(index&0x7fff));m.Word(0x2962014,unchecked(index+1));
  }
  //0x6516a0: original sample-definition handler. Tokenization/numeric readers are
  //explicit services; valid finite values and adequate disjoint storage required.
  public static void Parse(SoundSetupImage m,ISoundDefinitionTokens tokens)
  {
   SoundRecordInitialization.Initialize(m,unchecked((int)m.Word(0x296201c)));
   while(tokens.ReadNext())
   {
    string token=SceneryText.C(tokens.Current).ToLowerInvariant();uint r=Record(m);switch(token)
    {
     case "disable":Flag(m,0x40000);break;
     case "comment":Flag(m,0x80000);break;
     case "name":
      tokens.ReadNext();uint index=m.Word(0x296201c),name=0x293b318+index*32;CopyText(m,name,tokens.Current,32);m.Word(Record(m),name);uint bucket=Hash(m,Text(m,name))&255;uint head=m.Word(0x292fda0)+bucket*2;ushort prior=m.Half(head);m.Half(Record(m)+0x10,prior);m.Half(head,(ushort)index);break;
     case "fname":FileName(m,tokens);break;
     case "pitch":m.Word(Record(m)+8,unchecked((uint)tokens.ReadInteger()));break;
     case "pan":m.Word(Record(m)+0x18,Bits(Clamp(tokens.ReadFloat(),-1f,1f)));break;
     case "pri":m.Byte(Record(m)+12,unchecked((byte)Clamp(tokens.ReadInteger(),-128,127)));break;
     case "loop":Flag(m,0x8000);break;
     case "pitch_rnd":m.Word(Record(m)+0x1c,Bits(Clamp(tokens.ReadFloat(),0f,1f)));break;
     case "volume":m.Half(Record(m)+0x12,(ushort)Clamp(tokens.ReadInteger(),0,0x3fff));break;
     case "nofade":Flag(m,0x400000);break;
     case "volume_rnd":m.Word(Record(m)+0x20,Bits(Clamp(tokens.ReadFloat(),-1f,0f)));break;
     case "near":m.Word(Record(m)+0x24,Bits(Clamp(tokens.ReadFloat(),0f,250f)));break;
     case "far":m.Word(Record(m)+0x28,Bits(Clamp(tokens.ReadFloat(),0f,250f)));break;
     case "global":Flag(m,0x20000);break;
     case "rumble":float buzz=tokens.ReadFloat();int strength=tokens.ReadInteger();r=Record(m);m.Word(r+0x2c,Bits(Clamp(buzz,0f,5f)));m.Word(r+0x30,(uint)Clamp(strength,0,255));m.Word(Record(m)+0x34,Bits(Clamp(tokens.ReadFloat(),0f,5f)));m.Word(Record(m)+0x38,Bits(Clamp(tokens.ReadFloat(),0f,5f)));break;
     case "fcat":m.Half(Record(m)+0x16,(ushort)Clamp(tokens.ReadInteger(),0,0xffff));break;
    }
   }
   uint selected=m.Word(0x296201c)*64,record=m.Word(0x2947b74)+selected;m.Word(record+4,(m.Word(record+4)&~0x100000u)|0x200000);m.Copy(m.Word(0x292fda4)+selected,record,64);m.Word(0x296201c,unchecked(m.Word(0x296201c)+1));
  }
 }
}
