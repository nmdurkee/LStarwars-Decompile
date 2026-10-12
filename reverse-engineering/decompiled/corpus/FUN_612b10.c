/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612b10; label: FUN_00612b10
 */

void FUN_00612b10(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)(in_ECX + 0xc034);
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0xc030)) {
    while (*piVar2 != param_1) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (*(int *)(in_ECX + 0xc030) <= iVar1) {
        return;
      }
    }
    *piVar2 = 0;
  }
  return;
}

