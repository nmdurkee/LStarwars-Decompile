/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69cb10; label: FUN_0069cb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0069d173) */
/* WARNING: Removing unreachable block (ram,0x0069cf89) */
/* WARNING: Removing unreachable block (ram,0x0069ccca) */
/* WARNING: Removing unreachable block (ram,0x0069cbd1) */
/* WARNING: Removing unreachable block (ram,0x0069ceab) */
/* WARNING: Removing unreachable block (ram,0x0069d1f9) */
/* WARNING: Removing unreachable block (ram,0x0069cfb8) */

int FUN_0069cb10(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint extraout_EDX;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  undefined8 uVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  uint local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  uint local_60;
  int local_5c;
  uint uStack_40;
  uint uStack_3c;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  uint uStack_10;
  uint uStack_c;
  
  if (param_1[0x16] < 2) {
    lVar22 = -0x83;
  }
  else if ((param_1[1] == 0) || (param_1[0xd] < 0)) {
    lVar22 = -0x83;
  }
  else {
    lVar21 = 0;
    iVar9 = 0;
    lVar22 = 0;
    if (0 < param_1[0xd]) {
      do {
        lVar22 = FUN_0069c6b0(param_1,iVar9);
        lVar21 = lVar22 + lVar21;
        iVar9 = iVar9 + 1;
        lVar22 = lVar21;
      } while (iVar9 < param_1[0xd]);
    }
  }
  if (1 < param_1[0x16]) {
    if (param_1[1] == 0) {
      return -0x8a;
    }
    if ((-1 < param_3) && (CONCAT44(param_3,param_2) <= lVar22)) {
      iVar9 = param_1[0xd] + -1;
      if (-1 < iVar9) {
        puVar7 = (uint *)(iVar9 * 0x10 + 8 + param_1[0x11]);
        lVar21 = lVar22;
        do {
          lVar4 = *(longlong *)puVar7;
          iVar12 = ((int)((ulonglong)lVar21 >> 0x20) - puVar7[1]) - (uint)((uint)lVar21 < *puVar7);
          lVar22 = lVar21 - *(longlong *)puVar7;
          if ((iVar12 < param_3) ||
             ((iVar12 <= param_3 &&
              (lVar22 = lVar21 - *(longlong *)puVar7, (uint)lVar21 - *puVar7 <= param_2)))) break;
          iVar9 = iVar9 + -1;
          puVar7 = puVar7 + -4;
          lVar22 = lVar21 - lVar4;
          lVar21 = lVar21 - lVar4;
        } while (-1 < iVar9);
      }
      local_78 = (int)((ulonglong)lVar22 >> 0x20);
      local_7c = (uint)lVar22;
      puVar2 = (uint *)(param_1[0xe] + iVar9 * 8);
      puVar7 = puVar2 + 2;
      local_84 = *puVar2;
      local_80 = puVar2[1];
      iVar10 = iVar9 * 0x10;
      iVar12 = param_1[0x11];
      uVar13 = *(uint *)(iVar10 + iVar12);
      uVar11 = *(uint *)(iVar10 + 8 + iVar12);
      iVar3 = *(int *)(iVar10 + iVar12 + 4);
      iVar15 = uVar11 + uVar13;
      iVar12 = *(int *)(iVar10 + iVar12 + 0xc) + iVar3 + (uint)CARRY4(uVar11,uVar13);
      uVar11 = (uVar13 - local_7c) + param_2;
      iVar10 = ((iVar3 - local_78) - (uint)(uVar13 < local_7c)) + param_3 +
               (uint)CARRY4(uVar13 - local_7c,param_2);
      lVar22 = *(longlong *)puVar2;
      if (((int)local_80 <= (int)puVar2[3]) &&
         ((lVar21 = CONCAT44(iVar3,uVar13), lVar5 = CONCAT44(iVar12,iVar15),
          lVar4 = *(longlong *)puVar7, lVar6 = *(longlong *)puVar2, (int)local_80 < (int)puVar2[3]
          || (lVar21 = CONCAT44(iVar3,uVar13), lVar5 = CONCAT44(iVar12,iVar15),
             lVar4 = *(longlong *)puVar7, lVar6 = *(longlong *)puVar2, lVar22 = *(longlong *)puVar2,
             local_84 < *puVar7)))) {
        do {
          local_5c = (int)((ulonglong)lVar21 >> 0x20);
          local_60 = (uint)lVar21;
          lVar22 = lVar4 - CONCAT44(local_80,local_84);
          uVar13 = local_84;
          uVar16 = local_80;
          if (0xffff < lVar22) {
            uVar18 = __allmul(uVar11 - local_60,(iVar10 - local_5c) - (uint)(uVar11 < local_60),
                              lVar22);
            lVar22 = __alldiv(uVar18,lVar5 - lVar21);
            lVar22 = lVar22 + CONCAT44(local_80,local_84);
            uVar16 = (uint)lVar22;
            uVar13 = uVar16 - 0x10000;
            uVar16 = (int)((ulonglong)lVar22 >> 0x20) - (uint)(uVar16 < 0x10000);
            if (((int)uVar16 <= (int)local_80) &&
               (((int)uVar16 < (int)local_80 || (uVar13 <= local_84)))) {
              uVar13 = local_84 + 1;
              uVar16 = local_80 + (0xfffffffe < local_84);
            }
          }
          if (*param_1 == 0) {
            iVar12 = -0x81;
          }
          else if (((code *)param_1[0xb1] == (code *)0x0) ||
                  (iVar12 = (*(code *)param_1[0xb1])(*param_1,uVar13,uVar16,0), iVar12 == -1)) {
            iVar12 = -0x80;
          }
          else {
            param_1[2] = uVar13;
            param_1[3] = uVar16;
            FUN_0069fae0(param_1 + 6);
            iVar12 = 0;
          }
          if (iVar12 != 0) goto LAB_0069d224;
LAB_0069cd80:
          local_70 = (int)((ulonglong)lVar4 >> 0x20);
          local_74 = (uint)lVar4;
          lVar19 = FUN_0069b340(auStack_30,local_74 - param_1[2],
                                (local_70 - param_1[3]) - (uint)(local_74 < (uint)param_1[2]));
          iVar12 = (int)lVar19;
          if (lVar19 == -0x80) goto LAB_0069d224;
          lVar22 = lVar6;
          if ((lVar19 < 0x100000000) && (lVar19 < 0)) {
            uVar8 = local_80 + (0xfffffffe < local_84);
            if (((int)uVar16 < (int)uVar8) ||
               (((int)uVar16 <= (int)uVar8 && (uVar13 <= local_84 + 1)))) break;
            if (uVar13 == 0 && uVar16 == 0) goto LAB_0069d224;
            uVar14 = uVar13 - 0x10000;
            uVar16 = (uVar16 - 1) + (uint)(0xffff < uVar13);
            uVar13 = uVar14;
            if (((int)uVar16 <= (int)local_80) &&
               (((int)uVar16 < (int)local_80 || (uVar14 <= local_84)))) {
              uVar13 = local_84 + 1;
              uVar16 = uVar8;
            }
            lVar19 = lVar4;
            if (*param_1 == 0) {
              iVar12 = -0x81;
              bVar17 = false;
            }
            else if (((code *)param_1[0xb1] == (code *)0x0) ||
                    (iVar12 = (*(code *)param_1[0xb1])(*param_1,uVar13,uVar16,0), iVar12 == -1)) {
              iVar12 = -0x80;
              bVar17 = false;
            }
            else {
              param_1[2] = uVar13;
              param_1[3] = uVar16;
              FUN_0069fae0(param_1 + 6);
              iVar12 = 0;
              bVar17 = true;
            }
LAB_0069cf73:
            lVar4 = lVar19;
            if (!bVar17) goto LAB_0069d224;
LAB_0069cf79:
            lVar22 = lVar6;
            if (lVar4 <= CONCAT44(local_80,local_84)) break;
            goto LAB_0069cd80;
          }
          iVar12 = FUN_0069ed70(auStack_30);
          if (iVar12 != *(int *)(param_1[0x10] + iVar9 * 4)) goto LAB_0069cf79;
          lVar20 = FUN_0069ece0(auStack_30);
          if (lVar20 == -1) goto LAB_0069cf79;
          if (lVar20 < CONCAT44(iVar10,uVar11)) {
            uVar13 = param_1[2];
            uVar16 = param_1[3];
            uVar8 = (uint)(uVar11 < (uint)lVar20);
            uVar14 = iVar10 - (int)((ulonglong)lVar20 >> 0x20);
            bVar17 = -1 < (int)(uVar14 - uVar8);
            local_84 = uVar13;
            local_80 = uVar16;
            lVar21 = lVar20;
            lVar22 = lVar5;
            lVar6 = lVar19;
            if ((uVar14 != uVar8 && bVar17) || ((bVar17 && (0xac44 < uVar11 - (uint)lVar20))))
            goto LAB_0069cfa8;
            goto LAB_0069cf79;
          }
          uStack_40 = local_84 + 1;
          uStack_3c = local_80 + (0xfffffffe < local_84);
          if (((int)uVar16 < (int)uStack_3c) ||
             (((int)uVar16 <= (int)uStack_3c && (uVar13 <= uStack_40)))) break;
          lVar22 = lVar20;
          lVar4 = CONCAT44(uVar16,uVar13);
          if ((local_74 == param_1[2]) && (lVar4 = CONCAT44(uVar16,uVar13), local_70 == param_1[3]))
          {
            uVar8 = uVar13 - 0x10000;
            uVar16 = (uVar16 - 1) + (uint)(0xffff < uVar13);
            uVar13 = uVar8;
            if (((int)uVar16 <= (int)local_80) &&
               (((int)uVar16 < (int)local_80 || (uVar8 <= local_84)))) {
              uVar13 = uStack_40;
              uVar16 = uStack_3c;
            }
            iVar12 = FUN_0069b2e0(uVar13,uVar16);
            bVar17 = iVar12 == 0;
            goto LAB_0069cf73;
          }
LAB_0069cfa8:
          lVar5 = lVar22;
          lVar22 = lVar6;
        } while (CONCAT44(local_80,local_84) < lVar4);
      }
      iVar12 = FUN_0069b2e0(lVar22);
      param_1[0x14] = -1;
      param_1[0x15] = -1;
      if (iVar12 == 0) {
        lVar21 = FUN_0069b340(&uStack_40,0xffffffff,0xffffffff);
        iVar12 = (int)lVar21;
        if (-1 < lVar21) {
          if (iVar9 == param_1[0x18]) {
            FUN_006a2310(param_1 + 0x78);
          }
          else {
            FUN_0069c060();
            param_1[0x18] = iVar9;
            param_1[0x17] = *(int *)(param_1[0x10] + iVar9 * 4);
            param_1[0x16] = 3;
          }
          piVar1 = param_1 + 0x1e;
          FUN_0069fb50(piVar1,param_1[0x17]);
          FUN_0069f7f0(piVar1,&uStack_40);
          iVar9 = FUN_0069fce0(piVar1,auStack_20);
          while (iVar9 != 0) {
            if (iVar9 >> 0x1f < 0) {
              iVar12 = -0x88;
              goto LAB_0069d224;
            }
            if ((uStack_10 & uStack_c) != 0xffffffff) {
              puVar7 = (uint *)(param_1[0x18] * 0x10 + param_1[0x11]);
              iVar9 = (uStack_c - *(int *)(param_1[0x18] * 0x10 + 4 + param_1[0x11])) -
                      (uint)(uStack_10 < *puVar7);
              param_1[0x14] = uStack_10 - *puVar7;
              param_1[0x15] = iVar9;
              if ((iVar9 < 1) && (iVar9 < 0)) {
                param_1[0x14] = 0;
                param_1[0x15] = 0;
              }
              puVar7 = (uint *)(param_1 + 0x14);
              uVar13 = *puVar7;
              *puVar7 = *puVar7 + local_7c;
              param_1[0x15] = param_1[0x15] + local_78 + (uint)CARRY4(uVar13,local_7c);
              if ((param_1[0x15] <= param_3) &&
                 (((param_1[0x15] < param_3 || ((uint)param_1[0x14] <= param_2)) &&
                  (lVar22 = FUN_0069c6b0(param_1,0xffffffff), CONCAT44(param_3,param_2) <= lVar22)))
                 ) {
                param_1[0x1a] = 0;
                param_1[0x1b] = 0;
                param_1[0x1c] = 0;
                param_1[0x1d] = 0;
                return 0;
              }
              iVar12 = -0x81;
              goto LAB_0069d224;
            }
            FUN_0069fcc0(piVar1,0);
            iVar9 = FUN_0069fce0(piVar1,auStack_20);
          }
          iVar12 = FUN_0069b2e0(lVar22);
          if (-1 < iVar12 >> 0x1f) {
            lVar22 = FUN_0069b3f0(&uStack_40);
            iVar12 = (int)lVar22;
            while (-1 < lVar22) {
              do {
                iVar9 = FUN_0069ed70(&uStack_40);
                if ((iVar9 == param_1[0x17]) &&
                   ((FUN_0069ece0(&uStack_40), extraout_EDX < 0x80000000 ||
                    (iVar9 = FUN_0069ecb0(&uStack_40), iVar9 == 0)))) {
                  iVar9 = FUN_0069c7a0(param_1,lVar22);
                  return iVar9;
                }
                *(longlong *)(param_1 + 2) = lVar22;
                lVar22 = FUN_0069b3f0(&uStack_40);
                iVar12 = (int)lVar22;
              } while (0xffffffff < lVar22);
            }
          }
        }
      }
LAB_0069d224:
      param_1[0x14] = -1;
      param_1[0x15] = -1;
      FUN_006a1ae0(param_1 + 0x78);
      FUN_006a1630(param_1 + 0x94);
      param_1[0x16] = 2;
      return iVar12;
    }
  }
  return -0x83;
}

