/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f5ee0; label: FUN_005f5ee0
 */

void FUN_005f5ee0(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  uint *puVar9;
  char cVar10;
  undefined4 *puVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  int in_ECX;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  int local_90;
  int local_8c;
  int local_88;
  int local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar18 = 0;
  if (0 < *(int *)(in_ECX + 0x70c)) {
    puVar17 = (undefined4 *)(in_ECX + 0x344);
    do {
      iVar16 = 2;
      puVar11 = puVar17;
      do {
        puVar11[-2] = 0;
        *puVar11 = 0;
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      iVar18 = iVar18 + 1;
      puVar17 = puVar17 + 0xe0;
    } while (iVar18 < *(int *)(in_ECX + 0x70c));
  }
  iVar18 = *(int *)(param_1 + 0x110);
  local_88 = 0;
  local_74 = 0;
  if (0 < *(int *)(iVar18 + 0x10)) {
    local_90 = 0;
    do {
      if ((*(byte *)(local_88 + *(int *)(iVar18 + 0x48)) & 0x21) == 0x21) {
        pfVar12 = (float *)(*(int *)(iVar18 + 0x44) + local_90);
        pfVar14 = (float *)(*(int *)(iVar18 + 0x28) + local_74 * 4);
        if (*pfVar14 != 0.0) {
          fVar3 = *pfVar14;
          while ((DAT_00973720 - pfVar12[2]) * (DAT_00973720 - pfVar12[2]) +
                 (DAT_00973718 - *pfVar12) * (DAT_00973718 - *pfVar12) +
                 (DAT_0097371c - pfVar12[1]) * (DAT_0097371c - pfVar12[1]) < fVar3) {
            pfVar1 = pfVar14 + 1;
            pfVar14 = pfVar14 + 1;
            local_74 = local_74 + 1;
            fVar3 = *pfVar1;
          }
        }
        piVar21 = (int *)(*(int *)(iVar18 + 0x14) + local_74 * 0xc);
        local_8c = 0;
        if (0 < *(int *)(in_ECX + 0x70c)) {
          iVar16 = in_ECX + 0x290;
          do {
            iVar13 = FUN_005c8810(iVar16 + -0x10,*(undefined4 *)(iVar16 + 0x10),
                                  *(undefined4 *)(local_90 + *(int *)(param_1 + 0xfc) + 0xc));
            if (iVar13 != 0) {
              local_30 = *(float *)(*(int *)(param_1 + 0xfc) + 0x10 + local_90);
              pfVar14 = (float *)(*(int *)(param_1 + 0xfc) + local_90);
              local_20 = *pfVar14 - local_30;
              local_1c = pfVar14[1] - pfVar14[5];
              local_18 = pfVar14[2] - pfVar14[6];
              local_30 = *pfVar14 + local_30;
              local_2c = pfVar14[5] + pfVar14[1];
              local_28 = pfVar14[2] + pfVar14[6];
              cVar10 = FUN_005c6dc0(&local_20,&local_30,local_8c);
              if ((cVar10 != '\0') && (iVar13 = 0, 0 < *piVar21)) {
                do {
                  iVar15 = iVar16 + 0x58;
                  if (*(char *)(*(int *)(*(int *)(param_1 + 0xc) +
                                        *(int *)(piVar21[1] + iVar13 * 4) * 4) + 0x268) == '\0') {
                    iVar15 = iVar16 + 0x14;
                  }
                  iVar15 = ((iVar15 - (iVar16 + -0x290)) + -0x2a4) / 0x44;
                  uVar4 = *(uint *)(iVar16 + 0xbc + iVar15 * 4);
                  uVar5 = *(uint *)(iVar16 + 0xac + iVar15 * 4);
                  if (uVar4 <= uVar5) {
                    if (uVar4 < uVar5) {
                      iVar15 = FUN_005c12e0();
                    }
                    *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
                    puVar9 = DAT_009736e0;
                    *(uint *)(iVar16 + 0xac + iVar15 * 4) = *DAT_009736e0 + 0xf & 0xfffffff0;
                    *puVar9 = (*puVar9 + 0xf & 0xfffffff0) + 0x310;
                    puVar8 = *(undefined1 **)(iVar16 + 0xbc + iVar15 * 4);
                    if (puVar8 == (undefined1 *)0x0) {
                      *(undefined4 *)(iVar16 + 0xb4 + iVar15 * 4) =
                           *(undefined4 *)(iVar16 + 0xac + iVar15 * 4);
                    }
                    else {
                      *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(iVar16 + 0xac + iVar15 * 4);
                      *puVar8 = 0x8d;
                      puVar8[1] = 1;
                    }
                    *(uint *)(iVar16 + 0xbc + iVar15 * 4) = *puVar9 - 0x10;
                  }
                  puVar8 = *(undefined1 **)(iVar16 + 0xac + iVar15 * 4);
                  *(undefined4 *)(puVar8 + 4) =
                       *(undefined4 *)
                        (*(int *)(param_1 + 0xc) + *(int *)(piVar21[1] + iVar13 * 4) * 4);
                  *puVar8 = 0x80;
                  puVar8[1] = 3;
                  iVar19 = *(int *)(piVar21[2] + iVar13 * 4) * 0x10;
                  iVar2 = iVar19 + -0x10 + *(int *)(iVar18 + 8);
                  iVar6 = *(int *)(iVar16 + 0xac + iVar15 * 4);
                  *(undefined4 *)(iVar6 + 0x10) =
                       *(undefined4 *)(iVar19 + -0x10 + *(int *)(iVar18 + 8));
                  *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar2 + 4);
                  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar2 + 8);
                  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar2 + 0xc);
                  puVar17 = (undefined4 *)
                            (*(int *)(piVar21[2] + iVar13 * 4) * 0x10 + *(int *)(iVar18 + 8));
                  iVar2 = *(int *)(iVar16 + 0xac + iVar15 * 4);
                  *(undefined4 *)(iVar2 + 0x20) = *puVar17;
                  *(undefined4 *)(iVar2 + 0x24) = puVar17[1];
                  *(undefined4 *)(iVar2 + 0x28) = puVar17[2];
                  *(undefined4 *)(iVar2 + 0x2c) = puVar17[3];
                  *(undefined1 *)(*(int *)(iVar16 + 0xac + iVar15 * 4) + 0x11) = 3;
                  *(undefined1 *)(*(int *)(iVar16 + 0xac + iVar15 * 4) + 0x21) = 3;
                  piVar20 = (int *)(iVar16 + 0xac + iVar15 * 4);
                  *piVar20 = *piVar20 + 0x30;
                  iVar13 = iVar13 + 1;
                } while (iVar13 < *piVar21);
              }
            }
            local_8c = local_8c + 1;
            iVar16 = iVar16 + 0x380;
          } while (local_8c < *(int *)(in_ECX + 0x70c));
        }
        iVar16 = *(int *)(iVar18 + 0x28) + local_74 * 4;
        fVar3 = *(float *)(*(int *)(iVar18 + 0x28) + local_74 * 4);
        while (fVar3 != 0.0) {
          pfVar14 = (float *)(iVar16 + 4);
          iVar16 = iVar16 + 4;
          local_74 = local_74 + 1;
          fVar3 = *pfVar14;
        }
      }
      else {
        iVar16 = *(int *)(iVar18 + 0x28) + local_74 * 4;
        fVar3 = *(float *)(*(int *)(iVar18 + 0x28) + local_74 * 4);
        while (fVar3 != 0.0) {
          pfVar14 = (float *)(iVar16 + 4);
          iVar16 = iVar16 + 4;
          local_74 = local_74 + 1;
          fVar3 = *pfVar14;
        }
      }
      local_88 = local_88 + 1;
      local_90 = local_90 + 0x20;
      local_74 = local_74 + 1;
    } while (local_74 < *(int *)(iVar18 + 0x10));
  }
  FUN_005f56d0(iVar18,0,0);
  local_8c = 0;
  if (0 < *(int *)(in_ECX + 0x70c)) {
    piVar21 = (int *)(in_ECX + 0x2c8);
    do {
      piVar20 = piVar21 + 0x1f;
      iVar18 = 2;
      piVar22 = piVar21;
      do {
        if (*piVar20 != 0) {
          FUN_00603530(piVar22 + -9,1);
          uVar7 = **(undefined4 **)(param_1 + 0xc);
          *(undefined1 *)*piVar22 = 0x80;
          *(undefined1 *)(*piVar22 + 1) = 3;
          *(undefined4 *)(*piVar22 + 4) = uVar7;
          *piVar22 = *piVar22 + 0x10;
          puVar8 = (undefined1 *)piVar20[-2];
          *(int *)(piVar22[-4] + 4) = *piVar20;
          iVar16 = piVar22[-3];
          *puVar8 = 0x8d;
          *(int *)(puVar8 + 4) = iVar16 + 0x10;
          puVar8[1] = 1;
          piVar22[-4] = (int)puVar8;
        }
        piVar20 = piVar20 + 1;
        piVar22 = piVar22 + 0x11;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      local_8c = local_8c + 1;
      piVar21 = piVar21 + 0xe0;
    } while (local_8c < *(int *)(in_ECX + 0x70c));
  }
  return;
}

