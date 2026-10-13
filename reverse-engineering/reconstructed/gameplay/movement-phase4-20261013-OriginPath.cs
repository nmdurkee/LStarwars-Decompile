// Original-PC 0x536330/0x536dc0/0x52fda0 with byte-addressed reference identity.
using System;
using Recovered.Animation;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Gameplay
{
 public sealed class OriginPathMemory
 {
  public readonly uint Base;public readonly byte[] Bytes;
  public OriginPathMemory(uint address,byte[] image){Base=address;Bytes=(byte[])image.Clone();}
  int At(uint p,int size){long o=(long)p-Base;if(o<0||o+size>Bytes.Length)throw new InvalidOperationException("Native pointer outside supplied image.");return(int)o;}
  public byte U8(uint p){return Bytes[At(p,1)];}
  public uint U32(uint p){int o=At(p,4);return(uint)Bytes[o]|(uint)Bytes[o+1]<<8|(uint)Bytes[o+2]<<16|(uint)Bytes[o+3]<<24;}
  public float F32(uint p){return PcObjectImage.FromBits(U32(p));}
  public void Set8(uint p,int v){Bytes[At(p,1)]=unchecked((byte)v);}
  public void Set32(uint p,uint v){int o=At(p,4);for(int i=0;i<4;i++)Bytes[o+i]=unchecked((byte)(v>>(8*i)));}
  public void SetFloat(uint p,float v){Set32(p,PcObjectImage.ToBits(v));}
  public float[] Vector(uint p){return new float[]{F32(p),F32(p+4),F32(p+8)};}
  public void SetVector(uint p,float[] v){for(int i=0;i<3;i++)SetFloat(p+(uint)i*4,v[i]);}
 }
 public sealed class OriginPathWorld
 {
  public OriginPathMemory Memory;
  // Runtime sine table0x29899a0 is supplied verbatim; its producer is outside this projection.
  public float[] SineTable;
  public float Padding=.10000000149011612f;
  public readonly ExpressionEnvironment Expressions=new ExpressionEnvironment();
  public ScriptPacket Numbers;
  public Func<uint,uint,uint> OriginPosition;
  public Func<string,uint,bool> MovementToken;
  public Action<uint> Schedule;
 }
 public static class OriginPathCommands
 {
  struct N
  {
   Wide value;bool negative;
   static N Make(Wide v,bool zero){double d=v.StoreDouble();return new N{value=v,negative=d<0||(d==0&&zero)};}
   public static N From(float v){return new N{value=Wide.From(v),negative=(PcObjectImage.ToBits(v)&0x80000000u)!=0};}
   public static N FromDouble(double v){return new N{value=Wide.FromDouble(v),negative=(unchecked((ulong)BitConverter.DoubleToInt64Bits(v))>>63)!=0};}
   public static N operator+(N a,N b){return Make(Wide.Add(a.value,b.value),a.negative&&b.negative);}
   public static N operator-(N a){return Make(Wide.Multiply(a.value,Wide.From(-1)),!a.negative);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(Wide.Multiply(a.value,b.value),a.negative!=b.negative);}
   public float Store(){float f=value.Store();return f==0?PcObjectImage.FromBits(negative?0x80000000u:0):f;}
   public double StoreDouble(){double d=value.StoreDouble();return d==0&&negative?BitConverter.Int64BitsToDouble(unchecked((long)0x8000000000000000UL)):d;}
  }
  static float[] Rotate(OriginPathWorld w,float[] p,int heading)
  {
   if(w.SineTable==null||w.SineTable.Length!=32768)throw new ArgumentException("32768 runtime sine words required.");
   N s=N.From(w.SineTable[(heading>>1)&32767]),c=N.From(w.SineTable[((unchecked(heading+0x4000))>>1)&32767]);N x=N.From(p[0]),z=N.From(p[2]);
   return new float[]{(s*z+c*x).Store(),p[1],(z*c-x*s).Store()};
  }
  static float[] Add(float[] a,float[] b){return new float[]{(N.From(a[0])+N.From(b[0])).Store(),(N.From(a[1])+N.From(b[1])).Store(),(N.From(a[2])+N.From(b[2])).Store()};}
  static float Evaluate(OriginPathWorld w,uint creature,string text){return ScriptExpressions.Evaluate(w.Expressions,creature,w.Numbers,text);}
  static int Match(string t,string k){return t.IndexOf(k,StringComparison.OrdinalIgnoreCase);}
  static string Tail(string t,int at,int skip){if(at+skip>t.Length)throw new ArgumentException("Native skip exceeds supplied token.");return t.Substring(at+skip);}
  //0x52fda0. Byte slot/count comparisons, orientation bit copies and six-word intent.
  public static void FormationIntent(OriginPathWorld w,uint creature)
  {
   OriginPathMemory m=w.Memory;uint formation=m.U32(creature+0x144);byte index=m.U8(creature+0x14a);
   if(m.U8(formation+6)<=index)return;
   uint row=formation+0x54+(uint)index*0x34;byte slot=m.U8(creature+0x149);float x;
   if((m.U8(creature+0x1eb)&1)!=0)x=(m.U8(formation+8)&1)!=0?0:-(N.From(m.F32(formation+0x128))*N.From(.5f)).Store();
   else{x=(N.From(m.F32(formation+0x128))*N.From((slot+1)/2)).Store();if((slot&1)!=0)x=-x;}
   if((m.U8(formation+0x50)&4)!=0)x=-x;
   int heading=unchecked((int)m.U32(row+0x24));float[] position=m.Vector(row+0x18);
   float[] target=Add(Rotate(w,new float[]{x,0,0},heading),position);
   m.Set32(creature+0x1e8,m.U32(creature+0x1e8)|8);
   // Native rereads formation after vector calls; the supplied arithmetic calls have no callbacks.
   uint current=m.U32(creature+0x144);uint mode=current!=0&&(m.U8(current+0x50)&8)!=0?1u:5u;
   m.SetVector(creature+0x1b4,target);for(uint i=0;i<6;i++)m.Set32(creature+0x1cc+i*4,m.U32(row+i*4));
   m.Set32(creature+0x1c0,0);m.Set32(creature+0x1c4,0);m.SetVector(creature+0x78,new float[]{0,0,100});
   m.Set32(creature+0x1e8,(m.U32(creature+0x1e8)&~7u)|mode);
   m.SetVector(creature+0x78,Add(Rotate(w,m.Vector(creature+0x78),heading),position));m.Set32(creature+0x1e4,creature+0x78);
  }
  //0x52fcb0 refinement: formation expansion is the real recovered0x52fda0 body.
  public static void SetIntent(OriginPathWorld w,uint creature,uint point,float radius,uint words,uint mode,float goal)
  {
   OriginPathMemory m=w.Memory;uint formation=m.U32(creature+0x144);
   if(formation!=0&&(m.U8(formation+0x50)&8)!=0)
   {
    if(mode==1||mode==4){if(m.U32(formation)==m.U32(creature+0xd0)){if(w.Schedule==null)throw new InvalidOperationException("Scheduler service required.");w.Schedule(mode==1?0x51cbc0u:0x51c6a0u);}FormationIntent(w,creature);return;}
    if(mode==5)mode=1;
   }
   if(point!=0)for(uint i=0;i<3;i++)m.Set32(creature+0x1b4+i*4,m.U32(point+i*4));
   if(words!=0)for(uint i=0;i<6;i++)m.Set32(creature+0x1cc+i*4,m.U32(words+i*4));
   m.SetFloat(creature+0x1c0,radius);m.Set32(creature+0x1e8,(m.U32(creature+0x1e8)&~7u)|(mode&7));m.SetFloat(creature+0x1c4,goal);
  }
  //0x536330. Does not require a nonnull object in reference's first word.
  public static bool GoToOrigin(OriginPathWorld w,uint world,uint packet,uint creature,string[] tokens,bool first,float delta)
  {
   OriginPathMemory m=w.Memory;
   if(creature==0)return true;uint reference=m.U32(creature+0xd0);
   if(reference==0||m.U32(creature+0x158)==0||m.U32(creature+0x15c)==0||(m.U32(reference+0x1f8)&0x400)==0||m.U8(creature+0x138)==255)return true;
   uint spawn=m.U32(world+0x18)+(uint)m.U8(creature+0x138)*0xa4;
   uint origin=w.OriginPosition==null?0:w.OriginPosition(world,creature);if(origin==0)origin=spawn+0x20;
   if(first)
   {
    m.SetFloat(creature+0x180,.2f);float minimum=0,maximum=0;
    if(tokens!=null)foreach(string token in tokens)
    {
     MessageNumbers.RequireAscii(token);if(w.MovementToken!=null&&w.MovementToken(token,creature+0x13f))continue;int at;
     if((at=Match(token,"waittime"))>=0)m.SetFloat(packet+0x9c,Evaluate(w,creature,Tail(token,at,9)));
     else if((at=Match(token,"mintime"))>=0)minimum=Evaluate(w,creature,Tail(token,at,8));
     else if((at=Match(token,"maxtime"))>=0)maximum=Evaluate(w,creature,Tail(token,at,8));
     else if(String.Equals(token,"xz_rangecheck",StringComparison.OrdinalIgnoreCase))m.Set8(packet+0x69,1);
     else{at=Match(token,"goalrange");m.SetFloat(creature+0x180,Evaluate(w,creature,at<0?token:Tail(token,at,10)));}
    }
    if(m.F32(packet+0x9c)==0)m.SetFloat(packet+0x9c,maximum<=minimum?.01f:(N.From(w.Expressions.Random.Next())*(N.From(maximum)-N.From(minimum))+N.From(minimum)).Store());
    SetIntent(w,creature,origin,0,spawn+0x30,1,m.F32(creature+0x180));m.SetVector(packet+0x78,new float[]{0,0,1});
    m.SetVector(packet+0x78,Add(Rotate(w,m.Vector(packet+0x78),unchecked((int)m.U32(spawn+0x2c))),m.Vector(origin)));return false;
   }
   SetIntent(w,creature,origin,0,spawn+0x30,1,m.F32(creature+0x180));
   float[] a=m.Vector(creature+0x14c),b=m.Vector(origin);N x=N.From((N.From(a[0])-N.From(b[0])).Store()),y=N.From(m.U8(packet+0x69)!=0?0:(N.From(a[1])-N.From(b[1])).Store()),z=N.From((N.From(a[2])-N.From(b[2])).Store());
   float distance=(x*x+y*y+z*z).Store();float basis=(N.From(w.Padding)+N.From(m.F32(creature+0x180))).Store();
   // Reference pointer is reread after intent/scheduler callbacks.
   float threshold=(N.From(delta)*N.From(m.F32(m.U32(creature+0xd0)+0x22c))+N.From(basis)).Store();
   if((double)distance<(N.From(threshold)*N.From(threshold)).StoreDouble())
   {
    m.Set32(creature+0x1e4,packet+0x78);float wait=m.F32(packet+0x9c);if(wait<=0)return true;
    wait=(N.From(wait)-N.From(delta)).Store();m.SetFloat(packet+0x9c,wait<0?0:wait);
   }
   return false;
  }
  //0x536dc0. Timer completion can precede reaching any path node.
  public static bool FollowPath(OriginPathWorld w,uint packet,uint creature,string[] tokens,bool first,float delta)
  {
   OriginPathMemory m=w.Memory;if(creature==0)return true;uint reference=m.U32(creature+0xd0);
   if(reference==0||m.U32(reference)==0)return true;if(m.U32(creature+0x158)==0||m.U32(creature+0x15c)==0)return false;
   if(first)
   {
    m.Set32(creature+0x188,0);float minimum=0,maximum=0;
    if(tokens!=null)foreach(string token in tokens)
    {
     MessageNumbers.RequireAscii(token);if(w.MovementToken!=null&&w.MovementToken(token,creature+0x13f))continue;int at;
     if((at=Match(token,"mintime"))>=0)minimum=Evaluate(w,creature,Tail(token,at,8));
     else if((at=Match(token,"maxtime"))>=0)maximum=Evaluate(w,creature,Tail(token,at,8));
     else m.SetFloat(packet+0x9c,Evaluate(w,creature,token));
    }
    if(minimum<maximum){double firstTerm=((N.From(1)-N.From(w.Expressions.Random.Next()))*N.From(minimum)).StoreDouble();m.SetFloat(packet+0x9c,(N.From(w.Expressions.Random.Next())*N.From(maximum)+N.FromDouble(firstTerm)).Store());}
   }
   uint formation=m.U32(creature+0x144);
   if(formation==0||(m.U8(formation+0x50)&8)==0){m.Set32(creature+0x1c0,0);m.Set32(creature+0x1c4,m.U32(creature+0x180));m.Set32(creature+0x1e8,(m.U32(creature+0x1e8)&~3u)|4);}
   else{if(m.U32(formation)==m.U32(creature+0xd0)){if(w.Schedule==null)throw new InvalidOperationException("Scheduler service required.");w.Schedule(0x51c6a0);}FormationIntent(w,creature);}
   float wait=m.F32(packet+0x9c);if(wait>0){wait=(N.From(wait)-N.From(delta)).Store();m.SetFloat(packet+0x9c,wait);return wait<=0;}return false;
  }
 }
}
