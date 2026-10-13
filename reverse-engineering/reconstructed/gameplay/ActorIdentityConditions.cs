// Original-PC IAm predicate and its binding initializer. The bound identity is
// the reference record itself, not its first-pointer world object.
namespace Recovered.Gameplay
{
    public static class ActorIdentityConditions
    {
        // 0x515730. Bind once; do not resolve again during condition evaluation.
        public static ActorStateRecord Bind(ActorStateWorld world,string operand)
        {
            return operand!=null&&world.NameCallback?world.FindReference(operand):null;
        }
        // 0x515750. Reference equality wins even when names/definitions are null.
        // Name fallback reads the reference's definition, not WorldObject's.
        public static float IAm(ActorStateRecord reference,string operand,ActorStateRecord initialized)
        {
            if(reference==null)return 0;
            if(object.ReferenceEquals(reference,initialized))return 1;
            if(reference.Definition==null||reference.Definition.Name==null||operand==null)return 0;
            MessageNumbers.RequireAscii(operand);MessageNumbers.RequireAscii(reference.Definition.Name);
            return ActorStateWorld.Equal(reference.Definition.Name,operand)?1:0;
        }
    }
}
