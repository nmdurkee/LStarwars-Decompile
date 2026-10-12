/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505e50; label: FUN_00505e50
 */

void FUN_00505e50(int param_1)

{
  if (param_1 != 0) {
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffffeff8;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xffffefbf;
    *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    if (*(float *)(param_1 + 0x98) < 0.0) {
      *(float *)(param_1 + 0x98) = -*(float *)(param_1 + 0x98);
    }
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x5c);
    if (*(int *)(param_1 + 0xa0) != 0) {
      FUN_00502670(*(int *)(param_1 + 0xa0),*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x14));
    }
    if (*(int *)(param_1 + 0xa8) != 0) {
      FUN_00501590(param_1);
    }
    if (*(int *)(param_1 + 0xac) != 0) {
      FUN_00503820();
    }
    if ((*(int *)(param_1 + 0xa4) != 0) && (DAT_009213a0 != (code *)0x0)) {
      (*DAT_009213a0)(param_1);
    }
    if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
      DAT_00921359 = 0;
    }
  }
  return;
}

