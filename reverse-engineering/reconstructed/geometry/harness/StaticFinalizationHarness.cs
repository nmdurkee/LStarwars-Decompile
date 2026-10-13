using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;

public static class StaticFinalizationHarness
{
    private sealed class Scene
    {
        public byte[] Items;
        public ClipObject[] Clips;
        public float[][] Matrices;
        public int[][] Bindings;
        public MaterialGateBytes[] Materials;
        public MaterialControlTarget[] MaterialTargets;
    }
    private static readonly uint[] AlphaWords={0xbf800000,0x80000000,0,0x3e800000,0x3f800000,0x40000000,0x7fc12345,0x7f800000,0xff800000};
    private static float Float(uint word) {return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
    private static Scene ReadScene(BinaryReader r)
    {
        Scene s=new Scene();s.Items=r.ReadBytes(r.ReadInt32()*16);s.Clips=new ClipObject[r.ReadInt32()];
        for(int i=0;i<s.Clips.Length;++i) {int[] indices=new int[r.ReadInt32()];for(int j=0;j<indices.Length;++j) indices[j]=r.ReadInt32();s.Clips[i]=new ClipObject {ItemIndices=indices};}
        s.Matrices=new float[r.ReadInt32()][];
        for(int i=0;i<s.Matrices.Length;++i) {s.Matrices[i]=new float[16];for(int j=0;j<16;++j) s.Matrices[i][j]=r.ReadSingle();}
        s.Bindings=new int[r.ReadInt32()][];for(int i=0;i<s.Bindings.Length;++i) s.Bindings[i]=new int[]{r.ReadInt32(),r.ReadInt32()};
        int count=r.ReadInt32();s.Materials=new MaterialGateBytes[count];s.MaterialTargets=new MaterialControlTarget[count];
        for(int i=0;i<count;++i)
        {
            if(r.ReadBoolean()) s.Materials[i]=new MaterialGateBytes(r.ReadByte(),r.ReadByte(),r.ReadByte());
            s.MaterialTargets[i]=new MaterialControlTarget {MaterialIndex=r.ReadInt32(),ItemIndex=r.ReadInt32()};
        }
        return s;
    }
    private static StaticFinishScene Clone(Scene source,out float[][] matrices)
    {
        matrices=new float[source.Matrices.Length][];for(int i=0;i<matrices.Length;++i) matrices[i]=(float[])source.Matrices[i].Clone();
        float[][] targets=new float[source.Items.Length/16][];foreach(int[] b in source.Bindings) targets[b[0]]=matrices[b[1]];
        return new StaticFinishScene {Items=(byte[])source.Items.Clone(),Visibility=new SceneVisibility(source.Clips,new ClipBounds[0],new byte[0],source.MaterialTargets.Length),AlphaTargetsByItem=targets,Materials=source.Materials,MaterialTargets=source.MaterialTargets};
    }
    public static void Main(string[] args)
    {
        if(args.Length!=2) throw new ArgumentException("Compressed input fixture and output file required.");
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 hash=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="FFIN") throw new InvalidDataException("FFIN header required.");
            Scene[] scenes=new Scene[r.ReadInt32()];for(int i=0;i<scenes.Length;++i) scenes[i]=ReadScene(r);
            int count=r.ReadInt32();w.Write(new byte[]{70,70,79,85});w.Write(count);
            for(int ci=0;ci<count;++ci)
            {
                Scene source=scenes[r.ReadInt32()];byte kind=r.ReadByte();float[][] matrices;StaticFinishScene scene=Clone(source,out matrices);
                if(kind==0)
                {
                    bool present=r.ReadBoolean();int pattern=r.ReadByte();byte[] controls={0,1,3,255};for(int i=0;i<scene.Items.Length/16;++i) scene.Items[i*16+1]=controls[(i+pattern)%4];
                    if(present) {scene.Visibility.AlphaValues=new float[scene.Visibility.Clips.Length];for(int i=0;i<scene.Visibility.Clips.Length;++i) scene.Visibility.AlphaValues[i]=Float(AlphaWords[(i+pattern)%AlphaWords.Length]);}
                    StaticFinalization.PatchAlpha(scene);w.Write(matrices.Length);foreach(float[] m in matrices) w.Write(m[15]);w.Write(hash.ComputeHash(scene.Items));
                }
                else if(kind==1)
                {
                    int parity=r.ReadByte(),mode=r.ReadByte();bool equal=r.ReadBoolean();scene.Visibility.Flags=(uint)parity<<15;byte[] current=scene.Visibility.MaterialBits[parity],previous=scene.Visibility.MaterialBits[1-parity];
                    for(int i=0;i<current.Length;++i) {current[i]=(byte)(i*57+0xa5);previous[i]=(byte)(equal || i%2!=0?current[i]:current[i]^0x5a);}
                    StaticFinalization.PatchMaterials(scene,mode);w.Write(hash.ComputeHash(scene.Items));
                }
                else throw new InvalidDataException("Unknown authored case kind.");
            }
            int boundaryCount=r.ReadInt32();w.Write(boundaryCount);
            for(int ci=0;ci<boundaryCount;++ci)
            {
                int materials=r.ReadInt32();bool present=r.ReadBoolean(),first=r.ReadBoolean();int mode=r.ReadByte(),parity=r.ReadByte();int bytes=(materials+7)/8;
                SceneVisibility visibility=new SceneVisibility(new ClipObject[0],new ClipBounds[0],new byte[0],materials);visibility.Flags=(uint)parity<<15;Array.Copy(r.ReadBytes(bytes),visibility.MaterialBits[parity],bytes);Array.Copy(r.ReadBytes(bytes),visibility.MaterialBits[1-parity],bytes);
                MaterialGateBytes[] palette={null,new MaterialGateBytes(0,0,0),new MaterialGateBytes(255,0,0),new MaterialGateBytes(1,0,0),new MaterialGateBytes(0,255,0),new MaterialGateBytes(255,255,255)};
                StaticFinishScene scene=new StaticFinishScene {Visibility=visibility,Items=new byte[Math.Max(16,materials*16)],Materials=present?new MaterialGateBytes[materials]:null,MaterialTargets=new MaterialControlTarget[materials]};
                for(int i=0;i<scene.Items.Length;++i) scene.Items[i]=0xcc;
                for(int i=0;i<materials;++i) {if(present) scene.Materials[i]=i==0?(first?palette[1]:null):palette[i%palette.Length];scene.MaterialTargets[i]=new MaterialControlTarget {MaterialIndex=i,ItemIndex=i};}
                StaticFinalization.PatchMaterials(scene,mode);w.Write(scene.Items.Length);w.Write(scene.Items);
            }
            int finishes=r.ReadInt32();w.Write(finishes);
            for(int ci=0;ci<finishes;++ci)
            {
                int registeredCount=r.ReadInt32(),pattern=r.ReadByte();List<StaticFinishScene> registered=new List<StaticFinishScene>();uint[] patterns={0,2,4,6};
                for(int i=0;i<registeredCount;++i)
                {
                    SceneVisibility v=new SceneVisibility(new ClipObject[0],new ClipBounds[0],new byte[0],0);v.Flags=patterns[(i+pattern)%4];registered.Add(new StaticFinishScene {Visibility=v,Items=new byte[0]});
                }
                uint[] current=new uint[24],previous=new uint[24];for(int i=0;i<24;++i) current[i]=0xface0000u+(uint)(i*37+pattern);
                StaticFinishCallbacks callbacks=new StaticFinishCallbacks {EnterGate=delegate(int handle){if(handle!=0) throw new InvalidDataException("Only no-lock original fixture.");},LeaveGate=delegate(int handle){},FlushDynamicLists=delegate(){},FinalizeSortedPackets=delegate(){}};
                IList<uint> calls=StaticFinalization.Finish(null,registered,current,previous,0,0,callbacks);w.Write(calls.Count);foreach(uint a in calls) w.Write(a);foreach(uint value in previous) w.Write(value);
            }
            if(r.Read()!=-1) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} authored finish cases and {1} boundary/dispatch cases.",count,boundaryCount+finishes);
        }
    }
}
