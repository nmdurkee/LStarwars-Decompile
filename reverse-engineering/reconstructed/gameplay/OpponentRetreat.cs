using System;
namespace Recovered.Gameplay
{
    public static class OpponentRetreat
    {
        //0x535d60. This body writes an ordinary retreat intent directly; unlike
        //52fcb0 it never invokes formation expansion or requires a self reference.
        public static bool Execute(MovementWorld world,LocatorPacket packet,LocatorCreature creature,string[] tokens,bool firstCall)
        {
            if(creature==null)return true;
            if(firstCall)
            {
                creature.GoalRange=1;
                if(tokens!=null)foreach(string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);
                    if(!world.Movement.MovementToken(creature,token))creature.GoalRange=world.Movement.Evaluate(creature,packet,token);
                }
            }
            LocatorCreature opponent=creature.Opponent==null?null:creature.Opponent.Controller;
            if(opponent!=null)
            {
                creature.IntentPoint=opponent.PathPoint;
                if(opponent.PathWords==null||opponent.PathWords.Length<6)throw new ArgumentException("Opponent path has six native words.");
                Array.Copy(opponent.PathWords,creature.IntentWords,6);creature.IntentRadius=opponent.FollowRadius;creature.IntentGoal=creature.GoalRange;
                creature.Flags=(creature.Flags&0xfffffffau)|2;
            }
            return false;
        }
    }
}
