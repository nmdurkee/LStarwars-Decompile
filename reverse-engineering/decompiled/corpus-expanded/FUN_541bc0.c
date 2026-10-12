/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x541bc0; label: FUN_00541bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00541bc0(int *param_1,undefined4 *param_2,uint param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  uint local_20;
  float local_18;
  int local_14;
  uint local_c;
  
  uVar4 = DAT_00801e38;
  bVar2 = false;
  if (param_1 == (int *)0x0) {
    *(undefined1 *)((int)param_5 + 1) = 0xff;
    *(undefined2 *)((int)param_5 + 2) = 0xffff;
    *(undefined1 *)((int)param_5 + 0x2b) = 0;
    return;
  }
  local_c = DAT_00801e38;
  DAT_00801e38 = 0xffffffff;
  _memset(&DAT_02983900,0,0xe0);
  local_18 = 1e+06;
  _DAT_029838f0 = *param_2;
  _DAT_029838f4 = param_2[1];
  _DAT_029838f8 = param_2[2];
  local_24 = (undefined4 *)0x0;
  local_2c = 0x40;
  uVar9 = param_3;
  if (uVar4 != 0xffffffff) {
    local_2c = 1;
    uVar9 = uVar4;
  }
  if (uVar9 == 0xffffffff) {
    uVar9 = 0;
  }
  while( true ) {
    local_28 = 0;
    local_20 = 0;
    bVar3 = false;
    local_14 = 0;
    if (local_2c == 0) break;
    puVar10 = &DAT_02983908;
    do {
      if ((*(ushort *)(uVar9 * 0x13c + 0x68 + *param_1) & 0x100) == 0) {
        if ((((local_c != 0xffffffff) || (bVar2)) || (param_3 == 0xffffffff)) ||
           ((uVar9 == param_3 ||
            ((*(uint *)(*param_1 + 0xdc +
                       (param_3 * 0x4f + ((int)(uVar9 + ((int)uVar9 >> 0x1f & 0x1fU)) >> 5)) * 4) &
             1 << ((byte)uVar9 & 0x1f)) == 0)))) {
          puVar11 = puVar10 + -2;
          fVar12 = (float10)FUN_0053ebf0(param_1,param_2,puVar11,uVar9);
          uVar6 = DAT_009242d8;
          uVar5 = DAT_009242d4;
          fVar1 = (float)fVar12;
          if (*(char *)((int)puVar10 + -7) != -1) {
            *puVar10 = DAT_009242d0;
            uVar7 = DAT_009242e0;
            puVar10[1] = uVar5;
            uVar5 = DAT_009242e4;
            puVar10[2] = uVar6;
            uVar6 = DAT_009242e8;
            puVar10[3] = uVar7;
            puVar10[4] = uVar5;
            puVar10[5] = uVar6;
            if ((local_24 != (undefined4 *)0x0) && (local_18 <= fVar1)) {
              puVar11 = local_24;
              fVar1 = local_18;
            }
            local_18 = fVar1;
            local_24 = puVar11;
            local_28 = local_28 + 1;
            puVar10 = puVar10 + 0xe;
            local_20 = local_20 | 1 << ((byte)uVar9 & 0x1f);
            if (puVar10 == (undefined4 *)&DAT_029839e8) break;
          }
        }
        else {
          bVar3 = true;
        }
      }
      uVar9 = uVar9 + 1 & 0x8000003f;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xffffffc0) + 1;
      }
      local_14 = local_14 + 1;
    } while (local_14 < local_2c);
    if (local_24 != (undefined4 *)0x0) {
      puVar10 = local_24;
      puVar11 = param_5;
      for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      param_5[0xd] = local_20;
      *(undefined1 *)((int)param_5 + 0x2b) = 0;
      if (bVar2) {
        *(undefined1 *)((int)param_5 + 0x2b) = 1;
      }
      goto LAB_00541e2c;
    }
    if (!bVar3) break;
    uVar9 = 0;
    bVar2 = true;
    local_c = 0xffffffff;
    local_2c = 0x40;
  }
  *(undefined1 *)((int)param_5 + 1) = 0xff;
  *(undefined2 *)((int)param_5 + 2) = 0xffff;
  *(undefined1 *)((int)param_5 + 0x2b) = 0;
LAB_00541e2c:
  *(char *)((int)param_5 + 0x2a) = (char)local_28;
  _DAT_02983a18 = local_24;
  DAT_029838e4 = local_28;
  _DAT_02983a20 = *param_5;
  _DAT_02983a24 = param_5[1];
  return;
}

