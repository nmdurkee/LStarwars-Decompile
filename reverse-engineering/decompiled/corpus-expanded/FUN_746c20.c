/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x746c20; label: FUN_00746c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746c20(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_ECX + 0x89c);
  iVar1 = 0;
  if (0 < iVar4) {
    piVar2 = (int *)(in_ECX + 0x4b4);
    do {
      if (*(int *)(&DAT_007e9458 + *(int *)(*piVar2 + 4) * 4) <
          *(int *)(&DAT_007e9458 + *(int *)(param_1 + 4) * 4)) {
        if (iVar1 < iVar4) {
          puVar3 = (undefined4 *)(in_ECX + 0x4b4 + iVar4 * 4);
          iVar4 = iVar4 - iVar1;
          do {
            *puVar3 = puVar3[-1];
            puVar3 = puVar3 + -1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        *(int *)(in_ECX + 0x4b4 + iVar1 * 4) = param_1;
        *(int *)(in_ECX + 0x89c) = *(int *)(in_ECX + 0x89c) + 1;
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < iVar4);
  }
  *(int *)(in_ECX + 0x4b4 + iVar4 * 4) = param_1;
  *(int *)(in_ECX + 0x89c) = *(int *)(in_ECX + 0x89c) + 1;
  return;
}

