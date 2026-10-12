/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1530; label: FUN_005d1530
 */

void FUN_005d1530(int param_1,undefined4 param_2,float param_3)

{
  if (DAT_009738cc < 0x10) {
    *(uint *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    **(undefined4 **)(param_1 + 0x2c) = param_2;
    if ((DAT_009738c4 & 4) == 0) {
      **(float **)(param_1 + 0x30) = param_3 * 0.5;
    }
    else {
      **(float **)(param_1 + 0x30) = param_3;
    }
  }
  if (0 < DAT_009738cc) {
    DAT_009738cc = DAT_009738cc + -1;
    DAT_009738c4 = *(uint *)(&DAT_0096d870 + DAT_009738cc * 4);
  }
  return;
}

