/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443650; label: FUN_00443650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443650(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(byte *)(*(int *)(param_3 + 0xd0) + 0xe24) & 1) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

