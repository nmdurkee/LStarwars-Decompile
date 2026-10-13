using System;
using System.IO;
using System.IO.Compression;
using Recovered.Geometry;
public static class DynamicBoundsHarness
{
    private static float[] Read(BinaryReader reader,int n){if(n<0||n>3000000)throw new InvalidDataException();float[] v=new float[n];for(int i=0;i<n;++i)v[i]=reader.ReadSingle();return v;}
    private static void Write(BinaryWriter writer,float[] values){foreach(float v in values)writer.Write(v);}
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        {
            if(new string(r.ReadChars(4))!="DBPI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,66,80,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32();
                if(kind==0)
                {
                    float[] minimum=Read(r,3),maximum=Read(r,3),matrix=r.ReadInt32()!=0?Read(r,16):null;DynamicBoxState state=new DynamicBoxState();state.View=Read(r,16);float[] p=Read(r,6);state.Near=p[0];state.Far=p[1];state.FarOverride=p[2];state.HorizontalSlope=p[4];state.VerticalSlope=p[5];state.Enabled=r.ReadInt32()!=0;state.CombinedMatrix=Read(r,16);state.FarLanes=Read(r,4);w.Write(DynamicBounds.Classify(state,minimum,maximum,matrix,p[3]));Write(w,state.CombinedMatrix);Write(w,state.FarLanes);float[] points=state.LastCorners??new float[0];w.Write(points.Length);Write(w,points);
                }
                else
                {
                    float[] result;
                    if(kind==1)result=DynamicBounds.MultiplyAffine(Read(r,16),Read(r,16));
                    else if(kind==2){int size=r.ReadInt32();float[] matrix=Read(r,16);result=DynamicBounds.TransformPoints(Read(r,size),matrix);}
                    else throw new InvalidDataException();w.Write(result.Length);Write(w,result);
                }
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
