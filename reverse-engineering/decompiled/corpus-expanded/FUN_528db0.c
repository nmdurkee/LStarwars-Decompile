/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528db0; label: FUN_00528db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00528db0(undefined4 param_1,int param_2)

{
  undefined1 local_4;
  
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    local_4 = (undefined1)(int)ROUND(*(float *)(param_2 + 0x54));
    *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8c) = local_4;
  }
  return;
}

