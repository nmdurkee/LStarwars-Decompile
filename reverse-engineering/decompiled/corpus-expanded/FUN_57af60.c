/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57af60; label: FUN_0057af60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057af60(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  iVar1 = DAT_00951c4c;
  *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) | 0x80;
  *(float *)(iVar1 + 100) = (float)fVar2;
  return;
}

