/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62ab90; label: FUN_0062ab90
 */

void FUN_0062ab90(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 fVar15;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined8 uVar16;
  float local_c;
  float local_8;
  float local_4;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) && (param_5 != 0)) {
    if (param_3 <= *(int *)(param_1 + 0x208)) {
      *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + 1;
      *(undefined4 *)(param_1 + 0x208) = 0;
    }
    if (param_5 <= *(int *)(param_1 + 0x20c)) {
      *(undefined4 *)(param_1 + 0x20c) = 0;
    }
    iVar4 = *(int *)(param_1 + 0x20c);
    iVar5 = *(int *)(param_1 + 0x208);
    do {
      iVar6 = *(int *)(param_6 + *(int *)(param_1 + 0x20c) * 4);
      uVar11 = (uint)*(byte *)(iVar6 + 0x28d);
      do {
        iVar7 = *(int *)(param_4 + *(int *)(param_1 + 0x208) * 4);
        uVar12 = (uint)*(byte *)(iVar7 + 0x28d);
        FUN_005b3800(&local_c,iVar6 + 0x80,iVar7 + 0x80);
        fVar13 = (float10)local_8;
        fVar2 = *(float *)(iVar7 + 0x240);
        fVar3 = *(float *)(iVar6 + 0x230);
        fVar14 = (float10)(float)((float10)local_4 * (float10)local_4 +
                                 (float10)local_c * (float10)local_c + fVar13 * fVar13);
        if ((*(uint *)(iVar7 + 0x1fc) & 0x200) == 0) {
          fVar15 = (float10)(*(float *)(iVar7 + 0x230) + *(float *)(iVar6 + 0x240));
          if ((((*(uint *)(iVar7 + 0x1fc) & 0x4000) == 0) &&
              ((*(uint *)(iVar6 + 0x1fc) & 0x4000) == 0)) ||
             ((uVar16 = __allshl(), fVar15 = extraout_ST0, fVar14 = extraout_ST1,
              ((uint)uVar16 & *(uint *)(param_1 + 8 + uVar12 * 8)) == 0 &&
              ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(param_1 + 0xc + uVar12 * 8)) == 0 ||
              (extraout_ST0 * extraout_ST0 <= extraout_ST1)))) {
            if (((fVar15 * fVar15 <= fVar14) ||
                ((float10)*(float *)(iVar7 + 0x238) <= fVar13 - (float10)*(float *)(iVar6 + 0x1e0)))
               || (bVar9 = true,
                  (float10)*(float *)(iVar6 + 0x1e0) + fVar13 <= (float10)*(float *)(iVar7 + 0x23c))
               ) {
              bVar9 = false;
            }
          }
          else {
            bVar9 = true;
          }
        }
        else {
          bVar9 = true;
        }
        if ((*(uint *)(iVar6 + 0x1fc) & 0x200) == 0) {
          fVar15 = (float10)(fVar2 + fVar3);
          if (((((*(uint *)(iVar6 + 0x1fc) & 0x4000) == 0) &&
               ((*(uint *)(iVar7 + 0x1fc) & 0x4000) == 0)) ||
              (uVar16 = __allshl(), fVar15 = extraout_ST0_00, fVar14 = extraout_ST1_00,
              ((uint)uVar16 & *(uint *)(param_1 + 8 + uVar11 * 8)) == 0 &&
              ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(param_1 + 0xc + uVar11 * 8)) == 0)) ||
             (extraout_ST0_00 * extraout_ST0_00 <= extraout_ST1_00)) {
            if (((fVar15 * fVar15 <= fVar14) ||
                ((float10)*(float *)(iVar6 + 0x238) <= -fVar13 - (float10)*(float *)(iVar7 + 0x1e0))
                ) || ((float10)*(float *)(iVar7 + 0x1e0) - fVar13 <=
                      (float10)*(float *)(iVar6 + 0x23c))) {
              bVar8 = false;
            }
            else {
              bVar8 = true;
            }
          }
          else {
            bVar8 = true;
          }
        }
        else {
          bVar8 = true;
        }
        if (bVar8 || bVar9) {
          if ((((*(byte *)(param_1 + 0x210) & 1) == 0) && ((*(uint *)(iVar6 + 0x1fc) & 0x400) == 0))
             && ((*(uint *)(iVar7 + 0x1fc) & 0x400) == 0)) {
            iVar10 = FUN_0062a9a0(iVar7 + 0x80,&local_c,0,0,0x42c80000,param_7);
            if (iVar10 == 0) {
              uVar16 = __allshl();
              if (!bVar9) goto LAB_0062af68;
              puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
              goto LAB_0062af74;
            }
            if ((bVar9) && ((*(uint *)(iVar7 + 0x1fc) & 0x400) != 0)) {
              uVar16 = __allshl();
              puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
            }
            else {
              uVar16 = __allshl();
              puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
              *puVar1 = *puVar1 & ~(uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
              *puVar1 = *puVar1 & ~(uint)((ulonglong)uVar16 >> 0x20);
            }
            if ((bVar8) && ((*(uint *)(iVar6 + 0x1fc) & 0x400) != 0)) {
              uVar16 = __allshl();
              puVar1 = (uint *)(param_1 + 8 + uVar11 * 8);
              *puVar1 = *puVar1 | (uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar11 * 8);
              *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
              goto LAB_0062afc7;
            }
            uVar16 = __allshl();
          }
          else {
            if (bVar9) {
              uVar16 = __allshl();
              puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
              *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
            }
            else {
              uVar16 = __allshl();
LAB_0062af68:
              puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
              *puVar1 = *puVar1 & ~(uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
              *puVar1 = *puVar1 & ~(uint)((ulonglong)uVar16 >> 0x20);
            }
LAB_0062af74:
            uVar16 = __allshl();
            if (bVar8) {
              puVar1 = (uint *)(param_1 + 8 + uVar11 * 8);
              *puVar1 = *puVar1 | (uint)uVar16;
              puVar1 = (uint *)(param_1 + 0xc + uVar11 * 8);
              *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
              goto LAB_0062afc7;
            }
          }
          puVar1 = (uint *)(param_1 + 8 + uVar11 * 8);
          *puVar1 = *puVar1 & ~(uint)uVar16;
          puVar1 = (uint *)(param_1 + 0xc + uVar11 * 8);
          *puVar1 = *puVar1 & ~(uint)((ulonglong)uVar16 >> 0x20);
        }
        else {
          uVar16 = __allshl();
          puVar1 = (uint *)(param_1 + 8 + uVar11 * 8);
          *puVar1 = *puVar1 & ~(uint)uVar16;
          puVar1 = (uint *)(param_1 + 0xc + uVar11 * 8);
          *puVar1 = *puVar1 & ~(uint)((ulonglong)uVar16 >> 0x20);
          uVar16 = __allshl();
          puVar1 = (uint *)(param_1 + 8 + uVar12 * 8);
          *puVar1 = *puVar1 & ~(uint)uVar16;
          puVar1 = (uint *)(param_1 + 0xc + uVar12 * 8);
          *puVar1 = *puVar1 & ~(uint)((ulonglong)uVar16 >> 0x20);
        }
LAB_0062afc7:
        *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x208) + 1;
        param_2 = param_2 + -1;
        if (param_2 == 0) {
          return;
        }
        if ((iVar5 == *(int *)(param_1 + 0x208)) && (iVar4 == *(int *)(param_1 + 0x20c))) {
          return;
        }
      } while (*(int *)(param_1 + 0x208) < param_3);
      *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + 1;
      *(undefined4 *)(param_1 + 0x208) = 0;
      if (param_5 <= *(int *)(param_1 + 0x20c)) {
        *(undefined4 *)(param_1 + 0x20c) = 0;
      }
    } while ((iVar5 != 0) || (iVar4 != *(int *)(param_1 + 0x20c)));
  }
  return;
}

