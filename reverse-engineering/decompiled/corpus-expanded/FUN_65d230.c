/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d230; label: FUN_0065d230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065d230(int param_1)

{
  undefined4 uVar1;
  
  DAT_02962968 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065d210,"Plank Count");
  if (DAT_02962968 != 0) {
    uVar1 = FUN_00625240(0,&DAT_008109d8,0,&LAB_0065d1d0,1,0x17,_DAT_00810a30,"Plank Count");
    FUN_00618e10(DAT_02962968,uVar1);
    uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_0065d1f0,1,0x17,_DAT_00810a34,"Post Interval");
    FUN_00618e10(DAT_02962968,uVar1);
    FUN_006279b0(param_1,DAT_02962968);
    *(int *)(DAT_02962968 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962968 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

