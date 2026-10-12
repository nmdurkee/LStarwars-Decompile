/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7540; label: FUN_005d7540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7540(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    FUN_005d7230(iVar2);
    piVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    iVar2 = *piVar1;
  }
  return;
}

