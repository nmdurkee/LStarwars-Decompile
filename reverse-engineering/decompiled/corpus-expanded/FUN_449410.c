/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x449410; label: FUN_00449410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00449410(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (*piVar2 != 0)) {
    puVar1 = (uint *)(*piVar2 + 0xeec);
    *puVar1 = *puVar1 | 0x20000000;
  }
  return 1;
}

