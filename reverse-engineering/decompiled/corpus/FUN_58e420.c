/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58e420; label: FUN_0058e420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058e420(int param_1)

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

