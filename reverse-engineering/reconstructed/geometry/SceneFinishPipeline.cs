// Composition adapter for original normal finish0x5f0d70 and recovered helpers.
// This is not a new independent native entry mapping. Native-vs-Python evidence:
// geometry-finish-pipeline-native-validation.json. Managed equality pending.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class SceneFinishPipeline
    {
        private static int Count(uint n)
        {if(n>1000000)throw new ArgumentException("Finite adapter dimensions exceeded.");return (int)n;}
        private static SceneVisibility Visibility(int materials,ClipObject[] clips)
        {return new SceneVisibility(clips,new ClipBounds[0],new byte[0],materials);}
        private static void PatchMaterials(RenderPacketMemory memory,uint owner,int gateMode)
        {
            int count=Count(memory.Dword(owner+0x4c));uint table=memory.Dword(owner+0x50);
            if(count==0 || table==0 || memory.Dword(table)==0)return;
            SceneVisibility visibility=Visibility(count,new ClipObject[0]);visibility.Flags=memory.Dword(owner+0x74);
            for(int p=0;p<2;++p)Array.Copy(memory.Block(memory.Dword(owner+0x58+(uint)p*4),visibility.MaterialBits[p].Length),visibility.MaterialBits[p],visibility.MaterialBits[p].Length);
            int parity=(int)((visibility.Flags>>15)&1);MaterialGateBytes[] materials=new MaterialGateBytes[count];MaterialControlTarget[] targets=new MaterialControlTarget[count];
            for(int i=0;i<count;++i)
            {
                uint material=memory.Dword(table+(uint)i*4);
                if(material!=0)materials[i]=new MaterialGateBytes(memory.Byte(material+248),memory.Byte(material+249),memory.Byte(material+250));
            }
            // Compact item projection preserves duplicate target aliases. Only
            // changed visibility bytes require the native control record fields.
            Dictionary<uint,int> indices=new Dictionary<uint,int>();List<uint> pointers=new List<uint>();
            for(int i=0;i<count;++i)
            {
                if(visibility.MaterialBits[parity][i>>3]==visibility.MaterialBits[1-parity][i>>3])continue;
                uint record=memory.Dword(memory.Dword(owner+0x54)+(uint)i*4),command=memory.Dword(record+12);int item;
                if(!indices.TryGetValue(command,out item)){item=pointers.Count;indices.Add(command,item);pointers.Add(command);}
                targets[i]=new MaterialControlTarget{MaterialIndex=Count(memory.Dword(record+4)),ItemIndex=item};
            }
            byte[] items=new byte[pointers.Count*16];for(int i=0;i<pointers.Count;++i)items[i*16+1]=memory.Byte(pointers[i]+1);
            StaticFinalization.PatchMaterials(new StaticFinishScene{Visibility=visibility,Items=items,Materials=materials,MaterialTargets=targets},gateMode);
            for(int i=0;i<pointers.Count;++i)memory.Byte(pointers[i]+1,items[i*16+1]);
        }
        private static void PatchClipsAndAlpha(RenderPacketMemory memory,uint owner)
        {
            int count=Count(memory.Dword(owner+0x10)),itemCount=Count(memory.Dword(owner+4));uint itemPointer=memory.Dword(owner+8),definitions=memory.Dword(owner+0x14),sizes=memory.Dword(owner+0x18),alphas=memory.Dword(owner+0x68);
            if(count==0)return;
            ClipObject[] clips=new ClipObject[count];
            for(int i=0;i<count;++i)
            {
                int n=memory.Word(sizes+(uint)i*2);uint p=memory.Dword(definitions+(uint)i*12+8);int[] indices=new int[n];
                for(int j=0;j<n;++j)indices[j]=Count(memory.Dword(p+(uint)j*4));clips[i]=new ClipObject{ItemIndices=indices};
            }
            SceneVisibility visibility=Visibility(0,clips);visibility.Flags=memory.Dword(owner+0x74);
            for(int p=0;p<2;++p)Array.Copy(memory.Block(memory.Dword(owner+0x30+(uint)p*4),visibility.ClipBits[p].Length),visibility.ClipBits[p],visibility.ClipBits[p].Length);
            byte[] items=memory.Block(itemPointer,itemCount*16);SceneSubmission.PatchClipControls(visibility,items);
            StaticFinishScene scene=new StaticFinishScene{Visibility=visibility,Items=items};Dictionary<uint,float[]> matrices=new Dictionary<uint,float[]>();
            if(alphas!=0)
            {
                visibility.AlphaValues=new float[count];scene.AlphaTargetsByItem=new float[itemCount][];
                for(int i=0;i<count;++i)
                {
                    visibility.AlphaValues[i]=BitConverter.ToSingle(memory.Block(alphas+(uint)i*4,4),0);
                    foreach(int ix in clips[i].ItemIndices)
                    {
                        if(ix<=0 || ix>=itemCount)throw new ArgumentException("Invalid native command predecessor.");
                        if(items[ix*16]!=0x82 || items[ix*16+1]==0)continue;
                        uint p=BitConverter.ToUInt32(items,(ix-1)*16+4);float[] values;
                        if(!matrices.TryGetValue(p,out values))
                        {
                            byte[] bytes=memory.Block(p,64);values=new float[16];for(int k=0;k<16;++k)values[k]=BitConverter.ToSingle(bytes,k*4);matrices.Add(p,values);
                        }
                        scene.AlphaTargetsByItem[ix]=values;
                    }
                }
                StaticFinalization.PatchAlpha(scene);
            }
            memory.Block(itemPointer,items);
            // Only the native alpha lane is written; other matrix words remain
            // raw bytes. Shared matrix references retain source iteration order.
            foreach(KeyValuePair<uint,float[]> pair in matrices)memory.Block(pair.Key+60,BitConverter.GetBytes(pair.Value[15]));
        }
        // Explicit globals and zero-lock contract. Metadata/packet memory must
        // not partially overlap; command target and matrix aliases are retained.
        // Diagnostic trace intentionally records only entry addresses.
        public static IList<uint> Run(RenderPacketMemory memory,uint root,IList<uint> registered,uint globalTemplate,uint allocatorControl,uint descriptor,uint tokenBase,int gateMode)
        {
            if(memory==null || registered==null || registered.Count>256)throw new ArgumentException("Finite scene registry required.");
            if(memory.Dword(root+0x1e8)!=0)throw new NotSupportedException("OS lock side effects remain external; this adapter requires the original zero-lock branch.");
            List<uint> calls=new List<uint>();calls.Add(0x5f0d70);calls.Add(0x4ffaa0);calls.AddRange(DynamicMaterialQueue.Flush(memory,root));calls.Add(0x603920);calls.Add(0x5e0bd0);PatchMaterials(memory,root,gateMode);
            foreach(uint owner in registered)
            {
                uint flags=memory.Dword(owner+0x74);
                if((flags&4)!=0){calls.Add(0x5df910);calls.Add(0x5df880);PatchClipsAndAlpha(memory,owner);}
                if((flags&6)!=0){calls.Add(0x5e0bd0);PatchMaterials(memory,owner,gateMode);}
            }
            // Original24-DWORD statistics copy precedes sorted completion.
            memory.Block(root+0x178,memory.Block(root+0x118,96));
            foreach(uint[] row in ShaderContextEmission.CompleteSorted(memory,memory.Dword(root+0x110),registered,globalTemplate,allocatorControl,descriptor,tokenBase))calls.Add(row[0]);
            calls.Add(0x4ffac0);return calls;
        }
    }
}
