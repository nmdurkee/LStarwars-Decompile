/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65e040; label: FUN_0065e040
 */

void FUN_0065e040(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  DAT_02962a0c = param_4;
  DAT_02962a08 = param_3;
  DAT_02962a10 = param_5;
  if (param_5 == 0) {
    DAT_02962a0c = param_5;
  }
  DAT_02962a14 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_02962a14;
  *param_1 = *param_1 + DAT_02962a08 * 0x50;
  DAT_02962a18 = *param_1;
  *param_1 = *param_1 + DAT_02962a10 * DAT_02962a0c * 0x20;
  DAT_02962a1c = *param_1;
  *param_1 = *param_1 + DAT_02962a0c * 4;
  FUN_00546f90(param_1,param_2,0x3000,param_3);
  FUN_00545db0(param_1,param_2,0x3000,param_3);
  return;
}

