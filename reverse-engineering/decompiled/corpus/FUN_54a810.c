/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a810; label: FUN_0054a810
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

