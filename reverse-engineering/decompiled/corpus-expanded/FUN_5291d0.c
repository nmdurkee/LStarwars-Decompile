/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x5291d0; label: FUN_005291d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005291d0(undefined4 param_1,int param_2)

{
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x98) = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

