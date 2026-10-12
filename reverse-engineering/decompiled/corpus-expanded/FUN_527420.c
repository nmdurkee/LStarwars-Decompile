/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527420; label: FUN_00527420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527420(void)

{
  if (DAT_009242b4 != (code *)0x0) {
    (*DAT_009242b4)(DAT_009238e4 + 0x28);
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

