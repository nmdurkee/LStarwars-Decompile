/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449a50; label: FUN_00449a50
 */

undefined4
FUN_00449a50(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (iVar2 = *piVar1, param_6 != 0)) {
    iVar4 = 0;
    *(undefined1 *)(iVar2 + 0x408) = 0;
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"rotational");
        if (iVar3 == 0) {
          *(undefined1 *)(iVar2 + 0x408) = 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
  }
  return 1;
}

