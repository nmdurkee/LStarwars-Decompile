/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a3cc0; label: FUN_005a3cc0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a3cc0(void)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  float local_2418;
  undefined1 local_2414;
  float local_2410;
  int local_240c;
  undefined4 local_2408;
  int local_2400 [6];
  float afStack_23e8 [9];
  float afStack_23c4 [2288];
  undefined4 uStack_4;
  
  uStack_4 = 0x5a3cca;
  for (puVar4 = DAT_0095da40; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    fVar5 = 255.0;
    fVar6 = (float)0;
    for (piVar2 = (int *)puVar4[2]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (0.0 <= (float)piVar2[0x39]) {
        local_2410 = (float)piVar2[0x39];
      }
      else {
        local_2410 = 0.0;
      }
      fVar7 = (float)((uint)puVar4[6] >> 0x18);
      fVar3 = fVar5;
      if (local_2410 * fVar7 * _DAT_00805984 <= 255.0) {
        if (0.0 <= (float)piVar2[0x39]) {
          local_2410 = (float)piVar2[0x39];
        }
        else {
          local_2410 = 0.0;
        }
        fVar3 = _DAT_00805984 * local_2410 * fVar7;
      }
      local_240c._0_1_ = (undefined1)(int)ROUND(fVar3);
      local_2408._0_3_ = (undefined3)puVar4[6];
      local_2408 = (float)CONCAT13((undefined1)local_240c,(undefined3)local_2408);
      local_2400[(int)fVar6 * 9] = piVar2[2];
      local_2400[(int)fVar6 * 9 + 1] = piVar2[3];
      local_2400[(int)fVar6 * 9 + 2] = piVar2[4];
      afStack_23e8[(int)fVar6 * 9 + 1] = 0.01;
      afStack_23e8[(int)fVar6 * 9] = local_2408;
      local_2410 = (float)((int)fVar6 + 2);
      afStack_23e8[(int)fVar6 * 9 + 3] = (float)piVar2[5];
      afStack_23e8[(int)fVar6 * 9 + 4] = (float)piVar2[6];
      fVar3 = (float)piVar2[7];
      afStack_23c4[(int)fVar6 * 9 + 1] = 0.99;
      afStack_23e8[(int)fVar6 * 9 + 5] = fVar3;
      afStack_23c4[(int)fVar6 * 9] = local_2408;
      iVar11 = *piVar2;
      if ((iVar11 != 0) && (local_240c = 1, 1 < *(int *)(iVar11 + 0xe0))) {
        iVar13 = 0xc;
        piVar10 = local_2400 + (int)local_2410 * 9;
        pfVar8 = afStack_23e8 + (int)local_2410 * 9;
        pfVar12 = afStack_23e8 + (int)local_2410 * 9 + 1;
        do {
          if (0.0 <= (float)piVar2[0x39]) {
            local_2418 = (float)piVar2[0x39];
          }
          else {
            local_2418 = 0.0;
          }
          fVar3 = (float)((uint)puVar4[6] >> 0x18);
          fVar6 = fVar5;
          if (local_2418 * fVar3 * _DAT_00805984 <= 255.0) {
            if (0.0 <= (float)piVar2[0x39]) {
              local_2418 = (float)piVar2[0x39];
            }
            else {
              local_2418 = 0.0;
            }
            fVar6 = _DAT_00805984 * local_2418 * fVar3;
          }
          local_2414 = (undefined1)(int)ROUND(fVar6);
          local_2408._0_3_ = (undefined3)puVar4[6];
          local_2408 = (float)CONCAT13(local_2414,(undefined3)local_2408);
          *piVar10 = *(int *)(iVar13 + 0x2c + iVar11);
          piVar10[1] = *(int *)(iVar13 + 0x30 + iVar11);
          piVar10[2] = *(int *)(iVar13 + 0x34 + iVar11);
          *pfVar8 = local_2408;
          *pfVar12 = 0.01;
          if (0.0 <= (float)piVar2[0x39]) {
            local_2418 = (float)piVar2[0x39];
          }
          else {
            local_2418 = 0.0;
          }
          fVar3 = (float)((uint)puVar4[6] >> 0x18);
          fVar6 = fVar5;
          if (local_2418 * fVar3 * _DAT_00805984 <= 255.0) {
            if (0.0 <= (float)piVar2[0x39]) {
              local_2418 = (float)piVar2[0x39];
            }
            else {
              local_2418 = 0.0;
            }
            fVar6 = _DAT_00805984 * local_2418 * fVar3;
          }
          local_2410 = (float)((int)local_2410 + 2);
          local_2414 = (undefined1)(int)ROUND(fVar6);
          local_2408._0_3_ = (undefined3)puVar4[6];
          local_2408 = (float)CONCAT13(local_2414,(undefined3)local_2408);
          piVar1 = (int *)(iVar13 + 0x80 + *piVar2);
          piVar10[9] = *piVar1;
          piVar10[10] = piVar1[1];
          piVar10[0xb] = piVar1[2];
          pfVar12[9] = 1.01;
          pfVar8[9] = local_2408;
          local_240c = local_240c + 1;
          iVar11 = *piVar2;
          iVar13 = iVar13 + 0xc;
          piVar10 = piVar10 + 0x12;
          pfVar8 = pfVar8 + 0x12;
          pfVar12 = pfVar12 + 0x12;
        } while (local_240c < *(int *)(iVar11 + 0xe0));
      }
      fVar6 = local_2410;
    }
    local_240c = 0;
    if (0 < (int)fVar6) {
      pfVar8 = afStack_23c4 + 2;
      do {
        fVar5 = (float)local_240c;
        local_240c = local_240c + 2;
        fVar5 = (fVar5 / (float)(int)fVar6) * 0.99;
        pfVar8[-9] = fVar5;
        *pfVar8 = fVar5;
        pfVar8 = pfVar8 + 0x12;
      } while (local_240c < (int)fVar6);
    }
    uVar9 = DAT_0095da30;
    if (*(char *)((int)puVar4 + 0xe) == '\0') {
      uVar9 = DAT_0095da44;
    }
    FUN_005ddad0(local_2400,fVar6,0,uVar9);
  }
  return;
}

