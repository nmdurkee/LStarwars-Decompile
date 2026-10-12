/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c120; label: FUN_0060c120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060c120(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar1 = param_2;
    do {
      iVar2 = iVar1 + -8;
      *(undefined4 *)((param_3 - param_2) + iVar2) = *(undefined4 *)(iVar1 + -8);
      *(undefined4 *)((param_3 - param_2) + 4 + iVar2) = *(undefined4 *)(iVar1 + -4);
      iVar1 = iVar2;
    } while (iVar2 != param_1);
  }
  return param_3 + (param_2 - param_1 >> 3) * -8;
}

