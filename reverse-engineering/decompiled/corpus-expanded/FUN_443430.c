/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443430; label: FUN_00443430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443430(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if ((param_5 != 0) && (*(int *)(param_2 + 0xa4) != 0)) {
    iVar1 = *(int *)(param_2 + 0xa4) - *(int *)(param_1 + 0x28);
    iVar2 = 0;
    if (0 < *(char *)(param_5 + 0x10)) {
      do {
        if ((char)(((char)(iVar1 / 0x3c) + (char)(iVar1 >> 0x1f)) -
                  (char)((longlong)iVar1 * 0x88888889 >> 0x3f)) ==
            *(char *)(*(int *)(param_5 + 0x14) + iVar2)) {
          return (float10)1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(char *)(param_5 + 0x10));
    }
  }
  return (float10)0;
}

