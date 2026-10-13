using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class ActorCreationWorld
 {
  public OriginPathMemory Memory;
  public uint World,Registry;
  public bool TypeLock,RefreshTypeState;
  public ushort HeroType;
  public bool ContextActive;
  public sbyte ContextIndex;
  public int SelectedRoom,CurrentRoom;
  public byte[] GroupCounts;
  public uint[] DefaultPosition,LastPosition;
  public float[] SineTable;
  public Func<uint,uint> AllocateActor;
  public Func<uint,uint,uint[],uint> Service;
  public Action<uint> DimensionsUpdated;
 }
 public static class ActorCreation
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static uint Call(ActorCreationWorld w,uint address,uint actor,params uint[]args){if(w.Service==null)throw new InvalidOperationException("Original child service required.");return w.Service(address,actor,args);}
  static ushort Word(OriginPathMemory m,uint p){return unchecked((ushort)m.U32(p));}
  static void PutWord(OriginPathMemory m,uint p,ushort v){m.Set8(p,v&255);m.Set8(p+1,v>>8);}
  static N Sin(ActorCreationWorld w,int a){return N.From(w.SineTable[(a>>1)&32767]);}
  static N Cos(ActorCreationWorld w,int a){return N.From(w.SineTable[(unchecked(a+0x4000)>>1)&32767]);}
  static float[] Y(ActorCreationWorld w,float[]v,int a){N s=Sin(w,a),c=Cos(w,a),x=N.From(v[0]),z=N.From(v[2]);return new float[]{(s*z+c*x).Store(),v[1],(z*c-x*s).Store()};}
  static float[] X(ActorCreationWorld w,float[]v,int a){N s=Sin(w,a),c=Cos(w,a),y=N.From(v[1]),z=N.From(v[2]);return new float[]{v[0],(c*y-s*z).Store(),(s*y+c*z).Store()};}
  static void Add(OriginPathMemory m,uint output,uint a,uint b){for(uint j=0;j<3;j++)m.SetFloat(output+j*4,(N.From(m.F32(a+j*4))+N.From(m.F32(b+j*4))).Store());}
  static uint ShiftLow(uint count){uint c=count&255;return c<32?1u<<(int)c:0;}
  public static uint Create(ActorCreationWorld w,uint type,uint position,uint heading,uint state,uint path,uint formation,uint snap,uint spline,uint offset,uint pathTime,uint group,uint scratch)
  {
   if(position==0&&spline==0)return 0;if(w.TypeLock&&type!=unchecked((uint)(short)w.HeroType))return 0;if(w.ContextActive&&w.ContextIndex==0)return 0;if(type>0x153)return 0;var m=w.Memory;if(Word(m,m.U32(w.Registry+0x1c)+type*2)==0xffff)return 0;if(w.AllocateActor==null)throw new InvalidOperationException("Recovered actor allocation/initialization required.");uint actor=w.AllocateActor(type);if(actor==0)return 0;
   m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|0x400);uint index=type*0x4c,flags=m.U32(m.U32(w.Registry+0x20)+index+4);if((flags&0x200)!=0)m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|4);else if((flags&4)!=0)m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|1);m.Set32(actor+0x1044,m.U32(actor+0x1044)|1);if((m.U32(m.U32(w.Registry+0x20)+index+4)&0x1000)!=0)m.Set32(actor+0x1044,m.U32(actor+0x1044)|4);
   for(uint j=0;j<3;j++)m.Set32(actor+0x230+j*4,m.U32(m.U32(m.U32(w.Registry+0x20)+index+0x24)+0x64+j*4));uint last=m.U32(m.U32(m.U32(w.Registry+0x20)+index+0x24)+0x70);m.Set32(actor+0x4b0,m.U32(actor+0x4b0)&0xffffafff);m.Set32(actor+0xeec,m.U32(actor+0xeec)&0xfffff7fe);m.Set32(actor+0x23c,last);
   foreach(uint at in new uint[]{0x39c,0x454,0x3a4,0x3ac})m.Set32(actor+at,0);m.SetFloat(actor+0x3a8,1000000000);m.Set32(actor+0x3b4,0);m.SetFloat(actor+0x3b8,1000000000);foreach(uint at in new uint[]{0x2a8,0x2ac,0xeb0,0xec4,0xeb4,0xecc,0xec0})m.Set32(actor+at,0);Call(w,0x41b0a0,actor,actor);
   uint physical=actor+0x5c;
   if(spline!=0)
   {
    Call(w,0x553570,actor,actor+0xe64,spline,0,pathTime);Call(w,0x550a20,actor,m.U32(actor+0xe64),m.U32(actor+0xe80),scratch,scratch+0x10,scratch+0x14,unchecked((uint)(sbyte)m.U8(actor+0xe6a)));ushort angle=Word(m,scratch+0x10);PutWord(m,actor+0x5a,angle);PutWord(m,actor+0x58,angle);PutWord(m,actor+0x27a,angle);PutWord(m,actor+0x278,unchecked((ushort)-(int)Word(m,scratch+0x14)));
    if(offset!=0){for(uint j=0;j<3;j++)m.Set32(actor+0xe84+j*4,m.U32(offset+j*4));float[]v=m.Vector(actor+0xe84);if(v[0]!=0||v[1]!=0||v[2]!=0){v=Y(w,X(w,v,Word(m,actor+0x278)),Word(m,actor+0x27a));m.SetVector(scratch+0x20,v);Add(m,scratch,scratch,scratch+0x20);}}
    for(uint j=0;j<3;j++)m.Set32(physical+j*4,m.U32(scratch+j*4));
   }
   else
   {
    for(uint j=0;j<3;j++)m.Set32(physical+j*4,m.U32(position+j*4));PutWord(m,actor+0x27a,(ushort)heading);PutWord(m,actor+0x58,(ushort)heading);PutWord(m,actor+0x5a,(ushort)heading);
    if(formation!=0){Call(w,0x518040,actor,formation,actor);int column=(m.U8(actor+0x411)+1)/2;float x=(N.From(column)*N.From(m.F32(formation+0x128))).Store();if((m.U8(actor+0x411)&1)!=0)x=PcObjectImage.FromBits(PcObjectImage.ToBits(x)^0x80000000);float z=(N.From(m.U8(actor+0x412))*-N.From(m.F32(formation+0x12c))).Store();m.SetVector(scratch+0x20,Y(w,new float[]{x,0,z},unchecked((int)heading)));Add(m,physical,physical,scratch+0x20);}
   }
   Call(w,0x41af70,actor,actor);uint px=m.U32(physical),py=m.U32(physical+4),pz=m.U32(physical+8);m.Set32(actor+0x80,px);m.Set32(actor+0x84,py);m.Set32(actor+0x88,pz);m.Set32(actor+0x98,px);m.Set32(actor+0x9c,py);m.Set32(actor+0xa0,pz);w.LastPosition[0]=m.U32(actor+0x80);w.LastPosition[1]=m.U32(actor+0x84);w.LastPosition[2]=m.U32(actor+0x88);m.Set32(actor+0x8c,m.U32(actor+0x80));m.Set32(actor+0x90,m.U32(actor+0x84));m.Set32(actor+0x94,m.U32(actor+0x88));for(uint j=0;j<3;j++)m.Set32(actor+0x68+j*4,w.DefaultPosition[j]);ActorCollisionDimensions.HeightFactor(m,actor);ActorCollisionDimensions.Update(m,actor,w.DimensionsUpdated);Call(w,0x54a7f0,actor,m.U32(actor+0xca4)+0x40);Call(w,0x595840,actor,physical,actor+0x4d8,m.U32(w.World+0x2ab4));m.Set8(actor+0x671,255);PutWord(m,actor+0x672,0xffff);
   uint rooms=m.U32(w.World+0x2988);if(rooms!=0){int selected=w.SelectedRoom;if(selected!=-1&&m.U8(unchecked(m.U32(rooms)+(uint)(selected*0x13c)+0x32))!=0)w.CurrentRoom=selected;Call(w,0x541bc0,actor,rooms,physical,unchecked((uint)(sbyte)m.U8(actor+0x671)),unchecked((uint)(short)Word(m,actor+0x672)),actor+0x670);Call(w,0x53f380,actor,actor+0x7cc);}
   int h=Word(m,actor+0x27a);m.SetVector(actor+0xf30,new float[]{Sin(w,h).Store(),0,Cos(w,h).Store()});m.Set32(actor+0xef0,m.U32(actor+0xef0)&0xfffbffff);m.Set8(actor+0x288,1);m.Set8(actor+0x1079,0);m.Set8(actor+0x28c,0);if(spline==0){Call(w,0x5728a0,actor,actor);if(snap!=0)Call(w,0x572660,actor,actor,0);}Call(w,0x55d6a0,actor,actor,1,1,0xffffffff,m.U32(w.World+0x13c));
   if(w.RefreshTypeState){uint data=m.U32(m.U32(actor+0x54)+0x24);byte v=m.U8(data+0xf4);m.Set8(actor+0x107e,v);m.Set8(actor+0x107f,v);data=m.U32(m.U32(actor+0x54)+0x24);m.Set8(actor+0xe38,m.U8(data+0xf5));m.Set8(actor+0xe39,4);}m.Set32(actor+0x1fc,m.U32(actor+0x1fc)&0xfffffffb);m.SetFloat(actor+0xff8,1);m.Set8(actor+0x28b,0);m.Set8(actor+0x7b5,255);m.Set8(actor+0x289,0);m.Set32(actor+0x1f8,m.U32(actor+0x1f8)&0xfffffeff);for(uint j=0;j<6;j++)m.Set32(actor+0x420+j*4,0);PutWord(m,actor+0x3ec,0xffff);m.Set8(actor+0x404,255);m.Set8(actor+0x405,0);
   if(spline==0){if(path!=0){Call(w,0x51a7c0,actor,actor+0x2c8,m.U32(path));Call(w,0x51b890,actor,actor+0x2c8,physical,m.U32(path+4),m.U8(path+8));}if(m.U32(actor+0x424)==0)Call(w,0x52f800,actor,m.U32(w.World+0x2ae8),actor,actor+0x2c8,0xff,unchecked((uint)(sbyte)m.U8(actor+0x281)));}Call(w,0x514640,actor,m.U32(w.World+0x2ae8),actor+0x2c8,actor+0x2c8,0,state,0,1,0,0);m.SetFloat(actor+0x218,2000000);
   uint form=m.U32(actor+0x40c);if(form!=0){m.Set32(form+0x4c,m.U32(form+0x4c)|ShiftLow(m.U8(actor+0x410)));uint rowIndex=m.U8(actor+0x412);form=m.U32(actor+0x40c);uint row=form+0x54+rowIndex*0x34;uint count=unchecked((uint)m.U8(actor+0x410)-(uint)m.U8(form+8)*rowIndex);m.Set8(row+0x2d,m.U8(row+0x2d)|(int)(ShiftLow(count)&255));if(m.U8(actor+0x411)==0){for(uint j=0;j<3;j++)m.Set32(row+0x18+j*4,m.U32(physical+j*4));for(uint j=0;j<6;j++)m.Set32(row+j*4,m.U32(actor+0x420+j*4));uint angle=Word(m,actor+0x27a);m.Set32(row+0x30,m.U32(row+0x30)&0xfffffffd);m.Set32(row+0x24,angle);m.Set32(row+0x28,0);}}
   Call(w,0x498a40,actor,actor);Call(w,0x4b6b80,actor,actor);Call(w,0x55d2b0,actor,actor);px=m.U32(physical);py=m.U32(physical+4);pz=m.U32(physical+8);m.Set32(actor+0x1b4,px);m.Set32(actor+0x10bc,px);m.Set32(actor+0x1b8,py);m.Set32(actor+0x10c0,py);m.Set32(actor+0x1bc,pz);m.Set32(actor+0x10c4,pz);if(unchecked(group-1)<16){m.Set8(actor+0x378,(int)group);w.GroupCounts[group]=unchecked((byte)(w.GroupCounts[group]+1));}return actor;
  }
 }
}
