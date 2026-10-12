/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x450550; label: FUN_00450550
 */

undefined4
FUN_00450550(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (param_6 != 0)) {
    iVar3 = *piVar2;
    puVar1 = (uint *)(iVar3 + 0xef0);
    *puVar1 = *puVar1 | 0x100;
    if ((param_5 != 0) && (iVar5 = 0, 0 < param_5)) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          puVar1 = (uint *)(iVar3 + 0xef0);
          *puVar1 = *puVar1 & 0xfffffeff;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
  }
  return 1;
}

