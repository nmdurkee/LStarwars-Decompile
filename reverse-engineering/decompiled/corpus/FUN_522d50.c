/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522d50; label: FUN_00522d50
 */

undefined4 FUN_00522d50(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  
  if ((param_1 != 0) && (unaff_ESI != 0)) {
    iVar3 = 0;
    piVar4 = (int *)(param_1 + 0x30);
    do {
      if (*piVar4 == 0) {
        iVar1 = 0;
        piVar2 = (int *)(unaff_ESI + 0x30);
        do {
          if (*piVar2 == 0) {
            *(int *)(param_1 + (iVar3 * 3 + 0xc) * 4) = unaff_ESI;
            *(undefined4 *)(param_1 + 0x34 + iVar3 * 0xc) = 0;
            *(int *)(unaff_ESI + (iVar1 * 3 + 0xc) * 4) = param_1;
            *(undefined4 *)(unaff_ESI + 0x34 + iVar1 * 0xc) = 0;
            return 1;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 3;
        } while (iVar1 < 8);
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 3;
    } while (iVar3 < 8);
  }
  return 0;
}

