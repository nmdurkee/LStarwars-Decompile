/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4f10; label: FUN_005c4f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005c4f10(uint *param_1)

{
  int iVar1;
  float10 fVar2;
  float fVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  fVar2 = (float10)0;
  if ((iVar1 != 0) && (fVar2 != (float10)_DAT_0297dc04)) {
    if (1.0 < *(float *)(in_ECX + 0x1c)) {
      *(undefined4 *)(in_ECX + 0x1c) = 0x3f800000;
    }
    if ((float10)*(float *)(in_ECX + 0x1c) < fVar2) {
      *(float *)(in_ECX + 0x1c) = (float)fVar2;
    }
    fVar3 = _DAT_0297dc04 / (float)iVar1;
    *param_1 = (uint)(*(int *)(in_ECX + 0x24) == iVar1 + -1);
    return (float10)fVar3;
  }
  *param_1 = 1;
  return fVar2;
}

