/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b10a0; label: FUN_005b10a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b10a0(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x24);
  fVar1 = *(float *)(in_ECX + 4);
  if (iVar2 != -1) {
    fVar3 = *(float *)(in_ECX + 8) * _DAT_00925018 + *(float *)(in_ECX + 4);
    *(float *)(in_ECX + 4) = fVar3;
    if (fVar3 <= 1.0) {
      if (fVar3 < 0.0) {
        *(undefined4 *)(in_ECX + 4) = 0;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 4) = 0x3f800000;
    }
    if ((1.0 <= fVar1) || (*(float *)(in_ECX + 4) != 1.0)) {
      if (*(int *)(in_ECX + 0xc) != 0) {
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xc) = 1;
    }
    if (*(int *)(in_ECX + 0x14 + iVar2 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x14 + iVar2 * 4) + 0xc))();
    }
    if ((*(float *)(in_ECX + 4) == 0.0) || (*(float *)(in_ECX + 4) == 1.0)) {
      if (*(float *)(in_ECX + 4) == 0.0) {
        *(undefined4 *)(in_ECX + 0x24) = 0xffffffff;
      }
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
  }
  return;
}

