/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x4493d0; label: FUN_004493d0
 */

undefined4 FUN_004493d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (iVar3 = *piVar2, iVar3 != 0)) {
    puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_0080227c;
    *(uint *)(iVar3 + 0xeec) = *(uint *)(iVar3 + 0xeec) | 0x420;
  }
  return 1;
}

