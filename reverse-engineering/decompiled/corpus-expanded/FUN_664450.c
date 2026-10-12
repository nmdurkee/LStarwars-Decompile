/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664450; label: FUN_00664450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664450(int param_1)

{
  undefined4 uVar1;
  
  DAT_02962a88 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00664430,"Detail Level Settings")
  ;
  if (DAT_02962a88 != 0) {
    if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00664380,0x3f800000,0x41100000,
                           *(undefined4 *)
                            (*(int *)(DAT_0296209c +
                                     *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182
                                               + DAT_029620a4) * 4) + 0x2f4),"Maximum Thinning");
      FUN_00618e10(DAT_02962a88,uVar1);
      uVar1 = FUN_00627bc0(4,&DAT_008109d8,((byte)(&DAT_02924ba2)[DAT_029231a8 * 0x58] & 4) >> 2,1,
                           FUN_006643d0,"High Detail");
      FUN_00618e10(DAT_02962a88,uVar1);
      uVar1 = FUN_00627bc0(2,&DAT_008109d8,((byte)(&DAT_02924ba2)[DAT_029231a8 * 0x58] & 2) >> 1,2,
                           FUN_006643d0,"Medium Detail");
      FUN_00618e10(DAT_02962a88,uVar1);
      uVar1 = FUN_00627bc0(1,&DAT_008109d8,(&DAT_02924ba2)[DAT_029231a8 * 0x58] & 1,3,FUN_006643d0,
                           "Low Detail");
      FUN_00618e10(DAT_02962a88,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00664230,"Detail Level Test...");
      FUN_00618e10(DAT_02962a88,uVar1);
    }
    FUN_006279b0(param_1,DAT_02962a88);
    *(int *)(DAT_02962a88 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a88 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

