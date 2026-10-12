/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x7115af; label: ___ld12mul
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___ld12mul
   
   Library: Visual Studio 2005 Release */

void ___ld12mul(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  ushort uVar7;
  uint uVar8;
  ushort uVar9;
  short *psVar10;
  ushort uVar11;
  ushort uVar12;
  int local_34;
  int local_30;
  ushort *local_2c;
  ushort *local_28;
  int local_24;
  int local_1c;
  uint local_18;
  byte local_14;
  undefined1 uStack_13;
  ushort uStack_12;
  short local_10;
  undefined4 uStack_e;
  ushort uStack_a;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_24 = 0;
  local_10 = 0;
  iVar4 = 0;
  uStack_e._0_2_ = 0;
  uStack_e._2_2_ = 0;
  iVar5 = 0;
  uStack_a = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar9 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar12 = uVar9 + uVar7;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  iVar2 = 0;
  iVar3 = 0;
  if (((uVar7 < 0x7fff) && (iVar2 = 0, iVar3 = 0, uVar9 < 0x7fff)) &&
     (iVar2 = iVar4, iVar3 = iVar5, uVar12 < 0xbffe)) {
    if (uVar12 < 0x3fc0) {
LAB_0071161e:
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
      goto LAB_00711814;
    }
    if (((uVar7 == 0) && (uVar12 = uVar12 + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
       ((param_1[1] == 0 && (*param_1 == 0)))) {
      *(undefined2 *)((int)param_1 + 10) = 0;
      goto LAB_00711814;
    }
    if (((uVar9 == 0) && (uVar12 = uVar12 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
       ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_0071161e;
    local_30 = 0;
    psVar10 = &local_10;
    local_1c = 5;
    do {
      local_34 = local_1c;
      if (0 < local_1c) {
        local_2c = (ushort *)(param_2 + 2);
        local_28 = (ushort *)(local_30 * 2 + (int)param_1);
        do {
          bVar6 = false;
          uVar1 = *(uint *)(psVar10 + -2) + (uint)*local_28 * (uint)*local_2c;
          if ((uVar1 < *(uint *)(psVar10 + -2)) || (uVar1 < (uint)*local_28 * (uint)*local_2c)) {
            bVar6 = true;
          }
          *(uint *)(psVar10 + -2) = uVar1;
          if (bVar6) {
            *psVar10 = *psVar10 + 1;
          }
          local_28 = local_28 + 1;
          local_2c = local_2c + -1;
          local_34 = local_34 + -1;
        } while (0 < local_34);
      }
      uVar1 = CONCAT22((ushort)uStack_e,local_10);
      psVar10 = psVar10 + 1;
      local_30 = local_30 + 1;
      local_1c = local_1c + -1;
    } while (0 < local_1c);
    uVar12 = uVar12 + 0xc002;
    uVar8 = uVar1;
    if ((short)uVar12 < 1) {
LAB_00711738:
      uStack_12 = 0;
      uStack_13 = 0;
      local_14 = 0;
      uVar12 = uVar12 - 1;
      uVar8 = uVar1;
      if ((short)uVar12 < 0) {
        local_18 = (uint)(ushort)-uVar12;
        uVar12 = 0;
        do {
          if ((local_14 & 1) != 0) {
            local_24 = local_24 + 1;
          }
          iVar2 = CONCAT22(uStack_a,uStack_e._2_2_);
          uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
          uStack_a = uStack_a >> 1;
          uStack_e._0_2_ = (ushort)(uVar1 >> 0x11) | (ushort)((uint)(iVar2 << 0x1f) >> 0x10);
          uVar8 = CONCAT22(uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
          uStack_12 = uStack_12 >> 1 | (ushort)((uVar1 << 0x1f) >> 0x10);
          local_18 = local_18 - 1;
          local_10 = (short)(uVar1 >> 1);
          uVar1 = CONCAT22((ushort)uStack_e,local_10);
          local_14 = (byte)uVar8;
          uStack_13 = (undefined1)(uVar8 >> 8);
        } while (local_18 != 0);
        uVar8 = CONCAT22((ushort)uStack_e,local_10);
        if (local_24 != 0) {
          local_14 = local_14 | 1;
          uVar8 = uVar1;
        }
      }
    }
    else {
      do {
        uVar1 = uVar8;
        if ((uStack_a & 0x8000) != 0) break;
        uVar1 = uVar8 * 2;
        iVar2 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
        uStack_e._2_2_ = (ushort)iVar2 | (ushort)(uVar8 >> 0x1f);
        uVar12 = uVar12 - 1;
        uStack_a = (ushort)((uint)iVar2 >> 0x10);
        uVar8 = uVar1;
      } while (0 < (short)uVar12);
      uStack_12 = 0;
      uStack_13 = 0;
      local_14 = 0;
      uVar8 = uVar1;
      if ((short)uVar12 < 1) goto LAB_00711738;
    }
    uStack_e._0_2_ = (ushort)(uVar8 >> 0x10);
    local_10 = (short)uVar8;
    if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
       (iVar3 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e), iVar2 = CONCAT22(local_10,uStack_12),
       (CONCAT22(uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
      if (CONCAT22(local_10,uStack_12) == -1) {
        iVar2 = 0;
        if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
          if (uStack_a == 0xffff) {
            uStack_a = 0x8000;
            uVar12 = uVar12 + 1;
            iVar3 = 0;
            iVar2 = 0;
          }
          else {
            uStack_a = uStack_a + 1;
            iVar3 = 0;
            iVar2 = 0;
          }
        }
        else {
          iVar3 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
        }
      }
      else {
        iVar2 = CONCAT22(local_10,uStack_12) + 1;
        iVar3 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
      }
    }
    local_10 = (short)((uint)iVar2 >> 0x10);
    uStack_12 = (ushort)iVar2;
    uStack_e._2_2_ = (ushort)((uint)iVar3 >> 0x10);
    uStack_e._0_2_ = (ushort)iVar3;
    if (uVar12 < 0x7fff) {
      *(ushort *)param_1 = uStack_12;
      *(uint *)((int)param_1 + 2) = CONCAT22((ushort)uStack_e,local_10);
      *(uint *)((int)param_1 + 6) = CONCAT22(uStack_a,uStack_e._2_2_);
      *(ushort *)((int)param_1 + 10) = uVar12 | uVar11;
      goto LAB_00711814;
    }
  }
  param_1[1] = 0;
  *param_1 = 0;
  param_1[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
LAB_00711814:
  local_10 = (short)((uint)iVar2 >> 0x10);
  uStack_e = iVar3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

