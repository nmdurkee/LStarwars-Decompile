/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c350; label: FUN_0046c350
 */

int FUN_0046c350(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                int *param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = FUN_0056ffe0(param_1);
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  iVar2 = FUN_00566da0(param_1);
  if (param_3 != (int *)0x0) {
    *param_3 = iVar2;
  }
  iVar3 = FUN_00590b60(param_1);
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
  iVar4 = FUN_00468740(param_1);
  if (param_5 != (int *)0x0) {
    *param_5 = iVar4;
  }
  iVar5 = FUN_005592c0(param_1);
  if (param_6 != (int *)0x0) {
    *param_6 = iVar5;
  }
  iVar6 = FUN_005adf80(param_1);
  if (param_7 != (int *)0x0) {
    *param_7 = iVar6;
  }
  if ((*(int *)(param_1 + 300) == 0) || ((*(ushort *)(*(int *)(param_1 + 300) + 0x7a) & 0x100) == 0)
     ) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_0043e4b0();
  }
  if (param_8 != (int *)0x0) {
    *param_8 = iVar7;
  }
  return iVar1 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7;
}

