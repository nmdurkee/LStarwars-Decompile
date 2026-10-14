// Byte substring and private normalized-path traversal of the container's directory/sibling tree.
using System;
using System.Text;
namespace Recovered.Gameplay
{
 public static class PreparedHierarchicalScriptContainerIndex
 {
  static int Short(TakeoverReleaseMemory m,uint p){return unchecked((short)(m.Read8(p)|(m.Read8(p+1)<<8)));}
  //4f20a0 cdecl(text,needle). Empty text returns0 even for an empty needle.
  public static uint Substring(TakeoverReleaseMemory m,uint text,uint needle)
  {
   if(m.Read8(text)==0)return 0;uint budget=0;
   for(uint candidate=text;m.Read8(candidate)!=0;candidate=unchecked(candidate+1))
   {if(budget++>=4096)throw new ArgumentException("Prepared bounded substring input required.");uint offset=0;while(m.Read8(needle+offset)!=0){byte c=m.Read8(candidate+offset);if(c==0||c!=m.Read8(needle+offset))break;offset++;}if(m.Read8(needle+offset)==0)return candidate;}
   return 0;
  }
  //4f9aa0 cdecl(container,path); private compiler256-byte path plus cookie are unaliased.
  public static uint Find(ConditionParserMemory m,uint container,uint path,uint privatePath)
  {
   uint input=m.Read8(path)==64?unchecked(path+4):path;StringBuilder text=new StringBuilder();for(uint i=0;;i++){byte c=m.Read8(input+i);if(c==0)break;if(i>=255)throw new ArgumentException("Prepared private256-byte path required.");text.Append((char)c);}
   return ScriptCompilerLocals.CString(m,privatePath,text.ToString(),delegate(uint local){
    PreparedScriptContainerIndex.Normalize(m,0,local);uint tree=m.Read32(container+0x10);if(tree==0)return PreparedScriptContainerIndex.Flat(m,container,local);
    int node=Short(m,tree);uint component=local,delimiter=Substring(m,component,0x75a204);if(delimiter!=0)m.Write8(delimiter,0);uint budget=0;
    do
    {
     if(budget++>=4096)throw new ArgumentException("Prepared terminating directory tree required.");tree=m.Read32(container+0x10);uint row=unchecked(tree+(uint)(node*8));
     if(TextParserDispatch.Compare(m.Image,m.Read32(row+4),component)==0)
     {
      if(delimiter==0){int value=Short(m,unchecked(m.Read32(container+0x10)+(uint)(node*8)));return value>0?0xffffffff:unchecked((uint)-value);}
      node=Short(m,row);component=unchecked(delimiter+1);delimiter=Substring(m,component,0x75a204);if(delimiter!=0)m.Write8(delimiter,0);
     }
     else node=Short(m,row+2);
    }while(node!=0);
    return 0xffffffff;
   });
  }
 }
}
