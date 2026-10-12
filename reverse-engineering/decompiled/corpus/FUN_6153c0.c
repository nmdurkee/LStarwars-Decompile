/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6153c0; label: FUN_006153c0
 */

undefined4 FUN_006153c0(int param_1,int *param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  undefined4 in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  undefined4 local_4;
  
  piVar4 = (int *)*param_2;
  local_4 = 1;
  if (((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) &&
     (*(int *)(param_1 + 0xc) != *(int *)(param_1 + 8) &&
      -1 < *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8))) {
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)(in_ECX + 0xd844);
      iVar2 = 8;
      do {
        piVar1 = (int *)piVar4[-3];
        if ((piVar1 != (int *)0x0) && (*piVar4 == 3)) {
          if ((param_3 & 1) == 0) {
            FUN_0053d460(param_1);
            FUN_0060efd0(in_stack_ffffffcc,in_stack_ffffffd0);
          }
          else {
            in_stack_ffffffcc = 0x615492;
            FUN_0053d460(param_1);
            in_stack_ffffffd0 = 0x61549c;
            FUN_0060ef10();
          }
          iVar3 = (**(code **)(*piVar1 + 0x14))();
          if (iVar3 < 0x10) {
            local_4 = 0;
          }
        }
        piVar4 = piVar4 + 5;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return local_4;
    }
    if (((param_3 & 1) == 0) || ((0 < param_2[3] && (param_2[3] < 3)))) {
      FUN_0053d460(param_1);
      FUN_0060efd0(in_stack_ffffffcc,in_stack_ffffffd0);
    }
    else {
      FUN_0053d460(param_1);
      FUN_0060ef10();
    }
    iVar2 = (**(code **)(*piVar4 + 0x14))();
    if (iVar2 < 0x10) {
      return 0;
    }
  }
  return 1;
}

