/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0fe0; label: FUN_005d0fe0
 */

void FUN_005d0fe0(int param_1,undefined4 param_2,float param_3)

{
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    **(undefined4 **)(param_1 + 0x2c) = param_2;
    if (((byte)DAT_009738c4 & 4) != 0) {
      **(float **)(param_1 + 0x30) = param_3;
      return;
    }
    **(float **)(param_1 + 0x30) = param_3 * 0.5;
  }
  return;
}

