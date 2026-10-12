// Bounded reconstruction of the original PC navigation connection controllers.
// Original addresses, tests and limitations: reports/native-connections-contract.json.
using System;
using System.Collections.Generic;
namespace Recovered.Navigation
{
    public enum ConnectionKind : byte { SceneObject, Cutscene, BuildIt, Gizmo, BlowUp, FakeAnimation, FlowBox, Force, Obstacle, ZipUp }
    public sealed class NavigationConnection
    {
        public uint ForwardFlags, ReverseFlags;
        public byte Endpoint0, Endpoint1, Obstacle;
    }
    public sealed class NavigationLocator
    {
        public string Name;
        public readonly List<NavigationConnection> Connections = new List<NavigationConnection>();
    }
    public sealed class NavigationPath
    {
        public readonly List<NavigationLocator> Locators = new List<NavigationLocator>();
    }
    // Values resolved by the host from scene/gizmo/cutscene records; not a shared
    // native structure. Each ConnectionKind uses only its relevant fields.
    public sealed class ConnectionTarget
    {
        public bool HasAnimation = true, Visible = true;
        public float EndFrame = 1, Frame = 1;
        public byte BuildState, BlowUpFlags, FlowFlags;
        public int ObstacleState;
        public ushort ZipFlags;
        public uint ForceFlags, ForceFlags2;
        public float ForceTimer;
        public bool ForceHasObstacle;
    }
    public interface IConnectionServices
    {
        NavigationPath FindPath(string name);
        ConnectionTarget ResolveTarget(ConnectionKind kind, string name);
        ConnectionTarget FakeAnimation(int index);
        int EvaluateInteger(string expression);
        uint ReadGizmoOutput(ConnectionTarget target, uint outputIndex);
    }
    public sealed class ConnectionWorld
    {
        public ConnectionManager Manager;
        public NavigationPath DefaultPath;
        public readonly List<NavigationPath> Paths = new List<NavigationPath>();
        public IConnectionServices Services;
        // Native mode precedence: 0x876580 nonzero ->2; else0x7f39e4 nonzero ->1; else0.
        public int FlagDialect = 1;
        public uint BigJumpFlag = 4, RequiresPermissionFlag = 0x1000000, NoDestinationCheckFlag = 0x4000000;
    }
    internal static class ConnectionText
    {
        public static string C(string s) { if(s==null)return null;int i=s.IndexOf('\0');return i<0?s:s.Substring(0,i); }
        static int Fold(char c)
        {
            if(c>255)throw new ArgumentException("Native connection strings must be byte encoded.");
            return (c>='a'&&c<='z')||c>=0xe0?c-32:c;
        }
        public static int Index(string text,string part)
        {
            for(int i=0;i+part.Length<=text.Length;i++)
            {
                bool same=true;for(int j=0;j<part.Length;j++)if(Fold(text[i+j])!=Fold(part[j])){same=false;break;}
                if(same)return i;
            }
            return -1;
        }
        public static bool Equal(string a,string b) { a=C(a);b=C(b);return a!=null&&b!=null&&a.Length==b.Length&&Index(a,b)==0; }
    }
    public static class ConnectionFlags
    {
        static readonly string[][] Names = {
            new[]{"JUMP","COMBATROLL","BATGLIDE","GRAPPLE","USEHATCH","HOVERTUBE","FORGOODIES","FORBADDIES","OBSTACLE","JUMP_NOW","DONT_JUMP_NOW"},
            new[]{"DBLJUMP","R2D2GLIDE","ZIPUP","USEHATCH","JARJARJUMP","HOVERTUBE","SWAMP","TAKEOVER","VEHICLE","PARTY","FORGOODIES","FORBADDIES","OBSTACLE","JUMP_NOW","DONT_JUMP_NOW","BLOCKAGE","JUMP","DONTTOGGLE","FULLTERRAIN"},
            new[]{"DBLJUMP","BIGJUMP","JUMP","GRAPPLE","CLIMB","NO_DEST_CHECK","JUMP_NOW","DONT_JUMP_NOW","FORGOODIES","FORBADDIES","OBSTACLE","WHIPSWING"}
        };
        static readonly uint[][] Values = {
            new uint[]{1,2,4,8,16,64,128,256,0x20000000,0x400,0x800},
            new uint[]{2,4,8,16,32,64,0x4000,0x8000,0x10000,0x20000,128,256,0x20000000,0x400,0x800,0x40000,1,0x80000,0x100000},
            new uint[]{2,4,1,8,16,32,64,128,256,512,0x20000000,0x400}
        };
        // 0x407d00 /0x4cbf70 /0x4817e0. Exact ordered case-folded token lookup.
        public static uint LookupDialect(string name,int dialect)
        {
            if(dialect<0||dialect>2)throw new ArgumentOutOfRangeException("dialect");
            for(int i=0;i<Names[dialect].Length;i++)if(ConnectionText.Equal(name,Names[dialect][i]))return Values[dialect][i];
            return 0;
        }
        // 0x44d870 takes its native string in ESI, omitted by the decompiler.
        public static uint Lookup(string name,int dialect,uint bigJump,uint permission,uint noDestination)
        {
            uint result=LookupDialect(name,dialect);if(result!=0)return result;
            if(ConnectionText.Equal(name,"BLOCK"))return 0x80000000;
            if(ConnectionText.Equal(name,"BIGJUMP"))return bigJump;
            if(ConnectionText.Equal(name,"REQUIRESPERMISSION"))return permission;
            return ConnectionText.Equal(name,"NO_DESTINATION_CHECK")?noDestination:0;
        }
    }
    public sealed class ConnectionController
    {
        public NavigationConnection Connection;
        public ConnectionTarget Target;
        public ConnectionKind Kind;
        public byte PathIndex;
        public ushort Flags;
        public uint OnFlags, OffFlags, OutputIndex;
        public int FakeAnimationIndex;
        public readonly uint[] FrameMask = new uint[32];
        internal void Clear()
        {
            Connection=null;Target=null;Kind=0;PathIndex=0;Flags=0;OnFlags=OffFlags=OutputIndex=0;FakeAnimationIndex=0;Array.Clear(FrameMask,0,32);
        }
    }
    public sealed class ConnectionManager
    {
        readonly List<ConnectionController> records=new List<ConnectionController>();
        readonly List<ConnectionController> free=new List<ConnectionController>();
        readonly List<ConnectionController> active=new List<ConnectionController>();
        public IList<ConnectionController> Active { get { return active.AsReadOnly(); } }
        public int Available { get { return free.Count; } }
        internal IList<ConnectionController> FreeRecords { get { return free.AsReadOnly(); } }
        public ConnectionManager(int capacity)
        {
            if(capacity<0)throw new ArgumentOutOfRangeException("capacity");
            for(int i=0;i<capacity;i++)records.Add(new ConnectionController());Reset();
        }
        // 0x43cc30: reset every record, then append free records in index order.
        public void Reset() { free.Clear();active.Clear();foreach(ConnectionController c in records){c.Clear();free.Add(c);} }
        // 0x43cf70: release clears the record and appends it to the free tail.
        public void Release(ConnectionController c)
        {
            if(c==null)return;
            if(!active.Remove(c))throw new ArgumentException("Controller is not active in this manager.");
            c.Clear();free.Add(c);
        }
        internal ConnectionController Allocate()
        {
            if(free.Count==0)return null;ConnectionController c=free[0];free.RemoveAt(0);active.Add(c);return c;
        }
    }
    public static class ConnectionControllers
    {
        static int FiniteInteger(float x)
        {
            if(Single.IsNaN(x)||Single.IsInfinity(x)||x>=2147483648.0f||x<-2147483648.0f)throw new ArgumentOutOfRangeException("x","Finite native int32 conversion domain required.");
            return (int)x;
        }
        // 0x51ad80, after resolving explicit/default path.
        public static NavigationLocator FindLocator(NavigationPath path,string name)
        {
            if(path==null)return null;
            if(path.Locators.Count>255)throw new ArgumentException("PC locator count is a byte.");
            foreach(NavigationLocator l in path.Locators)if(l.Name!=null&&ConnectionText.Equal(l.Name,name))return l;
            return null;
        }
        // 0x51adf0. First matching target endpoint wins; zero and one mean the
        // two native connection flag words, not an inferred geometric direction.
        public static NavigationConnection FindConnection(NavigationPath path,string from,string to,ref byte direction)
        {
            NavigationLocator a=FindLocator(path,from),b=FindLocator(path,to);
            if(a==null||b==null||Object.ReferenceEquals(a,b))return null;
            int index=path.Locators.IndexOf(b);
            if(a.Connections.Count>255)throw new ArgumentException("PC adjacency count is a byte.");
            foreach(NavigationConnection c in a.Connections)
            {
                if(c.Endpoint0==index){direction=1;return c;}
                if(c.Endpoint1==index){direction=0;return c;}
            }
            return null;
        }
        // 0x43cca0: target lookup happens before checking free pool capacity.
        public static ConnectionController Create(ConnectionWorld world,NavigationPath requestedPath,string from,string to,ConnectionKind kind,string targetName,int fakeId,uint output)
        {
            if(world.Manager==null||from==null||to==null)return null;
            NavigationPath path=requestedPath??world.DefaultPath;byte direction=0;
            NavigationConnection edge=FindConnection(path,from,to,ref direction);ConnectionTarget target=null;
            if(edge!=null)
            {
                if(kind==ConnectionKind.FakeAnimation){if(fakeId<0||fakeId>=1)return null;}
                else if(kind!=ConnectionKind.SceneObject||targetName!=null)target=world.Services.ResolveTarget(kind,targetName);
            }
            if(target==null&&kind!=ConnectionKind.FakeAnimation)return null;
            ConnectionController c=world.Manager.Allocate();if(c==null)return null;
            // Native fake-animation path can allocate even with null connection.
            // Preserve creation evidence; Update explicitly rejects unsafe use.
            c.Connection=edge;c.Target=target;c.Kind=kind;c.FakeAnimationIndex=fakeId;c.OutputIndex=output;
            c.Flags=(ushort)((c.Flags&0xfffe)|direction);
            for(int i=0;i<world.Paths.Count;i++)if(Object.ReferenceEquals(world.Paths[i],requestedPath)){c.PathIndex=checked((byte)i);break;}
            return c;
        }
        static ConnectionTarget AnimationTarget(ConnectionController c,IConnectionServices services)
        { return c.Kind==ConnectionKind.FakeAnimation?services.FakeAnimation(c.FakeAnimationIndex):c.Target; }
        // 0x43cfb0 after native reference/header resolution. Ranges are inclusive,
        // one-based; sentinel-1 is last frame and-2 is penultimate frame.
        public static void AddFrameRange(ConnectionController c,int first,int last,IConnectionServices services)
        {
            if(c==null)return;
            int kind=(int)c.Kind;if(kind==2||kind==3||kind==4||kind==6)return;
            int end=1;
            if(kind==0||kind==1||kind==5)
            {
                ConnectionTarget target=AnimationTarget(c,services);
                if(target!=null&&(kind!=0||target.HasAnimation))end=Math.Min(1024,FiniteInteger(target.EndFrame));
            }
            first=first==-1?end:first==-2?end-1:first;last=last==-1?end:last==-2?end-1:last;
            first=Math.Max(1,first);last=Math.Min(end,last);
            for(int frame=first;frame<=last;frame++)c.FrameMask[(frame-1)/32]|=1u<<((frame-1)%32);
        }
        static bool ForceEnabled(ConnectionTarget t)
        {
            return (t.ForceFlags&2)==0&&(t.ForceTimer<=0||(t.ForceFlags2&0x2000)!=0)&&
                ((t.ForceFlags&0x40)==0||(t.ForceFlags2&0x800)!=0)&&
                (!t.ForceHasObstacle||t.ObstacleState==((t.ForceFlags2&0x40)!=0?0:2));
        }
        public static bool IsEnabled(ConnectionController c,IConnectionServices services)
        {
            ConnectionTarget t=c.Target;int kind=(int)c.Kind;
            if(kind==0||kind==1||kind==5)
            {
                t=AnimationTarget(c,services);int frame=1;
                if(kind==0&&(c.Flags&4)!=0&&(t==null||!t.Visible))return false;
                if(t!=null&&(kind!=0||t.HasAnimation))
                {
                    int end=Math.Min(1024,FiniteInteger(t.EndFrame));
                    if(end<1)throw new ArgumentOutOfRangeException("EndFrame","Update requires a valid positive frame count.");
                    frame=FiniteInteger(t.Frame);frame=frame<1?1:Math.Min(frame,end);
                }
                return (c.FrameMask[(frame-1)/32]&(1u<<((frame-1)%32)))!=0;
            }
            switch(kind)
            {
                case 2:return t.BuildState==2;
                case 3:return services.ReadGizmoOutput(t,c.OutputIndex)!=0;
                case 4:return (t.BlowUpFlags&1)==0;
                case 6:return (t.FlowFlags&2)!=0;
                case 7:return ForceEnabled(t);
                case 8:return t.ObstacleState==2;
                case 9:return (t.ZipFlags&0xc0)==0xc0;
                default:return true;
            }
        }
        // 0x43d0c0. Active order matters when controllers share an edge.
        public static void Update(ConnectionManager manager,IConnectionServices services)
        {
            if(manager==null)return;
            foreach(ConnectionController c in manager.Active)
            {
                c.Flags=(ushort)(c.Flags&0xffdf);
                if(c.Connection==null)throw new InvalidOperationException("Native update would dereference a null connection.");
                bool enabled=IsEnabled(c,services);if(enabled)c.Flags|=0x20;
                c.Connection.Obstacle=(byte)((c.Flags>>(enabled?3:4))&1);
                uint clear=enabled?c.OffFlags:c.OnFlags,set=enabled?c.OnFlags:c.OffFlags;
                int side=c.Flags&1;
                if(side==0||(c.Flags&2)!=0)c.Connection.ForwardFlags=(c.Connection.ForwardFlags&~clear)|set;
                if(side==1||(c.Flags&2)!=0)c.Connection.ReverseFlags=(c.Connection.ReverseFlags&~clear)|set;
            }
        }
        static int Endpoint(string s,IConnectionServices services)
        { return ConnectionText.Equal(s,"lastframe-1")?-2:ConnectionText.Equal(s,"lastframe")?-1:services.EvaluateInteger(s); }
        // 0x44d900. Returns1 even though Ghidra declares this command void.
        public static int Execute(ConnectionWorld world,string[] tokens,bool firstCall)
        {
            if(!firstCall)return 1;
            if(world==null||world.Services==null)throw new ArgumentNullException("world");
            string from=null,to=null,target=null;NavigationPath path=null;ConnectionKind kind=0;
            int fake=-1;uint output=0,on=0,off=0;bool both=false,visible=false,onObstacle=false,offObstacle=false;
            foreach(string raw in tokens)
            {
                string t=ConnectionText.C(raw);int at;
                if(ConnectionText.Index(t,"on_frames")>=0)continue;
                if((at=ConnectionText.Index(t,"from="))>=0){from=t.Substring(at+5);continue;}
                if((at=ConnectionText.Index(t,"to="))>=0){to=t.Substring(at+3);continue;}
                if((at=ConnectionText.Index(t,"pathname="))>=0){path=world.Services.FindPath(t.Substring(at+9));continue;}
                if(ConnectionText.Index(t,"CheckVisible")>=0){visible=true;continue;}
                if(ConnectionText.Index(t,"bothways")>=0){both=true;continue;}
                int flagAt=ConnectionText.Index(t,"on_flag"),offAt=ConnectionText.Index(t,"off_flag");
                if(flagAt>=0||offAt>=0)
                {
                    bool isOn=flagAt>=0;
                    if(ConnectionText.Index(t,"OBSTACLE_OPEN")>=0){if(isOn)onObstacle=true;else offObstacle=true;}
                    else if(ConnectionText.Index(t,"OBSTACLE_CLOSED")>=0){if(isOn)onObstacle=false;else offObstacle=false;}
                    else
                    {
                        uint value=ConnectionFlags.Lookup(t.Substring(isOn?flagAt+8:offAt+9),world.FlagDialect,world.BigJumpFlag,world.RequiresPermissionFlag,world.NoDestinationCheckFlag);
                        if(isOn)on|=value;else off|=value;
                    }
                    continue;
                }
                if((at=ConnectionText.Index(t,"obj="))>=0){target=t.Substring(at+4);kind=ConnectionKind.SceneObject;}
                else if((at=ConnectionText.Index(t,"cutscene="))>=0){target=t.Substring(at+9);kind=ConnectionKind.Cutscene;}
                else if((at=ConnectionText.Index(t,"buildit="))>=0){target=t.Substring(at+8);kind=ConnectionKind.BuildIt;}
                else if((at=ConnectionText.Index(t,"fakeanimid="))>=0){fake=world.Services.EvaluateInteger(t.Substring(at+11));kind=ConnectionKind.FakeAnimation;}
                else if((at=ConnectionText.Index(t,"gizmo_output="))>=0)output=unchecked((uint)world.Services.EvaluateInteger(t.Substring(at+13)));
                else if((at=ConnectionText.Index(t,"gizmo="))>=0){target=t.Substring(at+6);kind=ConnectionKind.Gizmo;}
                else if((at=ConnectionText.Index(t,"flowbox="))>=0){target=t.Substring(at+8);kind=ConnectionKind.FlowBox;}
                else if((at=ConnectionText.Index(t,"blowup="))>=0){target=t.Substring(at+7);kind=ConnectionKind.BlowUp;}
                else if((at=ConnectionText.Index(t,"force="))>=0){target=t.Substring(at+6);kind=ConnectionKind.Force;}
                else if((at=ConnectionText.Index(t,"obstacle="))>=0){target=t.Substring(at+9);kind=ConnectionKind.Obstacle;}
                else if((at=ConnectionText.Index(t,"zipup="))>=0){target=t.Substring(at+6);kind=ConnectionKind.ZipUp;}
            }
            ConnectionController c=Create(world,path,from,to,kind,target,fake,output);if(c==null)return 1;
            c.OnFlags=on;c.OffFlags=off;c.Flags=(ushort)((c.Flags&0xffe1)|(both?2:0)|(visible?4:0)|(onObstacle?8:0)|(offObstacle?16:0));
            foreach(string raw in tokens)
            {
                string t=ConnectionText.C(raw);int at=ConnectionText.Index(t,"on_frames");if(at<0)continue;
                string range=t.Substring(at+10);if(range.Length>=64)throw new ArgumentOutOfRangeException("tokens","Native on_frames buffer is64bytes.");
                int split=ConnectionText.Index(range,"to");if(split<0)continue;
                int first=Endpoint(range.Substring(0,split),world.Services),last=Endpoint(range.Substring(split+2),world.Services);
                if(first<=last||last==-1||last==-2)AddFrameRange(c,first,last,world.Services);
            }
            return 1;
        }
    }
}
