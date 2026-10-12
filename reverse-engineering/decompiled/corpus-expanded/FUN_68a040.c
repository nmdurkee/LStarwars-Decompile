/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x68a040; label: FUN_0068a040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068a040(undefined4 param_1,int param_2)

{
  if (DAT_02921884 != -1) {
    *(undefined4 *)(DAT_02921884 * 0x50 + 0x2c + DAT_02962a14) = *(undefined4 *)(param_2 + 0x54);
  }
  FUN_00689f70();
  return;
}

