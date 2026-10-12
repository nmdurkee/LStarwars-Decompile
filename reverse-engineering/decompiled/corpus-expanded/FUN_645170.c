/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x645170; label: FUN_00645170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00645170(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920888 != -1) {
    DAT_02920a04 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00645150,"Scale Type");
    if (DAT_02920a04 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00645040,0x3dcccccd,0x411e6666,_DAT_0081019c,
                           "Scale Factor");
      FUN_00618e10(DAT_02920a04,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_00645100,"Apply Scale to Type");
      FUN_00618e10(DAT_02920a04,uVar1);
      FUN_006279b0(param_1,DAT_02920a04);
      *(int *)(DAT_02920a04 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a04 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

