/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d90c0; label: FUN_005d90c0
 */

void FUN_005d90c0(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_2 != 0) {
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

