/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54bf00; label: FUN_0054bf00
 */

void FUN_0054bf00(int param_1)

{
  if ((0 < param_1) && (*(int *)(DAT_00926c20 + param_1 * 4) != 0)) {
    DAT_00802368 = param_1;
  }
  return;
}

