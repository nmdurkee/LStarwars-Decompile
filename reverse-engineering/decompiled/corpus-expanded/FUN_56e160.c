/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e160; label: FUN_0056e160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056e160(int param_1)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)(PTR_DAT_008032c4 + 4))) {
    iVar1 = *(int *)PTR_DAT_008032c4 + param_1 * 0x20;
    if (*(char *)(iVar1 + 8) != '\0') {
      return 1;
    }
    if ((DAT_008032cc == 0) && (0.0 < _DAT_00950d90)) {
      if (DAT_00951288 == 0) {
        if ((*(uint *)(iVar1 + 0x1c) & 0x10000) != 0) {
          return 1;
        }
      }
      else if ((*(uint *)(iVar1 + 0x1c) & 0x20000) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

