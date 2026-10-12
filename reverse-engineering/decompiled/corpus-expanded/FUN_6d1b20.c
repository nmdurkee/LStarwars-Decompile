/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d1b20; label: FUN_006d1b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d1b20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int iStack_24;
  int iStack_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_006d0e10();
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))();
  }
  if (*(int *)(in_ECX + 0x34) != 0) {
    iVar3 = FUN_006c9df0(in_ECX + 0x30);
    if (iVar3 == 0) {
      FUN_006c94a0(in_ECX + 0x30,*(undefined4 *)(in_ECX + 0x3c));
    }
  }
  if (0 < *(int *)(in_ECX + 0x2c)) {
    puVar1 = (undefined4 *)(in_ECX + 0x24);
    if (*(int *)(in_ECX + 0x20) == 0) {
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        FUN_006c94a0(puVar2 + 2,0xff800000);
      }
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x20) + 4))(puVar1);
    }
    for (puVar1 = (undefined4 *)*puVar1; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1
        ) {
      iVar3 = puVar1[2];
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
        (**(code **)(**(int **)(iVar3 + 0x14) + 0x3c))(puVar1[3],1);
      }
    }
  }
  iStack_24 = 0;
  if (0 < DAT_02973bac) {
    iStack_20 = 0;
    do {
      if ((iStack_24 < 0) || (DAT_02973bac <= iStack_24)) {
        iVar3 = 0;
      }
      else {
        iVar3 = iStack_20 + DAT_02973b90;
      }
      local_1c = iVar3;
      if ((((*(uint *)(in_ECX + 0x6c) & 1 << ((byte)iStack_24 & 0x1f)) != 0) &&
          (*(int *)(iVar3 + 0x14) != 0)) && ((*(uint *)(iVar3 + 4) & 0x8000080) != 0)) {
        for (iVar4 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x14))(0); iVar4 != 0;
            iVar4 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x14))(iVar4)) {
          local_18 = iVar4;
          iVar5 = FUN_006c8b60(iVar4,iVar3,0xffffffff);
          if (iVar5 != 0) {
            if ((*(uint *)(iVar3 + 4) & 0x8000000) != 0) {
              for (puVar1 = *(undefined4 **)(in_ECX + 0x24); puVar1 != (undefined4 *)0x0;
                  puVar1 = (undefined4 *)*puVar1) {
                if ((puVar1[3] == iVar4) && (puVar1[4] == 0)) goto LAB_006d1c87;
              }
              if (*(int *)(iVar3 + 0x14) != 0) {
                (**(code **)(**(int **)(iVar3 + 0x14) + 0x3c))(iVar4,0);
              }
            }
LAB_006d1c87:
            if ((*(byte *)(iVar3 + 4) & 0x80) != 0) {
              for (puVar1 = *(undefined4 **)(in_ECX + 0x24); puVar1 != (undefined4 *)0x0;
                  puVar1 = (undefined4 *)*puVar1) {
                if ((puVar1[3] == iVar4) && (puVar1[4] == 0)) {
                  if (iVar4 != *(int *)(in_ECX + 0x34)) {
                    FUN_006c94a0(&local_1c,0xff000080);
                  }
                  break;
                }
              }
            }
          }
        }
        local_18 = 0;
      }
      iStack_24 = iStack_24 + 1;
      iStack_20 = iStack_20 + 0x18;
    } while (iStack_24 < DAT_02973bac);
  }
  if (*(int *)(in_ECX + 0x4c) != 0) {
    FUN_00626b50(*(int *)(in_ECX + 0x4c));
  }
  return;
}

