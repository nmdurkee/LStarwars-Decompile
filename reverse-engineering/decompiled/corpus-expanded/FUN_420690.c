/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420690; label: FUN_00420690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420690(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = param_1[2];
  while ((((*(char *)(in_ECX + 8) != '\0' &&
           (iVar2 = param_1[1], *(char *)(iVar1 + 2 + iVar2 * 8) != '\0')) ||
          ((*(int *)(in_ECX + 0x38) == 0 &&
           (iVar2 = param_1[1], (*(byte *)(iVar1 + 3 + iVar2 * 8) & 0x20) != 0)))) ||
         (((*(int *)(in_ECX + 0x38) == 1 &&
           (iVar2 = param_1[1], (*(byte *)(iVar1 + 3 + iVar2 * 8) & 0x40) != 0)) ||
          (iVar2 = param_1[1], (*(byte *)(iVar1 + 3 + iVar2 * 8) & 0x80) != 0))))) {
    param_1[1] = iVar2 + 1;
    if (*param_1 <= iVar2 + 1) {
      param_1[1] = 0;
    }
  }
  return;
}

