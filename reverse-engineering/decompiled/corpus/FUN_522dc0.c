/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522dc0; label: FUN_00522dc0
 */

undefined4 FUN_00522dc0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (unaff_ESI != 0)) {
    iVar5 = 0;
    piVar6 = (int *)(unaff_EDI + 0x30);
    do {
      if (*piVar6 == unaff_ESI) {
        iVar3 = 0;
        piVar4 = (int *)(unaff_ESI + 0x30);
        do {
          if (*piVar4 == unaff_EDI) {
            puVar1 = (undefined4 *)(unaff_EDI + (iVar5 * 3 + 0xc) * 4);
            *puVar1 = 0;
            puVar1[1] = 0;
            puVar2 = (undefined4 *)(unaff_ESI + (iVar3 * 3 + 0xc) * 4);
            puVar1[2] = 0;
            *puVar2 = 0;
            puVar2[1] = 0;
            puVar2[2] = 0;
            return 1;
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 3;
        } while (iVar3 < 8);
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 3;
    } while (iVar5 < 8);
  }
  return 0;
}

