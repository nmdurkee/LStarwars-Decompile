/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x695ef0; label: FUN_00695ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00695ef0(undefined4 param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    iVar1 = *(int *)(in_ECX + 0x1d8);
    if (iVar1 != 0) {
      iVar2 = FUN_00693e50(param_1);
      if (iVar2 != -1) {
        if (param_2 < 0.0) {
          param_2 = 0.0;
        }
        *(float *)(*(int *)(iVar1 + 0xc + iVar2 * 4) + 0x24) = param_2;
        return 1;
      }
    }
    return 0;
  }
  return 0;
}

