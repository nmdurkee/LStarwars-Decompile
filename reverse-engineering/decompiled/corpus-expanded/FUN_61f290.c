/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f290; label: FUN_0061f290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f290(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (((param_1 != (int *)0x0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    iVar3 = -1;
    if ((*param_1 != 0) && (iVar1 = *(int *)(*param_1 + 0x24), iVar1 != 0)) {
      iVar3 = FUN_004f8b10(iVar1,param_2);
    }
    piVar2 = (int *)*param_1;
    param_1[3] = (int)piVar2;
    param_1[2] = (int)piVar2;
    iVar1 = *piVar2;
    while ((iVar1 != 0 && (iVar3 < 0))) {
      iVar3 = *(int *)param_1[2];
      param_1[2] = iVar3;
      iVar3 = *(int *)(iVar3 + 0x24);
      if (iVar3 == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = FUN_004f8b10(iVar3,param_2);
      }
      iVar1 = *(int *)param_1[2];
    }
    param_1[4] = param_1[2];
  }
  return;
}

