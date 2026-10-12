/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647000; label: FUN_00647000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647000(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029209c8 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00646fe0,"Instance Orientation"
                               );
    if (DAT_029209c8 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00646f00,(float)DAT_008101bc * -180.0,
                           (float)DAT_008101bc * 360.0,
                           (float)*(int *)(DAT_02920970 + 0xfc) * 0.005493164,"Base Rotation X");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(1,&DAT_008109d8,0,FUN_00646f00,(float)DAT_008101bc * -180.0,
                           (float)DAT_008101bc * 360.0,
                           (float)*(int *)(DAT_02920970 + 0x100) * 0.005493164,"Base Rotation Y");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(2,&DAT_008109d8,0,FUN_00646f00,(float)DAT_008101bc * -180.0,
                           (float)DAT_008101bc * 360.0,
                           (float)*(int *)(DAT_02920970 + 0x104) * 0.005493164,"Base Rotation Z");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00646f70,0,(float)DAT_008101bc * 180.0,
                           (float)*(int *)(DAT_02920970 + 0x108) * 0.005493164,
                           "Rotation Variation X");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(1,&DAT_008109d8,0,FUN_00646f70,0,(float)DAT_008101bc * 180.0,
                           (float)*(int *)(DAT_02920970 + 0x10c) * 0.005493164,
                           "Rotation Variation Y");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(2,&DAT_008109d8,0,FUN_00646f70,0,(float)DAT_008101bc * 180.0,
                           (float)*(int *)(DAT_02920970 + 0x110) * 0.005493164,
                           "Rotation Variation Z");
      FUN_00618e10(DAT_029209c8,uVar1);
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      FUN_006279b0(param_1,DAT_029209c8);
      *(int *)(DAT_029209c8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029209c8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

