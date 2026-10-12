/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54aa10; label: FUN_0054aa10
 */

void FUN_0054aa10(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f333333,0);
    if (**(int **)(param_1 + 0xca4) != 0) {
      FUN_00698900(**(int **)(param_1 + 0xca4),0x3dcccccd,0,0,0);
    }
  }
  return;
}

