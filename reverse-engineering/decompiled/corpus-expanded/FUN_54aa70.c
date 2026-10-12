/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54aa70; label: FUN_0054aa70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054aa70(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
    if (**(int **)(param_1 + 0xca4) != 0) {
      FUN_00698900(**(int **)(param_1 + 0xca4),2.0 / _DAT_00925024,0,0,0);
    }
  }
  return;
}

