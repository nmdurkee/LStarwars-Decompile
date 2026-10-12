/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443770; label: FUN_00443770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443770(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int iVar1;
  
  if ((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xd0), iVar1 != 0)) {
    if (param_5 == 2) {
      if ((*(uint *)(iVar1 + 0x1f8) & 0x10000) != 0) {
        return (float10)1;
      }
    }
    else if (param_5 == 1) {
      if ((*(byte *)(iVar1 + 0x1f8) & 5) == 0) {
LAB_004437a8:
        return (float10)1;
      }
    }
    else if (param_5 == -1) {
      if ((*(byte *)(iVar1 + 0x1f8) & 1) != 0) {
        return (float10)1;
      }
    }
    else if ((param_5 == 0) && ((*(byte *)(iVar1 + 0x1f8) & 4) != 0)) goto LAB_004437a8;
  }
  return (float10)0;
}

