/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8950; label: FUN_005e8950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8950(int param_1,float *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  FUN_005b7670(&DAT_00978440,(*(float *)(param_1 + 0x40) * 180.0) / 3.1415927,
               1.0 / *(float *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
               *(undefined4 *)(param_1 + 0x4c));
  FUN_005b5a40(&DAT_0097ac80,param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  iVar7 = param_3 + -1;
  *(undefined4 *)(in_ECX + 0x740) = *(undefined4 *)(param_1 + 0x30);
  iVar9 = 0;
  *(undefined4 *)(in_ECX + 0x744) = uVar1;
  *(undefined4 *)(in_ECX + 0x748) = uVar2;
  *(undefined4 *)(in_ECX + 0x74c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x74c) = 0x3f800000;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x750) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x754) = uVar1;
  *(undefined4 *)(in_ECX + 0x758) = uVar2;
  *(undefined4 *)(in_ECX + 0x75c) = 0x3f800000;
  *(int *)(in_ECX + 0x710) = iVar7;
  *(undefined4 *)(in_ECX + 0x75c) = 0;
  if (3 < param_3) {
    iVar8 = (param_3 - 4U >> 2) + 1;
    iVar9 = iVar8 * 4;
    pfVar5 = (float *)(in_ECX + 0x704);
    pfVar6 = param_2 + 2;
    do {
      pfVar5[-1] = pfVar6[-2];
      iVar8 = iVar8 + -1;
      *pfVar5 = pfVar6[-1];
      pfVar5[1] = *pfVar6;
      pfVar5[2] = pfVar6[1];
      pfVar5 = pfVar5 + 4;
      pfVar6 = pfVar6 + 4;
    } while (iVar8 != 0);
  }
  if (iVar9 < param_3) {
    pfVar5 = (float *)(in_ECX + 0x700 + iVar9 * 4);
    do {
      pfVar6 = param_2 + iVar9;
      iVar9 = iVar9 + 1;
      *pfVar5 = *pfVar6;
      pfVar5 = pfVar5 + 1;
    } while (iVar9 < param_3);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x48);
  uVar2 = *(undefined4 *)(param_1 + 0x4c);
  param_3 = 0;
  if (0 < iVar7) {
    iVar9 = in_ECX + 0x1a0;
    do {
      *(float *)(param_1 + 0x48) = param_2[param_3];
      *(float *)(param_1 + 0x4c) = param_2[param_3 + 1];
      FUN_005c8030(param_1,iVar9 + -0x80,iVar9 + 0xd0);
      uVar3 = FUN_005c82c0(in_ECX + 0x770,iVar9 + -0x80,iVar9);
      *(undefined4 *)(iVar9 + 0xc0) = uVar3;
      puVar4 = (undefined4 *)(in_ECX + 0x780);
      puVar10 = (undefined4 *)(iVar9 + -0x1a0);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar4 = (undefined4 *)(in_ECX + 0x7c0);
      puVar10 = (undefined4 *)(iVar9 + -0x160);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar10 = puVar10 + 1;
      }
      FUN_005c8540(in_ECX + 0x770,iVar9 + -0x80,iVar9 + 0xe0,iVar9 + 0xf0,iVar9 + 0x100);
      param_3 = param_3 + 1;
      iVar9 = iVar9 + 0x380;
    } while (param_3 < iVar7);
    if (0 < iVar7) {
      puVar4 = (undefined4 *)(in_ECX + 0x724);
      do {
        param_2 = param_2 + 1;
        puVar4[-1] = 0;
        iVar7 = iVar7 + -1;
        *puVar4 = 0;
        puVar4[1] = 1.0 / *param_2;
        puVar4[2] = 0xbf800000;
        puVar4 = puVar4 + 4;
      } while (iVar7 != 0);
    }
  }
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return;
}

