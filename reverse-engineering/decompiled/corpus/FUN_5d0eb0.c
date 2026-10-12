/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0eb0; label: FUN_005d0eb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005d0eb0(int param_1)

{
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return (float10)0;
  }
  return (float10)(**(float **)(param_1 + 0x30) * *(float *)(param_1 + 0x18) * _DAT_0080b60c);
}

