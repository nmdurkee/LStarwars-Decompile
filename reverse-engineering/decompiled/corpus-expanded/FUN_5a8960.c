/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a8960; label: FUN_005a8960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8960(void)

{
  byte bVar1;
  short sVar2;
  float fVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  int unaff_ESI;
  float *pfVar11;
  undefined4 *puVar12;
  bool bVar13;
  uint local_40;
  double local_3c;
  float local_34;
  float local_30 [2];
  float local_28;
  float local_24 [2];
  float local_1c;
  float local_18 [2];
  float local_10;
  undefined1 local_c [12];
  
  bVar1 = *(byte *)(unaff_ESI + 0x1c);
  uVar8 = (uint)(bVar1 >> 2);
  uVar4 = *(uint *)(unaff_ESI + 0x18) & 0xf;
  if (uVar4 == 0) {
    local_30[0] = *(float *)(unaff_ESI + 0xc);
    local_28 = 0.0;
    FUN_005b3620(local_30,local_30,*(undefined2 *)(unaff_ESI + 0x14));
    local_18[0] = 0.0;
    local_10 = *(float *)(unaff_ESI + 0x10);
    FUN_005b3620(local_18,local_18,*(undefined2 *)(unaff_ESI + 0x14));
    iVar9 = 0;
    if (*(char *)(unaff_ESI + 0x1c) != '\0') {
      pfVar11 = (float *)(*(int *)(unaff_ESI + 0x40) + 0x10);
      do {
        iVar5 = FUN_0054fa60();
        local_3c = ((double)iVar5 * 3.051804378628731e-05 - 1.0) * (double)local_18[0];
        iVar5 = FUN_0054fa60();
        pfVar11[-1] = ((float)iVar5 * 3.0518044e-05 - 1.0) * local_30[0] + (float)local_3c;
        iVar5 = FUN_0054fa60();
        local_3c = ((double)iVar5 * 3.051804378628731e-05 - 1.0) * (double)local_10;
        iVar5 = FUN_0054fa60();
        iVar9 = iVar9 + 1;
        *pfVar11 = ((float)iVar5 * 3.0518044e-05 - 1.0) * local_28 + (float)local_3c;
        pfVar11 = pfVar11 + 8;
      } while (iVar9 < (int)(uint)*(byte *)(unaff_ESI + 0x1c));
    }
  }
  else {
    if (uVar4 == 1) {
      local_30[0] = *(float *)(unaff_ESI + 0xc) / (float)uVar8;
      local_28 = 0.0;
      local_18[0] = 0.0;
      local_10 = *(float *)(unaff_ESI + 0x10) * 0.25;
      local_24[0] = -((float)uVar8 * 0.5 * local_30[0]);
      local_1c = -(local_10 + local_10);
      FUN_005b3620(local_30,local_30,*(ushort *)(unaff_ESI + 0x14) + 0x8000);
      FUN_005b3620(local_18,local_18,*(ushort *)(unaff_ESI + 0x14) + 0x8000);
      FUN_005b3620(local_24,local_24,*(ushort *)(unaff_ESI + 0x14) + 0x8000);
      iVar9 = *(int *)(unaff_ESI + 0x40);
      local_40 = 0;
      do {
        if ((DAT_0095df2c != 0) && (local_40 != 0)) {
          uVar4 = local_40 & 0x80000001;
          bVar13 = uVar4 == 0;
          if ((int)uVar4 < 0) {
            bVar13 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (bVar13) {
            local_24[0] = local_24[0] + local_18[0];
            local_1c = local_1c + local_10;
          }
        }
        local_34 = local_1c;
        iVar5 = 0;
        fVar3 = local_24[0];
        if (3 < bVar1 >> 2) {
          iVar7 = (uVar8 - 4 >> 2) + 1;
          iVar5 = iVar7 * 4;
          do {
            *(float *)(iVar9 + 0xc) = fVar3;
            *(float *)(iVar9 + 0x10) = local_34;
            uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            if (in_EAX != 0) {
              *(undefined2 *)(iVar9 + 4) = uVar10;
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            *(float *)(iVar9 + 0x2c) = local_30[0] + fVar3;
            *(undefined2 *)(iVar9 + 6) = uVar10;
            *(float *)(iVar9 + 0x30) = local_34 + local_28;
            uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            fVar3 = local_30[0] + local_30[0] + fVar3;
            local_34 = local_34 + local_28 + local_28;
            if (in_EAX != 0) {
              *(undefined2 *)(iVar9 + 0x24) = uVar10;
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            *(float *)(iVar9 + 0x4c) = fVar3;
            *(undefined2 *)(iVar9 + 0x26) = uVar10;
            *(float *)(iVar9 + 0x50) = local_34;
            uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            fVar3 = local_30[0] + fVar3;
            local_34 = local_34 + local_28;
            if (in_EAX != 0) {
              *(undefined2 *)(iVar9 + 0x44) = uVar10;
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            *(float *)(iVar9 + 0x6c) = fVar3;
            *(undefined2 *)(iVar9 + 0x46) = uVar10;
            *(float *)(iVar9 + 0x70) = local_34;
            uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            fVar3 = local_30[0] + fVar3;
            local_34 = local_34 + local_28;
            if (in_EAX != 0) {
              *(undefined2 *)(iVar9 + 100) = uVar10;
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            *(undefined2 *)(iVar9 + 0x66) = uVar10;
            iVar9 = iVar9 + 0x80;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        if (iVar5 < (int)uVar8) {
          iVar5 = uVar8 - iVar5;
          do {
            *(float *)(iVar9 + 0xc) = fVar3;
            *(float *)(iVar9 + 0x10) = local_34;
            fVar3 = local_30[0] + fVar3;
            local_34 = local_34 + local_28;
            if (in_EAX == 0) {
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            else {
              *(undefined2 *)(iVar9 + 4) = *(undefined2 *)(unaff_ESI + 0x14);
              uVar10 = *(undefined2 *)(unaff_ESI + 0x14);
            }
            *(undefined2 *)(iVar9 + 6) = uVar10;
            iVar9 = iVar9 + 0x20;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_40 = local_40 + 1;
        local_24[0] = local_24[0] + local_18[0];
        local_1c = local_1c + local_10;
      } while ((int)local_40 < 4);
      return;
    }
    iVar9 = 0;
    if (uVar4 == 4) {
      sVar2 = *(short *)(unaff_ESI + 0x14);
      local_3c = 0.0;
      if (bVar1 != 0) {
        puVar12 = (undefined4 *)(*(int *)(unaff_ESI + 0x40) + 0x10);
        do {
          local_3c = (double)CONCAT44(local_3c._4_4_,puVar12[-1]);
          local_34 = (float)*puVar12;
          FUN_005b3620(local_c,&local_3c,sVar2 + -0x8000);
          puVar12[-1] = local_3c._0_4_;
          iVar9 = iVar9 + 1;
          *puVar12 = local_34;
          puVar12 = puVar12 + 8;
        } while (iVar9 < (int)(uint)*(byte *)(unaff_ESI + 0x1c));
        return;
      }
    }
    else if (bVar1 != 0) {
      pfVar11 = (float *)(*(int *)(unaff_ESI + 0x40) + 0x10);
      do {
        local_30[0] = 0.0;
        iVar5 = FUN_0054fa60();
        local_28 = (float)iVar5 * 1.5259022e-05 * *(float *)(unaff_ESI + 0xc);
        uVar6 = FUN_0054fa60();
        FUN_005b3620(local_30,local_30,uVar6);
        pfVar11[-1] = local_30[0];
        iVar9 = iVar9 + 1;
        *pfVar11 = local_28;
        pfVar11 = pfVar11 + 8;
      } while (iVar9 < (int)(uint)*(byte *)(unaff_ESI + 0x1c));
      return;
    }
  }
  return;
}

