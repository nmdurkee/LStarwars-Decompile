using System;
using System.Text;
namespace Recovered.Gameplay
{
    //These are transport/lifecycle services, not recovered OS or archive implementations.
    public interface ILevelTextFileBackend
    {
        int ReadArchive(SoundSetupImage memory,uint archive,string path,uint destination,int capacity);
        int Exists(SoundSetupImage memory,string path);
        uint Open(SoundSetupImage memory,string path,uint mode,uint archive,uint flags);
        int ReadSpecial(SoundSetupImage memory,uint handle,uint destination,int capacity);
        int Length(SoundSetupImage memory,uint handle);
        int Read(SoundSetupImage memory,uint handle,uint destination,int count);
        void Close(SoundSetupImage memory,uint handle);
        void Pump(SoundSetupImage memory);
        long Seek(SoundSetupImage memory,uint handle,uint low,uint high,uint origin);
    }
    public static class LevelTextLoading
    {
        public const uint ProcessedText=0x92b0c8,Archive=0x91ee88,SpecialMode=0x91ee94,Error=0x91eea4;
        static string CString(SoundSetupImage memory,uint address)
        {
            StringBuilder text=new StringBuilder();for(byte c=memory.Byte(address);c!=0;c=memory.Byte(++address))text.Append((char)c);return text.ToString();
        }
        //0x54be70, including native exact in-place operation. Quote characters do not protect comments.
        //A single slash advances the input pointer even if it is not followed by another slash.
        //The return includes the copied NUL; an additional NUL is stored after that count.
        public static int Normalize(SoundSetupImage memory,uint source,uint output,int convertSeparators)
        {
            uint length=0;while(memory.Byte(unchecked(source+length))!=0)length++;
            uint end=unchecked(source+length);if(end<source){memory.Byte(output,0);return 0;}
            int count=0;
            do
            {
                byte c=memory.Byte(source);bool comment=c==59||c==35;
                if(c==47){source=unchecked(source+1);comment=memory.Byte(source)==47;}
                if(comment)
                {
                    source=unchecked(source+1);
                    while(memory.Byte(source)!=0&&memory.Byte(source)!=10&&memory.Byte(source)!=13)source=unchecked(source+1);
                }
                c=memory.Byte(source);source=unchecked(source+1);
                if(convertSeparators!=0&&(c==61||c==44))c=32;
                memory.Byte(output,c);output=unchecked(output+1);count++;
            }
            while(source<=end);
            memory.Byte(output,0);return count;
        }
        //0x4fd5d0. File length/capacity comparisons and read results are signed32-bit.
        //Seek is the original64-bit EDX:EAX result. Services must provide finite retry completion.
        //A nonnegative short read still returns the advertised length, not the actual read count.
        public static int ReadWhole(SoundSetupImage memory,ILevelTextFileBackend backend,string path,uint destination,int capacity)
        {
            memory.Word(Error,0);uint archive=memory.Word(Archive);
            if(archive!=0)
            {
                int value=backend.ReadArchive(memory,archive,path,destination,capacity);
                if(memory.Word(Error)==uint.MaxValue)return 0;
                if(value!=0)return value;
            }
            if(backend.Exists(memory,path)==0){memory.Word(Error,unchecked((uint)-2));return 0;}
            uint handle=backend.Open(memory,path,0,memory.Word(Archive),0);
            if(handle==0){memory.Word(Error,unchecked((uint)-3));return 0;}
            if(memory.Word(SpecialMode)!=0)
            {
                int value=backend.ReadSpecial(memory,handle,destination,capacity);backend.Close(memory,handle);return value;
            }
            int length=backend.Length(memory,handle);
            if(length>capacity||length==0){memory.Word(Error,uint.MaxValue);length=0;}
            else
            {
                int result=backend.Read(memory,handle,destination,length);
                while(result<0)
                {
                    long seek;do{backend.Pump(memory);seek=backend.Seek(memory,handle,0,0,0);}while(seek<0);
                    result=backend.Read(memory,handle,destination,length);
                }
            }
            backend.Close(memory,handle);return length;
        }
        //0x57a420. The fixed%s.txt CRT formatter remains an explicit supplied service.
        //Original native128-byte filename backing is a bounded precondition; it has no native length guard.
        //This producer allocates no parser record and does not advance the arena cursor beyond alignment.
        public static void Produce(SoundSetupImage memory,uint world,ILevelTextFileBackend backend,Func<string,string> formatFilename)
        {
            memory.Byte(ProcessedText,0);
            string path=formatFilename(CString(memory,world+0x80));
            if(path.Length>=128)throw new ArgumentException("Prepared byte filename must fit the native128-byte local.");
            uint cursor=unchecked(memory.Word(world+0x104)+3)&0xfffffffcu;memory.Word(world+0x104,cursor);
            int result=ReadWhole(memory,backend,path,cursor,0x10000);memory.Word(world+0x10c,unchecked((uint)result));
            if(result>0)
            {
                memory.Byte(unchecked(memory.Word(world+0x104)+(uint)result),0);
                int normalized=Normalize(memory,memory.Word(world+0x104),ProcessedText,1);
                memory.Word(world+0x10c,unchecked((uint)normalized));
            }
        }
    }
}
