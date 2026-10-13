// Reconstructed PC SCP OverrideAnimation and character-local name lookup.
using System;
namespace Recovered.Animation
{
    public sealed class AnimationNameEntry
    {
        public string Name;
        public short Action;
    }
    public sealed class ScriptAnimationProcessor
    {
        // Native script processor+0x9c. Expression evaluation remains external.
        public float ActionTimer;
    }
    public static class ScriptAnimationOverride
    {
        static int Fold(char v)
        {
            if(v>255||v==0)throw new ArgumentException("Non-NUL byte strings required");
            return (v>='a'&&v<='z')||v>223?v-32:v;
        }
        static bool Equal(string a,string b)
        {
            if(a==null||b==null||a.Length!=b.Length)return false;
            for(int i=0;i<a.Length;++i)if(Fold(a[i])!=Fold(b[i]))return false;return true;
        }
        static int Find(string text,string key)
        {
            for(int i=0;i+key.Length<=text.Length;++i)
            {bool match=true;for(int j=0;j<key.Length;++j)if(Fold(text[i+j])!=Fold(key[j])){match=false;break;}if(match)return i;}
            return -1;
        }
        // 0x62e000: characterData+10 points to76-byte rows; Name is row+0,
        // Action is signed16 row+8. A null Name terminates the original table.
        public static short FindAction(AnimationNameEntry[] definitions,string query)
        {
            if(definitions==null||query==null)return -1;
            foreach(var row in definitions)
            {if(row==null||row.Name==null)break;if(Equal(query,row.Name))return row.Action;}
            return -1;
        }
        // 0x516980, embedded-controller adapter: actor+2c8 is the script packet.
        // Its+126/+128 fields therefore alias actor+3ee/+3f0 consumed by418ca0.
        // A null actor represents a null script packet. Owner/world presence
        // describe the two native pointer gates, not model/clip availability.
        public static int Run(PcObjectImage actor,bool ownerPresent,bool worldObjectPresent,
            AnimationNameEntry[] definitions,int totalActionCount,string[] tokens,int tokenCount,
            int firstTime,ScriptAnimationProcessor processor,Func<string,float> evaluateExpression)
        {
            if(actor==null||!ownerPresent||!worldObjectPresent||firstTime==0)return 1;
            short from=-1,to=-1;
            if(tokenCount>0&&(tokens==null||tokenCount>tokens.Length))throw new ArgumentException("Valid token range required");
            for(int i=0;i<tokenCount;++i)
            {
                string token=tokens[i];if(token==null)throw new ArgumentNullException("tokens");
                if(Equal(token,"from=All")){from=unchecked((short)totalActionCount);continue;}
                int at=Find(token,"from=");if(at>=0){from=FindAction(definitions,token.Substring(at+5));continue;}
                at=Find(token,"to=");if(at>=0){to=FindAction(definitions,token.Substring(at+3));continue;}
                if(processor!=null)
                {if(evaluateExpression==null)throw new ArgumentNullException("evaluateExpression");processor.ActionTimer=evaluateExpression(tokens[0]);}
            }
            if(to==-1)from=-1;actor.Set16(0x3ee,from);actor.Set16(0x3f0,to);return 1;
        }
    }
}
