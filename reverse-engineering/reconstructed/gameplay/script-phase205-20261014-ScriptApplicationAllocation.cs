// Whole application allocation471/free450 byte bodies; recovered world133 memset reused.
namespace Recovered.Gameplay
{
 public abstract class ScriptApplicationHeapServices
 {
  public abstract uint CrtAllocate(ConditionParserMemory m,uint capacity);
  public abstract uint PoolAllocate(ConditionParserMemory m,uint pool,uint capacity,uint alignment);
  public abstract void CrtFree(ConditionParserMemory m,uint block);
  public abstract void PoolFree(ConditionParserMemory m,uint pool,uint block);
 }
 public static class RecoveredScriptAllocationDiagnostics
 {
  //Original4eeda0 and4eedc0 are single RETs in this release binary; warnings continue.
  public static void Fatal(){}public static void Diagnostic(){}
 }
 public static class RecoveredScriptApplicationAllocation
 {
  static uint Length(ConditionParserMemory m,uint p){uint q=p;while(m.Read8(q)!=0)q++;return unchecked(q-p);}
  static bool Canary(ConditionParserMemory m,uint p,uint expected){for(uint i=0;i<12;i++)if(m.Read8(p+i)!=m.Read8(expected+i))return false;return true;}
  public static uint Allocate(ConditionParserMemory m,ScriptApplicationHeapServices s,uint size,uint filename,uint line){unchecked{if((int)size<=0)RecoveredScriptAllocationDiagnostics.Fatal();uint arena=m.Read32(0x88ab28);if(arena!=0){uint cursor=m.Read32(arena);m.Write32(cursor,(m.Read32(cursor)+15)&0xfffffff0);cursor=m.Read32(arena);uint limit=m.Read32(arena+4);if(limit-m.Read32(cursor)<size){RecoveredScriptAllocationDiagnostics.Fatal();return 0;}uint result=m.Read32(cursor);m.Write32(cursor,result+size);return result;}uint bump=m.Read32(0x88ab20);if(bump!=0){uint remaining=m.Read32(bump+4),aligned=(size+15)&0xfffffff0;if((int)aligned>=(int)remaining)return 0;uint result=m.Read32(bump+8);m.Write32(bump+8,result+aligned);m.Write32(bump+4,remaining-aligned);return result;}uint pool=m.Read32(0x88ab2c),total=Length(m,filename)+size+45,block;if(pool!=0)block=s.PoolAllocate(m,pool,total,4);else{block=s.CrtAllocate(m,total);if(block!=0)PtlRuntimeMemory.Fill(m.Image,block,0,Length(m,filename)+size+45);}if(block!=0){PtlRuntimeMemory.Fill(m.Image,block,0,Length(m,filename)+size+45);m.Write32(0x88ab1c,m.Read32(0x88ab1c)+size);m.Write32(block+16,size);for(uint i=0;i<3;i++)m.Write32(block+20+i*4,m.Read32(0x800444+i*4));for(uint i=0;i<3;i++)m.Write32(block+size+32+i*4,m.Read32(0x800454+i*4));uint p=filename,q=block+size+44;while(true){byte b=m.Read8(p++);m.Write8(q++,b);if(b==0)break;}uint sequence=m.Read32(0x88ab24);m.Write32(block+12,sequence);m.Write32(0x88ab24,sequence+1);uint head=m.Read32(0x88ab18);m.Write32(block+8,line);m.Write32(block,head);if(head!=0)m.Write32(head+4,block);m.Write32(block+4,0);m.Write32(0x88ab18,block);block+=32;}else{RecoveredScriptAllocationDiagnostics.Diagnostic();RecoveredScriptAllocationDiagnostics.Fatal();}uint end=block+size;if((int)end>(int)m.Read32(0x88ab30))m.Write32(0x88ab30,end);if((int)end>(int)m.Read32(0x88ab34))m.Write32(0x88ab34,end);return block;}}
  public static void Release(ConditionParserMemory m,ScriptApplicationHeapServices s,uint pointer,uint filename,uint line){unchecked{if(m.Read32(0x88ab28)!=0)RecoveredScriptAllocationDiagnostics.Fatal();if(pointer==0){RecoveredScriptAllocationDiagnostics.Diagnostic();return;}uint size=m.Read32(pointer-16),block=pointer-32;if(!Canary(m,pointer+size,0x800454))RecoveredScriptAllocationDiagnostics.Diagnostic();if(!Canary(m,block+20,0x800444))RecoveredScriptAllocationDiagnostics.Diagnostic();uint previous=m.Read32(block);if(previous==0){if(m.Read32(block+4)==0)RecoveredScriptAllocationDiagnostics.Diagnostic();previous=m.Read32(block);}if(previous!=0)m.Write32(previous+4,m.Read32(block+4));uint next=m.Read32(block+4);if(next!=0)m.Write32(next,m.Read32(block));else m.Write32(0x88ab18,m.Read32(block));m.Write32(0x88ab1c,m.Read32(0x88ab1c)-m.Read32(block+16));m.Write32(block,0);m.Write32(block+4,0);uint pool=m.Read32(0x88ab2c);if(pool!=0)s.PoolFree(m,pool,block);else s.CrtFree(m,block);}}
 }
}
