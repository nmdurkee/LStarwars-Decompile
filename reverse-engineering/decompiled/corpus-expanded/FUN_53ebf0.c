/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53ebf0; label: FUN_0053ebf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0053ebf0(int *param_1,float *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 extraout_CX;
  uint in_ECX;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  float *pfVar14;
  float10 fVar15;
  undefined8 uVar16;
  uint local_34;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar13 = param_4 * 0x13c + *param_1;
  *(undefined1 *)((int)param_3 + 1) = 0xff;
  local_18 = 0;
  if (*(char *)(iVar13 + 0x32) != '\0') {
    uVar6 = *(ushort *)(iVar13 + 0x68) & 1;
    if (uVar6 == 0) {
      if ((((*(float *)(iVar13 + 0x40) <= *param_2) && (*param_2 <= *(float *)(iVar13 + 0x4c))) &&
          ((*(float *)(iVar13 + 0x44) <= param_2[1] &&
           ((param_2[1] <= *(float *)(iVar13 + 0x50) && (*(float *)(iVar13 + 0x48) <= param_2[2]))))
          )) && (param_2[2] <= *(float *)(iVar13 + 0x54))) {
LAB_0053ecbf:
        uVar7 = (uint)*(ushort *)(iVar13 + 0x30);
        if (*(char *)(iVar13 + 0x33) != '\0') {
          uVar7 = uVar7 + 1;
        }
        local_1c = in_ECX;
        if (in_ECX == 0xffffffff) {
          local_1c = uVar7 / 2;
        }
        local_c = local_1c + 1;
        local_8 = local_1c - 1;
        local_20 = 0;
        local_24 = 0;
        do {
          if (local_20 == 0) {
            local_34 = local_1c;
          }
          else if (local_20 == 1) {
            local_34 = local_c;
            local_c = local_c + 1;
          }
          else {
            local_34 = local_8;
            local_8 = local_8 - 1;
          }
          if (((int)local_34 < 0) || ((int)uVar7 <= (int)local_34)) {
            local_24 = local_24 | local_20;
          }
          else {
            local_10 = local_34 + 1;
            if ((local_10 == uVar7) && (*(char *)(iVar13 + 0x33) != '\0')) {
              local_10 = 0;
            }
            fVar3 = *param_2;
            iVar11 = *(int *)(*(int *)(iVar13 + 4) + 8);
            puVar1 = (undefined4 *)(iVar11 + local_34 * 0xc);
            iVar9 = *(int *)(*(int *)(iVar13 + 8) + 8);
            puVar8 = (undefined4 *)(local_34 * 0xc + iVar9);
            iVar5 = local_10 * 0xc;
            puVar2 = (undefined4 *)(iVar5 + iVar9);
            pfVar14 = (float *)(local_34 * 0x80 + *(int *)(iVar13 + 0x34));
            iVar11 = iVar11 + iVar5;
            fVar4 = *pfVar14;
            if (uVar6 == 0) {
              local_18 = *(int *)(*(int *)(iVar13 + 0xc) + 8) + iVar5;
              if ((((fVar4 < fVar3 != (fVar4 == fVar3)) && (*param_2 <= pfVar14[3])) &&
                  ((pfVar14[1] < param_2[1] != (pfVar14[1] == param_2[1]) &&
                   (((param_2[1] <= pfVar14[4] &&
                     (pfVar14[2] < param_2[2] != (pfVar14[2] == param_2[2]))) &&
                    (param_2[2] <= pfVar14[5])))))) &&
                 (((iVar9 = FUN_0053dd10(param_2), iVar9 != 0 &&
                   (iVar9 = FUN_0053dd10(param_2), iVar9 != 0)) &&
                  ((iVar9 = FUN_0053dd10(param_2), iVar9 != 0 &&
                   (((iVar9 = FUN_0053dd10(param_2), iVar9 != 0 &&
                     (iVar9 = FUN_0053dd10(param_2), iVar9 != 0)) &&
                    (iVar9 = FUN_0053dd10(param_2), iVar9 != 0)))))))) {
                uVar10 = (undefined2)local_34;
LAB_0053eec3:
                *(undefined1 *)((int)param_3 + 1) = (undefined1)param_4;
                *(undefined2 *)((int)param_3 + 2) = uVar10;
                if ((*(byte *)(iVar13 + 0x68) & 1) == 0) {
                  fVar15 = (float10)FUN_0053ddd0(param_2,puVar1,pfVar14 + 6,local_18,pfVar14 + 0x15)
                  ;
                  param_3[1] = (float)fVar15;
                }
                else {
                  fVar15 = (float10)FUN_0053ded0(param_2,puVar8,puVar1,puVar2,iVar11);
                  param_3[1] = (float)fVar15;
                }
                *(undefined2 *)(param_3 + 10) = (undefined2)local_10;
                FUN_0053eb80(&DAT_009242d0);
                fVar15 = (float10)FUN_005b3c50(param_2,&DAT_009242d0,0);
                FUN_0053e900();
                _DAT_02983a20 = *param_3;
                _DAT_02983a24 = param_3[1];
                return (float10)(float)fVar15;
              }
            }
            else if ((((fVar4 < fVar3 != (fVar4 == fVar3)) && (*param_2 <= pfVar14[3])) &&
                     (pfVar14[2] < param_2[2] != (pfVar14[2] == param_2[2]))) &&
                    (param_2[2] <= pfVar14[5])) {
              uVar16 = FUN_0053dd50(*param_2,param_2[2],*puVar8,puVar8[2],*puVar1,puVar1[2]);
              puVar12 = (undefined4 *)((ulonglong)uVar16 >> 0x20);
              if ((int)uVar16 != 0) {
                uVar16 = FUN_0053dd50(*param_2,param_2[2],*puVar1,puVar1[2],*puVar12,puVar12[2]);
                puVar12 = (undefined4 *)((ulonglong)uVar16 >> 0x20);
                if (((int)uVar16 != 0) &&
                   (iVar11 = FUN_0053dd50(*param_2,param_2[2],*puVar12,puVar12[2],*puVar2,puVar2[2])
                   , iVar11 != 0)) {
                  uVar16 = FUN_0053dd50(*param_2,param_2[2],*puVar2,puVar2[2],*puVar8,puVar8[2]);
                  iVar11 = (int)((ulonglong)uVar16 >> 0x20);
                  uVar10 = extraout_CX;
                  if ((int)uVar16 != 0) goto LAB_0053eec3;
                }
              }
            }
          }
          if (local_24 == 3) {
            return (float10)1e+06;
          }
          local_20 = 2 - (local_20 != 1);
        } while( true );
      }
    }
    else if ((((*(float *)(iVar13 + 0x40) <= *param_2) && (*param_2 <= *(float *)(iVar13 + 0x4c)))
             && (*(float *)(iVar13 + 0x48) <= param_2[2])) &&
            (param_2[2] <= *(float *)(iVar13 + 0x54))) goto LAB_0053ecbf;
  }
  return (float10)0;
}

