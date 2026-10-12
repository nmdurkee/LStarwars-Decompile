/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a810; label: FUN_0054a810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054a810(int param_1)

{
  if (0.0 < *(float *)(param_1 + 0xc)) {
    *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) - _DAT_00925018;
  }
  if (0.0 < *(float *)(param_1 + 4)) {
    *(float *)(param_1 + 4) = *(float *)(param_1 + 4) - _DAT_00925018;
  }
  if (*(char *)(param_1 + 0x10) != '\0') {
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + -1;
  }
  return;
}

