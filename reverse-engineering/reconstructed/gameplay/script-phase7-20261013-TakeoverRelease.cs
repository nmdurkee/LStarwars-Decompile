// Original-PC takeover release inline producer and seat projection.
// Evidence: script-phase7-20261013-contract.json. Prepared memory, no native pointers.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class TakeoverReleaseMemory
 {
  public abstract byte Read8(uint address);
  public abstract void Write8(uint address,byte value);
  public ushort Read16(uint p){return (ushort)(Read8(p)|(Read8(p+1)<<8));}
  public uint Read32(uint p){return (uint)(Read8(p)|(Read8(p+1)<<8)|(Read8(p+2)<<16)|(Read8(p+3)<<24));}
  public void Write16(uint p,ushort v){Write8(p,(byte)v);Write8(p+1,(byte)(v>>8));}
  public void Write32(uint p,uint v){for(int i=0;i<4;i++)Write8(p+(uint)i,(byte)(v>>(i*8)));}
  public float Float(uint p){return BitConverter.ToSingle(BitConverter.GetBytes(Read32(p)),0);}
  public static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
 }
 public abstract class TakeoverReleaseServices
 {
  // 4876a0(mode=1, camera=0, final=0). Includes all callee mutations.
  public abstract int Transfer(TakeoverReleaseMemory m,uint rider,uint other);
  public abstract void Rebind(TakeoverReleaseMemory m,uint actor);
  public abstract void RefreshPose(TakeoverReleaseMemory m,uint actor);
  public abstract void Eject(TakeoverReleaseMemory m,uint rider,uint other);
  public abstract void VehicleResponse(TakeoverReleaseMemory m,uint other,uint rider);
  public abstract float DistanceFactor(TakeoverReleaseMemory m,uint position,uint target);
  public abstract void DirectedJump(TakeoverReleaseMemory m,uint rider,uint target,float speed,float duration);
  public abstract void Camera(TakeoverReleaseMemory m,uint camera,float duration);
  public abstract int ChangeReleasedState(TakeoverReleaseMemory m,uint packet);
  public abstract void RunScript(TakeoverReleaseMemory m,uint system,uint actor,uint packet,uint deltaBits);
 }
 public static class TakeoverRelease
 {
  static uint Add(uint p,int delta){return unchecked(p+(uint)delta);}
  static void Finite(float f){if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("finite release arithmetic");}
  static float Product(float a,float b){Finite(a);Finite(b);float v=(float)((double)a*b);Finite(v);return v;}
  // 4871a0: signed index, native matrix presence gate, ordered writes preserve aliases.
  // Matrix path copies arbitrary bits. Fallback scope is finite binary32 positions.
  public static void SeatPosition(TakeoverReleaseMemory m,uint actor,uint output)
  {
   uint def=m.Read32(actor+0x54),type=m.Read32(def+0x24);int seat=unchecked((sbyte)m.Read8(type+0x113));
   if(seat!=-1&&m.Read32(Add(m.Read32(actor+0x50),0x14+seat*4))!=0)
   {uint p=Add(actor,0x834+seat*0x40);m.Write32(output,m.Read32(p));m.Write32(output+4,m.Read32(p+4));m.Write32(output+8,m.Read32(p+8));}
   else{Finite(m.Float(actor+0x5c));m.Write32(output,m.Read32(actor+0x5c));Finite(m.Float(actor+0x194));m.Write32(output+4,m.Read32(actor+0x194));Finite(m.Float(actor+0x64));m.Write32(output+8,m.Read32(actor+0x64));}
  }
  static byte[] Snapshot(TakeoverReleaseMemory m,uint p){byte[] b=new byte[0xcc];for(uint i=0;i<0xcc;i++)b[i]=m.Read8(p+i);return b;}
  static void Restore(TakeoverReleaseMemory m,uint p,byte[] b){for(uint i=0;i<0xcc;i++)m.Write8(p+i,b[i]);}
  static void Flag100(TakeoverReleaseMemory m,uint actor,uint saved){m.Write32(actor+0x1fc,(m.Read32(actor+0x1fc)&~0x100u)|(saved&0x100));}
  // 4882d0. 486f20 is RET: EAX still denotes other, not a newly allocated actor.
  // Service implementations must model downstream state and faults; none are implicit no-ops.
  public static void Release(TakeoverReleaseMemory m,TakeoverReleaseServices services,uint input)
  {
   uint linked=m.Read32(input+0xcd0);if(linked==0)return;
   uint rider,other;if(m.Read8(input+0x7b5)==59){rider=input;other=linked;}else{rider=linked;other=input;}
   byte[] savedRider=Snapshot(m,rider+0x2c8),savedOther=Snapshot(m,other+0x2c8);
   uint flagRider=m.Read32(rider+0x1fc),flagOther=m.Read32(other+0x1fc);
   if((m.Read8(rider+0xef4)&2)==0&&services.Transfer(m,rider,other)==0)return;
   // Original loads both definition names even though RET does not use their values.
   m.Read32(m.Read32(other+0x54)+0xc);m.Read32(m.Read32(rider+0x54)+0xc);
   Restore(m,rider+0x2c8,savedOther);Restore(m,other+0x2c8,savedRider);
   m.Write8(rider+0x378,savedRider[0xb0]);m.Write8(other+0x378,savedOther[0xb0]);
   services.Rebind(m,other);Flag100(m,rider,flagOther);Flag100(m,other,flagRider);
   linked=m.Read32(rider+0xcd0);
   if(linked!=0){SeatPosition(m,linked,rider+0x5c);linked=m.Read32(rider+0xcd0);m.Write16(rider+0x278,0);m.Write16(rider+0x27c,0);m.Write16(rider+0x27a,m.Read16(linked+0x58));m.Write16(rider+0x58,m.Read16(linked+0x58));m.Write16(rider+0x5a,m.Read16(linked+0x58));}
   services.RefreshPose(m,rider);m.Write32(rider+0xcd0,0);m.Write8(rider+0x7b5,255);
   if(m.Read16(other+0x1064)==m.Read16(0x7f1914)&&m.Read32(m.Read32(0x802c54)+0x128)==m.Read32(0x87b234))
   {float factor=services.DistanceFactor(m,rider+0x5c,0x7fa574);float duration=Product(factor,m.Float(0x7fa570));float speed=Product(factor,m.Float(0x7fa56c));services.DirectedJump(m,rider,0x7fa574,speed,duration);services.Camera(m,m.Read32(0x8021b4),2);}
   else services.Eject(m,rider,other);
   uint type=m.Read32(m.Read32(other+0x54)+0x24);
   if(m.Float(type+0x28)>0){float a=m.Float(rider+0x6c),b=m.Float(other+0x6c);Finite(a);Finite(b);float v=FiniteX87.Dot3PlusConstant(-0.5f,0,0,a,0,0,b);if(a==0&&b==0&&TakeoverReleaseMemory.Bits(a)==0&&TakeoverReleaseMemory.Bits(b)==0x80000000)v=b;Finite(v);m.Write32(other+0x6c,TakeoverReleaseMemory.Bits(v));}
   else if((m.Read32(type+0x94)&0x20000)!=0)services.VehicleResponse(m,other,rider);
   m.Write32(other+0xcd0,0);m.Write32(rider+0xe20,m.Read32(rider+0xe20)&0x7fffffff);m.Write32(other+0xe20,m.Read32(other+0xe20)&0x7fffffff);m.Write16(rider+0x42e,(ushort)(m.Read16(rider+0x42e)&0xfffe));
   m.Write32(other+0x10bc,m.Read32(other+0x5c));m.Write32(other+0x10c0,m.Read32(other+0x60));m.Write32(other+0x10c4,m.Read32(other+0x64));
   if(m.Read8(rider+0x280)!=255||m.Read8(other+0x280)!=255)services.Camera(m,m.Read32(0x8021b4),0.3f);
   uint packet=rider+0x2c8;if(services.ChangeReleasedState(m,packet)!=0)services.RunScript(m,m.Read32(m.Read32(0x802c54)+0x2ae8),rider,packet,m.Read32(0x925018));
   packet=other+0x2c8;if(services.ChangeReleasedState(m,packet)!=0)services.RunScript(m,m.Read32(m.Read32(0x802c54)+0x2ae8),other,packet,m.Read32(0x925018));
  }
 }
}
