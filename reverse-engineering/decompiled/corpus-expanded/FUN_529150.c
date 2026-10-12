/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x529150; label: FUN_00529150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529150(undefined4 param_1,int param_2)

{
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x94) = *(undefined4 *)(param_2 + 0x54);
    if (*(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x94) <
        *(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x90)) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x94) =
           *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x90);
      FUN_0061d850(param_2,*(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x94));
    }
  }
  return;
}

