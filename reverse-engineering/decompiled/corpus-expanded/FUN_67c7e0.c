/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c7e0; label: FUN_0067c7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067c7e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((-1 < param_1) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    param_1 = param_1 * 0x6c;
    if (*(float *)(*(int *)(DAT_0292fc68 + 0x68) + 0x54 + param_1) == 0.0) {
      *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + param_1 + 0x58) = 0;
      *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x5c + param_1) = 0;
    }
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x54 + param_1) = param_2;
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x60 + param_1) = param_3;
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 100 + param_1) = param_4;
  }
  return;
}

