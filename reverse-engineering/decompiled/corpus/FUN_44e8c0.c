/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44e8c0; label: FUN_0044e8c0
 */

undefined4 FUN_0044e8c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    FUN_0062e6c0(*(undefined4 *)(*piVar1 + 0x50),*piVar1 + 8);
  }
  return 1;
}

