/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x521ad0; label: FUN_00521ad0
 */

undefined4 FUN_00521ad0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((unaff_ESI != 0) && (unaff_EDI != 0)) {
    iVar1 = 0;
    piVar3 = (int *)(unaff_ESI + 0x18);
    do {
      if (*piVar3 == 0) {
        return 0;
      }
      if (unaff_EDI == *piVar3) {
        if (iVar1 < 0x40) {
          iVar4 = iVar1 + 1;
          puVar2 = (undefined4 *)(unaff_ESI + 0x18 + iVar1 * 4);
          do {
            if (iVar4 < 0x40) {
              *puVar2 = puVar2[1];
            }
            else {
              *puVar2 = 0;
            }
            iVar4 = iVar4 + 1;
            puVar2 = puVar2 + 1;
          } while (iVar4 < 0x41);
        }
        return 1;
      }
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < 0x40);
  }
  return 0;
}

