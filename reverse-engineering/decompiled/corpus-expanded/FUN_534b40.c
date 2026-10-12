/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534b40; label: FUN_00534b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00534b40(undefined4 param_1,int param_2)

{
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x60) = *(undefined4 *)(param_2 + 0x54);
    FUN_0052a710();
  }
  return;
}

