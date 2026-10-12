/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5760; label: FUN_006d5760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

