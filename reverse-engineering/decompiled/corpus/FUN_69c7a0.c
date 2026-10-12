/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69c7a0; label: FUN_0069c7a0
 */

void FUN_0069c7a0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int extraout_EDX;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  int local_1a8;
  uint local_1a4;
  int local_1a0;
  undefined1 local_19c [16];
  undefined1 local_18c [16];
  uint local_17c;
  uint local_178;
  undefined1 local_16c [360];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1a8;
  if (*(int *)(param_1 + 0x58) < 2) {
    __security_check_cookie(local_4 ^ (uint)&local_1a8);
    return;
  }
  if (*(int *)(param_1 + 4) == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_1a8);
    return;
  }
  if (((param_3 < 0) || (*(int *)(param_1 + 0x14) < param_3)) ||
     ((*(int *)(param_1 + 0x14) <= param_3 && (*(uint *)(param_1 + 0x10) < param_2)))) {
    __security_check_cookie(local_4 ^ (uint)&local_1a8);
    return;
  }
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  iVar8 = param_1 + 0x78;
  FUN_0069fb50(iVar8,*(undefined4 *)(param_1 + 0x5c));
  FUN_006a2310(param_1 + 0x1e0);
  iVar1 = FUN_0069b2e0(param_2,param_3);
  if (iVar1 == 0) {
    local_1a8 = 0;
    local_1a4 = 0;
    local_1a0 = 0;
    FUN_0069ee00(local_16c,*(undefined4 *)(param_1 + 0x5c));
    FUN_0069fb00(local_16c);
    iVar1 = local_1a8;
LAB_0069c8d0:
    do {
      local_1a8 = iVar1;
      if ((*(int *)(param_1 + 0x58) < 3) || (iVar1 = FUN_0069fcc0(local_16c,local_18c), iVar1 < 1))
      {
LAB_0069c97b:
        if (local_1a8 == 0) {
          FUN_0069b340(local_19c,0xffffffff,0xffffffff);
          if (-1 < extraout_EDX) {
            if (*(int *)(param_1 + 0x58) < 3) {
LAB_0069c9e8:
              iVar2 = FUN_0069ed70(local_19c);
              iVar7 = *(int *)(param_1 + 0x34);
              iVar3 = 0;
              if (0 < iVar7) {
                piVar6 = *(int **)(param_1 + 0x40);
                do {
                  if (*piVar6 == iVar2) break;
                  iVar3 = iVar3 + 1;
                  piVar6 = piVar6 + 1;
                } while (iVar3 < iVar7);
              }
              iVar1 = local_1a8;
              if (iVar3 == iVar7) goto LAB_0069c8d0;
              *(int *)(param_1 + 0x60) = iVar3;
              *(int *)(param_1 + 0x5c) = iVar2;
              FUN_0069fb50(iVar8,iVar2);
              FUN_0069fb50(local_16c,iVar2);
              *(undefined4 *)(param_1 + 0x58) = 3;
            }
            else {
              iVar1 = FUN_0069ed70(local_19c);
              if ((*(int *)(param_1 + 0x5c) != iVar1) &&
                 (iVar1 = FUN_0069ecc0(local_19c), iVar1 != 0)) {
                FUN_0069c060();
                FUN_0069ee70(local_16c);
              }
              if (*(int *)(param_1 + 0x58) < 3) goto LAB_0069c9e8;
            }
            FUN_0069f7f0(iVar8,local_19c);
            FUN_0069f7f0(local_16c,local_19c);
            local_1a0 = FUN_0069ecd0(local_19c);
            iVar1 = local_1a8;
            goto LAB_0069c8d0;
          }
          uVar11 = FUN_0069c6b0(param_1,0xffffffff);
          uVar5 = (undefined4)uVar11;
          *(int *)(param_1 + 0x54) = (int)((ulonglong)uVar11 >> 0x20);
        }
        else {
          uVar5 = 0xffffffff;
          *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0x50) = uVar5;
        goto LAB_0069cacd;
      }
      iVar1 = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x60) * 0x20;
      if (*(int *)(iVar1 + 0x1c) == 0) {
        FUN_0069fcc0(iVar8,0);
        goto LAB_0069c97b;
      }
      iVar1 = FUN_006a13f0(iVar1,local_18c);
      if (iVar1 < 0) {
        FUN_0069fcc0(iVar8,0);
        iVar1 = 0;
      }
      else if (local_1a0 == 0) {
        if (local_1a8 != 0) {
          local_1a4 = local_1a4 + (iVar1 + local_1a8 >> 2);
        }
      }
      else {
        FUN_0069fcc0(iVar8,0);
      }
    } while ((local_17c & local_178) == 0xffffffff);
    iVar8 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x44);
    puVar4 = (uint *)(iVar8 * 0x10 + iVar1);
    uVar9 = local_17c - *puVar4;
    iVar7 = (local_178 - *(int *)(iVar8 * 0x10 + 4 + iVar1)) - (uint)(local_17c < *puVar4);
    if ((iVar7 < 1) && (iVar7 < 0)) {
      uVar9 = 0;
      iVar7 = 0;
    }
    if (0 < iVar8) {
      puVar4 = (uint *)(iVar1 + 8);
      do {
        bVar10 = CARRY4(uVar9,*puVar4);
        uVar9 = uVar9 + *puVar4;
        iVar7 = iVar7 + puVar4[1] + (uint)bVar10;
        puVar4 = puVar4 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    *(uint *)(param_1 + 0x50) = uVar9 - local_1a4;
    *(uint *)(param_1 + 0x54) = (iVar7 - ((int)local_1a4 >> 0x1f)) - (uint)(uVar9 < local_1a4);
LAB_0069cacd:
    FUN_0069ee70(local_16c);
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
    FUN_0069ee70(local_16c);
    FUN_0069c060();
  }
  __security_check_cookie(local_4 ^ (uint)&local_1a8);
  return;
}

