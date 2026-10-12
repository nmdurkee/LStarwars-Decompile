/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612b60; label: FUN_00612b60
 */

int FUN_00612b60(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0x3c);
    do {
      if ((*(short *)((int)piVar2 + -10) != 0) && (*piVar2 == param_1)) {
        return in_ECX + (iVar1 * 3 + 6) * 8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 < 0x800);
  }
  return 0;
}

