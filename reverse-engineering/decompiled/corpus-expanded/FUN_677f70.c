/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x677f70; label: FUN_00677f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00677f70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar2 = *(int *)(param_2 + 0x148), iVar2 != 0)) {
    if (iVar2 == param_1) {
      *(undefined4 *)(param_2 + 0x148) = *(undefined4 *)(param_1 + -4);
      return;
    }
    while (iVar1 = *(int *)(iVar2 + -4), iVar1 != param_1) {
      iVar2 = iVar1;
      if (iVar1 == 0) {
        return;
      }
    }
    *(undefined4 *)(iVar2 + -4) = *(undefined4 *)(param_1 + -4);
  }
  return;
}

