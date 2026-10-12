/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fc430; label: FUN_005fc430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fc430(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  fVar3 = _DAT_0280d810;
  fVar2 = _DAT_0280d80c;
  fVar1 = _DAT_0280d808;
  iVar7 = 0;
  if (3 < param_3) {
    iVar6 = (param_3 - 4U >> 2) + 1;
    iVar7 = iVar6 * 4;
    pfVar4 = (float *)(param_1 + 0x28);
    do {
      pfVar4[9] = (fVar3 - *pfVar4) * (fVar3 - *pfVar4) +
                  (fVar1 - pfVar4[-2]) * (fVar1 - pfVar4[-2]) +
                  (fVar2 - pfVar4[-1]) * (fVar2 - pfVar4[-1]);
      pfVar4[0x1d] = (fVar3 - pfVar4[0x14]) * (fVar3 - pfVar4[0x14]) +
                     (fVar1 - pfVar4[0x12]) * (fVar1 - pfVar4[0x12]) +
                     (fVar2 - pfVar4[0x13]) * (fVar2 - pfVar4[0x13]);
      pfVar4[0x31] = (fVar3 - pfVar4[0x28]) * (fVar3 - pfVar4[0x28]) +
                     (fVar1 - pfVar4[0x26]) * (fVar1 - pfVar4[0x26]) +
                     (fVar2 - pfVar4[0x27]) * (fVar2 - pfVar4[0x27]);
      iVar6 = iVar6 + -1;
      pfVar4[0x45] = (fVar3 - pfVar4[0x3c]) * (fVar3 - pfVar4[0x3c]) +
                     (fVar1 - pfVar4[0x3a]) * (fVar1 - pfVar4[0x3a]) +
                     (fVar2 - pfVar4[0x3b]) * (fVar2 - pfVar4[0x3b]);
      pfVar4 = pfVar4 + 0x50;
    } while (iVar6 != 0);
  }
  if (iVar7 < param_3) {
    iVar6 = param_3 - iVar7;
    pfVar4 = (float *)(iVar7 * 0x50 + 0x28 + param_1);
    do {
      iVar6 = iVar6 + -1;
      pfVar4[9] = (fVar3 - *pfVar4) * (fVar3 - *pfVar4) +
                  (fVar1 - pfVar4[-2]) * (fVar1 - pfVar4[-2]) +
                  (fVar2 - pfVar4[-1]) * (fVar2 - pfVar4[-1]);
      pfVar4 = pfVar4 + 0x14;
    } while (iVar6 != 0);
  }
  iVar7 = 0;
  if (3 < param_3) {
    iVar6 = (param_3 - 4U >> 2) + 1;
    iVar7 = iVar6 * 4;
    piVar5 = (int *)(param_2 + 0xc);
    do {
      piVar5[-2] = *(int *)(piVar5[-3] * 0x50 + 0x4c + param_1);
      piVar5[1] = *(int *)(*piVar5 * 0x50 + 0x4c + param_1);
      piVar5[4] = *(int *)(piVar5[3] * 0x50 + 0x4c + param_1);
      iVar6 = iVar6 + -1;
      piVar5[7] = *(int *)(piVar5[6] * 0x50 + 0x4c + param_1);
      piVar5 = piVar5 + 0xc;
    } while (iVar6 != 0);
  }
  if (iVar7 < param_3) {
    param_3 = param_3 - iVar7;
    piVar5 = (int *)(param_2 + iVar7 * 0xc);
    do {
      param_3 = param_3 + -1;
      piVar5[1] = *(int *)(*piVar5 * 0x50 + 0x4c + param_1);
      piVar5 = piVar5 + 3;
    } while (param_3 != 0);
  }
  return 1;
}

