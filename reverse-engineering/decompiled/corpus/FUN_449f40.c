/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449f40; label: FUN_00449f40
 */

undefined4
FUN_00449f40(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  
  if ((((param_6 != 0) && (param_3 != 0)) &&
      (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) && (*piVar1 != 0)) {
    FUN_0049b960(*piVar1);
  }
  return 1;
}

