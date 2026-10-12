/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449f40; label: FUN_00449f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

