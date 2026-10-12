/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4fe390; label: FUN_004fe390
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fe390(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int iVar7;
  void *pvVar8;
  int iVar9;
  short *psVar10;
  int local_10c;
  int *local_108;
  short local_104;
  short local_102 [127];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  local_108 = param_2;
  if ((uint)(param_3 - *param_2) < 0x100000) {
    param_1 = FUN_004ef790(param_1);
    param_3 = extraout_ECX;
  }
  param_3 = param_3 + -0x100000;
  iVar4 = FUN_004fd5d0(param_1,param_3,0x100000);
  local_10c = 0;
  if (0 < iVar4) {
    iVar7 = 0;
    piVar5 = &DAT_02983750;
    do {
      if (*piVar5 == 0) {
        iVar1 = iVar7 * 0x14;
        *(int *)(&DAT_02983744 + iVar1) = iVar4 + -1 + param_3;
        iVar9 = iVar7 + 0x400;
        *(int *)(&DAT_02983740 + iVar1) = param_3;
        *(int *)(&DAT_02983748 + iVar1) = param_3;
        *(undefined4 *)(iVar1 + 0x298374c) = 0;
        (&DAT_02983750)[iVar7 * 5] = 1;
        if (iVar9 != 0) {
          puVar6 = (undefined4 *)FUN_004fc750(iVar9);
          if (puVar6 != (undefined4 *)0x0) {
            do {
              iVar7 = FUN_004f7fb0(puVar6);
              if (0 < iVar7) {
                local_10c = local_10c + 1;
              }
              iVar7 = FUN_004fc5b0(puVar6);
            } while (iVar7 != 0);
            *puVar6 = 0;
          }
          FUN_004f99e0(iVar9);
          param_2 = local_108;
        }
        break;
      }
      piVar5 = piVar5 + 5;
      iVar7 = iVar7 + 1;
    } while ((int)piVar5 < 0x29838e0);
  }
  pvVar8 = (void *)(*param_2 + 3U & 0xfffffffc);
  DAT_0091eef8 = pvVar8;
  *param_2 = (*param_2 + 3U & 0xfffffffc) + 4 + local_10c * 4;
  _memset(pvVar8,0,local_10c * 4 + 4);
  iVar7 = 0;
  if (0 < iVar4) {
    iVar9 = 0;
    piVar5 = &DAT_02983750;
    do {
      if (*piVar5 == 0) {
        iVar3 = iVar9 * 0x14;
        iVar1 = iVar9 + 0x400;
        *(int *)(&DAT_02983740 + iVar3) = param_3;
        *(int *)(&DAT_02983744 + iVar3) = iVar4 + -1 + param_3;
        *(int *)(&DAT_02983748 + iVar3) = param_3;
        *(undefined4 *)(iVar3 + 0x298374c) = 0;
        (&DAT_02983750)[iVar9 * 5] = 1;
        if (iVar1 != 0) {
          puVar6 = (undefined4 *)FUN_004fc750(iVar1);
          if (puVar6 != (undefined4 *)0x0) {
            do {
              iVar4 = FUN_004f7fb0(puVar6);
              if (0 < iVar4) {
                FUN_004f2f20(&local_104,puVar6[0x144]);
                pvVar8 = DAT_0091eef8;
                iVar4 = 0;
                psVar10 = &local_104;
                sVar2 = local_104;
                while (sVar2 != 0) {
                  psVar10 = psVar10 + 1;
                  iVar4 = iVar4 + 1;
                  sVar2 = *psVar10;
                }
                iVar9 = iVar4;
                if (iVar4 < 4) {
                  while (-1 < iVar9) {
                    local_102[iVar9] = local_102[iVar9 + -1];
                    iVar9 = iVar9 + -1;
                  }
                  local_104 = 0x21;
                  iVar4 = iVar4 + 1;
                }
                *(uint *)((int)DAT_0091eef8 + iVar7 * 4) = *param_2 + 1U & 0xfffffffe;
                *param_2 = (*param_2 + 1U & 0xfffffffe) + 2 + iVar4 * 2;
                FUN_004f26e0(*(undefined4 *)((int)pvVar8 + iVar7 * 4),&local_104);
                iVar7 = iVar7 + 1;
              }
              iVar4 = FUN_004fc5b0(puVar6);
            } while ((iVar4 != 0) && (iVar7 < local_10c));
            *puVar6 = 0;
          }
          FUN_004f99e0(iVar1);
        }
        break;
      }
      piVar5 = piVar5 + 5;
      iVar9 = iVar9 + 1;
    } while ((int)piVar5 < 0x29838e0);
  }
  _DAT_0091eefc = iVar7;
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

