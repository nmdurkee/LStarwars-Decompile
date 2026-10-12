/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x40aa00; label: FUN_0040aa00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040aa00(int param_1,undefined4 param_2)

{
  if (DAT_0093d810 != 0) {
    DAT_007f1114 = param_1;
    if (param_1 != 0) {
      DAT_007f1138 = param_2;
      DAT_007f1118 = *(undefined4 *)(DAT_0093d810 + 0x80);
      DAT_007f111c = *(undefined4 *)(DAT_0093d810 + 0x84);
      DAT_007f1120 = *(undefined4 *)(DAT_0093d810 + 0x88);
      return;
    }
    DAT_007f1138 = 0;
  }
  return;
}

