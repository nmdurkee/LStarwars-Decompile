/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b5a10; label: FUN_006b5a10
 */

/* WARNING: Type propagation algorithm not settling */

uint * FUN_006b5a10(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int **ppiVar12;
  uint *local_d34;
  int local_d30;
  int *local_d2c;
  int local_d28;
  int local_d24;
  int *local_d20;
  uint *local_d1c;
  int *local_d18;
  int *local_d14 [65];
  int *local_c10 [65];
  int local_b0c [65];
  int local_a08 [65];
  int local_904 [65];
  undefined1 local_800 [2048];
  
  iVar5 = *(int *)(param_2 + 0x504);
  local_d28 = *(int *)(param_2 + 0x510);
  uVar1 = *(undefined4 *)(param_2 + 0x508);
  local_d30 = 0;
  local_d34 = (uint *)0x0;
  if (0 < iVar5) {
    ppiVar12 = local_c10;
    for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
      *ppiVar12 = (int *)0xffffff38;
      ppiVar12 = ppiVar12 + 1;
    }
  }
  if (0 < iVar5) {
    ppiVar12 = local_d14;
    for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
      *ppiVar12 = (int *)0xffffff38;
      ppiVar12 = ppiVar12 + 1;
    }
    piVar10 = local_b0c;
    for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
    if (0 < iVar5) {
      piVar10 = local_a08;
      for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar10 = 1;
        piVar10 = piVar10 + 1;
      }
      piVar10 = local_904;
      for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar10 = -1;
        piVar10 = piVar10 + 1;
      }
    }
  }
  local_d24 = iVar5;
  if (iVar5 == 0) {
    iVar3 = FUN_006b53e0(param_3,uVar1,local_d28);
  }
  else {
    iVar7 = 0;
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      return (undefined4 *)0x0;
    }
    do {
      iVar3 = FUN_006b53e0(param_3,*(undefined4 *)(param_2 + 4 + iVar7 * 4),local_d28);
      iVar3 = local_d30 + iVar3;
      iVar7 = iVar7 + 1;
      local_d30 = iVar3;
    } while (iVar7 < iVar5 + -1);
  }
  if (iVar3 != 0) {
    local_d2c = (int *)0xffffff38;
    local_d34 = (uint *)0xffffff38;
    FUN_006b5580(local_800,iVar5 + -1,&local_d2c,&local_d34);
    local_c10[0] = local_d2c;
    local_d14[0] = local_d2c;
    local_d14[1] = (int *)local_d34;
    local_c10[1] = (int *)local_d34;
    local_d30 = 2;
    if (2 < iVar5) {
      local_d34 = (uint *)(param_2 + 0x210);
      do {
        iVar7 = local_b0c[*local_d34];
        iVar3 = local_a08[*local_d34];
        if (local_904[iVar7] != iVar3) {
          local_d20 = *(int **)(local_d28 + 0x344 + iVar7 * 4);
          local_d1c = *(uint **)(local_d28 + 0x344 + iVar3 * 4);
          iVar5 = *(int *)(param_2 + 0x208 + iVar7 * 4);
          iVar2 = *(int *)(param_2 + 0x208 + iVar3 * 4);
          piVar10 = local_c10[iVar7];
          piVar6 = local_d14[iVar7];
          local_904[iVar7] = iVar3;
          piVar11 = piVar6;
          if ((-1 < (int)piVar10) && (piVar11 = piVar10, -1 < (int)piVar6)) {
            piVar11 = (int *)((int)piVar6 + (int)piVar10 >> 1);
          }
          piVar10 = local_c10[iVar3];
          if ((int)piVar10 < 0) {
            piVar10 = local_d14[iVar3];
          }
          else if (-1 < (int)local_d14[iVar3]) {
            piVar10 = (int *)((int)piVar10 + (int)local_d14[iVar3] >> 1);
          }
          if ((piVar11 == (int *)0xffffffff) || (piVar10 == (int *)0xffffffff)) {
                    /* WARNING: Subroutine does not return */
            _exit(1);
          }
          iVar4 = FUN_006b5760(local_d1c,piVar11,param_4,param_3,local_d28);
          if (iVar4 == 0) {
            local_c10[local_d30] = (int *)0xffffff38;
            local_d14[local_d30] = (int *)0xffffff38;
            iVar5 = local_d24;
          }
          else {
            local_d2c = (int *)0xffffff38;
            local_d18 = (int *)0xffffff38;
            local_d20 = (int *)0xffffff38;
            local_d1c = (uint *)0xffffff38;
            FUN_006b5580(local_800 + iVar5 * 0x20,*local_d34 - iVar5,&local_d2c,&local_d18);
            uVar9 = *local_d34;
            FUN_006b5580(local_800 + uVar9 * 0x20,iVar2 - uVar9,&local_d20,&local_d1c);
            local_d14[iVar7] = local_d2c;
            if (iVar7 == 0) {
              local_c10[0] = local_d2c;
            }
            local_c10[local_d30] = local_d18;
            local_d14[local_d30] = local_d20;
            local_c10[iVar3] = (int *)local_d1c;
            if (iVar3 == 1) {
              local_d14[1] = (int *)local_d1c;
            }
            iVar5 = local_d24;
            if ((-1 < (int)local_d18) || (-1 < (int)local_d20)) {
              while ((uVar9 = uVar9 - 1, -1 < (int)uVar9 && (local_a08[uVar9] == iVar3))) {
                local_a08[uVar9] = local_d30;
              }
              uVar9 = *local_d34;
              while ((uVar9 = uVar9 + 1, (int)uVar9 < local_d24 && (local_b0c[uVar9] == iVar7))) {
                local_b0c[uVar9] = local_d30;
              }
            }
          }
        }
        local_d34 = local_d34 + 1;
        local_d30 = local_d30 + 1;
      } while (local_d30 < iVar5);
    }
    piVar6 = local_c10[0];
    piVar10 = local_d14[0];
    local_d34 = (uint *)FUN_006a1550(param_1,iVar5 * 4);
    piVar11 = piVar10;
    if ((-1 < (int)piVar6) && (piVar11 = piVar6, -1 < (int)piVar10)) {
      piVar11 = (int *)((int)piVar6 + (int)piVar10 >> 1);
    }
    *local_d34 = (uint)piVar11;
    puVar8 = (uint *)local_d14[1];
    if ((-1 < (int)local_c10[1]) && (puVar8 = (uint *)local_c10[1], -1 < (int)local_d14[1])) {
      puVar8 = (uint *)((int)local_c10[1] + (int)local_d14[1] >> 1);
    }
    local_d34[1] = (uint)puVar8;
    local_d30 = 2;
    if (2 < iVar5) {
      local_d2c = (int *)(local_d28 + 0x34c);
      piVar10 = (int *)(param_2 + 0x30c);
      do {
        iVar5 = *(int *)(local_d28 + 0x344 + piVar10[0x3f] * 4);
        uVar9 = (local_d34[*piVar10] & 0x7fff) - (local_d34[piVar10[0x3f]] & 0x7fff);
        iVar5 = (int)(((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)) * (*local_d2c - iVar5))
                / (*(int *)(local_d28 + 0x344 + *piVar10 * 4) - iVar5);
        if ((int)uVar9 < 0) {
          iVar5 = -iVar5;
        }
        piVar11 = (int *)((local_d34[piVar10[0x3f]] & 0x7fff) + iVar5);
        piVar6 = local_c10[local_d30];
        if ((int)piVar6 < 0) {
          piVar6 = local_d14[local_d30];
        }
        else if (-1 < (int)local_d14[local_d30]) {
          piVar6 = (int *)((int)piVar6 + (int)local_d14[local_d30] >> 1);
        }
        if (((int)piVar6 < 0) || (piVar11 == piVar6)) {
          local_d34[local_d30] = (uint)piVar11 | 0x8000;
        }
        else {
          local_d34[local_d30] = (uint)piVar6;
        }
        local_d2c = local_d2c + 1;
        local_d30 = local_d30 + 1;
        piVar10 = piVar10 + 1;
      } while (local_d30 < local_d24);
    }
  }
  return local_d34;
}

