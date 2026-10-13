using System;
namespace Recovered.Gameplay
{
 public static class SoundGroups
 {
  static uint Group(int id){return unchecked(0x2920d88u+(uint)id*8);}
  static uint Member(int index){return unchecked(0x2921260u+(uint)index*2);}
  static int Signed(ushort value){return unchecked((short)value);}
  //0x5b9e10: caller-owned state; return EAX also carries the new state.
  public static uint StepRandom(ref uint state){state=unchecked(state*0x19660du+0x3c6ef35fu);return state;}
  //0x650c50. Capacity guards compare equality, not greater-than.
  public static int Create(SoundSetupImage m,int sound)
  {
   uint group=m.Word(0x2962024),member=m.Word(0x2962020);if(group==128||member==512)return -1;uint record=Group(unchecked((int)group));m.Half(record,(ushort)member);m.Half(record+2,1);m.Half(record+4,0);m.Half(unchecked(m.Word(0x2947b74)+(uint)sound*64+0x14),(ushort)group);m.Half(Member(unchecked((int)member)),unchecked((ushort)sound));m.Word(0x2962020,unchecked(member+1));m.Word(0x2962024,unchecked(group+1));return unchecked((int)group);
  }
  //0x650cd0.
  public static int Contains(SoundSetupImage m,int group,int sound)
  {
   uint g=Group(group);int first=Signed(m.Half(g)),end=first+Signed(m.Half(g+2));for(int i=first;i<end;i++)if(Signed(m.Half(Member(i)))==sound)return 1;return 0;
  }
  //0x650d10. Random chooses high16 bits modulo unsigned-converted count;
  //sequential mode uses the old signed cursor and wraps its increment at16bits.
  public static int Select(SoundSetupImage m,int group,int sequential)
  {
   uint g=Group(group);int count=Signed(m.Half(g+2)),start=Signed(m.Half(g));uint selected;
   if(sequential==0){uint random=m.Word(0x810364);StepRandom(ref random);m.Word(0x810364,random);selected=random>>16;uint divisor=unchecked((uint)count);if(divisor==0)divisor=1;selected%=divisor;}
   else{selected=unchecked((uint)Signed(m.Half(g+4)));short next=unchecked((short)(Signed(m.Half(g+4))+1));m.Half(g+4,unchecked((ushort)next));if(count<=next)m.Half(g+4,0);}
   return Signed(m.Half(Member(unchecked((int)selected+start))));
  }
  //0x650d90 and0x650da0.
  public static int Count(SoundSetupImage m,int group){return Signed(m.Half(Group(group)+2));}
  public static int At(SoundSetupImage m,int group,int member){return Signed(m.Half(Member(unchecked(Signed(m.Half(Group(group)))+member))));}
  static int Find(SoundSetupImage m,string query)
  {
   if(query==null||m.Word(0x292fda0)==0)return -1;query=SceneryText.C(query);uint h=0;foreach(char raw in query){uint c=raw>='a'&&raw<='z'?(uint)raw-32:raw;h=unchecked((h<<8)^m.Word(m.Word(0x2947d80)+4*(c^(h>>24))));}int index=Signed(m.Half(m.Word(0x292fda0)+(h&255)*2));
   while(index!=-1){uint record=unchecked(m.Word(0x2947b74)+(uint)index*64),name=m.Word(record);if(name!=0){string candidate=SoundDefinitionParser.Text(m,name);if(String.Equals(candidate.Substring(0,Math.Min(candidate.Length,32)),query.Substring(0,Math.Min(query.Length,32)),StringComparison.OrdinalIgnoreCase))return index;}index=Signed(m.Half(record+0x10));}return -1;
  }
  //0x652010. A missing leader ends parsing. A full group table returns-1
  //from Create; original subsequent members still write its preceding record.
  public static void Parse(SoundSetupImage m,ISoundDefinitionTokens tokens)
  {
   bool first=true;int group=-1;while(tokens.ReadNext())
   {
    int sound=Find(m,tokens.Current);if(first){if(sound==-1)return;group=Create(m,sound);first=false;}
    else{sound=Find(m,tokens.Current);if(sound!=-1&&m.Word(0x2962020)!=512){uint count=m.Word(0x2962020);m.Half(Member(unchecked((int)count)),unchecked((ushort)sound));m.Word(0x2962020,unchecked(count+1));uint g=Group(group);m.Half(g+2,unchecked((ushort)(m.Half(g+2)+1)));m.Half(g+4,0);}}
   }
  }
 }
}
