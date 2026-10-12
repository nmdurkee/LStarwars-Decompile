/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x4492e0; label: FUN_004492e0
 */

undefined4
FUN_004492e0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((param_3 == 0) || (piVar2 = *(int **)(param_3 + 0xd0), piVar2 == (int *)0x0)) ||
     (*piVar2 == 0)) {
    return 1;
  }
  iVar3 = *piVar2;
  if (iVar3 != 0) {
    if ((param_6 != 0) && (iVar5 = 0, 0 < param_5)) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"hold_button");
        if (iVar4 == 0) {
          *(undefined1 *)(param_2 + 0x68) = 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
    puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802280;
    if (*(char *)(param_2 + 0x68) != '\0') {
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 4);
      *puVar1 = *puVar1 | DAT_00802280;
      return 0;
    }
  }
  return 1;
}

