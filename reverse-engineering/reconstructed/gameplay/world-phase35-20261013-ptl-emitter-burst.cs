using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEmitterBurst {
  const uint Emitters=0x29620a4,Packets=0x2961fec,Returns=0x2923198,ReturnCount=0x2947b70;
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static int I(uint w){return unchecked((int)w);}
  static int Short(ushort h){return (short)h;}
  static uint Chunk(SoundSetupImage m,uint e){return unchecked(m.Word(e+0x100+(uint)Short(m.Half(e+0x180))*4));}
  static uint ReturnTime(SoundSetupImage m,uint r,uint clock){N product=N.Mul(N.Word(m.Word(r+0x414)),N.Integer((sbyte)m.Byte(r+0x410)));N sum=N.Add(N.Word(m.Word(r+0xa4)),N.Word(clock));return N.Add(sum,product).Store();}
  // 653940: the original polling lock. Prepared single-threaded calls require an initially free word.
  public static void Acquire(SoundSetupImage m){while(m.Word(0x2962058)!=0){}m.Word(0x2962058,1);}
  // 6561d0: complete burst caller with original allocator, pool, transforms, event and list children.
  // Visibility takes copied XYZ, unit scale and radius as value words. The selected initializer is mutable.
  public static void Emit(SoundSetupImage m,uint physical,uint position,uint velocity,uint delta,int count,uint duration,uint secondary,uint primary,uint priority,uint flags,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   if(m.Word(0x2962050)!=0||m.Word(0x8104b4)==0||physical==0xffffffff||physical==0||I(physical)>=I(m.Word(0x2962098)))return;
   uint r=m.Word(m.Word(0x296209c)+physical*4);if(r==0||m.Byte(r+0x13)!=0||count<=0)return;
   if(m.Byte(r+0x2f1)!=4){uint x=m.Word(position),y=m.Word(position+4),z=m.Word(position+8),radius=m.Word(r+0x38);if(service(m,0x5d69a0,new uint[]{x,y,z,0x3f800000,0x3f800000,0x3f800000,radius})==0)return;}
   uint scale=m.Word(0x810908);if(m.Word(0x29620b8)==0){uint local=m.Word(r+0x2f4);if(F(local)<F(scale))scale=m.Word(r+0x2f4);}
   uint step=PtlBurstMath.SafeDivide(0x3f800000,PtlBurstMath.SafeDivide(Bits((float)count),scale));if(secondary==0)secondary=0x806680;if(primary==0)primary=0x806680;
   int bank=m.Byte(r+0x2f1)==4?1:0;uint clock=m.Word(bank==1?0x2962060u:0x296205cu);uint end=N.Add(N.Word(clock),N.Word(duration)).Store();uint quotient=PtlBurstMath.SafeDivide(clock,step);float q=F(quotient);int cycle=q>=2147483648f||q< -2147483648f||float.IsNaN(q)?int.MinValue:(int)q;
   uint previous=N.Mul(N.Integer(cycle),N.Word(step)).Store();uint first=N.Add(N.Word(previous),N.Word(step)).Store(),scan=first;int events=0,iterations=0;
   if(!(F(scan)<=F(end)))return;do{if(++iterations>=100)break;scan=N.Add(N.Word(scan),N.Word(step)).Store();events++;}while(F(scan)<=F(end));if(events==0)return;
   int particles=((sbyte)m.Byte(r+0x410)+1)*events;uint e=0,cachedBase=m.Word(Emitters);int selected=-1;
   for(int slot=0;slot<8;slot++){
    ushort id=m.Half(r+0x3d0+(uint)slot*2);
    if(id!=0xffff){e=cachedBase+(uint)Short(id)*0x330;int total=Short(m.Half(e+0x186))+particles;if(total<=(m.Byte(r+0x2e)==7?384:1024)){selected=slot;break;}}
    else if(I(m.Word(0x29211e8))<I(m.Word(0x2962094))){
     uint allocated=PtlEmitterConstruction.Allocate(m);m.Half(r+0x3d0+(uint)slot*2,(ushort)allocated);e=m.Word(Emitters)+(uint)(int)(short)allocated*0x330;
     m.Half(e+0x182,(ushort)physical);m.Word(e+0x1d4,0);m.Word(e+0x1c0,m.Word(0x810910+(uint)(int)(sbyte)m.Byte(r+0x2c)*4));m.Word(e+0x1c4,m.Word(0x810944+(uint)(int)(sbyte)m.Byte(r+0x2d)*4));
     for(uint i=0;i<64;i+=4)m.Word(e+0x40+i,m.Word(primary+i));m.Word(e+0x70,0);m.Word(e+0x74,0);m.Word(e+0x78,0);
     PtlEmitterConstruction.Position(m,(uint)Short(m.Half(r+0x3d0+(uint)slot*2)),0,0,0);m.Half(e+0x328,(ushort)priority);m.Byte(e+0x2f8,(byte)flags);selected=slot;break;
    }
   }
   if(e==0)return;
   bool special=m.Byte(r+0x2e)==7;int unit=special?12:32,totalParticles=particles+Short(m.Half(e+0x186));int current=Short(m.Half(e+0x180));
   if(totalParticles>current*unit){
    if(current<0)m.Half(e+0x180,0);int desired=(totalParticles+unit-1)/unit;int additional=desired-Short(m.Half(e+0x180));uint used=special?0x2947d84u:0x2948e98u,capacity=special?0x8108ecu:0x8108e8u,free=special?0x29211fcu:0x2921200u;
    if(I(m.Word(used)+(uint)additional)>=I(m.Word(capacity))||desired>32)return;
    for(int i=0;i<additional;i++){uint p=m.Word(m.Word(free)+m.Word(used)*4);m.Word(e+0x100+(uint)Short(m.Half(e+0x180))*4,p);m.Word(used,m.Word(used)+1);
     for(int j=0;j<unit;j++){p=Chunk(m,e);m.Word(p+0x2c+(uint)j*32,0);p=Chunk(m,e);m.Word(p+0x3c+(uint)j*32,0x47000000);}m.Half(e+0x180,(ushort)(m.Half(e+0x180)+1));
    }
    m.Half(e+0x180,(ushort)desired);PtlParticleLinks.Commands(m,e+0x100,desired);
    if(desired==additional){int limit=I(m.Word(0x8108ec)+m.Word(0x8108e8));uint table=m.Word(Packets);int index=0;for(;index<limit;index++)if(m.Word(table+(uint)index*0x64)==0)break;
     if(index<limit){uint off=(uint)index*0x64;m.Word(table+off,m.Word(e+0x100));m.Word(m.Word(Packets)+off+4,r);m.Word(m.Word(Packets)+off+8,e);m.Half(m.Word(Packets)+off+0x60,(ushort)priority);uint head=0x292fd30+(uint)(int)(sbyte)m.Byte(r+0x2f1)*4;PtlParticleLinks.Priority(m,m.Word(Packets)+off,head);}
    }
   }
   m.Half(e+0x186,(ushort)(m.Half(e+0x186)+particles));for(uint i=0;i<3;i++)m.Word(e+0x1a8+i*4,velocity==0?0:m.Word(velocity+i*4));
   PtlEmitterTransforms.SecondaryMatrix(m,(uint)Short(m.Half(r+0x3d0+(uint)selected*2)),secondary);m.Word(e+0x324,previous);uint time=first;iterations=0;
   if(F(time)<=F(end))do{
    if(++iterations>=100)break;
    if(delta!=0)PtlBurstMath.ScaledAdd(m,e+0x19c,position,delta,N.Sub(N.Word(time),N.Word(end)).Store());else for(uint i=0;i<3;i++)m.Word(e+0x19c+i*4,m.Word(position+i*4));
    m.Word(e+0x1e0,time);uint cue=service(m,m.Word(e+0x1c0),new uint[]{e,r,time});if(m.Byte(r+0x2f0)!=0&&iterations==1&&cue!=0)PtlEmitterEventRing.Produce(m,cue,time,r,e,1);
    time=N.Add(N.Word(step),N.Word(m.Word(e+0x324))).Store();
   }while(F(time)<=F(end));
   Acquire(m);ushort scheduled=m.Half(e+0x188),chunks=m.Half(e+0x180);
   if(Short(scheduled)<Short(chunks)){int i=Short(scheduled);uint cursor=e+0x100+(uint)i*4;uint cachedCount=m.Word(ReturnCount);
    while(i<Short(m.Half(e+0x180))){int max=I((m.Word(0x8108ec)+m.Word(0x8108e8))*2);if(I(cachedCount)<max){uint node=m.Word(m.Word(Returns)+cachedCount*4);m.Word(node,m.Word(cursor));uint life=m.Word(r+0x414);int frames=(sbyte)m.Byte(r+0x410);uint deadline=N.Add(N.Add(N.Word(m.Word(r+0xa4)),N.Word(clock)),N.Mul(N.Word(life),N.Integer(frames))).Store();node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+4,deadline);
      node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+8,1);node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+12,e);node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);PtlParticleLinks.Timed(m,node,0x292fbfc+(uint)bank*4);m.Word(ReturnCount,m.Word(ReturnCount)+1);m.Half(e+0x188,(ushort)(m.Half(e+0x188)+1));cachedCount=m.Word(ReturnCount);
     }i++;cursor+=4;
    }
   }
   chunks=m.Half(e+0x180);if(m.Half(e+0x188)==chunks){uint head=0x292fbfc+(uint)bank*4,node=m.Word(head);if(node!=0){uint last=m.Word(e+0xfc+(uint)Short(chunks)*4);while(node!=0&&m.Word(node)!=last)node=m.Word(node+16);if(node!=0){PtlParticleUnlinks.Timed(m,node,head);m.Word(node+4,ReturnTime(m,r,clock));PtlParticleLinks.Timed(m,node,head);}}}
   ushort active=m.Half(e+0x186),allocatedChunks=m.Half(e+0x180);m.Half(e+0x18e,active);m.Half(e+0x18c,allocatedChunks);m.Word(0x2962058,0);
  }}
 }
}
