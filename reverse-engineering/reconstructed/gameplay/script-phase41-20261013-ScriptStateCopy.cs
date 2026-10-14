// Deep state copying: names/conditions/actions/reference guards, preserving shallow condition fields.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptStateCopy
 {
  static void Zero(TakeoverReleaseMemory m,uint p,uint size){for(uint i=0;i<size;i++)m.Write8(p+i,0);}
  static uint Allocate(TakeoverReleaseMemory m,uint top,uint size){uint p=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(p+size));Zero(m,p,size);return p;}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  static uint Text(TakeoverReleaseMemory m,ScriptConditionLoadServices s,uint source,uint top,uint bottom){if(source==0)return 0;uint size=(uint)PreparedConditionLoading.Text(m,source).Length;if(size==0)return 0;size++;uint p=0;if(unchecked(m.Read32(top)+size)<m.Read32(bottom))p=Allocate(m,top,size);else s.Diagnostic(m,0x512850,new uint[0]);for(uint i=0;i<4096;i++){byte c=m.Read8(source+i);m.Write8(p+i,c);if(c==0)return p;}throw new ArgumentException("Bounded copied reference name required.");}
  //513cc0 customEAX=topPointer, cdecl(sourceState,bottomPointer); EAX newstatepointer.
  public static uint Copy(TakeoverReleaseMemory m,ScriptConditionLoadServices s,uint source,uint top,uint bottom)
  {
   if(top==0||bottom==0||unchecked(m.Read32(top)+0x24)>=m.Read32(bottom)){s.Diagnostic(m,0x512850,new uint[0]);return 0;}uint state=Allocate(m,top,0x24);if(state==0)return state;uint name=PreparedConditionLoading.CopyString(m,top,m.Read32(source+0x18),bottom);m.Write32(state+0x18,name);PreparedConditionMaterialization.CopyMacro(m,s,source+8,state+8,top,bottom);PreparedScriptActionPrimitives.CopyActions(m,s.Diagnostic,source+0x10,state+0x10,top,bottom);uint reference=m.Read32(source+0x1c),budget=0;
   while(reference!=0){if(++budget>4096)throw new ArgumentException("Bounded source references required.");if(unchecked(m.Read32(top)+0x24)>=m.Read32(bottom))s.Diagnostic(m,0x512850,new uint[0]);else{uint copy=Allocate(m,top,0x24);if(copy!=0){uint scriptName=Text(m,s,m.Read32(reference+8),top,bottom);m.Write32(copy+8,scriptName);uint target=Text(m,s,m.Read32(reference+0x10),top,bottom);m.Write32(copy+0x10,target);uint flags=m.Read32(copy+0x18);m.Write32(copy+0x18,flags^((flags^m.Read32(reference+0x18))&1));flags=m.Read32(copy+0x18);m.Write32(copy+0x18,flags^((flags^m.Read32(reference+0x18))&2));PreparedConditionMaterialization.CopyMacro(m,s,reference+0x1c,copy+0x1c,top,bottom);Append(m,state+0x1c,copy);}}reference=m.Read32(reference);}return state;
  }
 }
}
