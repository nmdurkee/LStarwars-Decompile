/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505e10; label: FUN_00505e10
 */

void FUN_00505e10(int param_1)

{
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffffeff9;
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_00502d60();
  }
  if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

