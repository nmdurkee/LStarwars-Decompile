using System;
namespace Recovered.Gameplay
{
    // Host composition, not another original native function. The recovered
    // 535d60 command calls the recovered 514920 evaluator through its existing
    // MovementServices boundary. This wrapper retains mutation of token bytes.
    public static class RetreatExpressionAdapter
    {
        sealed class Services:MovementServices
        {
            public MovementServices Inner;
            public ExpressionEnvironment Environment;
            public string[] Tokens;
            public Action<string> ObserveEvaluation;
            int index=-1;
            public override bool MovementToken(LocatorCreature creature,string token)
            {
                ++index;
                if(Tokens==null||index>=Tokens.Length||Tokens[index]!=token)throw new InvalidOperationException("Retreat token traversal changed.");
                return Inner.MovementToken(creature,token);
            }
            public override float Evaluate(LocatorCreature creature,LocatorPacket packet,string text)
            {
                if(ObserveEvaluation!=null)ObserveEvaluation(text);
                return ScriptExpressions.EvaluateToken(Environment,creature,packet==null?null:packet.Numbers,Tokens,index);
            }
            public override float NextFloat(){return Inner.NextFloat();}
            public override SpawnVector Rotate(SpawnVector vector,int heading){return Inner.Rotate(vector,heading);}
            public override bool SpecialCompletion(LocatorActor reference,LocatorRecord locator){return Inner.SpecialCompletion(reference,locator);}
            public override void FormationOwnerCommand(LocatorCreature creature,int mode){Inner.FormationOwnerCommand(creature,mode);}
            public override void FormationIntent(LocatorCreature creature){Inner.FormationIntent(creature);}
        }
        public static bool Execute(MovementWorld world,LocatorPacket packet,LocatorCreature creature,string[] tokens,bool firstCall,ExpressionEnvironment environment,Action<string> observeEvaluation)
        {
            MovementServices previous=world.Movement;
            world.Movement=new Services{Inner=previous,Environment=environment,Tokens=tokens,ObserveEvaluation=observeEvaluation};
            try{return OpponentRetreat.Execute(world,packet,creature,tokens,firstCall);}
            finally{world.Movement=previous;}
        }
    }
}
