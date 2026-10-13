// Table consumers from the PC navigation runtime. Loaded graph ownership,
// dynamic table rebuilding, movement and collision are separate contracts.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public sealed class RoutingConnection
    {
        public uint Identity;
        public byte Endpoint0,Endpoint1;
        public ushort RouteMask;
        public float Distance;
    }
    public sealed class RoutingPoint
    {
        public uint[] Adjacency=new uint[0];
        public ushort Membership58,Boundary5a;
        public byte CacheDestination0=255,CacheDestination1=255;
        public float CacheDistance0,CacheDistance1;
    }
    public sealed class RoutingGroup
    {
        public byte PointCount;
        public byte[] PointMap,Exits;
        public byte[][] NextSlots;
    }
    public sealed class RoutingPath
    {
        public RoutingPoint[] Points;
        public byte[][] BaseNextSlots;
        public RoutingGroup[] Groups;
        public readonly Dictionary<uint,RoutingConnection> Connections=new Dictionary<uint,RoutingConnection>();
        //0x512860 diagnostic dispatch. Runtime path selection does not depend
        // on its return value. The source preserves this observable boundary.
        public Action<int,int,int> InvalidGroupMap;
    }
    public static class PathRouting
    {
        static uint Shift(int count){count&=255;return count<32?1u<<count:0;}
        static float Add(float a,float b){return PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store();}
        static float Joined(float a,float b){return a==Single.MaxValue||b==Single.MaxValue?Single.MaxValue:Add(a,b);}
        static RoutingConnection Edge(RoutingPath p,uint id){return id==0?null:p.Connections[id];}
        //0x51a890. Cache writes occur only for unrestricted route255/mask0.
        public static float Distance(RoutingPath path,int start,int destination,int group,uint exclusion)
        {return Distance(path,start,destination,group,exclusion,0);}
        static float Distance(RoutingPath path,int start,int destination,int group,uint exclusion,int depth)
        {
            if(path.BaseNextSlots==null)return Single.MaxValue;
            if(start==destination)return 0;
            if(depth>256)throw new ArgumentException("Cyclic or malformed recursive route graph.");
            RoutingPoint first=path.Points[start],target=path.Points[destination];bool cache=exclusion==0&&group==255;
            if(cache)
            {
                if(first.CacheDestination0==destination)return first.CacheDistance0;
                if(first.CacheDestination1==destination)return first.CacheDistance1;
                first.CacheDestination1=first.CacheDestination0;first.CacheDistance1=first.CacheDistance0;first.CacheDestination0=(byte)destination;first.CacheDistance0=0;
            }
            RoutingGroup sub=group==255?null:path.Groups[group];
            if(sub!=null&&(first.Membership58&Shift(group))==0)return Single.MaxValue;
            int current=start;uint previous=0;float total=0;HashSet<ulong> seen=new HashSet<ulong>();
            while(current!=destination)
            {
                if(!seen.Add(((ulong)(uint)current<<32)|previous))throw new ArgumentException("Nonterminating route-table cycle outside recovered valid domain.");
                RoutingPoint point=path.Points[current];int slot;
                if(sub==null)slot=path.BaseNextSlots[current][destination];
                else if((target.Membership58&Shift(group))==0)
                {
                    float best=Single.MaxValue;
                    foreach(byte exit in sub.Exits)
                    {
                        float a=exit==start?0:Distance(path,start,exit,group,0,depth+1);
                        float b=exit==destination?0:Distance(path,exit,destination,255,Shift(group),depth+1);
                        float candidate=Joined(a,b);if(candidate<best)best=candidate;
                    }
                    return Finish(first,cache,best==Single.MaxValue?Single.MaxValue:Add(total,best));
                }
                else
                {
                    int a=sub.PointMap[current],b=sub.PointMap[destination];
                    if(a>=sub.PointCount||b>=sub.PointCount)
                    {if(path.InvalidGroupMap!=null)path.InvalidGroupMap(group,current,destination);return Finish(first,cache,Single.MaxValue);}
                    slot=sub.NextSlots[a][b];
                }
                if(slot==255)return Finish(first,cache,Single.MaxValue);
                RoutingConnection connection=Edge(path,point.Adjacency[slot]);
                // Native null-edge return bypasses the pending cache store.
                if(connection==null)return Single.MaxValue;
                if((exclusion&connection.RouteMask)!=0)return Finish(first,cache,Single.MaxValue);
                if(connection.Identity==previous)return Finish(first,cache,total);
                previous=connection.Identity;current=connection.Endpoint0==current?connection.Endpoint1:connection.Endpoint0;total=Add(total,connection.Distance);
            }
            return Finish(first,cache,total);
        }
        static float Finish(RoutingPoint first,bool cache,float value){if(cache)first.CacheDistance0=value;return value;}
        //0x51be90 (native creature argument in EAX). destination is an aligned
        // point index; invalid/nonaligned native backing pointers are excluded.
        // The out direction may be written before a later null-result return.
        public static uint NextConnection(RoutingPath path,uint currentConnection,byte direction,byte selectedRoute,int? destination,ref uint outputDirection)
        {
            if(!destination.HasValue||currentConnection==0)return 0;
            RoutingConnection old=path.Connections[currentConnection];int start=direction==0?old.Endpoint1:old.Endpoint0,dest=destination.Value;
            if((uint)dest>255)return 0;
            RoutingPoint point=path.Points[start];uint result=0;int ordinal=path.BaseNextSlots[start][dest];
            if(ordinal<point.Adjacency.Length){result=point.Adjacency[ordinal];outputDirection=(uint)(path.Connections[result].Endpoint0!=start?1:0);}
            if(selectedRoute!=255)
            {
                uint mask=Shift(selectedRoute);
                if((point.Membership58&mask)==0)return 0;
                if((point.Boundary5a&mask)==0||(result!=0&&(path.Connections[result].RouteMask&mask)!=0))
                {
                    RoutingGroup sub=path.Groups[selectedRoute];result=0;int next=dest;
                    if((path.Points[dest].Membership58&mask)==0)
                    {
                        float best=Single.MaxValue;next=0;
                        foreach(byte exit in sub.Exits)
                        {
                            float a=Distance(path,start,exit,selectedRoute,0),b=Distance(path,exit,dest,255,mask),candidate=Joined(a,b);
                            if(candidate<best){best=candidate;next=exit;}
                        }
                        if(best==Single.MaxValue)return 0;
                    }
                    ordinal=sub.NextSlots[sub.PointMap[start]][sub.PointMap[next]];
                    if(ordinal<point.Adjacency.Length){result=point.Adjacency[ordinal];outputDirection=(uint)(path.Connections[result].Endpoint0!=start?1:0);}
                }
            }
            return result;
        }
    }
}
