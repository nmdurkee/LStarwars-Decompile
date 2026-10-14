// ACTIONS and ACTIONMACRO raw text production, including continuation and saved argument slots.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public static class PreparedScriptActions
 {
  static void Zero(TakeoverReleaseMemory m,uint p,uint size){for(uint i=0;i<size;i++)m.Write8(p+i,0);}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  static uint Save(TakeoverReleaseMemory m,uint top,uint bottom,byte[] token){if(token.Length==0)return 0;uint size=(uint)token.Length+1,target=0;if(top!=0&&bottom!=0&&unchecked(m.Read32(top)+size)<m.Read32(bottom)){target=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(target+size));Zero(m,target,size);}for(uint i=0;i<token.Length;i++)m.Write8(target+i,token[i]);m.Write8(target+(uint)token.Length,0);return target;}
  static void Missing(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint parser){uint mode=m.Read32(0x922248),state=m.Read32(0x922220);uint stateName=state==0?0x755ba8:m.Read32(state+0x18),token=m.Read32(parser+0x510),scriptName=m.Read32(m.Read32(0x92221c)+8);s.Diagnostic(m,mode==1?0x512860u:0x512850u,new uint[]{token,scriptName,stateName});}
  public static void Load(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   uint line=s.NextLine(m,parser),budget=0;while(line!=0){if(++budget>65536)throw new ArgumentException("Bounded action block required.");ScriptTokenResults.Next(m.Image,parser,binary);uint text=m.Read32(parser+0x510);if(TextParserDispatch.Compare(m.Image,text,0x75ff74)==0)return;
    if(TextParserDispatch.Compare(m.Image,text,0x760424)==0){ScriptTokenResults.Next(m.Image,parser,binary);uint macro=m.Read32(m.Read32(0x92221c)+0x50),scan=0;bool found=false;while(macro!=0){if(++scan>4096)throw new ArgumentException("Bounded action macros required.");if(TextParserDispatch.Compare(m.Image,m.Read32(macro+8),m.Read32(parser+0x510))==0){PreparedScriptActionPrimitives.CopyActions(m,s.Diagnostic,macro+0xc,m.Read32(0x922234),m.Read32(0x922214),m.Read32(0x922218));found=true;break;}macro=m.Read32(macro);}if(!found)Missing(m,s,parser);}
    else{uint descriptor=PreparedScriptActionPrimitives.FindAction(m,m.Read32(parser+0x510));if(descriptor==0){if(PreparedConditionLoading.Text(m,m.Read32(parser+0x510)).IndexOf('{')<0)Missing(m,s,parser);}
     else{uint top=m.Read32(0x922214),bottom=m.Read32(0x922218);if(top==0||bottom==0||unchecked(m.Read32(top)+0x14)>=m.Read32(bottom))s.Diagnostic(m,0x512850,new uint[0]);else{uint action=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(action+0x14));Zero(m,action,0x14);if(action!=0){Zero(m,action,0x14);Append(m,m.Read32(0x922234),action);m.Write32(action+0x10,descriptor);var args=new List<byte[]>();while(ScriptTokenResults.Next(m.Image,parser,binary)!=0){uint token=m.Read32(parser+0x510);string value=PreparedConditionLoading.Text(m,token);if(value==PreparedConditionLoading.Text(m,0x75a204))s.NextLine(m,parser);else{if(args.Count>=24||value.Length>=128)throw new ArgumentException("Native 24 by 128-byte action argument locals required.");byte[] bytes=new byte[value.Length];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)value[i];args.Add(bytes);}}if(args.Count!=0){uint array=PreparedScriptActionPrimitives.AllocateBytes(m,m.Read32(0x922214),m.Read32(0x922218),(uint)args.Count*4);m.Write32(action+8,array);if(array!=0){m.Write32(action+0xc,(uint)args.Count);for(uint i=0;i<args.Count;i++){uint copy=Save(m,m.Read32(0x922214),m.Read32(0x922218),args[(int)i]);m.Write32(m.Read32(action+8)+i*4,copy);}}}}}
    }}line=s.NextLine(m,parser);
   }
  }
  public static void Macro(ConditionParserMemory m,ScriptConditionMaterializationServices s,uint parser,Func<SoundSetupImage,uint,uint> binary)
  {
   if(ScriptTokenResults.Next(m.Image,parser,binary)==0)return;uint top=m.Read32(0x922214);if(top==0){s.Diagnostic(m,0x512850,new uint[0]);return;}uint bottom=m.Read32(0x922218);if(bottom==0||unchecked(m.Read32(top)+0x14)>=m.Read32(bottom)){s.Diagnostic(m,0x512850,new uint[0]);return;}uint macro=unchecked(m.Read32(top)+15)&0xfffffff0;m.Write32(top,unchecked(macro+0x14));Zero(m,macro,0x14);if(macro==0)return;Zero(m,macro,0x14);uint name=PreparedConditionLoading.CopyString(m,top,m.Read32(parser+0x510),bottom);m.Write32(macro+8,name);Append(m,unchecked(m.Read32(0x92221c)+0x50),macro);m.Write32(0x922234,macro+0xc);Load(m,s,parser,binary);m.Write32(0x922234,0);
  }
 }
 public sealed class RecoveredScriptActionCommands:ScriptFileTransportServices
 {
  readonly ScriptFileTransportServices remaining;readonly RecoveredTextConditionServices readers;readonly Func<SoundSetupImage,uint,uint> binary;
  public RecoveredScriptActionCommands(ScriptFileTransportServices ports,Func<SoundSetupImage,uint,uint,int,int> readFile,Func<SoundSetupImage,uint,uint> binaryLine,Func<SoundSetupImage,uint,uint> binaryToken){if(ports==null)throw new ArgumentNullException("ports");remaining=ports;binary=binaryToken;readers=new RecoveredTextConditionServices(readFile,binaryLine,binaryToken==null?null:(Action<SoundSetupImage,uint>)delegate(SoundSetupImage m,uint p){binaryToken(m,p);},Diagnostic);}
  public override uint Open(TakeoverReleaseMemory m,uint a,uint b,uint c){return remaining.Open(m,a,b,c);}
  public override void Close(TakeoverReleaseMemory m,uint p){remaining.Close(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){remaining.Diagnostic(m,c,a);}
  public override void Command(TakeoverReleaseMemory m,uint callback,uint parser){if(callback!=0x52b9c0&&callback!=0x52bec0){remaining.Command(m,callback,parser);return;}ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");if(callback==0x52b9c0)PreparedScriptActions.Load(image,readers,parser,binary);else PreparedScriptActions.Macro(image,readers,parser,binary);}
 }
}
