// Complete narrow CRT output parser 6EEF05. Child services retain platform/locale/conversion boundaries.
namespace Recovered.Gameplay
{
 public abstract class ScriptFormattingServices : ScriptPrintfServices
 {
  public abstract ScriptLocaleUpdateServices LocaleServices { get; }
  public abstract uint Wide(TakeoverReleaseMemory m,uint result,uint buffer,uint capacity,ushort character);
  public abstract uint Decode(TakeoverReleaseMemory m,uint encoded);
  public abstract void Floating(TakeoverReleaseMemory m,uint function,uint value,uint buffer,uint capacity,int type,int precision,uint capitals,uint locale);
  public abstract void Alter(TakeoverReleaseMemory m,uint function,uint buffer,uint locale);
  public abstract uint Allocate(TakeoverReleaseMemory m,uint capacity);
  public abstract void Release(TakeoverReleaseMemory m,uint buffer);
  public abstract uint CountEnabled(TakeoverReleaseMemory m);
 }
 public static class PreparedScriptFormatting
 {
  static int I(uint v){return unchecked((int)v);}
  static uint U(int v){return unchecked((uint)v);}
  static uint Length(TakeoverReleaseMemory m,uint p){uint q=p;while(m.Read8(q)!=0)q=unchecked(q+1);return unchecked(q-p);}
  static void Cleanup(TakeoverReleaseMemory m,uint context){if(m.Read8(context+12)!=0){uint thread=m.Read32(context+8);m.Write32(thread+0x70,m.Read32(thread+0x70)&0xfffffffd);}}
  static uint Bad(TakeoverReleaseMemory m,ScriptFormattingServices s,uint context){m.Write32(s.Errno(m),22);s.Invalid(m,0,0,0,0,0);Cleanup(m,context);return 0xffffffff;}
  static uint Descriptor(TakeoverReleaseMemory m,uint file){int id=I(m.Read32(file+16));if(id==-1||I(m.Read32(file+16))==-2)return 0x829c00;int block=I(m.Read32(file+16))>>5;uint index=m.Read32(file+16)&31;return unchecked(m.Read32(0x29a9b40+U(block*4))+index*56);}
  static void Span(TakeoverReleaseMemory m,ScriptFormattingServices s,uint counter,uint p,uint file,uint count,uint slots){m.Write32(slots,count);PreparedScriptPrintfOutput.Span(m,s,counter,p,file,slots);}
  static void Repeat(TakeoverReleaseMemory m,ScriptFormattingServices s,uint counter,uint value,int count,uint file,uint slots){m.Write32(slots,value);m.Write32(slots+4,U(count));m.Write32(slots+8,file);PreparedScriptPrintfOutput.Repeat(m,s,counter,slots,slots+4,slots+8);}
  // frame is original EBP after its LEA; private frame/child argument slots must be writable and disjoint from caller data in this prepared domain.
  public static uint Execute(TakeoverReleaseMemory m,ScriptFormattingServices s,uint file,uint format,uint locale,uint arguments,uint frame)
  {
   uint context=frame-0x64,counter=frame-0x34,prefix=frame-0x38,buffer=frame-0x14,slots=frame-0x120;
   PreparedScriptLocaleUpdate.Construct(m,s.LocaleServices,context,locale);
   if(file==0)return Bad(m,s,context);
   if((m.Read8(file+12)&0x40)==0){if((m.Read8(Descriptor(m,file)+0x24)&0x7f)!=0)return Bad(m,s,context);if((m.Read8(Descriptor(m,file)+0x24)&0x80)!=0)return Bad(m,s,context);}
   if(format==0)return Bad(m,s,context);
   m.Write32(counter,0);int state=0,precision=0,width=0,prefixLength=0,digitOffset=0;uint flags=0,allocated=0,body=0,length=0,capitals=0;bool wide=false,skip=false;
   byte ch=m.Read8(format);
   while(ch!=0&&I(m.Read32(counter))>=0)
   {
    uint next=unchecked(format+1);uint category=(byte)(ch-0x20)<0x59?(uint)(m.Read8(0x777e80+(uint)(sbyte)ch)&15):0;
    state=(sbyte)m.Read8(0x777ea0+category*8+U(state))>>4;
    bool literal=false;
    switch(state)
    {
     case 1:precision=-1;capitals=0;skip=false;width=0;prefixLength=0;flags=0;wide=false;break;
     case 2:if(ch==32)flags|=2;else if(ch==35)flags|=0x80;else if(ch==43)flags|=1;else if(ch==45)flags|=4;else if(ch==48)flags|=8;break;
     case 3:if(ch==42){width=I(m.Read32(arguments));arguments=unchecked(arguments+4);if(width<0){flags|=4;width=unchecked(-width);}}else width=unchecked(width*10-48+(sbyte)ch);break;
     case 4:precision=0;break;
     case 5:if(ch==42){precision=I(m.Read32(arguments));arguments=unchecked(arguments+4);if(precision<0)precision=-1;}else precision=unchecked(precision*10-48+(sbyte)ch);break;
     case 6:
      if(ch==73){byte a=m.Read8(next);if(a==54&&m.Read8(next+1)==52){flags|=0x8000;next+=2;}else if(a==51&&m.Read8(next+1)==50){flags&=0xffff7fff;next+=2;}else if(a!=100&&a!=105&&a!=111&&a!=117&&a!=120&&a!=88){state=0;literal=true;}}
      else if(ch==104)flags|=0x20;else if(ch==108){if(m.Read8(next)==108){flags|=0x1000;next++;}else flags|=0x10;}else if(ch==119)flags|=0x800;break;
     case 0:literal=true;break;
     case 7:
      bool integer=false;uint radix=10;
      if(ch==100||ch==105){flags|=0x40;integer=true;}
      else if(ch==117)integer=true;
      else if(ch==111){radix=8;if((flags&0x80)!=0)flags|=0x200;integer=true;}
      else if(ch==120||ch==88||ch==112){radix=16;digitOffset=ch==120?39:7;if(ch==112)precision=8;if((flags&0x80)!=0){m.Write8(prefix,48);m.Write8(prefix+1,(byte)(digitOffset+81));prefixLength=2;}integer=true;}
      if(integer)
      {
       ulong number;if((flags&0x9000)!=0){number=m.Read32(arguments)|((ulong)m.Read32(arguments+4)<<32);arguments+=8;}
       else {uint word=m.Read32(arguments);arguments+=4;if((flags&0x20)!=0)word=(flags&0x40)!=0?U((short)(ushort)word):(uint)(ushort)word;number=(flags&0x40)!=0?unchecked((ulong)(long)I(word)):word;}
       if((flags&0x40)!=0&&unchecked((long)number)<0){number=unchecked(0UL-number);flags|=0x100;}if((flags&0x9000)==0)number=(uint)number;
       if(precision<0)precision=1;else{flags&=0xfffffff7;if(precision>512)precision=512;}if(number==0)prefixLength=0;
       uint p=frame+0x1eb;while(true){int old=precision;precision=unchecked(precision-1);if(old<=0&&number==0)break;uint digit=(uint)(number%radix)+48;number/=radix;if(digit>57)digit=unchecked(digit+U(digitOffset));m.Write8(p,(byte)digit);p--;}
       length=unchecked(frame+0x1eb-p);body=p+1;if((flags&0x200)!=0&&(length==0||m.Read8(body)!=48)){body--;m.Write8(body,48);length++;}
      }
      else if(ch==115||ch==83)
      {
       if(ch==83&&(flags&0x830)==0)flags|=0x800;int limit=precision==-1?0x7fffffff:precision;body=m.Read32(arguments);arguments+=4;wide=(flags&0x810)!=0;if(body==0)body=m.Read32(wide?0x829aacu:0x829aa8u);uint p=body;while(limit!=0){limit=unchecked(limit-1);if(wide?m.Read16(p)==0:m.Read8(p)==0)break;p+=wide?2u:1u;}length=unchecked(p-body)/(wide?2u:1u);
      }
      else if(ch==99||ch==67)
      {
       if(ch==67&&(flags&0x830)==0)flags|=0x800;ushort c=(ushort)m.Read32(arguments);arguments+=4;body=buffer;if((flags&0x810)!=0){if(s.Wide(m,frame-0x28,buffer,512,c)!=0)skip=true;length=m.Read32(frame-0x28);}else{m.Write8(buffer,(byte)c);length=1;}
      }
      else if(ch==90)
      {
       uint z=m.Read32(arguments);arguments+=4;body=m.Read32(0x829aa8);if(z==0||m.Read32(z+4)==0)length=Length(m,body);else{body=m.Read32(z+4);int zlen=(short)m.Read16(z);wide=(flags&0x800)!=0;length=U(wide?zlen/2:zlen);}
      }
      else if(ch==110)
      {
       uint target=m.Read32(arguments);arguments+=4;if(s.CountEnabled(m)==0)return Bad(m,s,context);if((flags&0x20)!=0)m.Write16(target,(ushort)m.Read32(counter));else m.Write32(target,m.Read32(counter));skip=true;
      }
      else if(ch==97||ch==65||ch==101||ch==69||ch==102||ch==103||ch==71)
      {
       if(ch==65||ch==69||ch==71){ch+=32;capitals=1;}flags|=0x40;uint capacity=512;body=buffer;
       if(precision<0)precision=6;else if(precision==0){if(ch==103)precision=1;}else{if(precision>512)precision=512;if(precision>163){allocated=s.Allocate(m,U(precision+349));if(allocated!=0){body=allocated;capacity=U(precision+349);}else precision=163;}}
       m.Write32(frame-0x80,m.Read32(arguments));m.Write32(frame-0x7c,m.Read32(arguments+4));arguments+=8;uint fn=s.Decode(m,m.Read32(0x829a98));s.Floating(m,fn,frame-0x80,body,capacity,(sbyte)ch,precision,capitals,context);
       bool alternate=(flags&0x80)!=0;if(alternate&&precision==0){fn=s.Decode(m,m.Read32(0x829aa4));s.Alter(m,fn,body,context);}if(ch==103&&!alternate){fn=s.Decode(m,m.Read32(0x829aa0));s.Alter(m,fn,body,context);}if(m.Read8(body)==45){flags|=0x100;body++;}length=Length(m,body);
      }
      if(!skip)
      {
       if((flags&0x40)!=0){if((flags&0x100)!=0){m.Write8(prefix,45);prefixLength=1;}else if((flags&1)!=0){m.Write8(prefix,43);prefixLength=1;}else if((flags&2)!=0){m.Write8(prefix,32);prefixLength=1;}}
       int padding=unchecked(width-I(length)-prefixLength);if((flags&12)==0)Repeat(m,s,counter,32,padding,file,slots);Span(m,s,counter,prefix,file,U(prefixLength),slots);
       if((flags&8)!=0&&(flags&4)==0)Repeat(m,s,counter,48,padding,file,slots);
       if(!wide||I(length)<1)Span(m,s,counter,body,file,length,slots);else{uint left=length,p=body;do{ushort c=m.Read16(p);p+=2;left--;uint status=s.Wide(m,frame-0x70,frame+0x1ec,6,c);uint count=m.Read32(frame-0x70);if(status!=0||count==0){m.Write32(counter,0xffffffff);break;}Span(m,s,counter,frame+0x1ec,file,count,slots);}while(left!=0);}
       if(I(m.Read32(counter))>=0&&(flags&4)!=0)Repeat(m,s,counter,32,padding,file,slots);
      }
      if(allocated!=0){s.Release(m,allocated);allocated=0;}break;
    }
    if(literal)
    {
     wide=false;m.Write32(slots,ch);m.Write32(slots+4,context);if(PreparedScriptLeadByte.Test(m,s.LocaleServices,slots,slots+4,frame-0x160)!=0){PreparedScriptPrintfOutput.Byte(m,s,file,counter,ch);ch=m.Read8(next);next++;if(ch==0)return Bad(m,s,context);}PreparedScriptPrintfOutput.Byte(m,s,file,counter,ch);
    }
    format=next;ch=m.Read8(format);
   }
   Cleanup(m,context);return m.Read32(counter);
  }
 }
}
