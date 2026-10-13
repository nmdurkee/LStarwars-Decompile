using System;
using System.Text;
namespace Recovered.Gameplay
{
    public static class PortalDoorTable
    {
        public const int EntryBytes=16;
        static string CurrentToken(SoundSetupImage memory,uint parser)
        {
            uint address=memory.Word(parser+0x510);StringBuilder text=new StringBuilder();
            for(uint i=0;memory.Byte(address+i)!=0;i++)text.Append((char)memory.Byte(address+i));
            return text.ToString();
        }
        static string NextToken(SoundSetupImage memory,uint parser)
        {
            TextParserTokens.Next(memory,parser,(m,p)=>{throw new ArgumentException("Prepared text-mode parser required.");});
            return CurrentToken(memory,parser);
        }
        static bool Equal(string a,string b){return String.Equals(a,b,StringComparison.OrdinalIgnoreCase);}
        //0x55f960. Parser lifecycle and scene lookup compose existing recovered services.
        //The scene callback writes the12-byte reference at output and returns bind success.
        //Prepared names and tokens are ASCII; numeric tokens fit the native64-byte local.
        //No original arena-capacity guard exists; readable/writable backing is a host precondition.
        public static void Load(SoundSetupImage memory,uint world,uint text,
            Func<string,uint,int,uint> openParser,
            Func<SoundSetupImage,uint,uint,int,int> readFile,
            Action<SoundSetupImage,uint> closeParser,
            Func<SoundSetupImage,uint,uint,string,bool> findSceneObject)
        {
            memory.Word(world+0x5048,0);memory.Word(world+0x504c,0);
            if(memory.Word(world+0x13c)==0)return;
            uint parser=openParser("portaldoors",text,0xffff);if(parser==0)return;
            if(memory.Byte(parser+0x578)!=0)throw new ArgumentException("Prepared text-mode parser required.");
            uint output=unchecked(memory.Word(world+0x104)+3)&0xfffffffcu;
            memory.Word(world+0x104,output);memory.Word(world+0x5048,output);
            while(TextParserLines.Next(memory,parser,readFile,(m,p)=>{throw new ArgumentException("Prepared text-mode parser required.");})!=0)
            {
                if(!Equal(NextToken(memory,parser),"portaldoor"))continue;
                memory.Zero(output,EntryBytes);
                string name=NextToken(memory,parser);
                if(name.Length==0||!findSceneObject(memory,memory.Word(world+0x13c),output,name))continue;
                int id=TextParserNumbers.ReadInteger(memory,parser,(m,p)=>{throw new ArgumentException("Prepared text-mode parser required.");});
                memory.Byte(output+14,unchecked((byte)id));
                for(string token=NextToken(memory,parser);token.Length!=0;token=NextToken(memory,parser))
                    if(Equal(token,"trigger_at_end"))memory.Half(output+12,(ushort)(memory.Half(output+12)|1));
                memory.Word(world+0x504c,unchecked(memory.Word(world+0x504c)+1));output=unchecked(output+EntryBytes);
            }
            closeParser(memory,parser);
            if(unchecked((int)memory.Word(world+0x504c))>0)
                memory.Word(world+0x104,unchecked(output+15)&0xfffffff0u);
            else memory.Word(world+0x5048,0);
        }
        //0x55fbb0. Clear transition-state bits1and2 while preserving configured bit0 and all other bits.
        public static void ResetTransitionFlags(SoundSetupImage memory,uint world)
        {
            uint table=memory.Word(world+0x5048);if(table==0)return;
            for(int i=0;i<unchecked((int)memory.Word(world+0x504c));i++,table=unchecked(table+EntryBytes))
                memory.Half(table+12,(ushort)(memory.Half(table+12)&0xfff9));
        }
    }
}
