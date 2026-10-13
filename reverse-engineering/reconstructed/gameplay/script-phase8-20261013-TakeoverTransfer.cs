// Original-PC 4876a0 takeover mode1. Mode0 lives in PlayerTransfer.cs.
// Uses the prepared memory interface and explicit downstream services from phase7.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class TakeoverTransferServices
 {
  public abstract void Rebind(TakeoverReleaseMemory m,uint actor);
  public abstract int ChangeTakenOverState(TakeoverReleaseMemory m,uint packet);
  public abstract void RunScript(TakeoverReleaseMemory m,uint system,uint actor,uint packet,uint deltaBits);
  public abstract void ClearAction(TakeoverReleaseMemory m,uint actor);
  public abstract void ResetActor(TakeoverReleaseMemory m,uint actor);
  public abstract void StopActor(TakeoverReleaseMemory m,uint actor);
  public abstract void ResetAnimation(TakeoverReleaseMemory m,uint embedded);
  public abstract void PrepareActor(TakeoverReleaseMemory m,uint actor);
  // Original custom ABI: ECX=target, EDI=source; no stack arguments.
  public abstract void SelectTakeoverAnimation(TakeoverReleaseMemory m,uint target,uint source);
  public abstract void Camera(TakeoverReleaseMemory m,uint camera,float duration);
 }
 public static class TakeoverTransfer
 {
  static uint Add(uint p,int d){return unchecked(p+(uint)d);}
  static void Finite(float f){if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("finite takeover arithmetic");}
  static void Swap32(TakeoverReleaseMemory m,uint a,uint b){uint v=m.Read32(a);m.Write32(a,m.Read32(b));m.Write32(b,v);}
  static void FloatSwap(TakeoverReleaseMemory m,uint a,uint b){Finite(m.Float(a));uint v=m.Read32(a);Finite(m.Float(b));m.Write32(a,m.Read32(b));m.Write32(b,v);}
  static void Flag(TakeoverReleaseMemory m,uint a,uint saved,uint mask){m.Write32(a+0x1fc,(m.Read32(a+0x1fc)&~mask)|(saved&mask));}
  static byte[] Snapshot(TakeoverReleaseMemory m,uint a){byte[] b=new byte[0xcc];for(uint i=0;i<0xcc;i++)b[i]=m.Read8(a+0x2c8+i);return b;}
  static void Restore(TakeoverReleaseMemory m,uint a,byte[] b){for(uint i=0;i<0xcc;i++)m.Write8(a+0x2c8+i,b[i]);}
  static void Reset(TakeoverReleaseMemory m,uint actor){foreach(uint offset in new uint[]{0xd80,0xd84,0xd14,0xd90,0xd18})m.Write32(actor+offset,0);m.Write32(actor+0xd88,0x3e4ccccd);}
  static void ClearAux(TakeoverReleaseMemory m,uint actor){uint p=m.Read32(actor+0x800);if(p!=0)for(uint i=0;i<0x630;i++)m.Write8(p+i,0);}
  // Exact nonzero takeover mode; negative and positive native mode values share this path.
  // Float-moved DA8/DEC/1000 fields and final arithmetic require finite F32 backing.
  public static int Transfer(TakeoverReleaseMemory m,TakeoverTransferServices services,uint source,uint target,bool camera)
  {
   if(m.Read32(0x951c5c)!=0)return 0;
   Finite(m.Float(source+0xda8));uint da8=m.Read32(source+0xda8),inputSource=m.Read32(source+0xca4),inputTarget=m.Read32(target+0xca4);
   // Both health loads occur natively even though takeover mode does not use them.
   m.Read8(target+0x107f);uint flagsTarget=m.Read32(target+0x1fc);m.Read8(source+0x107f);uint flagsSource=m.Read32(source+0x1fc);
   byte[] savedSource=Snapshot(m,source),savedTarget=Snapshot(m,target);Reset(m,source);Reset(m,target);
   m.Write32(target+0xca4,inputSource);m.Write32(source+0xca4,inputTarget);Flag(m,source,flagsTarget,0x80);Flag(m,target,flagsSource,0x80);
   Finite(m.Float(target+0xda8));m.Write32(source+0xda8,m.Read32(target+0xda8));m.Write32(target+0xda8,da8);Swap32(m,source+0x7fc,target+0x7fc);
   byte personal=m.Read8(source+0x280);m.Write8(source+0x280,m.Read8(target+0x280));m.Write8(target+0x280,personal);FloatSwap(m,source+0xdec,target+0xdec);Swap32(m,source+0x800,target+0x800);ClearAux(m,source);ClearAux(m,target);
   uint flags=m.Read32(source+0x1f8),mask=0x146fd;uint unmasked=flags&~mask;m.Write32(source+0x1f8,unmasked);m.Write32(source+0x1f8,unmasked|(m.Read32(target+0x1f8)&mask));m.Write32(target+0x1f8,(m.Read32(target+0x1f8)&~mask)|(flags&mask));
   Swap32(m,source+0xea8,target+0xea8);FloatSwap(m,source+0x1000,target+0x1000);services.Rebind(m,source);
   int index=unchecked((sbyte)m.Read8(source+0x280));if(index!=-1)m.Write32(Add(0x93d7f0,index*4),source);index=unchecked((sbyte)m.Read8(target+0x280));if(index!=-1)m.Write32(Add(0x93d7f0,index*4),target);
   m.Write32(target+0xef0,m.Read32(target+0xef0)&0xffe7ffff);m.Write32(target+0xee4,0);m.Write32(target+0xee8,0);m.Write32(target+0x7c0,0x3f800000);
   if(source==m.Read32(0x87a7c8)&&target!=m.Read32(0x87a7cc)){m.Write32(0x87a7d0,0);m.Write32(0x87a7c8,0);m.Write32(0x87a7cc,0);m.Write32(0x87a7d4,0);}
   uint packet=target+0x2c8;if(services.ChangeTakenOverState(m,packet)!=0)services.RunScript(m,m.Read32(m.Read32(0x802c54)+0x2ae8),target,packet,m.Read32(0x925018));
   Restore(m,source,savedTarget);Restore(m,target,savedSource);m.Write8(source+0x378,savedSource[0xb0]);m.Write8(target+0x378,savedTarget[0xb0]);services.Rebind(m,source);Flag(m,source,flagsTarget,0x100);Flag(m,target,flagsSource,0x100);
   services.ClearAction(m,source);services.ResetActor(m,source);services.StopActor(m,source);services.ResetAnimation(m,source+0x6c4);if((m.Read8(source+0xeec)&0x10)==0)services.PrepareActor(m,source);
   m.Write32(source+0xcd0,target);m.Write32(target+0xcd0,source);m.Write32(source+0xea4,0);m.Write32(target+0xea4,0);m.Write32(source+0xcd4,target);m.Write8(source+0x7b5,59);services.SelectTakeoverAnimation(m,m.Read32(source+0xcd0),source);
   m.Write32(source+0xdd0,0x3f800000);m.Write32(source+0x748,m.Read32(source+0x5c));m.Write32(source+0x74c,m.Read32(source+0x60));m.Write32(source+0x750,m.Read32(source+0x64));if(camera)services.Camera(m,m.Read32(0x8021b4),.5f);
   uint type=m.Read32(m.Read32(target+0x54)+0x24);if(m.Float(type+0x28)>0){float a=m.Float(m.Read32(m.Read32(source+0x54)+0x24)+0x2c),b=m.Float(target+0x6c);Finite(a);Finite(b);float v=FiniteX87.Dot3PlusConstant(-.5f,0,0,a,0,0,b);if(a==0&&b==0&&TakeoverReleaseMemory.Bits(a)==0&&TakeoverReleaseMemory.Bits(b)==0x80000000)v=b;Finite(v);m.Write32(target+0x6c,TakeoverReleaseMemory.Bits(v));}return 1;
  }
 }
}
