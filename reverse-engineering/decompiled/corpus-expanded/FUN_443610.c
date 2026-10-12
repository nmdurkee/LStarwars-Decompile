/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443610; label: FUN_00443610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443610(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  float10 fVar2;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(int *)(*piVar1 + 0xea4) != 0)) {
    fVar2 = (float10)FUN_005becc0(*(int *)(*piVar1 + 0xea4) + 0x5c,piVar1 + 0x17,0);
    return fVar2;
  }
  return (float10)(float)0x4e6e6b28;
}

