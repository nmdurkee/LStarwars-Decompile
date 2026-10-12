/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529200; label: FUN_00529200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529200(undefined4 param_1,int param_2)

{
  undefined1 local_4;
  
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    local_4 = (undefined1)(int)ROUND(*(float *)(param_2 + 0x54));
    *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a) = local_4;
  }
  return;
}

