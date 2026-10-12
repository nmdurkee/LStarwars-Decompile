/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449390; label: FUN_00449390
 */

undefined4 FUN_00449390(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (*piVar2 != 0)) {
    puVar1 = (uint *)(*(int *)(*piVar2 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802284;
  }
  return 1;
}

