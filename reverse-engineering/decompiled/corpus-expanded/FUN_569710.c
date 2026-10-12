/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x569710; label: FUN_00569710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00569710(int param_1)

{
  int *piVar1;
  float *pfVar2;
  byte *pbVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = param_1;
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    iVar11 = 0;
    do {
      iVar10 = *(int *)(param_1 + 0x50c4);
      pbVar3 = (byte *)(iVar10 + 0xfc + iVar11);
      *pbVar3 = *pbVar3 & 0xfe;
      iVar10 = iVar10 + iVar11;
      iVar7 = FUN_005d0420(iVar10 + 0x30);
      if (iVar7 == 0) {
        uVar4 = 0x3f800000;
      }
      else {
        uVar4 = *(undefined4 *)(iVar7 + 0x4c);
      }
      *(undefined4 *)(iVar10 + 0x90) = uVar4;
      iVar7 = FUN_005cfac0(iVar10 + 0x3c);
      if (iVar7 != 0) {
        FUN_005cfc00(iVar10 + 0x3c,0);
      }
      iVar9 = iVar9 + 1;
      iVar11 = iVar11 + 0x100;
    } while (iVar9 < *(int *)(param_1 + 0x50bc));
  }
  iVar9 = 0;
  piVar1 = (int *)(param_1 + 0x50c0);
  param_1 = 0;
  if (0 < *piVar1) {
    do {
      iVar11 = *(int *)(iVar6 + 0x50c8);
      *(undefined4 *)(iVar11 + 0xbc + iVar9) = 0x3f800000;
      iVar10 = *(int *)(iVar11 + 0xa4 + iVar9);
      iVar7 = iVar11 + iVar9;
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar11 + 0x94 + iVar9) & 0xf7b7fc00 | 0x810000;
      iVar11 = FUN_005cfac0(iVar10 + 0x30);
      if (iVar11 == 0) {
        local_c = DAT_0093b0cc;
        local_8 = DAT_0093b0d0;
        local_4 = DAT_0093b0d4;
        *(float *)(iVar7 + 100) = DAT_0093b0cc;
        *(float *)(iVar7 + 0x68) = DAT_0093b0d0;
        fVar5 = DAT_0093b0d4;
        *(float *)(iVar7 + 0x6c) = DAT_0093b0d4;
        *(undefined4 *)(iVar7 + 0x58) = *(undefined4 *)(iVar7 + 100);
        *(undefined4 *)(iVar7 + 0x5c) = *(undefined4 *)(iVar7 + 0x68);
        *(float *)(iVar7 + 0x60) = fVar5;
      }
      else {
        iVar11 = FUN_005cfac0(*(int *)(iVar7 + 0xa4) + 0x54);
        if (iVar11 != 0) {
          FUN_005cfc00(*(int *)(iVar7 + 0xa4) + 0x54,0);
        }
        if ((*(uint *)(*(int *)(iVar7 + 0xa4) + 0x7c) & 0x2000) != 0) {
          puVar8 = (undefined4 *)FUN_005cf9e0(*(int *)(iVar7 + 0xa4) + 0x30);
          *(undefined4 *)(iVar7 + 0x30) = *puVar8;
          *(undefined4 *)(iVar7 + 0x34) = puVar8[1];
          *(undefined4 *)(iVar7 + 0x38) = puVar8[2];
        }
        pfVar2 = (float *)(iVar7 + 0xa8);
        FUN_005d0260(*(int *)(iVar7 + 0xa4) + 0x30,&local_c,pfVar2);
        local_c = *(float *)(iVar7 + 0x30) + local_c;
        local_8 = *(float *)(iVar7 + 0x34) + local_8;
        local_4 = *(float *)(iVar7 + 0x38) + local_4;
        *(float *)(iVar7 + 0x58) = local_c - *pfVar2;
        *(float *)(iVar7 + 0x5c) = local_8 - *pfVar2;
        *(float *)(iVar7 + 0x60) = local_4 - *pfVar2;
        *(float *)(iVar7 + 100) = *pfVar2 + local_c;
        *(float *)(iVar7 + 0x68) = *pfVar2 + local_8;
        *(float *)(iVar7 + 0x6c) = *pfVar2 + local_4;
        iVar11 = FUN_005d0420(*(int *)(iVar7 + 0xa4) + 0x30);
        if ((iVar11 != 0) && ((*(byte *)(iVar11 + 0x50) & 1) != 0)) {
          *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x100000;
          if ((*(byte *)(iVar11 + 0x50) & 8) != 0) {
            *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x480000;
          }
        }
      }
      FUN_005687f0(iVar7);
      *(char *)(iVar7 + 0x111) = *(char *)(iVar7 + 0x111) * DAT_00803068;
      param_1 = param_1 + 1;
      iVar9 = iVar9 + 0x114;
    } while (param_1 < *(int *)(iVar6 + 0x50c0));
  }
  FUN_00568760();
  FUN_005686a0();
  return;
}

