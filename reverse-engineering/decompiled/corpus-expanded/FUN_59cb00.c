/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59cb00; label: FUN_0059cb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059cb00(int param_1)

{
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x2000) != 0) {
    if ((DAT_00802854 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802854)) {
      FUN_0054a3e0(0,0x3f000000,0,1);
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    *(undefined4 *)(param_1 + 0xdc4) = 0;
  }
  return;
}

