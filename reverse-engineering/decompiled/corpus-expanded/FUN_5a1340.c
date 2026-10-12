/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1340; label: FUN_005a1340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a1340(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 1;
  if ((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x18), piVar2 != (int *)0x0)) {
    while ((piVar2[4] == 0 || ((*(byte *)(piVar2[4] + 0x50) & 1) != 0))) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return uVar1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

