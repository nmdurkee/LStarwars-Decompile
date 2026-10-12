/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69bbf0; label: FUN_0069bbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0069be72) */

void FUN_0069bbf0(int param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_EAX;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar9;
  bool bVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  uint uStack_38;
  int iStack_34;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [32];
  
  pvVar4 = _realloc((void *)in_EAX[0x12],in_EAX[0xd] << 5);
  in_EAX[0x12] = (int)pvVar4;
  pvVar4 = _realloc((void *)in_EAX[0x13],in_EAX[0xd] << 4);
  in_EAX[0x13] = (int)pvVar4;
  pvVar4 = _malloc(in_EAX[0xd] * 4);
  in_EAX[0x10] = (int)pvVar4;
  pvVar4 = _malloc(in_EAX[0xd] * 8);
  in_EAX[0xf] = (int)pvVar4;
  pvVar4 = _malloc(in_EAX[0xd] << 4);
  in_EAX[0x11] = (int)pvVar4;
  if (0 < in_EAX[0xd]) {
    iVar9 = 0;
    do {
      if (iVar9 == 0) {
        *(int *)in_EAX[0x10] = in_EAX[0x17];
        piVar2 = (int *)in_EAX[0xf];
        *piVar2 = param_1;
        piVar2[1] = param_2;
        if (((*in_EAX == 0) || ((code *)in_EAX[0xb1] == (code *)0x0)) ||
           (iVar5 = (*(code *)in_EAX[0xb1])(*in_EAX,param_1,param_2,0), iVar5 == -1)) {
          puVar3 = (undefined4 *)in_EAX[0xf];
          *puVar3 = 0xffffffff;
          puVar3[1] = 0xffffffff;
        }
        else {
          in_EAX[2] = param_1;
          in_EAX[3] = param_2;
          FUN_0069fae0(in_EAX + 6);
        }
      }
      else {
        iVar5 = *(int *)(in_EAX[0xe] + iVar9 * 8);
        iVar6 = *(int *)(in_EAX[0xe] + 4 + iVar9 * 8);
        if (((*in_EAX == 0) || ((code *)in_EAX[0xb1] == (code *)0x0)) ||
           (iVar7 = (*(code *)in_EAX[0xb1])(*in_EAX,iVar5,iVar6,0), iVar7 == -1)) {
          iVar5 = in_EAX[0xf];
          *(undefined4 *)(iVar5 + iVar9 * 8) = 0xffffffff;
          *(undefined4 *)(iVar5 + 4 + iVar9 * 8) = 0xffffffff;
        }
        else {
          in_EAX[2] = iVar5;
          in_EAX[3] = iVar6;
          FUN_0069fae0(in_EAX + 6);
          iVar6 = FUN_0069b9c0(iVar9 * 0x20 + in_EAX[0x12],iVar9 * 0x10 + in_EAX[0x13],
                               in_EAX[0x10] + iVar9 * 4);
          iVar5 = in_EAX[0xf];
          if (iVar6 < 0) {
            *(undefined4 *)(iVar5 + iVar9 * 8) = 0xffffffff;
            *(undefined4 *)(iVar5 + 4 + iVar9 * 8) = 0xffffffff;
          }
          else {
            *(int *)(iVar5 + iVar9 * 8) = in_EAX[2];
            *(int *)(iVar5 + 4 + iVar9 * 8) = in_EAX[3];
          }
        }
      }
      if ((*(uint *)(in_EAX[0xf] + iVar9 * 8) & *(uint *)(in_EAX[0xf] + 4 + iVar9 * 8)) !=
          0xffffffff) {
        uStack_38 = 0;
        iStack_34 = 0;
        lVar11 = 0;
        piVar2 = in_EAX + 0x1e;
        iVar5 = -1;
        FUN_0069fb50(piVar2,*(undefined4 *)(in_EAX[0x10] + iVar9 * 4));
        FUN_0069b340(auStack_30,0xffffffff,0xffffffff);
        if (-1 < extraout_EDX) {
          do {
            lVar11 = CONCAT44(iStack_34,uStack_38);
            iVar6 = FUN_0069ecc0(auStack_30);
            if (iVar6 != 0) break;
            iVar6 = FUN_0069ed70(auStack_30);
            if (iVar6 == *(int *)(in_EAX[0x10] + iVar9 * 4)) {
              FUN_0069f7f0(piVar2,auStack_30);
              iVar6 = FUN_0069fcc0(piVar2,auStack_20);
              while (iVar6 != 0) {
                iVar7 = iVar5;
                if ((0 < iVar6) &&
                   (iVar7 = FUN_006a13f0(iVar9 * 0x20 + in_EAX[0x12],auStack_20), iVar5 != -1)) {
                  uVar8 = iVar7 + iVar5 >> 2;
                  bVar10 = CARRY4(uStack_38,uVar8);
                  uStack_38 = uStack_38 + uVar8;
                  iStack_34 = iStack_34 + (iVar7 + iVar5 >> 0x1f) + (uint)bVar10;
                }
                iVar6 = FUN_0069fcc0(piVar2,auStack_20);
                iVar5 = iVar7;
              }
              lVar11 = FUN_0069ece0(auStack_30);
              if (lVar11 != -1) {
                lVar11 = FUN_0069ece0(auStack_30);
                lVar11 = lVar11 - CONCAT44(iStack_34,uStack_38);
                break;
              }
            }
            lVar11 = CONCAT44(iStack_34,uStack_38);
            FUN_0069b340(auStack_30,0xffffffff,0xffffffff);
          } while ((0 < extraout_EDX_00) || (-1 < extraout_EDX_00));
          iStack_34 = (int)((ulonglong)lVar11 >> 0x20);
          if ((iStack_34 < 1) && (lVar11 < 0)) {
            lVar11 = 0;
          }
        }
        iStack_34 = (int)((ulonglong)lVar11 >> 0x20);
        uStack_38 = (uint)lVar11;
        iVar5 = in_EAX[0x11];
        *(uint *)(iVar9 * 0x10 + iVar5) = uStack_38;
        *(int *)(iVar9 * 0x10 + 4 + iVar5) = iStack_34;
      }
      iVar5 = *(int *)(in_EAX[0xe] + 8 + iVar9 * 8);
      iVar6 = *(int *)(in_EAX[0xe] + 0xc + iVar9 * 8);
      if (((*in_EAX == 0) || ((code *)in_EAX[0xb1] == (code *)0x0)) ||
         (iVar7 = (*(code *)in_EAX[0xb1])(*in_EAX,iVar5,iVar6,0), iVar7 == -1)) {
        FUN_006a0180(iVar9 * 0x20 + in_EAX[0x12]);
        FUN_006a00b0(iVar9 * 0x10 + in_EAX[0x13]);
      }
      else {
        in_EAX[2] = iVar5;
        in_EAX[3] = iVar6;
        FUN_0069fae0(in_EAX + 6);
        lVar11 = FUN_0069b3f0(auStack_30);
        while (-1 < lVar11) {
          do {
            iVar5 = FUN_0069ed70(auStack_30);
            if ((iVar5 == *(int *)(in_EAX[0x10] + iVar9 * 4)) &&
               (lVar12 = FUN_0069ece0(auStack_30), lVar12 != -1)) {
              puVar1 = (uint *)(iVar9 * 0x10 + in_EAX[0x11]);
              uVar13 = FUN_0069ece0(auStack_30);
              puVar1[2] = (uint)uVar13 - *puVar1;
              puVar1[3] = ((int)((ulonglong)uVar13 >> 0x20) - puVar1[1]) -
                          (uint)((uint)uVar13 < *puVar1);
              goto LAB_0069bfd6;
            }
            *(longlong *)(in_EAX + 2) = lVar11;
            lVar11 = FUN_0069b3f0(auStack_30);
          } while (0xffffffff < lVar11);
        }
        FUN_006a0180(iVar9 * 0x20 + in_EAX[0x12]);
        FUN_006a00b0(iVar9 * 0x10 + in_EAX[0x13]);
      }
LAB_0069bfd6:
      iVar9 = iVar9 + 1;
    } while (iVar9 < in_EAX[0xd]);
  }
  return;
}

