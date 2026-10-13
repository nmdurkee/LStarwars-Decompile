// Original backend constructor, including partial-byte writes and preserved gaps.
using System;
namespace Recovered.Geometry
{
 public static class RenderBackendInitialization
 {
  static void Write(byte[] image,int offset,uint value){image[offset]=(byte)value;image[offset+1]=(byte)(value>>8);image[offset+2]=(byte)(value>>16);image[offset+3]=(byte)(value>>24);}
  // Original0x6e1930. Constant7519a8 is finite3faaaaab and unchanged by
  // its actual FLD/FST/FSTP sequence. The only callee is original memset.
  // Return is the receiver object, matching original EAX=this identity.
  public static byte[] Apply(byte[] image)
  {
   if(image==null||image.Length<0x700)throw new ArgumentException("Resolved writable backend image required.");
   Write(image,0x628,0x3faaaaab);Write(image,0x630,0x3faaaaab);
   int[] zero={0,4,0x1a0,0x5f4,0x5fc,0x618,0x61c,0x620,0x624,0x62c,0x638,0x654,0x660,0x668,0x684,0x688,0x68c,0x690,0x694,0x698,0x6a4,0x6a8,0x6ac,0x6b0,0x6e8,0x6ec};foreach(int offset in zero)Write(image,offset,0);
   int[] one={0x5f0,0x600,0x604,0x69c,0x6a0};foreach(int offset in one)Write(image,offset,1);
   int[] byteZero={0x5f8,0x5f9,0x634,0x63c,0x664};foreach(int offset in byteZero)image[offset]=0;
   image[0x5fa]=1;image[0x65c]=1;image[0x66c]=1;image[0x66d]=0;image[0x6e4]=1;image[0x6e5]=0;
   Array.Clear(image,0x1a4,0x44c);Array.Clear(image,8,0x130);Array.Clear(image,0x138,0x38);
   for(int offset=0x170;offset<=0x184;offset+=4)Write(image,offset,0);for(int offset=0x608;offset<=0x614;offset+=4)Write(image,offset,0);
   Write(image,0x158,image[0x65c]);for(int offset=0x644;offset<=0x650;offset+=4)Write(image,offset,0xffffffff);Write(image,0x640,0);Write(image,0x658,0);
   for(int i=0;i<4;++i){Write(image,0x6b4+i*4,0);Write(image,0x6c4+i*4,0);Write(image,0x6d4+i*4,0xffffffff);Write(image,0x6f0+i*4,0);}
   return image;
  }
 }
}
