/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d5760; label: FUN_006d5760
 */

int FUN_006d5760(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_ECX + 0x3c);
  if (iVar1 == param_1) {
    return param_1;
  }
  piVar2 = *(int **)(in_ECX + 0x20);
  *(int *)(in_ECX + 0x3c) = param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x20))(piVar2);
    if (param_1 == 0) {
      uVar3 = 6;
    }
    else {
      uVar3 = 5;
    }
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x34))(*(int **)(in_ECX + 0x20),DAT_00924864,uVar3);
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x1c))(*(int **)(in_ECX + 0x20));
  }
  return iVar1;
}

