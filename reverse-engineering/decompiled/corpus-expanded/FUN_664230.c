/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664230; label: FUN_00664230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00664230(int param_1)

{
  undefined4 uVar1;
  
  DAT_02962a8c = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00664210,"Detail Level Test");
  if (DAT_02962a8c != 0) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006641f0,0x3f800000,0x41100000,_DAT_00810908,
                         "Thinning Level");
    FUN_00618e10(DAT_02962a8c,uVar1);
    uVar1 = FUN_00627b80(4,&DAT_008109d8,DAT_0081090c == 4,1,FUN_00664200,"High Detail");
    FUN_00618e10(DAT_02962a8c,uVar1);
    uVar1 = FUN_00627b80(2,&DAT_008109d8,DAT_0081090c == 2,1,FUN_00664200,"Medium Detail");
    FUN_00618e10(DAT_02962a8c,uVar1);
    uVar1 = FUN_00627b80(1,&DAT_008109d8,DAT_0081090c == 1,1,FUN_00664200,"Low Detail");
    FUN_00618e10(DAT_02962a8c,uVar1);
    FUN_006279b0(param_1,DAT_02962a8c);
    *(int *)(DAT_02962a8c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a8c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

