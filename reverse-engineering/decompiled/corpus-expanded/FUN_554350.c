/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554350; label: FUN_00554350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00554350(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_40 [16];
  
  iVar3 = param_1;
  iVar6 = *(int *)(param_1 + 0x46e0);
  iVar7 = 0;
  bVar2 = false;
  if ((iVar6 != 0) &&
     (piVar1 = (int *)(param_1 + 0x128), param_1 = 0, *(char *)(*piVar1 + 0xf2) != '\0')) {
    do {
      if ((*(byte *)(iVar6 + 0xac + iVar7) & 1) != 0) {
        uVar5 = FUN_005cffb0(iVar6 + 0x50 + iVar7);
        FUN_0067c760(uVar5);
        FUN_005b44e0(local_40);
        FUN_005b4670(local_40,0);
        FUN_005b4f70(local_40,*(undefined2 *)(*(int *)(iVar3 + 0x46e0) + 0x7c + iVar7));
        FUN_005b4900(local_40,*(int *)(iVar3 + 0x46e0) + 0x5c + iVar7);
        puVar8 = local_40;
        puVar11 = (undefined4 *)(*(int *)(iVar3 + 0x46e0) + iVar7);
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar6 = FUN_005d0450(*(int *)(iVar3 + 0x46e0) + 0x50 + iVar7,&DAT_0093b118);
        if (iVar6 == 0) {
          if (!bVar2) {
            uVar4 = FUN_0067bf50(*(int *)(iVar3 + 0x46e0) + iVar7,uVar5);
            *(undefined2 *)(*(int *)(iVar3 + 0x46e0) + 0xae + iVar7) = uVar4;
            iVar6 = *(int *)(iVar3 + 0x46e0);
            iVar9 = 0;
            iVar12 = iVar6 + iVar7;
            if (*(char *)(iVar12 + 0x8b) != '\0') {
              iVar10 = 0;
              do {
                *(undefined2 *)(iVar10 + 0xf4 + iVar12) = 0xffff;
                iVar6 = *(int *)(iVar3 + 0x46e0);
                iVar12 = iVar6 + iVar7;
                iVar9 = iVar9 + 1;
                iVar10 = iVar10 + 0x44;
              } while (iVar9 < (int)(uint)*(byte *)(iVar6 + 0x8b + iVar7));
            }
            goto LAB_00554565;
          }
        }
        else {
          bVar2 = true;
        }
        if (DAT_008025b4 == -1) {
          *(undefined2 *)(*(int *)(iVar3 + 0x46e0) + 0xae + iVar7) = 0xffff;
        }
        else {
          uVar4 = FUN_0067c4f0(*(int *)(iVar3 + 0x46e0) + iVar7,DAT_008025b4);
          *(undefined2 *)(*(int *)(iVar3 + 0x46e0) + 0xae + iVar7) = uVar4;
        }
        iVar6 = *(int *)(iVar3 + 0x46e0);
        iVar12 = 0;
        if (*(char *)(iVar6 + 0x8b + iVar7) != '\0') {
          iVar9 = 0;
          do {
            if (DAT_008025b8 == -1) {
              *(undefined2 *)(iVar9 + iVar7 + 0xf4 + iVar6) = 0xffff;
            }
            else {
              uVar4 = FUN_0067c4f0(iVar9 + iVar7 + 0xb4 + iVar6,DAT_008025b8);
              *(undefined2 *)(iVar9 + iVar7 + 0xf4 + *(int *)(iVar3 + 0x46e0)) = uVar4;
            }
            FUN_0067c7b0((int)*(short *)(iVar9 + iVar7 + 0xf4 + *(int *)(iVar3 + 0x46e0)),1);
            iVar6 = *(int *)(iVar3 + 0x46e0);
            iVar12 = iVar12 + 1;
            iVar9 = iVar9 + 0x44;
          } while (iVar12 < (int)(uint)*(byte *)(iVar6 + 0x8b + iVar7));
        }
      }
LAB_00554565:
      param_1 = param_1 + 1;
      iVar7 = iVar7 + 0x304;
    } while (param_1 < (int)(uint)*(byte *)(*(int *)(iVar3 + 0x128) + 0xf2));
  }
  return;
}

