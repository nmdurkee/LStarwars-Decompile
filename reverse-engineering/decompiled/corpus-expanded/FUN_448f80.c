/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x448f80; label: FUN_00448f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00448f80(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    FUN_0049ca10(*piVar1);
  }
  return 1;
}

