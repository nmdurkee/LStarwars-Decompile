// Exact finite 64-significand subtraction/ordering closes opponent-below cancellation boundaries.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedExactOpponentBelow
 {
  struct Wide
  {
   public ulong S;public int E;public bool N;
   public static Wide Bits32(uint bits){uint field=(bits>>23)&255;ulong s=bits&0x7fffff;int e=-149;if(field!=0){s|=0x800000;e=(int)field-150;}return Normalize(s,e,(bits>>31)!=0);}
   public static Wide Bits64(ulong bits){ulong field=(bits>>52)&2047,s=bits&0xfffffffffffffUL;int e=-1074;if(field!=0){s|=0x10000000000000UL;e=(int)field-1075;}return Normalize(s,e,(bits>>63)!=0);}
   static Wide Normalize(ulong s,int e,bool n){if(s==0)return new Wide();while((s&0x8000000000000000UL)==0){s<<=1;e--;}return new Wide{S=s,E=e,N=n};}
   static bool Bit(uint[] a,int bit){return bit>=0&&(a[bit/32]&(1u<<(bit%32)))!=0;}
   static uint[] Align(Wide a,int e,int length){uint[] words=new uint[length];int shift=a.E-e;for(int i=0;i<64;i++)if((a.S&(1UL<<i))!=0)words[(shift+i)/32]|=1u<<((shift+i)%32);return words;}
   public static Wide Add(Wide a,Wide b){if(a.S==0)return b;if(b.S==0)return a;int e=Math.Min(a.E,b.E),length=(Math.Max(a.E,b.E)-e+96)/32+1;uint[] x=Align(a,e,length),y=Align(b,e,length),z=new uint[length];bool n=a.N;if(a.N==b.N){ulong carry=0;for(int i=0;i<length;i++){ulong sum=(ulong)x[i]+y[i]+carry;z[i]=(uint)sum;carry=sum>>32;}}else{int cmp=0;for(int i=length-1;i>=0;i--)if(x[i]!=y[i]){cmp=x[i]>y[i]?1:-1;break;}if(cmp==0)return new Wide();if(cmp<0){uint[] t=x;x=y;y=t;n=b.N;}long borrow=0;for(int i=0;i<length;i++){long d=(long)x[i]-y[i]-borrow;z[i]=unchecked((uint)d);borrow=d<0?1:0;}}int high=length*32-1;while(!Bit(z,high))high--;ulong sig=0;for(int i=0;i<64;i++)if(Bit(z,high-i))sig|=1UL<<(63-i);bool round=false;if(high>=64&&Bit(z,high-64)){round=(sig&1)!=0;for(int i=high-65;i>=0&&!round;i--)round=Bit(z,i);}int exp=e+high-63;if(round){sig=unchecked(sig+1);if(sig==0){sig=0x8000000000000000UL;exp++;}}return new Wide{S=sig,E=exp,N=n};}
   public static int Compare(Wide a,Wide b){if(a.S==0&&b.S==0)return 0;if(a.S==0)return b.N?1:-1;if(b.S==0)return a.N?-1:1;if(a.N!=b.N)return a.N?-1:1;int c=a.E!=b.E?(a.E>b.E?1:-1):a.S==b.S?0:a.S>b.S?1:-1;return a.N?-c:c;}
  }
  public static uint Evaluate(TakeoverReleaseMemory m,uint actor){if(actor==0)return 0;uint opponent=m.Read32(actor+0xe4);if(opponent==0)return 0;uint oy=m.Read32(opponent+0x60),controller=m.Read32(actor+0xd0),ay=m.Read32(controller+0x60);ulong threshold=((ulong)m.Read32(0x75178c)<<32)|m.Read32(0x751788);if(threshold!=0x3fb99999a0000000UL)throw new ArgumentException("Original threshold required.");if((oy&0x7f800000)==0x7f800000||(ay&0x7f800000)==0x7f800000){float a=BitConverter.ToSingle(BitConverter.GetBytes(ay),0),b=BitConverter.ToSingle(BitConverter.GetBytes(oy),0);return ((double)a-BitConverter.Int64BitsToDouble((long)threshold))>b?0x3f800000u:0;}Wide t=Wide.Bits64(threshold);t.N=true;return Wide.Compare(Wide.Add(Wide.Bits32(ay),t),Wide.Bits32(oy))>0?0x3f800000u:0;}
 }
}
