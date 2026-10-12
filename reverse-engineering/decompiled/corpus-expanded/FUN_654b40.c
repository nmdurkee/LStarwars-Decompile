/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654b40; label: FUN_00654b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00654b40(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (DAT_02962070 == 0) {
    uVar1 = *param_1 + 0x7f & 0xffffff80;
    *param_1 = uVar1;
    DAT_008108e8 = param_3;
    DAT_008108ec = param_4;
    DAT_02962070 = uVar1;
    *param_1 = *param_1 + DAT_008108fc * 0xa4c + param_3 * 0x430 + param_4 * 0x1b0;
    _DAT_02962074 = *param_1 - uVar1;
  }
  return;
}

