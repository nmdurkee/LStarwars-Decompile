using System;
public static class RecoveredSourceVerify
{
    public static int Main(string[] args)
    {
        if(args.Length<1)throw new ArgumentException("Specify a verifier module followed by fixture/report paths; see verify.ps1.");
        string[] rest=new string[args.Length-1];Array.Copy(args,1,rest,0,rest.Length);
        switch(args[0])
        {
            case "navigation":return ConnectionDifferential.Main(rest);
            case "gameplay-createcreatures":return GameplayCreateCreaturesVerify.Main(rest);
            case "geometry-volumes":PortalVolumeHarness.Main(rest);return 0;
            case "geometry-visibility":PortalVisibilityHarness.Main(rest);return 0;
            case "combat-kill":return KillDifferential.Main(rest);
            case "gameplay-conditions":return GameplayCompactConditionVerify.Main(rest);
            case "geometry-rooms":return PortalSelectionHarness.Main(rest);
            case "frame":return FrameDifferential.Main(rest);
            case "gameplay-message":return GameplayMessageVerify.Main(rest);
            case "input":return InputDifferential.Main(rest);
            case "gameplay-state":return GameplayStateCommandVerify.Main(rest);
            case "gameplay-visibility":return GameplayVisibilityVerify.Main(rest);
            case "combat":return CombatDifferential.Main(rest);
            case "animation":return AnimationDifferentialHarness.Main(rest);
            case "gameplay":return GameplayPortableVerify.Main(rest);
            case "geometry":return GeometryUvHarness.Main(rest);
            default:throw new ArgumentException("Unknown verifier module.");
        }
    }
}
