/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b920; label: FUN_0064b920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064b920(void)

{
  int *piVar1;
  
  piVar1 = &DAT_0291f7b4;
  do {
    if (*piVar1 != -1) {
      *piVar1 = -1;
      DAT_02920a98 = DAT_02920a98 + -1;
    }
    piVar1 = piVar1 + 0x1b;
  } while ((int)piVar1 < 0x292cfb4);
  return;
}

