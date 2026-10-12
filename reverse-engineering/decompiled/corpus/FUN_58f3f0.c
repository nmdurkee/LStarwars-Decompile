/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58f3f0; label: FUN_0058f3f0
 */

void FUN_0058f3f0(int param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  float10 fVar11;
  float local_38;
  uint local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  local_20 = DAT_0093b0d0;
  local_14 = DAT_0093b0d0;
  iVar9 = 0;
  if ((((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_2 + 0x10) != 0)) &&
     (bVar1 = *(byte *)(param_2 + 0x6c), bVar1 != 0)) {
    fVar2 = *(float *)(param_1 + 0x80);
    local_18 = 1e+09;
    local_10 = 1e+09;
    local_8 = *(undefined4 *)(param_1 + 0x84);
    fVar3 = *(float *)(param_1 + 0x88);
    local_24 = -1e+09;
    local_1c = -1e+09;
    fVar4 = *(float *)(param_2 + 0x28);
    local_2c = *(undefined4 *)(param_2 + 0x2c);
    fVar5 = *(float *)(param_2 + 0x30);
    local_30 = fVar4;
    local_28 = fVar5;
    if ((*(byte *)(param_2 + 0x72) & 0x10) == 0) {
      local_c = *(float *)(param_2 + 0x28);
      local_8 = *(undefined4 *)(param_2 + 0x2c);
      uVar10 = (uint)bVar1;
      local_4 = *(float *)(param_2 + 0x30);
      iVar9 = 0;
      if (3 < uVar10) {
        piVar8 = (int *)(*(int *)(param_2 + 0x14) + 8);
        iVar7 = (uVar10 - 4 >> 2) + 1;
        iVar9 = iVar7 * 4;
        do {
          fVar3 = *(float *)(*(int *)(piVar8[-2] + 0x24) + 0x30) - fVar4;
          fVar2 = *(float *)(*(int *)(piVar8[-2] + 0x24) + 0x38) - fVar5;
          if (local_24 <= fVar3) {
            local_24 = fVar3;
          }
          if (local_1c <= fVar2) {
            local_1c = fVar2;
          }
          if (fVar3 <= local_18) {
            local_18 = fVar3;
          }
          if (fVar2 <= local_10) {
            local_10 = fVar2;
          }
          fVar3 = *(float *)(*(int *)(piVar8[-1] + 0x24) + 0x30) - fVar4;
          fVar2 = *(float *)(*(int *)(piVar8[-1] + 0x24) + 0x38) - fVar5;
          if (local_24 <= fVar3) {
            local_24 = fVar3;
          }
          if (local_1c <= fVar2) {
            local_1c = fVar2;
          }
          if (fVar3 <= local_18) {
            local_18 = fVar3;
          }
          if (fVar2 <= local_10) {
            local_10 = fVar2;
          }
          fVar3 = *(float *)(*(int *)(*piVar8 + 0x24) + 0x30) - fVar4;
          fVar2 = *(float *)(*(int *)(*piVar8 + 0x24) + 0x38) - fVar5;
          if (local_24 <= fVar3) {
            local_24 = fVar3;
          }
          if (local_1c <= fVar2) {
            local_1c = fVar2;
          }
          if (fVar3 <= local_18) {
            local_18 = fVar3;
          }
          if (fVar2 <= local_10) {
            local_10 = fVar2;
          }
          iVar6 = *(int *)(piVar8[1] + 0x24);
          local_30 = *(float *)(iVar6 + 0x30);
          local_2c = *(undefined4 *)(iVar6 + 0x34);
          fVar3 = local_30 - fVar4;
          local_28 = *(float *)(iVar6 + 0x38);
          fVar2 = local_28 - fVar5;
          if (local_24 <= fVar3) {
            local_24 = fVar3;
          }
          if (local_1c <= fVar2) {
            local_1c = fVar2;
          }
          if (fVar3 <= local_18) {
            local_18 = fVar3;
          }
          if (fVar2 <= local_10) {
            local_10 = fVar2;
          }
          piVar8 = piVar8 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (iVar9 < (int)uVar10) {
        piVar8 = (int *)(*(int *)(param_2 + 0x14) + iVar9 * 4);
        iVar9 = uVar10 - iVar9;
        do {
          iVar7 = *(int *)(*piVar8 + 0x24);
          local_30 = *(float *)(iVar7 + 0x30);
          local_2c = *(undefined4 *)(iVar7 + 0x34);
          fVar3 = local_30 - fVar4;
          local_28 = *(float *)(iVar7 + 0x38);
          fVar2 = local_28 - fVar5;
          if (local_24 <= fVar3) {
            local_24 = fVar3;
          }
          if (local_1c <= fVar2) {
            local_1c = fVar2;
          }
          if (fVar3 <= local_18) {
            local_18 = fVar3;
          }
          if (fVar2 <= local_10) {
            local_10 = fVar2;
          }
          piVar8 = piVar8 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      local_38 = local_24 * local_24 + local_1c * local_1c;
      fVar11 = (float10)FUN_005c0240(local_38);
      local_38 = (float)fVar11;
    }
    else {
      local_34 = (uint)bVar1;
      local_38 = 1e+09;
      iVar7 = 0;
      local_c = fVar2;
      local_4 = fVar3;
      if (3 < local_34) {
        piVar8 = (int *)(*(int *)(param_2 + 0x14) + 8);
        do {
          iVar6 = *(int *)(piVar8[-2] + 0x24);
          fVar5 = *(float *)(iVar6 + 0x30) - fVar2;
          fVar4 = *(float *)(iVar6 + 0x38) - fVar3;
          fVar4 = fVar5 * fVar5 + fVar4 * fVar4;
          if (fVar4 < local_38) {
            iVar9 = iVar7;
            local_38 = fVar4;
            local_c = *(float *)(iVar6 + 0x30);
            local_8 = *(undefined4 *)(iVar6 + 0x34);
            local_4 = *(float *)(iVar6 + 0x38);
          }
          iVar6 = *(int *)(piVar8[-1] + 0x24);
          fVar5 = *(float *)(iVar6 + 0x30) - fVar2;
          fVar4 = *(float *)(iVar6 + 0x38) - fVar3;
          fVar4 = fVar5 * fVar5 + fVar4 * fVar4;
          if (fVar4 < local_38) {
            iVar9 = iVar7 + 1;
            local_38 = fVar4;
            local_c = *(float *)(iVar6 + 0x30);
            local_8 = *(undefined4 *)(iVar6 + 0x34);
            local_4 = *(float *)(iVar6 + 0x38);
          }
          iVar6 = *(int *)(*piVar8 + 0x24);
          fVar5 = *(float *)(iVar6 + 0x30) - fVar2;
          fVar4 = *(float *)(iVar6 + 0x38) - fVar3;
          fVar4 = fVar5 * fVar5 + fVar4 * fVar4;
          if (fVar4 < local_38) {
            iVar9 = iVar7 + 2;
            local_38 = fVar4;
            local_c = *(float *)(iVar6 + 0x30);
            local_8 = *(undefined4 *)(iVar6 + 0x34);
            local_4 = *(float *)(iVar6 + 0x38);
          }
          iVar6 = *(int *)(piVar8[1] + 0x24);
          local_30 = *(float *)(iVar6 + 0x30);
          local_28 = *(float *)(iVar6 + 0x38);
          fVar4 = (local_30 - fVar2) * (local_30 - fVar2) + (local_28 - fVar3) * (local_28 - fVar3);
          if (fVar4 < local_38) {
            iVar9 = iVar7 + 3;
            local_38 = fVar4;
            local_c = local_30;
            local_8 = *(undefined4 *)(iVar6 + 0x34);
            local_4 = local_28;
          }
          iVar7 = iVar7 + 4;
          piVar8 = piVar8 + 4;
        } while (iVar7 < (int)(local_34 - 3));
      }
      if (iVar7 < (int)local_34) {
        piVar8 = (int *)(*(int *)(param_2 + 0x14) + iVar7 * 4);
        do {
          iVar6 = *(int *)(*piVar8 + 0x24);
          local_30 = *(float *)(iVar6 + 0x30);
          local_28 = *(float *)(iVar6 + 0x38);
          fVar4 = (local_30 - fVar2) * (local_30 - fVar2) + (local_28 - fVar3) * (local_28 - fVar3);
          if (fVar4 < local_38) {
            iVar9 = iVar7;
            local_38 = fVar4;
            local_c = local_30;
            local_8 = *(undefined4 *)(iVar6 + 0x34);
            local_4 = local_28;
          }
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar7 < (int)local_34);
      }
      iVar9 = *(int *)(*(int *)(param_2 + 0x14) + iVar9 * 4) + 4;
      FUN_005d0130(iVar9,&local_18,&local_24);
      FUN_005d0260(iVar9,&local_30,&local_38);
    }
    local_24 = local_c + local_24;
    local_1c = local_4 + local_1c;
    local_18 = local_18 + local_c;
    local_10 = local_4 + local_10;
    FUN_0055e660(&local_c,local_38,&local_18,&local_24,param_1,0,0x3f800000,0);
  }
  return;
}

