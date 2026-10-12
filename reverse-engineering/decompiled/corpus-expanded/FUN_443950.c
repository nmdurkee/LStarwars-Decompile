/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443950; label: FUN_00443950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443950(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((param_1 != 0 && (*(int *)(param_1 + 0x138c) != 0)))) {
    fVar1 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,*(int *)(param_3 + 0xe4) + 0x5c,
                                  local_c);
    return fVar1;
  }
  return (float10)(float)0x4e6e6b28;
}

