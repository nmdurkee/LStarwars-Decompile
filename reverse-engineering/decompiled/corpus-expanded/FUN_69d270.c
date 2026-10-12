/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69d270; label: FUN_0069d270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069d270(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  int extraout_EDX;
  undefined8 uVar12;
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  uint local_10;
  uint local_c;
  
  iVar3 = FUN_0069cb10(param_1,param_2,param_3);
  if ((-1 < iVar3) && (iVar3 = FUN_0069bff0(), iVar6 = 0, iVar3 == 0)) {
LAB_0069d2a5:
    while( true ) {
      iVar3 = param_1 + 0x78;
      iVar4 = FUN_0069fce0(iVar3,local_20);
      if (iVar4 < 1) break;
      iVar4 = FUN_006a13f0(*(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48),local_20);
      if (iVar4 < 0) {
        FUN_0069fcc0(iVar3,0);
      }
      else {
        if (iVar6 != 0) {
          uVar5 = iVar4 + iVar6 >> 2;
          puVar8 = (uint *)(param_1 + 0x50);
          uVar7 = *puVar8;
          *puVar8 = *puVar8 + uVar5;
          *(int *)(param_1 + 0x54) =
               *(int *)(param_1 + 0x54) + (iVar4 + iVar6 >> 0x1f) + (uint)CARRY4(uVar7,uVar5);
        }
        iVar6 = FUN_006a0120(*(undefined4 *)(param_1 + 0x48),1);
        uVar7 = iVar6 + iVar4 >> 2;
        iVar6 = (iVar6 + iVar4 >> 0x1f) + *(int *)(param_1 + 0x54) +
                (uint)CARRY4(uVar7,*(uint *)(param_1 + 0x50));
        if ((param_3 < iVar6) ||
           ((param_3 <= iVar6 && (param_2 <= uVar7 + *(uint *)(param_1 + 0x50)))))
        goto LAB_0069d492;
        FUN_0069fcc0(iVar3,0);
        FUN_006a1320(param_1 + 0x250,local_20);
        FUN_006a23b0(param_1 + 0x1e0,param_1 + 0x250);
        iVar6 = iVar4;
        if ((-2 < (int)local_c) && (local_c < 0x80000000)) {
          iVar3 = *(int *)(param_1 + 0x60);
          iVar4 = *(int *)(param_1 + 0x44);
          puVar8 = (uint *)(iVar3 * 0x10 + iVar4);
          uVar7 = *puVar8;
          iVar10 = *(int *)(iVar3 * 0x10 + 4 + iVar4);
          *(uint *)(param_1 + 0x50) = local_10 - *puVar8;
          *(uint *)(param_1 + 0x54) = (local_c - iVar10) - (uint)(local_10 < uVar7);
          iVar10 = 0;
          if ((*(int *)(param_1 + 0x54) < 1) && (*(int *)(param_1 + 0x54) < 0)) {
            *(undefined4 *)(param_1 + 0x50) = 0;
            *(undefined4 *)(param_1 + 0x54) = 0;
          }
          if (0 < iVar3) {
            puVar8 = (uint *)(iVar4 + 8);
            do {
              uVar5 = *puVar8;
              puVar1 = (uint *)(param_1 + 0x50);
              uVar7 = *puVar1;
              *puVar1 = *puVar1 + uVar5;
              *(int *)(param_1 + 0x54) =
                   *(int *)(param_1 + 0x54) + puVar8[1] + (uint)CARRY4(uVar7,uVar5);
              iVar10 = iVar10 + 1;
              puVar8 = puVar8 + 4;
            } while (iVar10 < iVar3);
          }
        }
      }
    }
    if (((-1 < iVar4) || (iVar4 == -3)) &&
       (FUN_0069b340(local_30,0xffffffff,0xffffffff), -1 < extraout_EDX)) {
      iVar3 = FUN_0069ecc0(local_30);
      if (iVar3 != 0) {
        FUN_006a1ae0(param_1 + 0x1e0);
        FUN_006a1630(param_1 + 0x250);
        *(undefined4 *)(param_1 + 0x58) = 2;
      }
      if (*(int *)(param_1 + 0x58) < 3) goto code_r0x0069d41b;
      goto LAB_0069d47f;
    }
LAB_0069d492:
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if (*(int *)(param_1 + 0x54) <= param_3) {
      if (*(int *)(param_1 + 0x54) < param_3) goto LAB_0069d4c0;
      uVar7 = *(uint *)(param_1 + 0x50);
      while (uVar7 < param_2) {
LAB_0069d4c0:
        do {
          uVar5 = param_2 - *(uint *)(param_1 + 0x50);
          iVar3 = (param_3 - *(int *)(param_1 + 0x54)) - (uint)(param_2 < *(uint *)(param_1 + 0x50))
          ;
          uVar7 = FUN_006a2db0(param_1 + 0x1e0,0);
          if ((iVar3 <= (int)uVar7 >> 0x1f) && ((iVar3 < (int)uVar7 >> 0x1f || (uVar5 < uVar7)))) {
            uVar7 = uVar5;
          }
          FUN_006a2e10(param_1 + 0x1e0,uVar7);
          iVar6 = (int)uVar7 >> 0x1f;
          puVar8 = (uint *)(param_1 + 0x50);
          uVar2 = *puVar8;
          *puVar8 = *puVar8 + uVar7;
          *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + iVar6 + (uint)CARRY4(uVar2,uVar7);
          if ((iVar6 <= iVar3) &&
             (((iVar6 < iVar3 || (uVar7 < uVar5)) && (iVar3 = FUN_0069c090(0,1,1), iVar3 < 1)))) {
            uVar12 = FUN_0069c6b0(param_1,0xffffffff);
            *(undefined8 *)(param_1 + 0x50) = uVar12;
          }
        } while (*(int *)(param_1 + 0x54) < param_3);
        if (param_3 < *(int *)(param_1 + 0x54)) break;
        uVar7 = *(uint *)(param_1 + 0x50);
      }
    }
    iVar3 = 0;
  }
  return iVar3;
code_r0x0069d41b:
  iVar4 = FUN_0069ed70(local_30);
  iVar3 = *(int *)(param_1 + 0x34);
  iVar10 = 0;
  if (0 < iVar3) {
    piVar11 = *(int **)(param_1 + 0x40);
    do {
      if (*piVar11 == iVar4) break;
      iVar10 = iVar10 + 1;
      piVar11 = piVar11 + 1;
    } while (iVar10 < iVar3);
  }
  if (iVar10 != iVar3) {
    *(int *)(param_1 + 0x60) = iVar10;
    *(undefined4 *)(param_1 + 0x58) = 3;
    uVar9 = FUN_0069ed70(local_30);
    *(undefined4 *)(param_1 + 0x5c) = uVar9;
    FUN_0069fb50(param_1 + 0x78,iVar4);
    iVar3 = FUN_0069bff0();
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar6 = 0;
LAB_0069d47f:
    FUN_0069f7f0(param_1 + 0x78,local_30);
  }
  goto LAB_0069d2a5;
}

