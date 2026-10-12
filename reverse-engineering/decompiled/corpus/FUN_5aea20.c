/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5aea20; label: FUN_005aea20
 */

undefined4 FUN_005aea20(int param_1)

{
  if (param_1 != 0) {
    if (*(float *)(param_1 + 0x40) < 0.0) {
      return 1;
    }
    if (0.0 < *(float *)(param_1 + 0x40)) {
      return 0;
    }
  }
  return 0xffffffff;
}

