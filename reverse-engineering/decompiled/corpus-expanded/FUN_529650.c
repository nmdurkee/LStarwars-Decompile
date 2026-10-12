/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529650; label: FUN_00529650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529650(undefined4 param_1,int param_2)

{
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0) = *(undefined4 *)(param_2 + 0x54);
    if (*(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x9c) <
        *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0)) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0) =
           *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x9c);
      FUN_0061d850(param_2,*(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0));
    }
  }
  return;
}

