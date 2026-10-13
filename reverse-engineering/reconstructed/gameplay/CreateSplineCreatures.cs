// Handwritten bounded projection of PC 0x44a190 (CreateSplineCreatures).
// Allocation, spline evaluation and physical effects are explicit services.
// See gameplay-createsplinecreatures-contract.json.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class SplineReference
    {
        public int Id;
        public string Name;
    }
    // Native actor+0xe64, eight words copied as one block by relative placement.
    public sealed class SplineFollower
    {
        public SplineReference Spline;
        public uint Header;              // +0xe68; byte +0xe6a is the signed mode passed to evaluation
        public readonly uint[] Words=new uint[5];
        public float Time;               // +0xe80
        public sbyte Mode { get { return unchecked((sbyte)(Header>>16)); } }
    }
    public sealed class SplineActor
    {
        public int Id;
        public SplineFollower Follower=new SplineFollower();
        public SpawnVector Offset;       // +0xe84, supplied by the allocator from the request offset
        public ushort Heading58, Heading5A, Pitch278, Heading27A;
        public SpawnVector Position, Origin80, Origin8C, Origin98, Previous1B4, Previous10BC;
    }
    public sealed class SplineSpawnRequest
    {
        public short Type;
        public string Script;
        public SplineReference Spline;
        public SpawnVector Offset;
        public bool Looping;
        public int Set;
    }
    public sealed class SplineSpawnContext
    {
        public ScriptPacket Packet;
        // PC param_3. ridden_by=myself needs it and its +0xd0 rider reference;
        // the reference word may itself hold a null rider.
        public object Self;
        public bool HasSelfRiderReference;
        public object SelfRider;
        public SplineReference MySpline;       // packet+0xac
        public SplineReference SelectedSpline; // global 0x876d94
        public IList<SplineReference> Splines=new List<SplineReference>(); // world+0x13c table order
        public object PlayerReference;         // player+0x80 relative base
        public bool LevelSplineLimitsActive;   // world+0x128 equals global 0x87b0a0
        public bool TypeCallbacksAvailable=true;
        public SplineSpawnServices Services;
        public SpawnVector LastPlacement;      // globals 0x93d620..0x93d628
        public int OperationBudget=4096;
    }
    public abstract class SplineSpawnServices
    {
        public abstract byte FindType(string name);
        public abstract short ResolveType(byte index);
        public abstract object FindLocator(string name);
        public abstract object FindRider(string name);
        public abstract int NextInteger();
        public abstract float NextFloat();
        // Shared 16-bit LCG at 0x80253c: returns the new 0..0xffff state.
        public abstract int NextSpline16();
        public abstract SplineActor Spawn(SplineSpawnRequest request);
        public abstract void LevelSplineLimits(SplineReference spline,out int first,out int second);
        public abstract SplineFollower RelativeFollower(object origin,SplineReference spline,bool looping,int first,int second);
        public abstract void Advance(SplineFollower follower,float distance);
        public abstract void Evaluate(SplineReference spline,float time,int mode,out SpawnVector position,out ushort heading,out int pitch);
        // Original sine LUT at 0x29899a0, indexed by angle>>1.
        public abstract float AngleTable(int index);
        public abstract void UpdatePlacement(SplineActor actor);
        public abstract void Ride(object rider,SplineActor mount);
    }
    public sealed class SplineSpawnPlan
    {
        public int Minimum=-1, Maximum=-1, Count=1, Set;
        public float Distance, MinimumDistance=1e9f, MaximumDistance=1e9f;
        public bool UseSelected, Looping, RelativeToPlayer;
        public object RelativeLocator, Rider;
        public SpawnVector Offset;
        public string Script="default";
        public readonly List<short> Types=new List<short>();
        public readonly List<SplineReference> Splines=new List<SplineReference>();
    }
    public static class SplineCreatureSpawner
    {
        const int SplineCapacity=32;
        static bool Match(string token,string key,out int at)
        { at=token.IndexOf(key,StringComparison.OrdinalIgnoreCase); return at>=0; }
        static bool Equal(string a,string b) { return String.Equals(a,b,StringComparison.OrdinalIgnoreCase); }
        static string Tail(string t,int at,int skip)
        { if(at+skip>t.Length)throw new ArgumentException("Token reads beyond its terminator in the native command."); return t.Substring(at+skip); }
        static float Number(SplineSpawnContext c,string t,int at,int skip)
        {
            float value=MessageNumbers.Resolve(c.Packet,Tail(t,at,skip));
            if(Single.IsNaN(value)||Single.IsInfinity(value)) throw new ArgumentOutOfRangeException("tokens");
            return value;
        }
        static int Integer(float f)
        {
            if((double)f < -2147483648.0 || (double)f >= 2147483648.0) throw new ArgumentOutOfRangeException("tokens");
            return (int)f;
        }
        static int Fold(char c) { return (c>='a'&&c<='z')||c>=(char)0xe0?c-0x20:c; }
        // PC 0x4f8b80 with length strlen(pattern): compares at least one byte,
        // so an empty pattern only matches an empty name.
        static bool NativePrefix(string pattern,string name)
        {
            int n=Math.Max(pattern.Length,1);
            for(int i=0;i<n;i++)
            {
                char p=i<pattern.Length?pattern[i]:'\0',q=i<name.Length?name[i]:'\0';
                if(Fold(p)!=Fold(q))return false;
                if(p=='\0'||q=='\0')break;
            }
            return true;
        }

        public static SplineSpawnPlan Parse(SplineSpawnContext c,string[] tokens)
        {
            if(c==null||c.Services==null)throw new ArgumentNullException("context/services");
            SplineSpawnServices s=c.Services; SplineSpawnPlan p=new SplineSpawnPlan();
            if(tokens==null)return p;
            foreach(string t in tokens)
            {
                MessageNumbers.RequireAscii(t); int a; string text;
                if(Match(t,"mingroupsize",out a))p.Minimum=Integer(Number(c,t,a,13));
                else if(Match(t,"maxgroupsize",out a))p.Maximum=Integer(Number(c,t,a,13));
                else if(Match(t,"groupsize",out a))p.Count=Integer(Number(c,t,a,10));
                else if(Match(t,"type",out a))
                {
                    if(c.TypeCallbacksAvailable)
                    {
                        byte index=s.FindType(Tail(t,a,5));
                        if(index!=255){ short id=s.ResolveType(index); if(id!=-1&&p.Types.Count<10)p.Types.Add(id); }
                    }
                }
                else if(Match(t,"script",out a))
                { p.Script=Tail(t,a,7);if(p.Script.Length>63)throw new ArgumentOutOfRangeException("tokens","Native script buffer is 64 bytes."); }
                else if(Match(t,"mindistance",out a))p.MinimumDistance=Number(c,t,a,12);
                else if(Match(t,"maxdistance",out a))p.MaximumDistance=Number(c,t,a,12);
                else if(Match(t,"distance",out a))p.Distance=Number(c,t,a,9);
                // Recognized only while a selected spline exists; otherwise the token falls through.
                else if(c.SelectedSpline!=null&&Equal(t,"use_selected_spline"))p.UseSelected=true;
                else if(Match(t,"splines=",out a))
                {
                    text=Tail(t,a,8);
                    foreach(SplineReference r in c.Splines)
                    { if(p.Splines.Count>=SplineCapacity)break; if(NativePrefix(text,r.Name))p.Splines.Add(r); }
                }
                else if(Match(t,"spline=myspline",out a))
                {
                    if(c.MySpline!=null)
                    {
                        // Native appends without a bound; index32 overwrites the type array.
                        if(p.Splines.Count>=SplineCapacity)throw new InvalidOperationException("Native spline candidate overflow.");
                        p.Splines.Add(c.MySpline);
                    }
                }
                else if(Match(t,"spline=",out a))
                {
                    text=Tail(t,a,7);SplineReference found=null;
                    foreach(SplineReference r in c.Splines)if(Equal(text,r.Name)){found=r;break;}
                    if(found!=null&&p.Splines.Count<SplineCapacity)p.Splines.Add(found);
                }
                else if(Match(t,"x_offset=",out a))p.Offset.X=Number(c,t,a,9);
                else if(Match(t,"y_offset=",out a))p.Offset.Y=Number(c,t,a,9);
                else if(Match(t,"z_offset=",out a))p.Offset.Z=Number(c,t,a,9);
                else if(Equal(t,"looping"))p.Looping=true;
                else if(Match(t,"addtoset=myset",out a))p.Set=c.Packet.SetId;
                else if(Match(t,"addtoset=",out a))p.Set=Integer(Number(c,t,a,9));
                else if(Equal(t,"relative_to_player"))p.RelativeToPlayer=true;
                else if(Match(t,"relative_to_locator=",out a))p.RelativeLocator=s.FindLocator(Tail(t,a,20));
                else if(Match(t,"ridden_by=myself",out a)) { if(c.Self!=null&&c.HasSelfRiderReference)p.Rider=c.SelfRider; }
                else if(Match(t,"ridden_by=",out a))p.Rider=s.FindRider(Tail(t,a,10));
            }
            return p;
        }

        // Adjacent binary32 values by value (callers exclude zero).
        static float NextUp(float f){int b=BitConverter.ToInt32(BitConverter.GetBytes(f),0);b+=f>0?1:-1;return BitConverter.ToSingle(BitConverter.GetBytes(b),0);}
        static float NextDown(float f){int b=BitConverter.ToInt32(BitConverter.GetBytes(f),0);b+=f>0?-1:1;return BitConverter.ToSingle(BitConverter.GetBytes(b),0);}
        // (1-r)*min + r*max computed as x87 64-bit-mantissa products and sum,
        // then one store to binary32. Both products are exact in double; a
        // two-sum keeps the remainder so binary32 midpoints round as on x87.
        internal static float Lerp(float minimum,float maximum,float r)
        {
            double a=(1.0-(double)r)*minimum,b=(double)r*maximum,sum=a+b,bb=sum-a,error=(a-(sum-bb))+(b-bb);
            float f=MessageNumbers.Round((float)sum);
            if(error==0||f==0||Double.IsInfinity(sum))return f;
            float low=(double)f<=sum?f:NextDown(f),high=(double)f<=sum?NextUp(f):f;
            if(Math.Abs(sum-low)!=Math.Abs(high-sum))return f;
            long bits=BitConverter.DoubleToInt64Bits(Math.Abs(sum));int exponent=(int)((bits>>52)&0x7ff);
            double ulp53=Math.Pow(2,exponent-1075);
            if(Math.Abs(error)<=ulp53/4096)return f; // removed by x87 64-bit rounding; tie stays even
            return error>0?high:low;
        }
        static float Product(double a,double b,double c,double d,bool subtract)
        { return MessageNumbers.Round((float)(subtract?a*b-c*d:a*b+c*d)); }

        public static bool Execute(SplineSpawnContext c,string[] tokens,bool firstCall)
        {
            if(!firstCall)return true;
            SplineSpawnPlan p=Parse(c,tokens);SplineSpawnServices s=c.Services;int count=p.Count;
            if(tokens!=null&&tokens.Length>0&&p.Minimum>=0&&p.Minimum<p.Maximum)
            { long span=(long)p.Maximum-p.Minimum+1;if(span>Int32.MaxValue)throw new ArgumentOutOfRangeException("tokens");count=s.NextInteger()%(int)span+p.Minimum; }
            float distance=p.Distance;
            if(p.MinimumDistance!=1e9f&&p.MaximumDistance!=1e9f)distance=Lerp(p.MinimumDistance,p.MaximumDistance,s.NextFloat());
            if(!(p.UseSelected||p.Splines.Count!=0)||p.Types.Count==0||count<=0)return true;
            if(count>c.OperationBudget)throw new InvalidOperationException("Spawn operation budget exceeded.");
            SplineReference spline;
            if(p.UseSelected)spline=c.SelectedSpline;
            else spline=p.Splines[s.NextSpline16()/(0xffff/p.Splines.Count+1)];
            int random=s.NextInteger();if(random<0)throw new InvalidOperationException("Negative type RNG index is outside this contract.");
            short type=p.Types[random%p.Types.Count];
            for(int i=0;i<count;i++)
            {
                SplineActor actor=s.Spawn(new SplineSpawnRequest{Type=type,Script=p.Script,Spline=spline,Offset=p.Offset,Looping=p.Looping,Set=p.Set});
                if(actor==null)continue;
                if(p.RelativeToPlayer||p.RelativeLocator!=null)
                {
                    int first=-1,second=-1;
                    if(c.LevelSplineLimitsActive)s.LevelSplineLimits(spline,out first,out second);
                    actor.Follower=s.RelativeFollower(p.RelativeToPlayer?c.PlayerReference:p.RelativeLocator,spline,p.Looping,first,second);
                }
                if(distance!=0||Single.IsNaN(distance))
                {
                    s.Advance(actor.Follower,distance);
                    SpawnVector position;ushort heading;int pitch;
                    s.Evaluate(actor.Follower.Spline,actor.Follower.Time,actor.Follower.Mode,out position,out heading,out pitch);
                    ushort tilt=unchecked((ushort)(-pitch));
                    actor.Heading5A=actor.Heading58=actor.Heading27A=heading;actor.Pitch278=tilt;
                    SpawnVector o=actor.Offset;
                    if(o.X!=0||o.Y!=0||o.Z!=0||Single.IsNaN(o.X)||Single.IsNaN(o.Y)||Single.IsNaN(o.Z))
                    {
                        double cos=s.AngleTable(((tilt+0x4000)>>1)&0x7fff),sin=s.AngleTable((tilt>>1)&0x7fff);
                        SpawnVector r=new SpawnVector(o.X,Product(cos,o.Y,sin,o.Z,true),Product(o.Y,sin,cos,o.Z,false));
                        cos=s.AngleTable(((heading+0x4000)>>1)&0x7fff);sin=s.AngleTable((heading>>1)&0x7fff);
                        r=new SpawnVector(Product(sin,r.Z,cos,r.X,false),r.Y,Product(r.Z,cos,r.X,sin,true));
                        position=SpawnVector.Add(position,r);
                    }
                    actor.Position=actor.Origin98=actor.Origin80=position;
                    c.LastPlacement=position;actor.Origin8C=position;
                    s.UpdatePlacement(actor);
                    actor.Previous1B4=actor.Previous10BC=actor.Position;
                }
                if(p.Rider!=null)s.Ride(p.Rider,actor);
            }
            return true;
        }
    }
}
