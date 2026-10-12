/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e480; label: FUN_0058e480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058e480(int param_1)

{
  if ((DAT_00802820 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802820)) {
    if (0.0 < *(float *)(param_1 + 0x77c)) {
      *(float *)(param_1 + 0x77c) = *(float *)(param_1 + 0x77c) - _DAT_00925018;
      return;
    }
    if ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c) == 0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
  }
  return;
}

