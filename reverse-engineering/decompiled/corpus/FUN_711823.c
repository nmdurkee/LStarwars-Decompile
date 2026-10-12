/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x711823; label: FUN_00711823
 */

void FUN_00711823(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  uint uVar7;
  ushort *puVar8;
  ushort uVar9;
  uint uVar10;
  short *psVar11;
  uint uVar12;
  ushort uVar13;
  ushort *local_44;
  ushort *local_40;
  int local_3c;
  int local_34;
  int local_30;
  undefined *local_2c;
  int local_28;
  ushort local_24;
  ushort local_20;
  undefined4 uStack_1e;
  undefined2 uStack_1a;
  undefined4 local_18;
  byte local_14;
  undefined1 uStack_13;
  undefined4 uStack_12;
  undefined4 uStack_e;
  ushort uStack_a;
  uint local_8;
  
  iVar1 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_2c = &DAT_0082aad8;
  if (param_2 == 0) {
LAB_00711b1f:
    uStack_1e = iVar1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((int)param_2 < 0) {
    param_2 = -param_2;
    local_2c = &DAT_0082ac38;
  }
  if (param_3 == 0) {
    *(undefined2 *)param_1 = 0;
  }
joined_r0x00711868:
  do {
    if (param_2 == 0) goto LAB_00711b1f;
    local_2c = local_2c + 0x54;
    uVar12 = (int)param_2 >> 3;
    uVar7 = param_2 & 7;
    param_2 = uVar12;
    if (uVar7 != 0) {
      puVar8 = (ushort *)(local_2c + uVar7 * 0xc);
      if (0x7fff < *puVar8) {
        local_20 = (ushort)*(undefined4 *)puVar8;
        uStack_1e._0_2_ = (undefined2)((uint)*(undefined4 *)puVar8 >> 0x10);
        puVar3 = puVar8 + 4;
        uStack_1e._2_2_ = (undefined2)*(undefined4 *)(puVar8 + 2);
        uStack_1a = (undefined2)((uint)*(undefined4 *)(puVar8 + 2) >> 0x10);
        puVar8 = &local_20;
        local_18 = *(undefined4 *)puVar3;
        iVar1 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e) + -1;
        uStack_1e._0_2_ = (undefined2)iVar1;
        uStack_1e._2_2_ = (undefined2)((uint)iVar1 >> 0x10);
      }
      local_34 = 0;
      local_14 = 0;
      uStack_13 = 0;
      uStack_12._0_2_ = 0;
      uStack_12._2_2_ = 0;
      uStack_e._0_2_ = 0;
      uStack_e._2_2_ = 0;
      uStack_a = 0;
      uVar9 = *(ushort *)((int)param_1 + 10) & 0x7fff;
      uVar13 = puVar8[5] & 0x7fff;
      local_24 = uVar13 + uVar9;
      uVar6 = (puVar8[5] ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
      if (((uVar9 < 0x7fff) && (uVar13 < 0x7fff)) && (local_24 < 0xbffe)) {
        if (0x3fbf < local_24) {
          if (((uVar9 == 0) && (local_24 = local_24 + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
             ((param_1[1] == 0 && (*param_1 == 0)))) {
            *(undefined2 *)((int)param_1 + 10) = 0;
            uStack_12 = 0;
            uStack_e = 0;
            goto joined_r0x00711868;
          }
          if (((uVar13 != 0) || (local_24 = local_24 + 1, (*(uint *)(puVar8 + 4) & 0x7fffffff) != 0)
              ) || ((*(int *)(puVar8 + 2) != 0 || (*(int *)puVar8 != 0)))) {
            local_3c = 0;
            psVar11 = (short *)((int)&uStack_12 + 2);
            local_28 = 5;
            do {
              local_30 = local_28;
              if (0 < local_28) {
                local_44 = puVar8 + 4;
                local_40 = (ushort *)(local_3c * 2 + (int)param_1);
                do {
                  bVar5 = false;
                  uVar12 = *(uint *)(psVar11 + -2) + (uint)*local_40 * (uint)*local_44;
                  if ((uVar12 < *(uint *)(psVar11 + -2)) ||
                     (uVar12 < (uint)*local_40 * (uint)*local_44)) {
                    bVar5 = true;
                  }
                  *(uint *)(psVar11 + -2) = uVar12;
                  if (bVar5) {
                    *psVar11 = *psVar11 + 1;
                  }
                  local_40 = local_40 + 1;
                  local_44 = local_44 + -1;
                  local_30 = local_30 + -1;
                } while (0 < local_30);
              }
              psVar11 = psVar11 + 1;
              local_3c = local_3c + 1;
              local_28 = local_28 + -1;
            } while (0 < local_28);
            local_24 = local_24 + 0xc002;
            if ((short)local_24 < 1) {
LAB_00711a15:
              local_24 = local_24 - 1;
              if ((short)local_24 < 0) {
                uVar12 = (uint)(ushort)-local_24;
                local_24 = 0;
                do {
                  if ((local_14 & 1) != 0) {
                    local_34 = local_34 + 1;
                  }
                  iVar2 = CONCAT22(uStack_a,uStack_e._2_2_);
                  uVar7 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                  iVar4 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                  uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
                  uStack_a = uStack_a >> 1;
                  uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uint)(iVar2 << 0x1f) >> 0x10);
                  uVar10 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
                  uStack_12._0_2_ = (ushort)uStack_12 >> 1 | (ushort)((uint)(iVar4 << 0x1f) >> 0x10)
                  ;
                  uVar12 = uVar12 - 1;
                  uStack_12._2_2_ = (ushort)(uVar7 >> 1);
                  local_14 = (byte)uVar10;
                  uStack_13 = (undefined1)(uVar10 >> 8);
                } while (uVar12 != 0);
                if (local_34 != 0) {
                  local_14 = local_14 | 1;
                }
              }
            }
            else {
              do {
                uVar9 = (ushort)uStack_12;
                if ((uStack_a & 0x8000) != 0) break;
                local_24 = local_24 - 1;
                iVar4 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) << 1;
                local_14 = (byte)iVar4;
                uStack_13 = (undefined1)((uint)iVar4 >> 8);
                uStack_12._0_2_ = (ushort)((uint)iVar4 >> 0x10);
                iVar4 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
                uStack_12._2_2_ = (ushort)iVar4 | uVar9 >> 0xf;
                iVar2 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
                uStack_e._2_2_ = (ushort)iVar2 | (ushort)uStack_e >> 0xf;
                uStack_e._0_2_ = (ushort)((uint)iVar4 >> 0x10);
                uStack_a = (ushort)((uint)iVar2 >> 0x10);
              } while (0 < (short)local_24);
              if ((short)local_24 < 1) goto LAB_00711a15;
            }
            if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
               (iVar4 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e),
               iVar2 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12),
               (CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
              if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
                uStack_12._0_2_ = 0;
                uStack_12._2_2_ = 0;
                iVar2 = 0;
                if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
                  uStack_e._0_2_ = 0;
                  uStack_e._2_2_ = 0;
                  if (uStack_a == 0xffff) {
                    local_24 = local_24 + 1;
                    uStack_a = 0x8000;
                    iVar4 = 0;
                    iVar2 = 0;
                  }
                  else {
                    uStack_a = uStack_a + 1;
                    iVar4 = 0;
                    iVar2 = 0;
                  }
                }
                else {
                  iVar4 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
                  uStack_e._0_2_ = (ushort)iVar4;
                  uStack_e._2_2_ = (ushort)((uint)iVar4 >> 0x10);
                }
              }
              else {
                iVar2 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
                uStack_12._0_2_ = (ushort)iVar2;
                uStack_12._2_2_ = (ushort)((uint)iVar2 >> 0x10);
                iVar4 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
              }
            }
            uStack_12._2_2_ = (ushort)((uint)iVar2 >> 0x10);
            uStack_12._0_2_ = (ushort)iVar2;
            uStack_e._2_2_ = (ushort)((uint)iVar4 >> 0x10);
            uStack_e._0_2_ = (ushort)iVar4;
            uStack_12 = iVar2;
            uStack_e = iVar4;
            if (local_24 < 0x7fff) {
              *(ushort *)param_1 = (ushort)uStack_12;
              *(uint *)((int)param_1 + 2) = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              *(uint *)((int)param_1 + 6) = CONCAT22(uStack_a,uStack_e._2_2_);
              *(ushort *)((int)param_1 + 10) = local_24 | uVar6;
            }
            else {
              param_1[1] = 0;
              *param_1 = 0;
              param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
            }
            goto joined_r0x00711868;
          }
        }
        param_1[2] = 0;
      }
      else {
        param_1[2] = (-(uint)(uVar6 != 0) & 0x80000000) + 0x7fff8000;
      }
      param_1[1] = 0;
      *param_1 = 0;
      uStack_12 = 0;
      uStack_e = 0;
    }
  } while( true );
}

