/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8880; label: FUN_004f8880
 */

float10 FUN_004f8880(int *param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8830();
  while( true ) {
    while( true ) {
      fVar1 = (float)fVar2;
      if (*param_1 != 0) break;
      FUN_004f8420();
      fVar2 = (float10)FUN_004f8830();
      fVar2 = fVar2 + (float10)fVar1;
    }
    if (*param_1 != 1) break;
    FUN_004f8420();
    fVar2 = (float10)FUN_004f8830();
    fVar2 = (float10)fVar1 - fVar2;
  }
  return (float10)fVar1;
}

