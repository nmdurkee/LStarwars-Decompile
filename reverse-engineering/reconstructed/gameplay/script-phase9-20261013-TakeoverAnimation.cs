// Original-PC takeover animation selector487270. Native ECX=vehicle, EDI=rider.
// Runtime type IDs are words at the original globals; no invented character IDs.
namespace Recovered.Gameplay
{
 public static class TakeoverAnimationSelector
 {
  static int CurrentAction(TakeoverReleaseMemory m,uint actor)
  {uint p=actor+8;return unchecked((short)m.Read16(p+(m.Read8(p+0x31)!=0?0x34u:0x36u)));}
  static bool Type(TakeoverReleaseMemory m,ushort type,uint address){return type==m.Read16(address);}
  static void Store(TakeoverReleaseMemory m,uint rider,int action)
  {uint clips=m.Read32(m.Read32(rider+0x50)+0xc);m.Write16(rider+0x7aa,(ushort)(m.Read32(clips+(uint)action*4)!=0?action:0x6c));}
  // Prepared pointer chains remain unchecked, including faults after priority gates.
  public static void Select(TakeoverReleaseMemory m,uint vehicle,uint rider)
  {
   ushort type=m.Read16(vehicle+0x1064);int action;
   if(Type(m,type,0x7f1814))action=0x70;
   else if(Type(m,type,0x7f1850))action=0x83;
   else
   {
    if(m.Read32(0x7f39e4)==0){m.Write16(rider+0x7aa,0x6c);return;}
    if(m.Read8(m.Read32(m.Read32(vehicle+0x54)+0x24)+0x116)==12)
     action=CurrentAction(m,vehicle)==3||CurrentAction(m,vehicle)==0x17?0xc4:0xc3;
    else if(Type(m,type,0x7f1934)||Type(m,type,0x7f1938))action=0x70;
    else if(Type(m,type,0x7f193c))action=0x83;
    else if(Type(m,type,0x7f1940)||Type(m,type,0x7f1aa4))action=0x84;
    else if(Type(m,type,0x7f1944))action=0x86;
    else if(Type(m,type,0x7f1948))action=0xc0;
    else if(Type(m,type,0x7f194c)||Type(m,type,0x7f1950))action=0xc1;
    else if(Type(m,type,0x7f1954))action=m.Read32(m.Read32(m.Read32(rider+0x50)+0xc)+0x308)!=0?0xc2:0xc1;
    else if(Type(m,type,0x7f19bc))action=0xc1;
    else if(Type(m,type,0x7f1920))action=0xc0;
    else{m.Write16(rider+0x7aa,0x6c);return;}
   }
   Store(m,rider,action);
  }
 }
}
