/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fc690; label: FUN_005fc690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fc690(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar3 = *(undefined4 *)(param_1 + 4 + param_3 * 0xc);
  uVar4 = *(undefined4 *)(param_1 + param_3 * 0xc);
  puVar9 = (undefined4 *)(param_1 + param_3 * 0xc);
  uVar5 = puVar9[2];
  puVar1 = (undefined4 *)(param_1 + ((param_4 - param_3) / 2 + param_3) * 0xc);
  *puVar9 = *puVar1;
  puVar9[1] = puVar1[1];
  puVar9[2] = puVar1[2];
  *puVar1 = uVar4;
  puVar1[1] = uVar3;
  puVar1[2] = uVar5;
  uVar3 = *puVar9;
  fVar6 = (float)puVar9[1];
  uVar4 = puVar9[2];
  iVar11 = param_3;
  iVar12 = param_4;
  if (param_3 < param_4) {
    do {
      fVar2 = *(float *)(param_1 + 4 + iVar12 * 0xc);
      iVar10 = param_1 + 4 + iVar12 * 0xc;
      for (; (fVar2 < fVar6 && (iVar11 < iVar12)); iVar12 = iVar12 + -1) {
        fVar2 = *(float *)(iVar10 + -0xc);
        iVar10 = iVar10 + -0xc;
      }
      if (iVar11 != iVar12) {
        uVar5 = puVar9[1];
        uVar7 = *puVar9;
        uVar8 = puVar9[2];
        puVar1 = (undefined4 *)(param_1 + iVar12 * 0xc);
        *puVar9 = *(undefined4 *)(param_1 + iVar12 * 0xc);
        puVar9[1] = puVar1[1];
        puVar9[2] = puVar1[2];
        *puVar1 = uVar7;
        puVar1[1] = uVar5;
        puVar1[2] = uVar8;
        iVar11 = iVar11 + 1;
      }
      fVar2 = *(float *)(param_1 + 4 + iVar11 * 0xc);
      iVar10 = param_1 + 4 + iVar11 * 0xc;
      for (; (fVar6 < fVar2 && (iVar11 < iVar12)); iVar11 = iVar11 + 1) {
        fVar2 = *(float *)(iVar10 + 0xc);
        iVar10 = iVar10 + 0xc;
      }
      if (iVar11 != iVar12) {
        uVar5 = *(undefined4 *)(param_1 + iVar12 * 0xc);
        puVar1 = (undefined4 *)(param_1 + iVar12 * 0xc);
        uVar7 = puVar1[1];
        uVar8 = puVar1[2];
        puVar9 = (undefined4 *)(param_1 + iVar11 * 0xc);
        *puVar1 = *(undefined4 *)(param_1 + iVar11 * 0xc);
        puVar1[1] = puVar9[1];
        puVar1[2] = puVar9[2];
        *puVar9 = uVar5;
        puVar9[1] = uVar7;
        puVar9[2] = uVar8;
        iVar12 = iVar12 + -1;
      }
      puVar9 = (undefined4 *)(param_1 + iVar11 * 0xc);
      *puVar9 = uVar3;
      puVar9[1] = fVar6;
      puVar9[2] = uVar4;
    } while (iVar11 < iVar12);
  }
  if (param_3 < iVar11) {
    FUN_005fc690(param_1,param_2,param_3,iVar11 + -1);
  }
  if (iVar11 < param_4) {
    FUN_005fc690(param_1,param_2,iVar11 + 1,param_4);
  }
  return 1;
}

