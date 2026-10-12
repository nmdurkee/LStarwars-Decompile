/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x616b50; label: FUN_00616b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00616b50(ushort *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 local_18;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar5 = 1;
  local_18 = 1;
  if (((param_2 == 0) || (*(int *)(param_2 + 0xc) < 1)) || (2 < *(int *)(param_2 + 0xc))) {
    *param_1 = *param_1 & 0xfffb;
  }
  else {
    *param_1 = *param_1 | 4;
  }
  if (param_2 == 0) {
    param_2 = in_ECX + 0xd8d8;
  }
  iVar3 = FUN_006be780(*(undefined4 *)(param_1 + 8));
  if ((*(int *)(in_ECX + 0xd5b4 + iVar3 * 4) != 0) && (param_3 == 0)) {
    iVar5 = (**(code **)**(undefined4 **)(in_ECX + 0xd5b4 + iVar3 * 4))
                      (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 6));
  }
  iVar4 = DAT_028fec2c;
  if (0.0 < _DAT_0290082c) {
    iVar4 = FUN_006e6b90();
  }
  bVar2 = true;
  if ((iVar5 != 0) || (param_3 != 0)) {
    iVar5 = 0;
    for (puVar1 = *(undefined4 **)(in_ECX + 0xd1b4 + iVar3 * 0xc); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      if ((*param_1 & 2) != 0) {
        *(ushort *)((int)puVar1 + 0xe) = *(ushort *)((int)puVar1 + 0xe) | 8;
      }
      iStack_10 = *(int *)(param_1 + 10) + iVar5;
      iStack_c = iStack_10 + (uint)*(ushort *)(puVar1 + 5);
      iVar5 = iVar5 + (uint)*(ushort *)(puVar1 + 5);
      if ((DAT_028fec10 < iVar4) && ((*(byte *)((int)puVar1 + 0xe) & 0x40) == 0)) {
        bVar2 = false;
LAB_00616c71:
        if (param_3 != 0) goto LAB_00616c75;
      }
      else {
        if (!bVar2) goto LAB_00616c71;
LAB_00616c75:
        iStack_8 = iStack_10;
        iVar3 = (**(code **)*puVar1)
                          (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 6),&iStack_10,
                           param_3,0);
        if ((iVar3 != 0) && (iVar3 = FUN_00616230(param_1,puVar1,&iStack_10,param_2), iVar3 == 0)) {
          local_18 = 0;
        }
      }
    }
  }
  if ((*param_1 & 2) != 0) {
    *param_1 = *param_1 & 0xfffd;
  }
  return local_18;
}

