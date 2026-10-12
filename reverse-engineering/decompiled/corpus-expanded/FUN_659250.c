/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x659250; label: FUN_00659250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00659250(int param_1,undefined4 param_2)

{
  if (param_1 != -1) {
    *(undefined4 *)(param_1 * 0x330 + 0x32c + DAT_029620a4) = param_2;
  }
  return;
}

