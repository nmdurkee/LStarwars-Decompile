using System;
using System.Text;
namespace Recovered.Gameplay
{
    //Resource payload construction/release remains external. Calls may mutate the supplied image.
    public interface IWorldResourceServices
    {
        uint Call(SoundSetupImage memory,uint entry,params uint[] arguments);
        string TitleSuffix(SoundSetupImage memory);
        uint LoadScene(SoundSetupImage memory,uint entry,uint[] arguments,string path,string role);
        //Observational entry hook only, matching native fixture instrumentation.
        void TeardownStarted(uint world);
    }
    public static class WorldResourceTeardown
    {
        //0x55f6c0. Full own-state teardown order; subsystem backend behavior remains explicit.
        public static void Run(SoundSetupImage memory,uint world,IWorldResourceServices services)
        {
            services.TeardownStarted(world);
            services.Call(memory,0x5934d0,memory.Word(0x955870),world);
            uint group=memory.Word(world+0x2ab0);
            if(group!=0&&unchecked((int)memory.Word(group+4))>0)
            {
                int i=0;
                do
                {
                    group=memory.Word(world+0x2ab0);
                    uint record=memory.Word(memory.Word(group)+(uint)i*4);
                    services.Call(memory,0x652b40,memory.Word(record+4));i++;
                }
                while(i<unchecked((int)memory.Word(memory.Word(world+0x2ab0)+4)));
            }
            services.Call(memory,0x59a030,world);
            services.Call(memory,0x55b5b0,world);
            services.Call(memory,0x57cf00,memory.Word(world+0x2ab0));
            if(memory.Word(world+0x2964)!=0)
            {
                services.Call(memory,0x5ef880,memory.Word(world+0x2964));memory.Word(world+0x2964,0);
            }
            //Sentinel checks are fullDWORD; byte arguments are read again after each service call.
            if(memory.Word(world+0x2a98)!=uint.MaxValue)
            {
                services.Call(memory,0x68e900,memory.Byte(world+0x2a98));
                services.Call(memory,0x68ea00,memory.Byte(world+0x2a98));
            }
            if(memory.Word(world+0x2a9c)!=uint.MaxValue)
            {
                services.Call(memory,0x648a30,memory.Byte(world+0x2a9c));
                services.Call(memory,0x64c6e0,memory.Byte(world+0x2a9c));
            }
            if(memory.Word(world+0x2aa4)!=uint.MaxValue)
            {
                services.Call(memory,0x689e70,memory.Byte(world+0x2aa4));
                services.Call(memory,0x689ed0,memory.Byte(world+0x2aa4));
            }
            if(memory.Word(world+0x2aa8)!=uint.MaxValue)services.Call(memory,0x65ceb0,memory.Byte(world+0x2aa8));
            if(memory.Word(world+0x2aa0)!=uint.MaxValue)
            {
                services.Call(memory,0x65a5c0,memory.Word(world+0x2aa0));
                services.Call(memory,0x65a5d0,memory.Word(world+0x2aa0));
            }
            if(memory.Word(0x7fac04)==0)
            {
                for(uint i=2;i<8;i++)if(memory.Word(0x2948eb0+i*4)!=0)
                {services.Call(memory,0x68e900,i);services.Call(memory,0x68ea00,i);}
                for(uint i=1;i<8;i++)if(memory.Word(0x2913a2c+i*4)!=0)
                {services.Call(memory,0x648a30,i);services.Call(memory,0x64c6e0,i);}
            }
            services.Call(memory,0x5a29d0,world);
            if(memory.Word(world+0x13c)!=0)
            {services.Call(memory,0x5ef880,memory.Word(world+0x13c));memory.Word(world+0x13c,0);}
            if(memory.Word(world+0x140)!=0)
            {services.Call(memory,0x5ef880,memory.Word(world+0x140));memory.Word(world+0x140,0);}
        }
    }
    public enum WorldScenePhaseResult { Aborted,HandoffToAuxiliary }
    public static class WorldSceneLoaderPhase
    {
        public const uint Failure=0x93d840,SceneTag=0x2854d4c;
        static string CString(SoundSetupImage memory,uint address)
        {
            StringBuilder text=new StringBuilder();for(byte c=memory.Byte(address);c!=0;c=memory.Byte(++address))text.Append((char)c);return text.ToString();
        }
        sealed class MemoryAdapter:IWorldLoadingMemory
        {
            readonly SoundSetupImage image;public MemoryAdapter(SoundSetupImage image){this.image=image;}
            public uint ReadUInt32(uint address){return image.Word(address);}
            public sbyte ReadSByte(uint address){return unchecked((sbyte)image.Byte(address));}
            public byte ReadByte(uint address){return image.Byte(address);}
            public void WriteUInt32(uint address,uint value){image.Word(address,value);}
            public void Clear(uint address,int size)
            {
                foreach(var r in image.Regions)if(address>=r.Key&&(ulong)(address-r.Key)+(ulong)size<=(ulong)r.Value.Length)
                {Array.Clear(r.Value,(int)(address-r.Key),size);return;}
                image.Zero(address,(uint)size);
            }
            public string ReadCString(uint address){return CString(image,address);}
            public void WriteCString(uint address,string value)
            {foreach(char c in value){if(c>255)throw new ArgumentException("Byte string required.");image.Byte(address++,(byte)c);}image.Byte(address,0);}
        }
        sealed class ResetCalls:IWorldLoadingCalls
        {
            readonly SoundSetupImage image;readonly IWorldResourceServices services;
            public ResetCalls(SoundSetupImage image,IWorldResourceServices services){this.image=image;this.services=services;}
            public void Invoke(uint entry,params uint[]args)
            {
                if(entry==0x55f6c0)WorldResourceTeardown.Run(image,args[0],services);
                else services.Call(image,entry,args);
            }
        }
        static WorldScenePhaseResult Abort(SoundSetupImage memory,uint world,IWorldResourceServices services)
        {
            WorldResourceTeardown.Run(memory,world,services);
            WorldLoadingContracts.Initialize(new MemoryAdapter(memory),new ResetCalls(memory,services),world,-1);
            return WorldScenePhaseResult.Aborted;
        }
        //0x48ce00 bounded initial phase ce00..d063 plus full native abort d64d..d65e.
        //Handoff occurs BEFORE5a05b0 allocation and is not full resource-load success or+110 commit.
        //Text production, cache reset and full teardown compose their previously recovered implementations.
        public static WorldScenePhaseResult Run(SoundSetupImage memory,uint world,ILevelTextFileBackend files,
            Func<string,string> formatFilename,IWorldResourceServices services)
        {
            LevelTextLoading.Produce(memory,world,files,formatFilename);
            if(memory.Word(Failure)!=0)return Abort(memory,world,services);
            if(unchecked((int)memory.Word(world+0x10c))>0)
            {
                services.Call(memory,0x578f60,memory.Word(world+0x128),LevelTextLoading.ProcessedText,memory.Word(0x951ba8));
                if(memory.Word(Failure)!=0)return Abort(memory,world,services);
            }
            uint level=memory.Word(world+0x128);
            if((memory.Byte(level+0x64)&4)!=0)
            {
                memory.Word(world+0x104,unchecked(memory.Word(world+0x104)+3)&0xfffffffcu);
                string path;
                if(level==memory.Word(0x951b88))
                {
                    string suffix=services.TitleSuffix(memory);
                    if(suffix.Length>=64)throw new ArgumentException("Prepared title suffix must fit native64-byte local.");
                    path="levels\\titles\\"+suffix;
                }
                else path=CString(memory,world+0x80);
                path+=".gsc";if(path.Length>=256)throw new ArgumentException("Prepared scene path must fit native256-byte local.");
                level=memory.Word(world+0x128);memory.Word(SceneTag,(uint)memory.Byte(level+0xa0)+1);
                int channel=unchecked((sbyte)memory.Byte(level+0xa2))+1;bool matched=false;
                for(uint i=0;i<11;i++)if(memory.Word(0x87b060+i*4)==level){channel=1;matched=true;break;}
                if(!matched)for(uint i=0;i<4;i++)if(memory.Word(0x87b164+i*4)==level){channel=3;break;}
                services.Call(memory,0x6d34c0,unchecked((uint)channel));
                bool alternate=memory.Word(0x8264bc)==2;
                uint[]args=alternate?new[]{world+0x104,memory.Word(world+0x108),2u}:new[]{world+0x104,memory.Word(world+0x108)};
                uint scene=services.LoadScene(memory,alternate?0x5f4f00u:0x5ef7f0u,args,path,"scene");
                memory.Word(world+0x13c,scene);services.Call(memory,0x6d34c0,0);memory.Word(SceneTag,0);
                services.Call(memory,0x48c270,memory.Word(world+0x13c),world+0x15c,1);
                services.Call(memory,0x5528b0,memory.Word(world+0x13c));
                if(memory.Word(world+0x13c)!=0)services.Call(memory,0x48c630,world);
                if(memory.Word(Failure)!=0)return Abort(memory,world,services);
            }
            level=memory.Word(world+0x128);
            if(level==memory.Word(0x951b88)||level==memory.Word(0x951b9c))
            {
                memory.Word(SceneTag,(uint)memory.Byte(level+0xa0)+1);
                uint scene=services.LoadScene(memory,0x5ef7f0,new[]{world+0x104,memory.Word(world+0x108)},"levels\\titles\\pictures.gsc","pictures");
                memory.Word(world+0x140,scene);
                if(memory.Word(Failure)!=0)return Abort(memory,world,services);
            }
            return WorldScenePhaseResult.HandoffToAuxiliary;
        }
    }
}
