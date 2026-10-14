// Original UTF16 token reader4f7df0 with byte delimiter matching and doubled quotes.
namespace Recovered.Gameplay
{
 public static class PreparedScriptWideTokens
 {
  static bool Contains(TakeoverReleaseMemory m,uint p,byte c){if(p==0)return false;for(byte b=m.Read8(p);b!=0;b=m.Read8(++p))if(b==c)return true;return false;}
  static uint Mask(uint bytes){return unchecked((uint)((unchecked((int)bytes)>>1)-1));}
  public static uint Next(TakeoverReleaseMemory m,uint parser)
  {
   uint line=m.Read32(parser+0x50c),token=m.Read32(parser+0x510),count=0;bool quoted=false;uint cursor=m.Read32(parser+0x520);m.Write32(0x88ab4c,cursor);
   if(m.Read16(line+2*(Mask(m.Read32(parser+0x514))&cursor))!=0)
   {
    while(true)
    {
     cursor=m.Read32(parser+0x520);uint at=line+2*cursor;ushort c=m.Read16(at);
     if(!quoted&&Contains(m,m.Read32(parser+0x580),(byte)c)){if(count==0){m.Write16(token,c);count=1;m.Write32(parser+0x520,cursor+1);}break;}
     if(!quoted&&Contains(m,m.Read32(parser+0x57c),(byte)c))c=32;
     if(!quoted&&((byte)c==9||(byte)c==32||(byte)c==44)){if(count!=0)break;}
     else if(c==34){if(quoted&&m.Read16(at+2)==34){m.Write16(token+2*(Mask(m.Read32(parser+0x518))&count),34);count++;m.Write32(parser+0x520,m.Read32(parser+0x520)+1);}else quoted=!quoted;}
     else{m.Write16(token+2*(Mask(m.Read32(parser+0x518))&count),c);count++;}
     m.Write32(parser+0x520,m.Read32(parser+0x520)+1);
     if(m.Read16(line+2*(Mask(m.Read32(parser+0x514))&m.Read32(parser+0x520)))==0)break;
    }
   }
   m.Write16(token+2*(Mask(m.Read32(parser+0x518))&count),0);return count;
  }
 }
}
