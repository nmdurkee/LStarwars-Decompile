// Original shadow parameter setters and two-context initialization.
// Native/Python comparisons are separate from pending managed execution.
using System;
namespace Recovered.Geometry
{
    public static class ShadowSetup
    {
        static uint Offset(uint parameter)
        {
            switch(parameter)
            {
                case 0:return 0x80c; case 1:return 0x810; case 2:return 0x814; case 3:return 0x818;
                case 6:case 7:return 0x110; case 8:return 0x490;
                case 9:case 10:case 11:return 0x104;
                case 12:case 13:case 14:return 0x100;
                case 15:case 16:return 0x484; case 17:case 18:return 0x480;
                case 19:return 0x81c; case 20:return 0x820; default:return 0;
            }
        }
        //0x5953b0. Original ECX=context, callee pops two stack arguments.
        // Unknown selectors do not dereference the context or value.
        public static void SetFloat(RenderPacketMemory m,uint context,uint parameter,float value)
        {
            uint offset=Offset(parameter);if(offset==0)return;
            if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite float parameter required.");
            m.Dword(checked(context+offset),BitConverter.ToUInt32(BitConverter.GetBytes(value),0));
        }
        //0x5c6c90 converts the cdecl context argument to ECX.
        public static void SetFloatCdecl(RenderPacketMemory m,uint context,uint parameter,float value)
        {SetFloat(m,context,parameter,value);}
        //0x5c6cc0 writes integer modes; all other selectors are no-ops.
        public static void SetInteger(RenderPacketMemory m,uint context,uint parameter,uint value)
        {if(parameter==4)m.Dword(checked(context+0x800),value);else if(parameter==5)m.Dword(checked(context+0x804),value);}
        static float F(uint value){return BitConverter.ToSingle(BitConverter.GetBytes(value),0);}
        static void Configure(RenderPacketMemory m,uint context,bool first)
        {
            SetInteger(m,context,5,2);
            SetFloatCdecl(m,context,0,F(first?0x3f59999au:0x3e800000u));
            SetFloatCdecl(m,context,1,F(0x40600000));
            SetFloatCdecl(m,context,2,F(first?0x3ecccccdu:0x3f59999au));
            SetFloatCdecl(m,context,3,F(0x3e4ccccd));
            SetFloatCdecl(m,context,14,F(0x38d1b717));
            SetFloatCdecl(m,context,11,F(0x38d1b717));
            if(first){SetFloatCdecl(m,context,18,F(0x38d1b717));SetFloatCdecl(m,context,16,F(0x38d1b717));}
            // Native stores mode0 then directly calls5b79d0. Reusing the
            // existing equivalent configuration helper adds no native credit.
            ShadowLight.ConfigureOrthographic(m,context,new float[]{-60,60,-60,60,0,300});
        }
        //0x596530. Returned pair adapts original globals955b38 and955b3c;
        // original returns void. No rendering or registry operation occurs.
        public static uint[] Initialize(RenderPacketMemory m,uint contextPool,uint commandPool,uint shaderPool)
        {
            byte occupied=m.Byte(checked(contextPool+8*0x830));int free=0;
            for(int i=0;i<8;++i)if((occupied&(1<<i))==0)++free;
            if(free<2||m.Byte(checked(commandPool+8*0x10))!=0||m.Byte(checked(shaderPool+8*0x40))!=0)
                throw new NotSupportedException("Original initialization requires two context slots and eight free command/shader slots.");
            uint first=ShadowContextConstruction.Create(m,contextPool,commandPool,shaderPool);Configure(m,first,true);
            uint second=ShadowContextConstruction.Create(m,contextPool,commandPool,shaderPool);Configure(m,second,false);
            // This enable transition is inlined in the original caller.
            ShadowContextLifecycle.SetEnabled(m,second,1);
            return new uint[]{first,second};
        }
    }
}
