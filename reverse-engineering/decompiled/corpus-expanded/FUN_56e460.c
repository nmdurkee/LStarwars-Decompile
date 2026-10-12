/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e460; label: FUN_0056e460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056e460(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_008032cc == 0) {
    if (0.0 < _DAT_00950d90) {
      return 1;
    }
  }
  else if ((param_1 == 0) || (param_1 == 1)) {
    piVar2 = &DAT_0093d7f0;
    while (((iVar1 = *piVar2, iVar1 == 0 || (*(float *)(iVar1 + 0xdec) <= 0.0)) ||
           ((param_1 != -1 && (*(char *)(iVar1 + 0x280) != param_1))))) {
      piVar2 = piVar2 + 1;
      if (0x93d7f7 < (int)piVar2) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

