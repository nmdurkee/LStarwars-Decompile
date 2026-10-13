using System;
namespace Recovered.Gameplay {
 public interface IParticleResourceBackend {
  int Exists(SoundSetupImage m,string path);
  uint Load(SoundSetupImage m,string path,uint mode,uint scene);
 }
 // Recovered x86 byte/word contracts; all arithmetic below wraps at 32 bits.
 public static class ParticleResourceConstruction {
  public static uint Allocate(SoundSetupImage m,uint cursorRef,uint endRef,uint size) { // 0x552670
   unchecked { if(cursorRef==0||endRef==0)return 0; uint raw=m.Word(cursorRef);
    if(raw+size>=m.Word(endRef))return 0;
    uint dst=(raw+3)&0xfffffffc; m.Word(cursorRef,dst+size);
    if(dst!=0)for(uint i=0;i<size;i++)m.Byte(dst+i,0); return dst;
   }
  }
  public static uint CreateAuxiliary(SoundSetupImage m,uint cursorRef,uint endRef) { // 0x5a05b0
   unchecked { uint record=Allocate(m,cursorRef,endRef,16);
    if(record!=0&&m.Word(0x956618)!=0)m.Word(record+12,Allocate(m,cursorRef,endRef,m.Word(0x956618)*4));
    return record;
   }
  }
  static bool EqualAscii(SoundSetupImage m,uint a,uint b) {
   unchecked { for(;;a++,b++) { byte x=m.Byte(a),y=m.Byte(b);
    if(x>=65&&x<=90)x=(byte)(x+32); if(y>=65&&y<=90)y=(byte)(y+32);
    if(x!=y)return false; if(x==0)return true;
   }}
  }
  static bool Active(SoundSetupImage m,int group) {return m.Word(unchecked(0x2924b10u+(uint)(group*4)))!=0;}
  // 0x658330; 0x658470 supplies exclude=0. Third pass uses MOVSX on stored group byte.
  public static uint Resolve(SoundSetupImage m,uint query,uint preferred,int exclude) {return ResolvePasses(m,query,(byte)preferred,exclude,true);}
  // 0x658490 lacks the third pass; a name in another active group can remain unresolved.
  public static uint ResolveFast(SoundSetupImage m,uint query,uint preferred) {
   if(query==0)return 0xffffffff;
   EffectActivationWorld state=new EffectActivationWorld();state.Count=unchecked((int)m.Word(0x2962098));state.Entries.Add(null);
   for(int g=0;g<8;g++)state.LoadedGroups[g]=Active(m,g);
   for(int i=1;i<state.Count;i++) {
    uint record=m.Word(m.Word(0x296209c)+(uint)i*4);
    state.Entries.Add(record==0?null:new EffectActivationEntry{Name=ReadAscii(m,record),Group=m.Byte(record+17)});
   }
   return unchecked((uint)EffectActivation.Find(state,ReadAscii(m,query),(byte)preferred));
  }
  static string ReadAscii(SoundSetupImage m,uint p){string text="";for(byte b=m.Byte(p);b!=0;b=m.Byte(++p))text+=(char)b;return text;}
  static uint ResolvePasses(SoundSetupImage m,uint query,byte preferred,int exclude,bool allGroups) {
   unchecked { if(query==0)return 0xffffffff;
    int passes=allGroups?3:2;
    for(int pass=0;pass<passes;pass++) {
     if(pass==0&&(preferred>=8||!Active(m,preferred)))continue;
     for(int i=1;i<(int)m.Word(0x2962098);i++) {
      if(i==exclude)continue;
      uint record=m.Word(m.Word(0x296209c)+(uint)i*4); if(record==0)continue;
      byte group=m.Byte(record+17);
      bool eligible=pass==0?group==preferred:pass==1?(group==0||group==1)&&Active(m,group):Active(m,(sbyte)group);
      if(eligible&&EqualAscii(m,record,query))return (uint)i;
     }
    } return 0xffffffff;
   }
  }
  static void CopyName(SoundSetupImage m,uint dst,uint src) {unchecked{byte x;do{x=m.Byte(src++);m.Byte(dst++,x);}while(x!=0);}}
  // 0x62c400. endRef is deliberately unused in the original. Explicit count is not clamped to capacity.
  public static uint CreateCache(SoundSetupImage m,uint cursorRef,uint endRef,int capacity,int explicitCount,uint names,uint preferred) {
   unchecked { uint header=(m.Word(cursorRef)+15)&0xfffffff0; m.Word(cursorRef,header+12); if(header==0)return 0;
    m.Word(header+8,0);m.Word(header,(uint)explicitCount);m.Word(header+4,(uint)capacity);
    uint entries=(m.Word(cursorRef)+15)&0xfffffff0;m.Word(header+8,entries);m.Word(cursorRef,entries+(uint)capacity*20);
    if(entries==0)return 0;
    for(uint i=0;i<(uint)capacity*20;i++)m.Byte(entries+i,255);
    int written=0;uint offset=0;
    while(written<(int)m.Word(header)) {
     uint at=m.Word(header+8)+offset; CopyName(m,at+4,m.Word(names+(uint)written*4));m.Word(at,0xffffffff);
     m.Word(m.Word(header+8)+offset,Resolve(m, m.Word(header+8)+offset+4,preferred,0)); written++;offset+=20;
    }
    int scan=1; offset=(uint)written*20;
    while(written<(int)m.Word(header+4)) {
     if(scan>=(int)m.Word(0x2962098))break;
     uint at=m.Word(header+8)+offset;m.Word(at,0xffffffff);
     uint name=m.Word(m.Word(0x296209c)+(uint)scan*4);
     if(name!=0) {CopyName(m,at+4,name);m.Word(m.Word(header+8)+offset,ResolveFast(m,m.Word(header+8)+offset+4,preferred));written++;offset+=20;}
     scan++;
    }
    while(written<(int)m.Word(header+4)) {m.Word(m.Word(header+8)+(uint)written*20,0xffffffff);written++;}
    return header;
   }
  }
  // Bounded caller fragment 0x48d063..0x48d094; stops BEFORE failure check and later loader phases.
  public static void InitializeAuxiliaryAndParticles(SoundSetupImage m,uint world,IParticleResourceBackend backend) {
   m.Word(world+0x2960,CreateAuxiliary(m,world+0x104,world+0x108));
   LoadParticleResources(m,world,0x7f5dd0,400,147,backend);
  }
  // 0x5a8090. Caller supplies capacity/count/name table. PTL decoding stays an explicit backend.
  public static void LoadParticleResources(SoundSetupImage m,uint world,uint names,int capacity,int explicitCount,IParticleResourceBackend backend) {
   unchecked {m.Word(world+0x2a98,0xffffffff);uint p=world+0x80;string path="";for(byte b=m.Byte(p);b!=0;b=m.Byte(++p))path+=(char)b;path+=".ptl";
    if(backend.Exists(m,path)!=0)m.Word(world+0x2a98,backend.Load(m,path,1,m.Word(world+0x13c)));
    m.Word(world+0x134,CreateCache(m,world+0x104,world+0x108,capacity,explicitCount,names,m.Word(world+0x2a98)));
   }
  }
 }
}
