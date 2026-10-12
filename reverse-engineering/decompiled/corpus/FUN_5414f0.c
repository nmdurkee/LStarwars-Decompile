/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x5414f0; label: FUN_005414f0
 */

void FUN_005414f0(int *param_1,uint *param_2,undefined4 *param_3)

{
  float *pfVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  float10 fVar16;
  undefined4 *local_18;
  int local_14;
  int local_c;
  float local_8;
  int local_4;
  
  if (param_1 != (int *)0x0) {
    puVar14 = (undefined4 *)*param_1;
    local_14 = 0;
    do {
      if (*(char *)((int)puVar14 + 0x32) != '\0') {
        uVar6 = *param_2;
        if (param_3 <= (undefined4 *)(uVar6 + *(short *)*puVar14 * 4)) {
          return;
        }
        puVar14[0xe] = uVar6;
        uVar6 = FUN_0053e490(puVar14,(short *)*puVar14,uVar6);
        *param_2 = uVar6;
        if (param_3 <= (undefined4 *)(uVar6 + *(short *)*puVar14 * 4)) {
          return;
        }
        puVar14[0xf] = uVar6;
        local_18 = (undefined4 *)FUN_0053e490(puVar14,puVar14[5],uVar6);
        *param_2 = (uint)local_18;
        if (param_3 <= local_18 + *(short *)*puVar14 * 0x20) {
          return;
        }
        iVar11 = 0;
        puVar14[0xd] = local_18;
        local_8 = 0.0;
        iVar8 = 0;
        if (0 < *(short *)*puVar14) {
          puVar13 = local_18 + 0x18;
          local_c = 0;
          do {
            iVar8 = iVar8 + 1;
            iVar10 = iVar8 % (int)*(short *)*puVar14;
            if ((*(byte *)(puVar14 + 0x1a) & 1) == 0) {
              FUN_005b3bb0(puVar13 + -0x12,*(int *)(puVar14[1] + 8) + iVar11,
                           *(int *)(puVar14[2] + 8) + iVar11,*(int *)(puVar14[4] + 8) + iVar11);
              iVar7 = iVar10 * 0xc;
              FUN_005b3bb0(puVar13 + -0xf,*(int *)(puVar14[1] + 8) + iVar7,
                           *(int *)(puVar14[2] + 8) + iVar7,*(int *)(puVar14[2] + 8) + iVar11);
              FUN_005b3bb0(puVar13 + -0xc,*(int *)(puVar14[2] + 8) + iVar7,
                           *(int *)(puVar14[3] + 8) + iVar7,*(int *)(puVar14[3] + 8) + iVar11);
              FUN_005b3bb0(puVar13 + -9,*(int *)(puVar14[3] + 8) + iVar7,
                           *(int *)(puVar14[4] + 8) + iVar7,*(int *)(puVar14[4] + 8) + iVar11);
              FUN_005b3bb0(puVar13 + -6,*(int *)(puVar14[4] + 8) + iVar7,
                           *(int *)(puVar14[1] + 8) + iVar7,*(int *)(puVar14[1] + 8) + iVar11);
              FUN_005b3bb0(puVar13 + -3,*(int *)(puVar14[2] + 8) + iVar7,
                           *(int *)(puVar14[1] + 8) + iVar7,*(int *)(puVar14[3] + 8) + iVar7);
              FUN_005b37d0(puVar13,*(int *)(puVar14[1] + 8) + iVar11,
                           *(int *)(puVar14[2] + 8) + iVar11);
              FUN_005b37d0(puVar13,puVar13,*(int *)(puVar14[3] + 8) + iVar11);
              FUN_005b37d0(puVar13,puVar13,*(int *)(puVar14[4] + 8) + iVar11);
              FUN_005b3830(puVar13,puVar13,0x3e800000);
              FUN_005b37d0(puVar13 + 3,*(int *)(puVar14[1] + 8) + iVar7,
                           *(int *)(puVar14[2] + 8) + iVar7);
              FUN_005b37d0(puVar13 + 3,puVar13 + 3,*(int *)(puVar14[3] + 8) + iVar7);
              FUN_005b37d0(puVar13 + 3,puVar13 + 3,*(int *)(puVar14[4] + 8) + iVar7);
              FUN_005b3830(puVar13 + 3,puVar13 + 3,0x3e800000);
              iVar7 = *(int *)(puVar14[1] + 8) + iVar11;
              puVar13[-0x15] = *(undefined4 *)(*(int *)(puVar14[1] + 8) + iVar11);
              puVar13[-0x14] = *(undefined4 *)(iVar7 + 4);
              puVar13[-0x13] = *(undefined4 *)(iVar7 + 8);
              uVar3 = puVar13[-0x14];
              *local_18 = puVar13[-0x15];
              uVar4 = puVar13[-0x13];
              local_18[1] = uVar3;
              local_18[2] = uVar4;
              FUN_0053dc00();
              FUN_0053dc00();
              FUN_0053dc00();
              FUN_0053dc00();
              FUN_0053dc00();
              FUN_0053dc00();
            }
            else {
              FUN_005b37d0(puVar13,*(int *)(puVar14[1] + 8) + iVar11,
                           *(int *)(puVar14[2] + 8) + iVar11);
              FUN_005b3830(puVar13,puVar13,0x3f000000);
              FUN_005b37d0(puVar13 + 3,*(int *)(puVar14[1] + 8) + iVar10 * 0xc,
                           *(int *)(puVar14[2] + 8) + iVar10 * 0xc);
              FUN_005b3830(puVar13 + 3,puVar13 + 3,0x3f000000);
              iVar7 = *(int *)(puVar14[1] + 8);
              puVar13[-0x15] = *(undefined4 *)(iVar7 + iVar11);
              puVar13[-0x14] = *(undefined4 *)(iVar7 + 4 + iVar11);
              puVar13[-0x13] = *(undefined4 *)(iVar7 + iVar11 + 8);
              uVar3 = puVar13[-0x14];
              *local_18 = puVar13[-0x15];
              uVar4 = puVar13[-0x13];
              local_18[1] = uVar3;
              local_18[2] = uVar4;
              FUN_0053dc00();
              FUN_0053dc00();
            }
            FUN_0053dc00();
            if (puVar14[5] == 0) {
              fVar16 = (float10)FUN_005becc0(puVar14[0xd] + local_c + 0x60,
                                             puVar14[0xd] + local_c + 0x6c,0);
              puVar13[6] = (float)fVar16;
            }
            else {
              iVar7 = *(int *)(puVar14[5] + 8);
              fVar16 = (float10)FUN_005becc0(iVar7 + iVar11,iVar7 + iVar10 * 0xc,0);
              puVar13[6] = (float)fVar16;
            }
            puVar13[7] = local_8;
            local_8 = local_8 + (float)puVar13[6];
            local_c = local_c + 0x80;
            local_18 = local_18 + 0x20;
            puVar13 = puVar13 + 0x20;
            iVar11 = iVar11 + 0xc;
          } while (iVar8 < *(short *)*puVar14);
        }
        if (puVar14[5] == 0) {
          uVar6 = (uint)*(ushort *)(puVar14 + 0xc);
          puVar14[0x26] = 0;
          if (*(char *)((int)puVar14 + 0x33) != '\0') {
            uVar6 = uVar6 + 1;
          }
          if (uVar6 != 0) {
            iVar8 = 0;
            do {
              fVar16 = (float10)FUN_005becc0(puVar14[0xd] + iVar8 + 0x60,puVar14[0xd] + iVar8 + 0x6c
                                             ,0);
              iVar8 = iVar8 + 0x80;
              uVar6 = uVar6 - 1;
              puVar14[0x26] = (float)(fVar16 + (float10)(float)puVar14[0x26]);
            } while (uVar6 != 0);
          }
        }
        else {
          fVar16 = (float10)FUN_0053dc80(puVar14[5],*(undefined1 *)((int)puVar14 + 0x33));
          puVar14[0x26] = (float)fVar16;
        }
        *param_2 = (uint)local_18;
      }
      local_14 = local_14 + 1;
      puVar14 = puVar14 + 0x4f;
    } while (local_14 < 0x40);
    *param_2 = *param_2 + 0xf & 0xfffffff0;
    iVar8 = *param_1;
    local_14 = 0;
    do {
      if (*(char *)(iVar8 + 0x32) != '\0') {
        pbVar12 = (byte *)(*param_1 + 0x68);
        local_18 = (undefined4 *)0x0;
        do {
          if ((local_18 != (undefined4 *)local_14) && (pbVar12[-0x36] != 0)) {
            if (((*(byte *)(iVar8 + 0x68) & 1) != 0) || (bVar5 = false, (*pbVar12 & 1) != 0)) {
              bVar5 = true;
            }
            if (((((*(float *)(pbVar12 + -0x28) <= *(float *)(iVar8 + 0x4c)) &&
                  (*(float *)(iVar8 + 0x40) <= *(float *)(pbVar12 + -0x1c))) &&
                 (*(float *)(pbVar12 + -0x20) <= *(float *)(iVar8 + 0x54))) &&
                (*(float *)(iVar8 + 0x48) <= *(float *)(pbVar12 + -0x14))) &&
               ((bVar5 || ((*(float *)(pbVar12 + -0x24) <= *(float *)(iVar8 + 0x50) &&
                           (*(float *)(iVar8 + 0x44) <= *(float *)(pbVar12 + -0x18))))))) {
              uVar6 = (uint)*(ushort *)(iVar8 + 0x30);
              if (*(char *)(iVar8 + 0x33) != '\0') {
                uVar6 = uVar6 + 1;
              }
              uVar15 = (uint)*(ushort *)(pbVar12 + -0x38);
              if (pbVar12[-0x35] != 0) {
                uVar15 = uVar15 + 1;
              }
              local_4 = 0;
              if (uVar6 != 0) {
                iVar11 = 0;
                do {
                  iVar10 = 0;
                  if (uVar15 != 0) {
                    pfVar1 = (float *)(*(int *)(iVar8 + 0x34) + iVar11);
                    pfVar9 = *(float **)(pbVar12 + -0x34);
                    do {
                      if ((((*pfVar9 < pfVar1[3] != (*pfVar9 == pfVar1[3])) &&
                           (*pfVar1 <= pfVar9[3])) &&
                          ((pfVar9[2] < pfVar1[5] != (pfVar9[2] == pfVar1[5]) &&
                           (pfVar1[2] <= pfVar9[5])))) &&
                         ((bVar5 || ((pfVar9[1] < pfVar1[4] != (pfVar9[1] == pfVar1[4]) &&
                                     (pfVar1[1] <= pfVar9[4])))))) goto LAB_00541b82;
                      iVar10 = iVar10 + 1;
                      pfVar9 = pfVar9 + 0x20;
                    } while (iVar10 < (int)uVar15);
                  }
                  local_4 = local_4 + 1;
                  iVar11 = iVar11 + 0x80;
                } while (local_4 < (int)uVar6);
              }
            }
            puVar2 = (uint *)(iVar8 + 0xdc +
                             ((int)((int)local_18 + ((int)local_18 >> 0x1f & 0x1fU)) >> 5) * 4);
            *puVar2 = *puVar2 | 1 << ((byte)local_18 & 0x1f);
          }
LAB_00541b82:
          local_18 = (undefined4 *)((int)local_18 + 1);
          pbVar12 = pbVar12 + 0x13c;
        } while ((int)local_18 < 0x40);
      }
      local_14 = local_14 + 1;
      iVar8 = iVar8 + 0x13c;
    } while (local_14 < 0x40);
  }
  return;
}

