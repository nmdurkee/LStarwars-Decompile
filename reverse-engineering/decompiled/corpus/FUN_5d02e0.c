/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d02e0; label: FUN_005d02e0
 */

float10 FUN_005d02e0(int *param_1)

{
  float10 fVar1;
  
  if (param_1[1] != 0) {
    return (float10)*(float *)(*(int *)(*(int *)(*param_1 + 0x18) +
                                       *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4) + 0x14);
  }
  fVar1 = (float10)FUN_005bec80(param_1[2] + 0xa0);
  return (float10)(float)(fVar1 + (float10)*(float *)(param_1[2] + 0xac));
}

