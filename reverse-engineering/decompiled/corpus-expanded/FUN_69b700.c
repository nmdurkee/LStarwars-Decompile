/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b700; label: FUN_0069b700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0069b922) */

int FUN_0069b700(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
                uint param_6,int param_7,int *param_8,int param_9,int param_10)

{
  int *piVar1;
  longlong lVar2;
  void *_Memory;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  bool bVar9;
  longlong lVar10;
  longlong lVar11;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  int local_1c;
  uint uStack_18;
  undefined1 auStack_10 [4];
  uint uStack_c;
  uint uStack_4;
  
  local_30._4_4_ = param_7;
  local_20 = param_6;
  local_1c = param_7;
  iVar4 = param_5;
  if ((param_5 <= param_7) &&
     ((uVar8 = param_4, lVar10 = CONCAT44(local_28._4_4_,(int)local_28),
      lVar2 = CONCAT44(param_7,param_6), param_5 < param_7 ||
      (lVar10 = CONCAT44(local_28._4_4_,(int)local_28), lVar2 = CONCAT44(param_7,param_6),
      param_4 < param_6)))) {
    do {
      local_30._4_4_ = (int)((ulonglong)lVar2 >> 0x20);
      local_30._0_4_ = (void *)lVar2;
      bVar9 = -1 < (int)((local_30._4_4_ - iVar4) - (uint)((void *)local_30 < uVar8));
      if ((local_30._4_4_ - iVar4 != (uint)((void *)local_30 < uVar8) && bVar9) ||
         ((local_28 = CONCAT44(iVar4,uVar8), bVar9 &&
          (local_28 = CONCAT44(iVar4,uVar8), 0xffff < (int)(void *)local_30 - uVar8)))) {
        local_28 = lVar10;
        local_30 = lVar2;
        lVar10 = __alldiv(lVar2 + CONCAT44(iVar4,uVar8),2,0);
        local_28 = lVar10;
        lVar2 = local_30;
      }
      iVar3 = (int)local_28;
      if (*param_1 == 0) {
        iVar3 = -0x81;
      }
      else {
        if ((code *)param_1[0xb1] != (code *)0x0) {
          local_30 = lVar2;
          iVar5 = (*(code *)param_1[0xb1])(*param_1,local_28,0);
          lVar2 = local_30;
          if (iVar5 != -1) {
            param_1[2] = iVar3;
            param_1[3] = local_28._4_4_;
            FUN_0069fae0(param_1 + 6);
            iVar3 = 0;
            lVar2 = local_30;
            goto LAB_0069b87d;
          }
        }
        iVar3 = -0x80;
      }
LAB_0069b87d:
      if (iVar3 != 0) {
        return iVar3;
      }
      local_30 = lVar2;
      lVar11 = FUN_0069b340(auStack_10,0xffffffff,0xffffffff);
      iVar3 = (int)((ulonglong)lVar11 >> 0x20);
      uStack_18 = (uint)lVar11;
      if (lVar11 == -0x80) {
        return -0x80;
      }
      if (-1 < lVar11) {
        iVar6 = FUN_0069ed70(auStack_10);
        iVar4 = param_5;
        uVar8 = param_4;
        iVar5 = param_9;
        piVar1 = param_8;
        if (param_8 != (int *)0x0) {
          while (iVar5 != 0) {
            if (*piVar1 == iVar6) {
              uVar8 = uStack_4 + uStack_c + uStack_18;
              iVar4 = ((int)uStack_4 >> 0x1f) + ((int)uStack_c >> 0x1f) +
                      (uint)CARRY4(uStack_4,uStack_c) + iVar3 +
                      (uint)CARRY4(uStack_4 + uStack_c,uStack_18);
              param_4 = uVar8;
              param_5 = iVar4;
              lVar10 = local_28;
              lVar2 = local_30;
              goto LAB_0069b912;
            }
            iVar5 = iVar5 + -1;
            piVar1 = piVar1 + 1;
          }
        }
      }
      lVar10 = local_28;
      lVar2 = local_28;
      if (-1 < lVar11) {
        local_20 = uStack_18;
        local_1c = iVar3;
      }
LAB_0069b912:
      local_30._4_4_ = (int)((ulonglong)lVar2 >> 0x20);
      local_28._4_4_ = (int)((ulonglong)lVar10 >> 0x20);
    } while (CONCAT44(iVar4,uVar8) < lVar2);
  }
  local_30._0_4_ = (void *)0x0;
  local_28._0_4_ = 0;
  iVar3 = FUN_0069b2e0(local_20,local_1c);
  if ((iVar3 == 0) &&
     (iVar3 = FUN_0069b5e0(param_1,&local_30), _Memory = (void *)local_30, iVar3 == 0)) {
    if ((param_7 < iVar4) || (((param_7 <= iVar4 && (param_6 <= param_4)) || ((int)local_28 == 0))))
    {
      param_1[0xd] = param_10 + 1;
      pvVar7 = _malloc((param_10 + 1) * 8 + 8);
      param_1[0xe] = (int)pvVar7;
      *(uint *)((int)pvVar7 + param_10 * 8 + 8) = param_4;
      *(int *)((int)pvVar7 + param_10 * 8 + 0xc) = iVar4;
    }
    else {
      iVar4 = FUN_0069b700(param_1,local_20,local_1c,param_1[2],param_1[3],param_6,param_7,
                           (void *)local_30,(int)local_28,param_10 + 1);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    if (_Memory != (void *)0x0) {
      _free(_Memory);
    }
    iVar4 = param_1[0xe];
    *(undefined4 *)(iVar4 + param_10 * 8) = param_2;
    *(undefined4 *)(iVar4 + 4 + param_10 * 8) = param_3;
    iVar3 = 0;
  }
  return iVar3;
}

