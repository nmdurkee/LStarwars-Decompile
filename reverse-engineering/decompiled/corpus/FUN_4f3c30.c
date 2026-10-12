/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f3c30; label: FUN_004f3c30
 */

float10 FUN_004f3c30(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int local_8;
  int local_4;
  
  FUN_004ffb90(&local_4,&local_8);
  fVar3 = (float)*param_1;
  if (*param_1 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  fVar1 = (float)local_8;
  if (local_8 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)local_4;
  if (local_4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  return (float10)((fVar3 + (float)param_1[1] * 4.2949673e+09) / (fVar2 + fVar1 * 4.2949673e+09));
}

