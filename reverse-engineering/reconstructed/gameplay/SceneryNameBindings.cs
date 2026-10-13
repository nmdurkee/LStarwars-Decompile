// Native 0x55a020 lookup and 0x558770/0x5ae390 object-name accessors.
// Type count is signed; requesting exactly count takes the indexed branch.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
    public sealed class SceneryNameBucket
    {
        public int Count;
        public readonly List<SceneryGizmo> Records=new List<SceneryGizmo>();
    }
    public sealed class SceneryNameBindings : ISceneryBindings
    {
        // Null represents the absent native global type table. The separate
        // count preserves native empty/negative-count gates and its index==count edge.
        public Func<SceneryGizmo,string>[] NameAccessors;
        public int TypeCount;
        public static string ObjectName(SceneryGizmo record)
        {return record==null||record.Target==null?null:record.Target.Name;}
        SceneryGizmo Scan(SceneryRegistry registry,int type,string name)
        {
            if(type>=NameAccessors.Length)throw new ArgumentException("Native lookup would read beyond the prepared type table.");
            Func<SceneryGizmo,string> accessor=NameAccessors[type];
            if(accessor==null)return null;
            if(registry.NameBuckets==null||type>=registry.NameBuckets.Length)throw new ArgumentException("Missing native bucket projection.");
            SceneryNameBucket bucket=registry.NameBuckets[type];
            if(bucket==null)throw new ArgumentException("Missing native bucket projection.");
            for(int i=0;i<bucket.Count;i++)
            {
                if(i>=bucket.Records.Count)throw new ArgumentException("Native lookup would read beyond the prepared records.");
                SceneryGizmo record=bucket.Records[i];
                string candidate=SceneryText.C(accessor(record));
                if(candidate!=null&&SceneryText.Equal(candidate,name))return record;
            }
            return null;
        }
        public SceneryGizmo Find(SceneryRegistry registry,int type,string name)
        {
            if(NameAccessors==null||registry==null||name==null)return null;
            name=SceneryText.C(name);
            if(type<0||TypeCount<type)
            {
                for(int i=0;i<TypeCount;i++){SceneryGizmo result=Scan(registry,i,name);if(result!=null)return result;}
                return null;
            }
            return Scan(registry,type,name);
        }
    }
}
