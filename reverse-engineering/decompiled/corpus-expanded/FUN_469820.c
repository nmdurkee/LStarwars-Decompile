/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x469820; label: FUN_00469820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00469820(int param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  float10 fVar13;
  float local_40;
  float local_3c;
  int *local_38;
  int local_34;
  undefined4 *local_30;
  float local_24 [2];
  float local_1c;
  float local_18;
  float local_10;
  undefined1 local_c [12];
  
  iVar7 = param_1;
  local_3c = 1e+09;
  local_40 = 1e+09;
  local_30 = (undefined4 *)0x0;
  local_38 = (int *)0x0;
  local_34 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar5 = FUN_0041aef0(param_2);
  if ((iVar5 == 0) &&
     (((*(byte *)(param_2 + 0x1fc) & 0x80) == 0 || (iVar5 = FUN_0056e160(0x19), iVar5 == 0)))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  *(undefined4 *)(param_2 + 0x10cc) = 0;
  *(undefined4 *)(param_2 + 0x10d0) = 0;
  psVar1 = (short *)(param_1 + 0x10);
  local_18 = (float)(&DAT_029899a0)[*(ushort *)(param_2 + 0x5a) >> 1];
  local_10 = (float)(&DAT_029899a0)[(int)(*(ushort *)(param_2 + 0x5a) + 0x4000) >> 1 & 0x7fff];
  param_1 = 0;
  if (*psVar1 != 0) {
    do {
      iVar5 = *(int *)(*(int *)(iVar7 + 4) + param_1 * 4);
      if (((*(int *)(iVar5 + 0x38) == 0) && (*(int *)(iVar5 + 0x3c) == 0)) &&
         (((*(byte *)(iVar5 + 0x74) & 0x10) == 0 ||
          (((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 4) != 0 || (bVar4)))))) {
        iVar10 = *(int *)(iVar5 + 0x40);
        if (iVar10 == 0) {
          iVar10 = FUN_00467890(iVar5);
joined_r0x00469969:
          if (iVar10 == 0) {
LAB_0046996f:
            iVar10 = FUN_004677d0(iVar5,param_2);
            if (iVar10 == 0) {
              fVar13 = (float10)FUN_005b3c50(iVar5 + 0x1c,param_2 + 0x80,local_24);
              if ((float)fVar13 <= *(float *)(iVar5 + 0x54) * *(float *)(iVar5 + 0x54)) {
                if ((*(uint *)(iVar5 + 0x74) & 0x400) == 0) {
                  if (0.0 <= local_24[0] * local_18 + local_1c * local_10) {
                    (&DAT_00877ae8)[local_34 * 4] = (float)fVar13;
                    *(int *)(&DAT_00877ae0 + local_34 * 0x10) = iVar5;
                    *(undefined4 *)(&DAT_00877ae4 + local_34 * 0x10) = 0;
                    iVar5 = *(int *)(*(int *)(iVar5 + 0x28) + 0x18);
                    if (iVar5 == 0) {
                      (&DAT_00877aec)[local_34 * 4] = 0xffffffff;
                      local_34 = local_34 + 1;
                    }
                    else {
                      (&DAT_00877aec)[local_34 * 4] =
                           (iVar5 - *(int *)(*(int *)(iVar7 + 0x14) + 8)) / 0x28;
                      local_34 = local_34 + 1;
                    }
                  }
                }
                else {
                  piVar12 = *(int **)(*(int *)(iVar5 + 0x28) + 0x18);
                  if (piVar12 != (int *)0x0) {
                    piVar9 = (int *)(&DAT_00877ae0 + local_34 * 0x10);
                    do {
                      if ((*(byte *)(piVar12 + 8) & 1) == 0) {
                        uVar6 = FUN_005cf9e0(piVar12 + 1);
                        fVar13 = (float10)FUN_005b3c50(uVar6,param_2 + 0x80,local_24);
                        if (0.0 <= local_24[0] * local_18 + local_1c * local_10) {
                          local_34 = local_34 + 1;
                          piVar9[2] = (int)(float)fVar13;
                          *piVar9 = iVar5;
                          piVar9[1] = (int)piVar12;
                          piVar9[3] = ((int)piVar12 - *(int *)(*(int *)(iVar7 + 0x14) + 8)) / 0x28;
                          piVar9 = piVar9 + 4;
                        }
                      }
                      piVar12 = (int *)*piVar12;
                    } while (piVar12 != (int *)0x0);
                  }
                }
              }
            }
          }
        }
        else {
          if ((*(char *)(iVar10 + 0x26) == '\0') ||
             (iVar5 == *(int *)(iVar10 + -4 + (uint)*(byte *)(iVar10 + 0x26) * 4)))
          goto LAB_0046996f;
          if (((*(byte *)(iVar10 + 0x24) & 1) == 0) && (*(int *)(*(int *)(iVar5 + 0x28) + 0xc) != 2)
             ) {
            iVar10 = *(int *)(iVar10 + -4 + (uint)*(byte *)(iVar10 + 0x26) * 4);
            if (iVar10 == 0) goto LAB_0046996f;
            if ((*(ushort *)(*(int *)(iVar10 + 0x28) + 10) & 7) == 0) {
              iVar10 = *(int *)(iVar10 + 0x38);
              goto joined_r0x00469969;
            }
          }
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 < (int)(uint)*(ushort *)(iVar7 + 0x10));
  }
  iVar7 = *(int *)(param_2 + 0x800);
  if (iVar7 == 0) goto LAB_00469e29;
  piVar12 = (int *)0x0;
  iVar5 = 0;
  piVar9 = (int *)&DAT_00877ae0;
  if (3 < local_34) {
    iVar10 = (local_34 - 4U >> 2) + 1;
    iVar5 = iVar10 * 4;
    do {
      iVar2 = *(int *)(iVar7 + 0x30 + piVar9[3] * 4);
      fVar3 = (float)iVar2;
      if (iVar2 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < local_40) {
        piVar12 = piVar9;
        local_40 = fVar3;
      }
      iVar2 = *(int *)(iVar7 + 0x30 + piVar9[7] * 4);
      fVar3 = (float)iVar2;
      if (iVar2 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < local_40) {
        piVar12 = piVar9 + 4;
        local_40 = fVar3;
      }
      iVar2 = *(int *)(iVar7 + 0x30 + piVar9[0xb] * 4);
      fVar3 = (float)iVar2;
      if (iVar2 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < local_40) {
        piVar12 = piVar9 + 8;
        local_40 = fVar3;
      }
      iVar2 = *(int *)(iVar7 + 0x30 + piVar9[0xf] * 4);
      fVar3 = (float)iVar2;
      if (iVar2 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < local_40) {
        piVar12 = piVar9 + 0xc;
        local_40 = fVar3;
      }
      piVar9 = piVar9 + 0x10;
      iVar10 = iVar10 + -1;
      local_38 = piVar12;
    } while (iVar10 != 0);
  }
  if (iVar5 < local_34) {
    iVar5 = local_34 - iVar5;
    do {
      iVar10 = *(int *)(*(int *)(param_2 + 0x800) + 0x30 + piVar9[3] * 4);
      fVar3 = (float)iVar10;
      if (iVar10 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < local_40) {
        local_38 = piVar9;
        local_40 = fVar3;
      }
      piVar9 = piVar9 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (local_38 == (int *)0x0) goto LAB_00469e29;
  *(undefined4 *)(iVar7 + 0x30 + local_38[3] * 4) = DAT_009250a8;
  iVar7 = local_38[3];
  if ((*(uint *)(*local_38 + 0x74) & 0x800) == 0) {
    iVar5 = *(int *)(param_2 + 0x800);
LAB_00469e17:
    puVar8 = (uint *)(iVar5 + (iVar7 >> 5) * 4);
  }
  else {
    puVar8 = (uint *)(*(int *)(param_2 + 0x800) + (iVar7 >> 5) * 4);
    *puVar8 = *puVar8 & ~(1 << ((byte)iVar7 & 0x1f));
    if (local_38[1] == 0) {
      FUN_005b3800(local_c,*local_38 + 0x1c,param_2 + 0x80);
      iVar7 = FUN_0067b430(param_2 + 0x80,local_c,0,0x3f800000,0,0);
      if (iVar7 != 0) {
        if (((*(uint *)(*local_38 + 0xa0) & 0x100) != 0) && (iVar7 = FUN_0067fb40(), iVar7 != -1)) {
          for (puVar11 = *(undefined4 **)(*(int *)(*local_38 + 0x28) + 0x18);
              puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)*puVar11) {
            iVar7 = FUN_0067fb40();
            if (*(short *)(puVar11[9] + 2) == iVar7) goto LAB_00469e00;
          }
        }
        goto LAB_00469e29;
      }
LAB_00469e00:
      iVar7 = local_38[3];
      iVar5 = *(int *)(param_2 + 0x800);
      goto LAB_00469e17;
    }
    uVar6 = FUN_005cf9e0(local_38[1] + 4);
    FUN_005b3800(local_c,uVar6,param_2 + 0x80);
    iVar7 = FUN_0067b430(param_2 + 0x80,local_c,0,0x3f800000,0,0);
    if (iVar7 == 0) {
      iVar7 = local_38[3];
      puVar8 = (uint *)(*(int *)(param_2 + 0x800) + (iVar7 >> 5) * 4);
    }
    else {
      iVar7 = FUN_0067fb40();
      if ((iVar7 == -1) ||
         (iVar7 = FUN_0067fb40(), *(short *)(*(int *)(local_38[1] + 0x24) + 2) != iVar7))
      goto LAB_00469e29;
      iVar7 = local_38[3];
      puVar8 = (uint *)(*(int *)(param_2 + 0x800) + (iVar7 >> 5) * 4);
    }
  }
  *puVar8 = *puVar8 | 1 << ((byte)iVar7 & 0x1f);
LAB_00469e29:
  iVar7 = 0;
  puVar11 = (undefined4 *)&DAT_00877ae0;
  if (3 < local_34) {
    iVar5 = *(int *)(param_2 + 0x800);
    iVar10 = (local_34 - 4U >> 2) + 1;
    iVar7 = iVar10 * 4;
    do {
      if ((((iVar5 == 0) || (iVar2 = puVar11[3], iVar2 == -1)) ||
          ((*(uint *)(iVar5 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0)) &&
         ((float)puVar11[2] < local_3c)) {
        local_3c = (float)puVar11[2];
        local_30 = puVar11;
      }
      if ((((iVar5 == 0) || (iVar2 = puVar11[7], iVar2 == -1)) ||
          ((*(uint *)(iVar5 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0)) &&
         ((float)puVar11[6] < local_3c)) {
        local_3c = (float)puVar11[6];
        local_30 = puVar11 + 4;
      }
      if ((((iVar5 == 0) || (iVar2 = puVar11[0xb], iVar2 == -1)) ||
          ((*(uint *)(iVar5 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0)) &&
         ((float)puVar11[10] < local_3c)) {
        local_3c = (float)puVar11[10];
        local_30 = puVar11 + 8;
      }
      if ((((iVar5 == 0) || (iVar2 = puVar11[0xf], iVar2 == -1)) ||
          ((*(uint *)(iVar5 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0)) &&
         ((float)puVar11[0xe] < local_3c)) {
        local_3c = (float)puVar11[0xe];
        local_30 = puVar11 + 0xc;
      }
      puVar11 = puVar11 + 0x10;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (iVar7 < local_34) {
    local_34 = local_34 - iVar7;
    do {
      if ((((*(int *)(param_2 + 0x800) == 0) || (iVar7 = puVar11[3], iVar7 == -1)) ||
          ((*(uint *)(*(int *)(param_2 + 0x800) + (iVar7 >> 5) * 4) & 1 << ((byte)iVar7 & 0x1f)) !=
           0)) && ((float)puVar11[2] < local_3c)) {
        local_3c = (float)puVar11[2];
        local_30 = puVar11;
      }
      puVar11 = puVar11 + 4;
      local_34 = local_34 + -1;
    } while (local_34 != 0);
  }
  if (local_30 != (undefined4 *)0x0) {
    *(undefined4 *)(param_2 + 0x10cc) = *local_30;
    *(undefined4 *)(param_2 + 0x10d0) = local_30[1];
  }
  return 0;
}

