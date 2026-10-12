/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d370; label: FUN_0065d370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065d370(int param_1)

{
  undefined4 uVar1;
  
  DAT_0296295c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065d350,"Dpad Mode");
  if (DAT_0296295c != 0) {
    uVar1 = FUN_00627b80(0,&DAT_008109d8,DAT_02962984 == 0,1,FUN_0065d340,"Bridge Orient");
    FUN_00618e10(DAT_0296295c,uVar1);
    uVar1 = FUN_00627b80(1,&DAT_008109d8,DAT_02962984 == 1,1,FUN_0065d340,"Bridge Size");
    FUN_00618e10(DAT_0296295c,uVar1);
    FUN_006279b0(param_1,DAT_0296295c);
    *(int *)(DAT_0296295c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0296295c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

