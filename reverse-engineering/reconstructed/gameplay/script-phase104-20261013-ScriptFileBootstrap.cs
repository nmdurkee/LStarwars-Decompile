// Full file bootstrap and literal reversed-name registry, with final OS critical-section initialization explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptFileBootstrapHost {public abstract void InitializeCriticalSection(TakeoverReleaseMemory m,uint address);}
 public static class RecoveredScriptFileBootstrap
 {
  static readonly uint[,] Rows={
   {0x75eba8,0,6},
   {0x75eba0,1,6},
   {0x75eb94,2,6},
   {0x75eb88,3,6},
   {0x75eb7c,4,6},
   {0x75eb74,5,6},
   {0x75eb6c,6,6},
   {0x75eb64,7,6},
   {0x75eb5c,8,6},
   {0x75eba8,0,5},
   {0x75eba0,1,5},
   {0x75eb50,2,5},
   {0x75eb44,3,5},
   {0x75eb38,4,5},
   {0x75eb74,5,5},
   {0x75eb30,6,5},
   {0x75eb28,7,5},
   {0x75eb20,8,5},
   {0x75eb18,0,4},
   {0x75eb10,1,4},
   {0x75eb08,4,4},
   {0x75eb00,5,4},
   {0x75eaf8,6,4},
   {0x75eb28,7,4},
   {0x75eaf0,8,4},
   {0x75eae8,3,4},
   {0x75ead4,2,4},
   {0x75eb18,0,0},
   {0x75eb10,1,0},
   {0x75eacc,2,0},
   {0x75a1fc,3,0},
   {0x75eac4,4,0},
   {0x75eb00,5,0},
   {0x75eabc,6,0},
   {0x75eb28,7,0},
   {0x75eab4,8,0},
   {0x75eba8,0,2},
   {0x75eba0,1,2},
   {0x75eaac,2,2},
   {0x75eaa4,3,2},
   {0x75ea9c,4,2},
   {0x75eb74,5,2},
   {0x75ea94,6,2},
   {0x75ea8c,7,2},
   {0x75ea84,8,2},
   {0x75eb18,0,1},
   {0x75eb10,1,1},
   {0x75ea7c,2,1},
   {0x75ea74,3,1},
   {0x75d014,4,1},
   {0x75eb00,5,1},
   {0x75eb6c,6,1},
   {0x75eb64,7,1},
   {0x75eb5c,8,1},
   {0x75eb18,0,3},
   {0x75eb10,1,3},
   {0x75ea6c,2,3},
   {0x75ea64,3,3},
   {0x75eac4,4,3},
   {0x75eb00,5,3},
   {0x75eabc,6,3},
   {0x75ea5c,7,3},
   {0x75eab4,8,3}
  };
  public static void PlatformSetup(){} //4ff4a0 RET; arguments ignored.
  public static uint CrtByte(TakeoverReleaseMemory m){return m.Read8(0x8264c7);} //6db910
  //4ffa60: signed old count<=12 increments; callback may change counter before native reload.
  public static uint CriticalSlot(TakeoverReleaseMemory m,ScriptFileBootstrapHost host){if(unchecked((int)m.Read32(0x92124c))>12)return 0;m.Write32(0x92124c,unchecked(m.Read32(0x92124c)+1));host.InitializeCriticalSection(m,unchecked(0x91ef70+m.Read32(0x92124c)*24));return m.Read32(0x92124c);}
  //4f7830 EDI=name cdecl(slot,type); stores reversed bytes and length/type/slot metadata.
  //Original release warning continues at count>=64 and length>=13; mapped destination backing is required.
  public static uint Register(TakeoverReleaseMemory m,uint name,uint slot,uint type){uint index=m.Read32(0x88ab38);if(unchecked((int)index)>=64)RecoveredReleaseScriptDiagnostics.FileWarning();uint destination=unchecked(0x90fba8+(index<<4)),length=0;while(m.Read8(unchecked(name+length))!=0){if(++length>4096)throw new ArgumentException("Bounded name required.");}m.Write8(destination+15,(byte)length);if(unchecked((int)length)>=13)RecoveredReleaseScriptDiagnostics.FileWarning();for(uint i=0;i<length;i++)m.Write8(unchecked(destination+i),m.Read8(unchecked(name+length-1-i)));m.Write8(unchecked(destination+length),0);m.Write32(0x88ab38,unchecked(index+1));m.Write8(destination+13,(byte)slot);m.Write8(destination+14,(byte)type);return(byte)slot;}
  //4f78b0 argument selects one type4/slot2 literal, all63rows retain native order.
  public static uint InitializeRegistry(TakeoverReleaseMemory m,uint ignored){for(uint i=0;i<0x400;i++)m.Write8(0x90fba8+i,0);m.Write32(0x88ab38,0);uint result=0;for(int i=0;i<Rows.GetLength(0);i++)result=Register(m,Rows[i,1]==2&&Rows[i,2]==4&&ignored!=0?0x75eadcu:Rows[i,0],Rows[i,1],Rows[i,2]);return result;}
  //4f9940 cdecl(first,second,third), EAX first; complete child bodies above and final OS service.
  public static uint Initialize(TakeoverReleaseMemory m,ScriptFileBootstrapHost host,uint first,uint second,uint third){PlatformSetup();for(uint i=0;i<0x190;i++)m.Write8(0x2983740+i,0);for(uint i=0;i<0x3c0;i++)m.Write8(0x297dc60+i,0);m.Write32(0x88ab48,CriticalSlot(m,host));InitializeRegistry(m,CrtByte(m)==0?1u:0u);m.Write32(0x91ce60,0);m.Write32(0x917844,0);m.Write32(0x88ab40,0xffffffff);m.Write32(0x88ab44,0xffffffff);return first;}
 }
}
