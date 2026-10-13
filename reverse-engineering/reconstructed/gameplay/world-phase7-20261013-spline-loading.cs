using System;
namespace Recovered.Gameplay {
 public interface ISplineFileTransport {
  int Open(SoundSetupImage m,uint path,uint mode,uint archive,uint flags);
  int Read(SoundSetupImage m,uint handle,uint destination,int count);
  void Close(SoundSetupImage m,uint handle);
 }
 public static class SplineResourceLoading {
  public const uint Handle=0x80f884,Position=0x2900a5c,Buffer=0x29110b8,Mode=0x2912f3c,Archive=0x2912f40,Writing=0x2912f44,Swap=0x2912f48,Base=0x95e41c,Count=0x95e420;
  // 0x621270, ordinary read mode with archive source0. Existing handle blocks opening.
  public static uint OpenRead(SoundSetupImage m,uint path,ISplineFileTransport file) {
   if(m.Word(Handle)!=0xffffffff)return 0;
   m.Zero(Buffer,4096);m.Word(Position,0);m.Word(0x2910ca0,0);m.Word(0x2910c9c,0);m.Word(Handle,0xffffffff);m.Word(Writing,0);
   if(m.Word(Mode)!=1)return 0;
   // Archive2912f40 must be0 for this recovered projection; alternate archive lookup remains outside.
   int handle=file.Open(m,path,0,m.Word(0x91ee88),0);m.Word(Handle,unchecked((uint)handle));
   if(handle<1){m.Word(Handle,0xffffffff);return 0;}
   m.Zero(Buffer,4096);file.Read(m,m.Word(Handle),Buffer,4096);m.Word(Position,0);return 1;
  }
  // 0x6216f0. Reads consume zero-filled4096-byte blocks; transport return count is ignored.
  public static void Read(SoundSetupImage m,uint destination,uint count,ISplineFileTransport file) {
   unchecked {uint pos=m.Word(Position);
    while((int)count>0){uint take=4096-pos;if((int)count<(int)take)take=count;
     for(uint i=0;i<take;i++)m.Byte(destination+i,m.Byte(Buffer+pos+i));
     uint handle=m.Word(Handle);pos=m.Word(Position)+take;count-=take;destination+=take;m.Word(Position,pos);
     if(pos==4096&&handle!=0xffffffff){m.Zero(Buffer,4096);if(m.Word(Mode)==1){file.Read(m,handle,Buffer,4096);pos=0;m.Word(Position,0);}}
    }
   }
  }
  // Equivalent byte/word/float wrappers6218c0/6217e0/6217a0 use local scratch in the original.
  static uint ReadValue(SoundSetupImage m,int size,ISplineFileTransport file) {
   uint v=0;for(int i=0;i<size;i++){uint pos=m.Word(Position);byte b=m.Byte(Buffer+pos);v|=(uint)b<<(8*i);uint handle=m.Word(Handle);pos++;m.Word(Position,pos);
    if(pos==4096&&handle!=0xffffffff){m.Zero(Buffer,4096);if(m.Word(Mode)==1){file.Read(m,handle,Buffer,4096);m.Word(Position,0);}}
   }
   if(size==4&&m.Word(Swap)!=0)v=(v>>24)|((v>>8)&0xff00)|((v<<8)&0xff0000)|(v<<24);return v;
  }
  public static uint Word(SoundSetupImage m,ISplineFileTransport file){return ReadValue(m,4,file);}
  public static byte Byte(SoundSetupImage m,ISplineFileTransport file){return (byte)ReadValue(m,1,file);}
  // Retain binary32 bits for finite values, infinities and quiet NaNs; signaling-NaN hardware behavior is outside the contract.
  static uint FloatBits(SoundSetupImage m,ISplineFileTransport file){return Word(m,file);}
  // 0x6213e0, read-only mode projection (Writing0); no write-flush body is claimed.
  public static uint CloseRead(SoundSetupImage m,ISplineFileTransport file){m.Word(Archive,0);if(m.Word(Handle)!=0xffffffff&&m.Word(Mode)==1){file.Close(m,m.Word(Handle));m.Word(Handle,0xffffffff);m.Word(Mode,0);return 1;}return 0;}
  // 0x5b1ee0. Raw arena base is retained BEFORE aligning cursor; count/version/bounds are native widths.
  public static uint Load(SoundSetupImage m,uint path,uint cursorRef,uint endRef,ISplineFileTransport file) {
   unchecked {uint raw=m.Word(cursorRef);m.Word(Base,raw);uint names=(raw+3)&0xfffffffc;m.Word(cursorRef,names);m.Word(Mode,1);
    if(OpenRead(m,path,file)==0){m.Word(Base,0);return 0;}
    const string signature="EDSPLINE v. ";for(int i=0;i<signature.Length;i++)if(Byte(m,file)!=(byte)signature[i]){CloseRead(m,file);m.Word(Base,0);return 0;}
    Word(m,file);uint count=Word(m,file),points=Word(m,file),nameBytes=Word(m,file);names+=count*12;
    uint namesEnd=names+nameBytes,pointsCursor=(namesEnd+3)&0xfffffffc,end=pointsCursor+points*12;
    if(m.Word(endRef)<end){CloseRead(m,file);m.Word(Base,0);return 0;}
    bool failed=false;
    for(int record=0;record<(int)count;record++) {
     Byte(m,file);int length=(int)Word(m,file);uint at=m.Word(Base)+(uint)record*12;
     m.Half(at+2,12);m.Word(at+4,names);m.Half(at,(ushort)Word(m,file));m.Word(at+8,pointsCursor);
     for(int i=0;i<length;i++)m.Byte(m.Word(at+4)+(uint)i,Byte(m,file));names+=(uint)length;
     if(namesEnd<names){CloseRead(m,file);m.Word(Base,0);failed=true;break;}
     int pointCount=(short)m.Half(m.Word(Base)+(uint)record*12);
     for(int i=0;i<pointCount;i++){uint p=m.Word(m.Word(Base)+(uint)record*12+8)+(uint)i*12;for(uint j=0;j<3;j++)m.Word(p+j*4,FloatBits(m,file));}
     pointsCursor+=(uint)(pointCount*12);
     if(end<pointsCursor){CloseRead(m,file);m.Word(Base,0);failed=true;break;}
    }
    CloseRead(m,file);m.Word(cursorRef,end);m.Word(Count,count);return failed?0:count;
   }
  }
 }
}
