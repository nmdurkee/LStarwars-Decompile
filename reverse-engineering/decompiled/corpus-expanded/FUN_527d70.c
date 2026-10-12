/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527d70; label: FUN_00527d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527d70(undefined4 param_1,int param_2)

{
  if ((((param_2 != 0) && (*(int *)(param_2 + 0xc) != 0)) && (*(int *)(DAT_009238e4 + 0x4381c) != 0)
      ) && (*(int *)(DAT_009238e4 + 0x4381c) == *(int *)(DAT_009238e4 + 0x43820))) {
    FUN_005275e0();
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = 0;
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

