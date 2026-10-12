/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443050; label: FUN_00443050
 */

float10 FUN_00443050(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_5 == 0) {
    if (param_4 == 0) {
      if ((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0))
      goto LAB_004430b5;
      piVar1 = (int *)*piVar3;
LAB_004430ce:
      if (piVar1 == (int *)0x0) goto LAB_004430b5;
      param_5 = *piVar3;
    }
    else {
      iVar2 = FUN_004f8b10(param_4,"Opponent");
      if (iVar2 == 0) {
        piVar3 = *(int **)(**(int **)(param_3 + 0xd0) + 0x3ac);
        piVar1 = piVar3;
        goto LAB_004430ce;
      }
      iVar2 = FUN_004f8b10(param_4,"TakeoverTarget");
      if (((iVar2 != 0) || (**(int **)(param_3 + 0xd0) == 0)) ||
         (param_5 = *(int *)(**(int **)(param_3 + 0xd0) + 0xea4), param_5 == 0)) goto LAB_004430b5;
    }
    if (param_5 == 0) goto LAB_004430b5;
  }
  if ((*(int *)(param_5 + 0xcd0) != 0) && (*(char *)(param_5 + 0x7b5) != ';')) {
    return (float10)1;
  }
LAB_004430b5:
  return (float10)0;
}

