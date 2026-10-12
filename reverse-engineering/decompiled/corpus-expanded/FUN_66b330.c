/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b330; label: FUN_0066b330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066b330(char *param_1,int param_2,int *param_3,int *param_4)

{
  short *psVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  short *extraout_ECX;
  short *psVar11;
  uint uVar12;
  float *pfVar13;
  short *psVar14;
  int iVar15;
  float *pfVar16;
  int iVar17;
  float local_7c;
  float local_78;
  float local_74;
  ushort *local_70;
  undefined1 local_6c [4];
  char local_68 [4];
  undefined1 local_64 [96];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_7c;
  _DAT_02921194 = 0;
  FUN_0064fdb0(param_3);
  iVar9 = -(int)param_1;
  do {
    cVar4 = *param_1;
    param_1[(int)(local_68 + iVar9)] = cVar4;
    param_1 = param_1 + 1;
  } while (cVar4 != '\0');
  puVar6 = (undefined4 *)(local_6c + 3);
  do {
    puVar7 = puVar6;
    puVar6 = (undefined4 *)((int)puVar7 + 1);
  } while (*(char *)((int)puVar7 + 1) != '\0');
  *(undefined4 *)((int)puVar7 + 1) = 0x7265742e;
  *(undefined1 *)((int)puVar7 + 5) = 0;
  uVar8 = FUN_004fd5d0(local_68,*param_3,0x7fffffff);
  iVar9 = FUN_0064fdb0(local_68,uVar8);
  if (iVar9 != 0) {
    piVar5 = (int *)*param_3;
    psVar1 = (short *)((int)piVar5 + *piVar5 * 2);
    *param_3 = (int)(piVar5 + 1);
    iVar9 = 0;
    local_6c = (undefined1  [4])0x0;
    if (0 < *psVar1) {
      psVar11 = psVar1 + 0xb;
      do {
        if (*psVar11 == 0x1ca) {
          iVar9 = FUN_0064fdb0(local_68);
          psVar11 = extraout_ECX;
        }
        iVar9 = iVar9 + 1;
        psVar11 = psVar11 + 0x1a;
      } while (iVar9 < *psVar1);
    }
    *(short *)((int)param_4 + 0x14e) = psVar1[1];
    param_4[0x52] = 0;
    local_70 = (ushort *)0x0;
    if (0 < *psVar1) {
      psVar11 = psVar1 + 10;
      iVar9 = param_2 * 0x38;
      do {
        iVar15 = iVar9;
        switch(*psVar11) {
        case 0:
        case 1:
          *(short *)(*param_4 + 0x32 + iVar9) = psVar11[0xf];
          *(int *)(*param_4 + 0x2c + iVar9) = (int)*psVar11;
          local_6c = (undefined1  [4])((int)local_6c + 1);
          *(short *)(*param_4 + 0x30 + iVar9) = psVar11[1];
          iVar15 = iVar9 + 0x38;
          *(undefined4 *)(iVar9 + *param_4) = *(undefined4 *)(psVar11 + -6);
          *(undefined4 *)(*param_4 + -0x34 + iVar15) = *(undefined4 *)(psVar11 + -4);
          *(undefined4 *)(*param_4 + -0x30 + iVar15) = *(undefined4 *)(psVar11 + -2);
          *(int *)(*param_4 + -0x2c + iVar15) = *param_3;
          *(undefined4 *)(*param_4 + -0x10 + iVar15) = *(undefined4 *)(psVar11 + 0xc);
          break;
        case 2:
          if (*(int *)*param_3 == 0x12345678) {
            *(int *)*param_3 = param_4[0x52];
            psVar14 = (short *)(*param_3 + 4);
            param_4[0x52] = (int)psVar14;
            *psVar14 = *psVar14 + -1;
          }
          break;
        case 3:
          _DAT_02921194 = *param_3;
        }
        *param_3 = *param_3 + *(int *)(psVar11 + -8) * 2;
        local_70 = (ushort *)((int)local_70 + 1);
        psVar11 = psVar11 + 0x1a;
        iVar9 = iVar15;
      } while ((int)local_70 < (int)*psVar1);
    }
    local_70 = (ushort *)param_4[0x52];
    if (local_70 != (ushort *)0x0) {
      do {
        uVar12 = (uint)*local_70;
        if (uVar12 != 0) {
          pfVar16 = (float *)(local_70 + 2);
          iVar9 = 1;
          do {
            if (pfVar16[1] != 2.1474836e+09) {
              if (iVar9 + 0xe < (int)uVar12) {
                fVar2 = *pfVar16;
                iVar15 = iVar9 + 0xf;
                fVar3 = pfVar16[2];
                iVar17 = iVar9;
                local_7c = fVar3;
                local_78 = fVar3;
                local_74 = fVar2;
                if (3 < (iVar15 - iVar9) + 1) {
                  iVar10 = (((iVar9 + 0xe) - iVar9) - 2U >> 2) + 1;
                  pfVar13 = pfVar16 + 5;
                  iVar17 = iVar9 + iVar10 * 4;
                  do {
                    if (pfVar13[-2] < local_74) {
                      local_74 = pfVar13[-2];
                    }
                    if (fVar2 < pfVar13[-2]) {
                      fVar2 = pfVar13[-2];
                      local_7c = fVar2;
                    }
                    if (*pfVar13 < local_78) {
                      local_78 = *pfVar13;
                    }
                    if (fVar3 < *pfVar13) {
                      fVar3 = *pfVar13;
                      local_7c = fVar3;
                    }
                    if (pfVar13[1] < local_74) {
                      local_74 = pfVar13[1];
                    }
                    if (fVar2 < pfVar13[1]) {
                      fVar2 = pfVar13[1];
                      local_7c = fVar2;
                    }
                    if (pfVar13[3] < local_78) {
                      local_78 = pfVar13[3];
                    }
                    if (fVar3 < pfVar13[3]) {
                      fVar3 = pfVar13[3];
                      local_7c = fVar3;
                    }
                    if (pfVar13[4] < local_74) {
                      local_74 = pfVar13[4];
                    }
                    if (fVar2 < pfVar13[4]) {
                      fVar2 = pfVar13[4];
                      local_7c = fVar2;
                    }
                    if (pfVar13[6] < local_78) {
                      local_78 = pfVar13[6];
                    }
                    if (fVar3 < pfVar13[6]) {
                      fVar3 = pfVar13[6];
                      local_7c = fVar3;
                    }
                    if (pfVar13[7] < local_74) {
                      local_74 = pfVar13[7];
                    }
                    if (fVar2 < pfVar13[7]) {
                      fVar2 = pfVar13[7];
                      local_7c = fVar2;
                    }
                    if (pfVar13[9] < local_78) {
                      local_78 = pfVar13[9];
                    }
                    if (fVar3 < pfVar13[9]) {
                      fVar3 = pfVar13[9];
                      local_7c = fVar3;
                    }
                    pfVar13 = pfVar13 + 0xc;
                    iVar10 = iVar10 + -1;
                  } while (iVar10 != 0);
                }
                if (iVar17 <= iVar15) {
                  pfVar13 = (float *)(local_70 + (iVar17 * 3 + 3) * 2);
                  iVar15 = (iVar15 - iVar17) + 1;
                  do {
                    if (pfVar13[-2] < local_74) {
                      local_74 = pfVar13[-2];
                    }
                    if (fVar2 < pfVar13[-2]) {
                      fVar2 = pfVar13[-2];
                      local_7c = fVar2;
                    }
                    if (*pfVar13 < local_78) {
                      local_78 = *pfVar13;
                    }
                    if (fVar3 < *pfVar13) {
                      fVar3 = *pfVar13;
                      local_7c = fVar3;
                    }
                    pfVar13 = pfVar13 + 3;
                    iVar15 = iVar15 + -1;
                  } while (iVar15 != 0);
                }
                pfVar16[1] = local_74;
                pfVar16[4] = fVar2;
                pfVar16[7] = local_78;
                pfVar16[10] = fVar3;
              }
              else {
                pfVar16[1] = 2.1474836e+09;
              }
            }
            uVar12 = (uint)*local_70;
            iVar15 = iVar9 + 0xf;
            pfVar16 = pfVar16 + 0x30;
            iVar9 = iVar9 + 0x10;
          } while (iVar15 < (int)uVar12);
        }
        local_70 = *(ushort **)(local_70 + -2);
      } while (local_70 != (ushort *)0x0);
      local_70 = (ushort *)0x0;
    }
    __security_check_cookie(local_4 ^ (uint)&local_7c);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_7c);
  return;
}

