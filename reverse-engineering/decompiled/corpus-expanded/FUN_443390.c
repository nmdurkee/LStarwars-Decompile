/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443390; label: FUN_00443390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443390(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_c [12];
  
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    iVar1 = **(int **)(param_3 + 0xd0);
    iVar2 = *(int *)(iVar1 + 0x10a8);
    if (iVar2 != 0) {
      fVar3 = (float10)FUN_005becc0(iVar1 + 0x5c,iVar2 + 0x5c,local_c);
      return fVar3;
    }
  }
  return (float10)(float)0x4e6e6b28;
}

