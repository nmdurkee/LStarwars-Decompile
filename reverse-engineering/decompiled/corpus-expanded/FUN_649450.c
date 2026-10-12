/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x649450; label: FUN_00649450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649450(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029209c0 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00649430,"Instance Settings");
    if (DAT_029209c0 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644890,"Max Instance Life...");
      FUN_00618e10(DAT_029209c0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00647000,"Instance Orientation...");
      FUN_00618e10(DAT_029209c0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00648b00,"Instance Flags...");
      FUN_00618e10(DAT_029209c0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644a40,"Instance Tint...");
      FUN_00618e10(DAT_029209c0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644bd0,"Instance Scale...");
      FUN_00618e10(DAT_029209c0,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209c0);
    *(int *)(DAT_029209c0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209c0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

