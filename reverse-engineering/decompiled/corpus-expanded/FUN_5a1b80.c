/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1b80; label: FUN_005a1b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1b80(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (((param_1 != 0) && (param_2 != 0)) &&
     (piVar2 = *(int **)(param_1 + 0x18), piVar2 != (int *)0x0)) {
    while (iVar1 = FUN_005d0450(piVar2 + 1,param_2), iVar1 == 0) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
    if (piVar2 != (int *)0x0) {
      FUN_005a09a0(param_1,piVar2);
    }
  }
  return;
}

