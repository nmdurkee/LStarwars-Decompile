/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b5f80; label: FUN_006b5f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006b5f80(undefined4 param_1,int param_2,int param_3,int *param_4,void *param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int *local_164;
  int local_15c;
  uint local_158;
  uint *local_154;
  int local_144 [16];
  int local_104 [65];
  
  piVar2 = *(int **)(param_3 + 0x510);
  local_15c = *(int *)(param_3 + 0x504);
  iVar18 = *(int *)(*(int *)(*(int *)(param_2 + 0x40) + 4) + 0x1c);
  iVar11 = *(int *)(iVar18 + 0xb20);
  if (param_4 == (int *)0x0) {
    FUN_006a3570(param_1,0,1);
    _memset(param_5,0,(*(int *)(param_2 + 0x24) / 2) * 4);
    _DAT_02973a08 = _DAT_02973a08 + 1;
    return 0;
  }
  iVar17 = 0;
  if (0 < local_15c) {
    do {
      uVar8 = param_4[iVar17] & 0x7fff;
      switch(piVar2[0xd0]) {
      case 1:
        uVar8 = (int)uVar8 >> 2;
        break;
      case 2:
        uVar8 = (int)uVar8 >> 3;
        break;
      case 3:
        uVar8 = uVar8 / 0xc;
        break;
      case 4:
        uVar8 = (int)uVar8 >> 4;
      }
      param_4[iVar17] = param_4[iVar17] & 0x8000U | uVar8;
      iVar17 = iVar17 + 1;
    } while (iVar17 < local_15c);
  }
  iVar17 = *param_4;
  iVar14 = param_4[1];
  if (2 < local_15c) {
    local_164 = piVar2 + 0xd3;
    local_154 = (uint *)(param_4 + 2);
    piVar15 = (int *)(param_3 + 0x30c);
    local_15c = local_15c + -2;
    do {
      iVar6 = piVar15[0x3f];
      iVar10 = *piVar15;
      uVar16 = param_4[iVar6] & 0x7fff;
      uVar8 = (param_4[iVar10] & 0x7fffU) - uVar16;
      iVar3 = (int)(((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) *
                   (*local_164 - piVar2[iVar6 + 0xd1])) /
              (piVar2[iVar10 + 0xd1] - piVar2[iVar6 + 0xd1]);
      if ((int)uVar8 < 0) {
        iVar3 = -iVar3;
      }
      uVar9 = uVar16 + iVar3;
      uVar8 = *local_154;
      if (((uVar8 & 0x8000) == 0) && (uVar9 != uVar8)) {
        uVar12 = *(int *)(param_3 + 0x50c) - uVar9;
        if ((int)uVar9 <= (int)uVar12) {
          uVar12 = uVar9;
        }
        iVar3 = uVar8 - uVar9;
        if (iVar3 < 0) {
          if (iVar3 < (int)-uVar12) {
            iVar3 = (uVar12 - iVar3) + -1;
          }
          else {
            iVar3 = iVar3 * -2 + -1;
          }
        }
        else if (iVar3 < (int)uVar12) {
          iVar3 = iVar3 * 2;
        }
        else {
          iVar3 = iVar3 + uVar12;
        }
        *(int *)(((int)local_104 - (int)param_4) + (int)local_154) = iVar3;
        param_4[iVar6] = uVar16;
        param_4[iVar10] = param_4[iVar10] & 0x7fff;
      }
      else {
        *local_154 = uVar9 | 0x8000;
        *(undefined4 *)(((int)local_104 - (int)param_4) + (int)local_154) = 0;
      }
      piVar15 = piVar15 + 1;
      local_164 = local_164 + 1;
      local_154 = local_154 + 1;
      local_15c = local_15c + -1;
    } while (local_15c != 0);
  }
  local_104[0] = iVar17;
  local_104[1] = iVar14;
  FUN_006a3570(param_1,1,1);
  *(int *)(param_3 + 0x51c) = *(int *)(param_3 + 0x51c) + 1;
  iVar17 = 0;
  uVar16 = *(int *)(param_3 + 0x50c) - 1;
  for (uVar8 = uVar16; uVar8 != 0; uVar8 = uVar8 >> 1) {
    iVar17 = iVar17 + 1;
  }
  *(int *)(param_3 + 0x518) = *(int *)(param_3 + 0x518) + iVar17 * 2;
  iVar17 = 0;
  for (; uVar16 != 0; uVar16 = uVar16 >> 1) {
    iVar17 = iVar17 + 1;
  }
  FUN_006a3570(param_1,local_104[0],iVar17);
  iVar17 = 0;
  for (uVar8 = *(int *)(param_3 + 0x50c) - 1; uVar8 != 0; uVar8 = uVar8 >> 1) {
    iVar17 = iVar17 + 1;
  }
  FUN_006a3570(param_1,local_104[1],iVar17);
  local_154 = (uint *)0x0;
  local_164 = (int *)0x2;
  piVar15 = piVar2;
  if (0 < *piVar2) {
    do {
      iVar17 = piVar15[1];
      iVar14 = piVar2[iVar17 + 0x20];
      iVar6 = piVar2[iVar17 + 0x30];
      iVar3 = 1 << ((byte)iVar6 & 0x1f);
      iVar10 = 0;
      local_144[0] = 0;
      local_144[1] = 0;
      local_144[2] = 0;
      local_144[3] = 0;
      local_144[4] = 0;
      local_144[5] = 0;
      local_144[6] = 0;
      local_144[7] = 0;
      local_158 = 0;
      if (iVar6 != 0) {
        iVar4 = 0;
        if (0 < iVar3) {
          piVar13 = piVar2 + (iVar17 + 10) * 8;
          do {
            if (*piVar13 < 0) {
              local_144[iVar4 + 8] = 1;
            }
            else {
              local_144[iVar4 + 8] = *(int *)(*(int *)(iVar18 + 0x720 + *piVar13 * 4) + 4);
            }
            iVar4 = iVar4 + 1;
            piVar13 = piVar13 + 1;
          } while (iVar4 < iVar3);
        }
        iVar4 = 0;
        if (0 < iVar14) {
          piVar13 = local_104 + (int)local_164;
          do {
            iVar5 = 0;
            if (0 < iVar3) {
              do {
                if (*piVar13 < local_144[iVar5 + 8]) {
                  local_144[iVar4] = iVar5;
                  break;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < iVar3);
            }
            piVar1 = local_144 + iVar4;
            bVar7 = (byte)iVar10;
            iVar4 = iVar4 + 1;
            iVar10 = iVar10 + iVar6;
            piVar13 = piVar13 + 1;
            local_158 = local_158 | *piVar1 << (bVar7 & 0x1f);
          } while (iVar4 < iVar14);
        }
        iVar6 = FUN_006a96a0(piVar2[iVar17 + 0x40] * 0x2c + iVar11,local_158,param_1);
        *(int *)(param_3 + 0x514) = *(int *)(param_3 + 0x514) + iVar6;
      }
      iVar6 = 0;
      if (0 < iVar14) {
        piVar13 = local_104 + (int)local_164;
        do {
          if (-1 < piVar2[local_144[iVar6] + iVar17 * 8 + 0x50]) {
            iVar10 = piVar2[local_144[iVar6] + iVar17 * 8 + 0x50] * 0x2c + iVar11;
            if (*piVar13 < *(int *)(iVar10 + 4)) {
              iVar10 = FUN_006a96a0(iVar10,*piVar13,param_1);
              *(int *)(param_3 + 0x518) = *(int *)(param_3 + 0x518) + iVar10;
            }
          }
          iVar6 = iVar6 + 1;
          piVar13 = piVar13 + 1;
        } while (iVar6 < iVar14);
      }
      local_164 = (int *)((int)local_164 + iVar14);
      local_154 = (uint *)((int)local_154 + 1);
      piVar15 = piVar15 + 1;
    } while ((int)local_154 < *piVar2);
  }
  iVar11 = piVar2[0xd0] * *param_4;
  iVar18 = 0;
  local_164 = (int *)0x1;
  if (1 < *(int *)(param_3 + 0x504)) {
    piVar15 = (int *)(param_3 + 0x108);
    iVar17 = 0;
    do {
      uVar8 = param_4[*piVar15] & 0x7fff;
      iVar14 = iVar17;
      if (uVar8 == param_4[*piVar15]) {
        iVar14 = piVar2[*piVar15 + 0xd1];
        iVar11 = piVar2[0xd0] * uVar8;
        FUN_006b5350(iVar17,iVar14,param_5);
        iVar18 = iVar14;
      }
      local_164 = (int *)((int)local_164 + 1);
      piVar15 = piVar15 + 1;
      iVar17 = iVar14;
    } while ((int)local_164 < *(int *)(param_3 + 0x504));
  }
  if (iVar18 < *(int *)(param_2 + 0x24) / 2) {
    do {
      *(int *)((int)param_5 + iVar18 * 4) = iVar11;
      iVar18 = iVar18 + 1;
    } while (iVar18 < *(int *)(param_2 + 0x24) / 2);
  }
  _DAT_02973a08 = _DAT_02973a08 + 1;
  return 1;
}

