// Condition materialization and macro node copier; parser transport and game symbols explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptConditionMaterializationServices:ScriptConditionLoadServices {public abstract uint NextLine(TakeoverReleaseMemory m,uint parser);}
 public static class PreparedConditionMaterialization
 {
  static uint Current(TakeoverReleaseMemory m,uint parser){return m.Read32(parser+0x510);}static bool Is(TakeoverReleaseMemory m,uint parser,uint name){return PreparedConditionLoading.Equal(m,Current(m,parser),name);}
  static void Clear(TakeoverReleaseMemory m,uint p,uint n){for(uint i=0;i<n;i++)m.Write8(unchecked(p+i),0);}
  static bool Admit(TakeoverReleaseMemory m,uint top,uint bottom,uint size){return top!=0&&bottom!=0&&unchecked(m.Read32(top)+size)<m.Read32(bottom);}
  static uint Allocate(TakeoverReleaseMemory m,uint top,uint size){uint p=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(p+size));Clear(m,p,size);return p;}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){m.Write32(node,0);m.Write32(node+4,m.Read32(list+4));if(m.Read32(list+4)!=0)m.Write32(m.Read32(list+4),node);m.Write32(list+4,node);if(m.Read32(list)==0)m.Write32(list,node);}
  static bool Operator(TakeoverReleaseMemory m,uint parser,uint node){uint[] names={0x758460,0x76041c,0x7533c8,0x7533c4,0x760418,0x760414,0x760410};for(int i=0;i<names.Length;i++)if(Is(m,parser,names[i])){m.Write8(node+0xc,(byte)(i<2?0:i-1));return true;}return false;}
  static uint StoreBits(uint bits){float f=BitConverter.ToSingle(BitConverter.GetBytes(bits),0);if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentException("Finite condition constant stores required.");return bits;}
  static uint[] ErrorContext(TakeoverReleaseMemory m,uint token,bool includeToken){uint state=m.Read32(0x922220),name=state==0?0x755ba8:m.Read32(state+0x18),script=m.Read32(0x92221c),scriptName=m.Read32(script+8);return includeToken?new uint[]{token,scriptName,name}:new uint[]{scriptName,name};}
  //513990 cdecl(sourceList,targetList,topPointer,bottomPointer). Disjoint source/destination lists and payloads.
  public static void CopyMacro(TakeoverReleaseMemory m,ScriptConditionLoadServices s,uint sourceList,uint targetList,uint top,uint bottom)
  {
   uint node=m.Read32(sourceList),budget=0;while(node!=0){if(++budget>4096)throw new ArgumentException("Bounded macro source list required.");if(!Admit(m,top,bottom,0x2c))s.Diagnostic(m,0x512850,new uint[0]);else{uint copy=Allocate(m,top,0x2c);if(copy!=0){Clear(m,copy,0x2c);for(uint i=0;i<0x2c;i++)m.Write8(copy+i,m.Read8(node+i));m.Write32(copy,0);m.Write32(copy+4,0);uint argText=m.Read32(node+0x14);if(argText!=0&&PreparedConditionLoading.Text(m,argText).Length!=0&&!Admit(m,top,bottom,(uint)PreparedConditionLoading.Text(m,argText).Length+1))s.Diagnostic(m,0x512850,new uint[0]);uint argument=PreparedConditionLoading.CopyString(m,top,argText,bottom);m.Write32(copy+0x14,argument);uint targetText=m.Read32(node+0x20);if(targetText!=0&&PreparedConditionLoading.Text(m,targetText).Length!=0&&!Admit(m,top,bottom,(uint)PreparedConditionLoading.Text(m,targetText).Length+1))s.Diagnostic(m,0x512850,new uint[0]);uint target=PreparedConditionLoading.CopyString(m,top,targetText,bottom);m.Write32(copy+0x20,target);Append(m,targetList,copy);}}node=m.Read32(node);}
  }
  //52b3f0 cdecl(parser), void. Creates2c-byte conditions from IF/OnMacro text lines.
  public static void Load(TakeoverReleaseMemory m,ScriptConditionMaterializationServices s,ScriptExpressionServices symbols,uint parser)
  {
   uint expressionSlot=0,budget=0;while(s.NextLine(m,parser)!=0)
   {
    if(++budget>4096)throw new ArgumentException("Bounded source lines required.");s.NextToken(m,parser);if(Is(m,parser,0x75ff74))return;
    if(Is(m,parser,0x760420))
    {
     s.NextToken(m,parser);uint descriptor=PreparedConditionLoading.FindPredicate(m,Current(m,parser));if(descriptor==0){uint callback=m.Read32(0x922248)==1?0x512870u:0x512850u;s.Diagnostic(m,callback,ErrorContext(m,Current(m,parser),true));continue;}
     uint top=m.Read32(0x922214),bottom=m.Read32(0x922218);if(!Admit(m,top,bottom,0x2c)){s.Diagnostic(m,0x512850,new uint[0]);continue;}uint condition=Allocate(m,top,0x2c);if(condition==0)continue;Clear(m,condition,0x2c);Append(m,m.Read32(0x922230),condition);m.Write32(condition+0x1c,descriptor);s.NextToken(m,parser);
     if(!Operator(m,parser,condition)){bottom=m.Read32(0x922218);uint text=Current(m,parser);top=m.Read32(0x922214);uint argument=PreparedConditionLoading.CopyString(m,top,text,bottom);m.Write32(condition+0x14,argument);s.NextToken(m,parser);Operator(m,parser,condition);}
     s.NextToken(m,parser);
     if(m.Read32(condition+0x28)==0)
     {
      string name=PreparedConditionLoading.Text(m,Current(m,parser));bool parameter=name.IndexOf("param",StringComparison.OrdinalIgnoreCase)>=0;if(parameter){m.Write8(condition+0xd,0);m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)|4));}
      else for(uint i=0;i<4;i++){uint script=m.Read32(0x92221c),p=m.Read32(script+0x18+i*8);if(p!=0&&PreparedConditionLoading.Equal(m,p,Current(m,parser))){m.Write8(condition+0xd,(byte)i);m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)|4));break;}}
      if((m.Read8(condition+0xe)&4)==0)
      {
       int index=0;if(unchecked((int)m.Read32(0x922244))>0){uint p=0x9220f0;while(index<unchecked((int)m.Read32(0x922244))){if(PreparedConditionLoading.Equal(m,p,Current(m,parser))){m.Write32(condition+8,StoreBits(m.Read32(unchecked(0x922110+(uint)index*0x24))));break;}index++;p+=0x24;}}
       if(index==unchecked((int)m.Read32(0x922244))){uint value=PreparedScriptExpressionLoading.Evaluate(m,symbols,Current(m,parser));m.Write32(condition+8,value);if(m.Read32(0x922254)!=0){m.Write16(condition+0xe,(ushort)(m.Read16(condition+0xe)|8));bottom=m.Read32(0x922218);top=m.Read32(0x922214);m.Write8(condition+0xd,(byte)expressionSlot);expressionSlot++;uint text=Current(m,parser),expression=PreparedConditionLoading.CopyString(m,top,text,bottom);m.Write32(condition+0x10,expression);}}
      }
     }
     PreparedConditionLoading.Finish(m,s,parser,condition);continue;
    }
    if(Is(m,parser,0x760408))
    {
     s.NextToken(m,parser);uint script=m.Read32(0x92221c),macro=m.Read32(script+0x48),scan=0;while(macro!=0){if(++scan>4096)throw new ArgumentException("Bounded macro list required.");if(PreparedConditionLoading.Equal(m,m.Read32(macro+8),Current(m,parser)))break;macro=m.Read32(macro);}
     if(macro!=0){uint bottom=m.Read32(0x922218),top=m.Read32(0x922214),list=m.Read32(0x922230);CopyMacro(m,s,macro+0xc,list,top,bottom);list=m.Read32(0x922230);PreparedConditionLoading.Finish(m,s,parser,m.Read32(list+4));}
     else{s.Diagnostic(m,m.Read32(0x922248)==1?0x512860u:0x512850u,ErrorContext(m,Current(m,parser),true));}continue;
    }
    if(PreparedConditionLoading.Text(m,Current(m,parser)).IndexOf('{')<0)s.Diagnostic(m,m.Read32(0x922248)==1?0x512870u:0x512850u,ErrorContext(m,0,false));
   }
  }
 }
}
