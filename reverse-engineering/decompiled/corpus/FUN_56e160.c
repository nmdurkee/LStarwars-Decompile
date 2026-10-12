/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56e160; label: FUN_0056e160
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

