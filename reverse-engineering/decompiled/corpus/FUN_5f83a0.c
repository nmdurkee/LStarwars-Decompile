/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f83a0; label: FUN_005f83a0
 */

void FUN_005f83a0(int *param_1,int param_2)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_ESI;
  uint unaff_EDI;
  undefined1 local_20 [12];
  undefined2 uStack_14;
  undefined2 uStack_10;
  
  iVar3 = FUN_005e5310(param_2);
  piVar1 = *(int **)(iVar3 + 0x24);
  *param_1 = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    _memset(param_1,0,0x30);
    return;
  }
  (**(code **)(*piVar1 + 0x44))(piVar1,0,local_20);
  *(undefined2 *)((int)param_1 + 6) = uStack_10;
  *(undefined2 *)(param_1 + 1) = uStack_14;
  *(undefined2 *)(param_1 + 2) = 0;
  uVar2 = (**(code **)(*(int *)*param_1 + 0x34))((int *)*param_1);
  *(undefined2 *)((int)param_1 + 10) = uVar2;
  *(undefined2 *)(param_1 + 3) = uVar2;
  param_1[4] = 1;
  iVar3 = FUN_005f79e0();
  param_1[5] = iVar3;
  param_1[0xb] = param_2;
  param_1[6] = unaff_EDI & 1;
  param_1[7] = unaff_ESI;
  param_1[9] = 0;
  param_1[8] = (int)&DAT_012449d0;
  return;
}

