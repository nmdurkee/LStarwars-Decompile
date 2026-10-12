/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a91f0; label: FUN_006a91f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a91f0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  
  piVar4 = param_1;
  FUN_006a3570(param_2,0x564342,0x18);
  FUN_006a3570(param_2,*param_1,0x10);
  FUN_006a3570(param_2,param_1[1],0x18);
  iVar9 = param_1[1];
  iVar5 = 1;
  if (1 < iVar9) {
    piVar7 = (int *)param_1[2];
    do {
      if ((*piVar7 == 0) ||
         (*(int *)(param_1[2] + iVar5 * 4) < *(int *)(param_1[2] + -4 + iVar5 * 4))) break;
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar5 < iVar9);
  }
  if (iVar5 == iVar9) {
    iVar9 = 0;
    FUN_006a3570(param_2,1,1);
    FUN_006a3570(param_2,*(int *)param_1[2] + -1,5);
    iVar5 = 1;
    if (1 < param_1[1]) {
      do {
        iVar1 = *(int *)(piVar4[2] + iVar5 * 4);
        iVar2 = *(int *)(piVar4[2] + iVar5 * 4 + -4);
        if (iVar2 < iVar1) {
          param_1 = (int *)(iVar1 - iVar2);
          do {
            uVar6 = FUN_006a7ed0(piVar4[1] - iVar9);
            FUN_006a3570(param_2,iVar5 - iVar9,uVar6);
            param_1 = (int *)((int)param_1 + -1);
            iVar9 = iVar5;
          } while (param_1 != (int *)0x0);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < piVar4[1]);
    }
    uVar6 = FUN_006a7ed0(piVar4[1] - iVar9);
    FUN_006a3570(param_2,iVar5 - iVar9,uVar6);
  }
  else {
    FUN_006a3570(param_2,0,1);
    iVar9 = param_1[1];
    iVar5 = 0;
    if (0 < iVar9) {
      piVar7 = (int *)param_1[2];
      do {
        if (*piVar7 == 0) break;
        iVar5 = iVar5 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar5 < iVar9);
    }
    if (iVar5 == iVar9) {
      FUN_006a3570(param_2,0,1);
      iVar9 = 0;
      if (0 < param_1[1]) {
        do {
          FUN_006a3570(param_2,*(int *)(param_1[2] + iVar9 * 4) + -1,5);
          iVar9 = iVar9 + 1;
        } while (iVar9 < param_1[1]);
      }
    }
    else {
      FUN_006a3570(param_2,1,1);
      iVar9 = 0;
      if (0 < param_1[1]) {
        do {
          if (*(int *)(param_1[2] + iVar9 * 4) == 0) {
            FUN_006a3570(param_2,0,1);
          }
          else {
            FUN_006a3570(param_2,1,1);
            FUN_006a3570(param_2,*(int *)(param_1[2] + iVar9 * 4) + -1,5);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < param_1[1]);
      }
    }
  }
  FUN_006a3570(param_2,piVar4[3],4);
  if (piVar4[3] != 0) {
    if ((1 < piVar4[3] - 1U) || (piVar4[8] == 0)) {
      return 0xffffffff;
    }
    FUN_006a3570(param_2,piVar4[4],0x20);
    FUN_006a3570(param_2,piVar4[5],0x20);
    FUN_006a3570(param_2,piVar4[6] + -1,4);
    FUN_006a3570(param_2,piVar4[7],1);
    if (piVar4[3] == 1) {
      iVar9 = FUN_006a8150(piVar4);
    }
    else if (piVar4[3] == 2) {
      iVar9 = piVar4[1] * *piVar4;
    }
    else {
      iVar9 = -1;
    }
    iVar5 = 0;
    if (0 < iVar9) {
      do {
        uVar3 = *(uint *)(piVar4[8] + iVar5 * 4);
        uVar8 = (int)uVar3 >> 0x1f;
        FUN_006a3570(param_2,(uVar3 ^ uVar8) - uVar8,piVar4[6]);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar9);
    }
  }
  return 0;
}

