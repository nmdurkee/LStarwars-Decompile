/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a510; label: FUN_0054a510
 */

int FUN_0054a510(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  return ((int)ROUND(*(float *)(param_1 + 0x218)) & 0xffffU) + *(int *)(param_1 + 0x1fc);
}

