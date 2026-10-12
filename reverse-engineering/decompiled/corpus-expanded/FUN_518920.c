/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518920; label: FUN_00518920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518920(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  float local_48;
  float local_40;
  float local_3c [3];
  float local_30 [3];
  float local_24 [2];
  undefined4 local_1c;
  float local_18 [2];
  undefined4 local_10;
  float local_c [2];
  undefined4 local_4;
  
  fVar1 = *param_3 * *param_3 + param_3[2] * param_3[2];
  if (fVar1 < param_4 * param_4) {
    fVar2 = param_2[0x11] / param_2[0x10];
    param_3[1] = 0.0;
    FUN_005b3620(local_24,param_3,-(int)param_2[0xe]);
    iVar3 = FUN_005be2d0(local_24[0] * fVar2,local_1c);
    local_3c[0] = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * param_2[0x10];
    local_3c[1] = 0.0;
    local_3c[2] = (float)(&DAT_029899a0)[iVar3 + 0x4000 >> 1 & 0x7fff] * param_2[0x11];
    FUN_005b3b30(param_3,local_3c);
    FUN_005b3830(param_3,param_3,*(undefined4 *)(*(int *)(param_1 + 4) + 0x120));
    FUN_005b37d0(local_3c,local_3c,param_3);
    if (fVar1 < local_3c[0] * local_3c[0] + local_3c[2] * local_3c[2]) {
      *param_3 = *(float *)(param_1 + 0x5c) - *param_2;
      param_3[1] = 0.0;
      param_3[2] = *(float *)(param_1 + 100) - param_2[2];
      FUN_005b3620(local_18,param_3,-(int)param_2[0xe]);
      iVar4 = FUN_005be2d0(local_18[0] * fVar2,local_10);
      uVar5 = iVar4 >> 1 & 0x7fff;
      local_30[0] = param_2[0x10] * (float)(&DAT_029899a0)[uVar5];
      local_30[1] = 0.0;
      local_30[2] = (float)(&DAT_029899a0)[iVar4 + 0x4000 >> 1 & 0x7fff] * param_2[0x11];
      FUN_005b3b30(param_3,local_30);
      FUN_005b3830(param_3,param_3,*(undefined4 *)(*(int *)(param_1 + 4) + 0x120));
      FUN_005b37d0(local_30,local_30,param_3);
      *param_3 = *(float *)(*(int *)(param_1 + 4) + 0x104) - *param_2;
      param_3[1] = 0.0;
      param_3[2] = *(float *)(*(int *)(param_1 + 4) + 0x10c) - param_2[2];
      FUN_005b3620(local_c,param_3,-(int)param_2[0xe]);
      uVar6 = FUN_005be2d0(local_c[0] * fVar2,local_4);
      uVar7 = FUN_005be5b0(uVar6,iVar4);
      iVar3 = *(int *)(param_1 + 4);
      if (*(float *)(iVar3 + 0x18c) <= 0.0) {
        if ((int)uVar7 < 1) {
          *(uint *)(iVar3 + 0x1e8) = *(uint *)(iVar3 + 0x1e8) & 0xffff7fff;
        }
        else {
          *(uint *)(iVar3 + 0x1e8) = *(uint *)(iVar3 + 0x1e8) | 0x8000;
        }
      }
      else {
        if (((((*(ushort *)(iVar3 + 0x166) & 1) == 0) && ((*(ushort *)(iVar3 + 0x166) & 2) != 0)) ||
            (1.0 < *(float *)(param_1 + 0x1d8))) && (*(float *)(iVar3 + 0x18c) < _DAT_00801c74)) {
          *(uint *)(iVar3 + 0x1e8) =
               *(uint *)(iVar3 + 0x1e8) ^
               (~*(uint *)(iVar3 + 0x1e8) ^ *(uint *)(iVar3 + 0x1e8)) & 0x8000;
          *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c78 + _DAT_00801c74;
        }
        if ((*(uint *)(*(int *)(param_1 + 4) + 0x1e8) & 0x8000) == 0) {
          if (0 < (int)uVar7) {
            uVar7 = uVar7 - 0x10000;
          }
        }
        else if ((int)uVar7 < 0) {
          uVar7 = uVar7 + 0x10000;
        }
      }
      if (((*(byte *)((int)param_2 + 0x49) & 2) == 0) &&
         (*(float *)(*(int *)(param_1 + 4) + 0x18c) < _DAT_00801c74)) {
        *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c74;
      }
      local_48 = (float)(&DAT_029899a0)[iVar4 + 0x4000 >> 1 & 0x7fff] * param_2[0x10];
      local_40 = -(float)(&DAT_029899a0)[uVar5] * param_2[0x11];
      if ((int)uVar7 < 0) {
        local_48 = -local_48;
        local_40 = -local_40;
      }
      iVar3 = (uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f);
      if (iVar3 < 0x71c) {
        fVar1 = (float)iVar3 / 1820.0;
        local_48 = fVar1 * local_48;
        local_40 = fVar1 * local_40;
      }
      *(float *)(*(int *)(param_1 + 4) + 0x114) = local_48 + local_30[0];
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x118) = 0;
      *(float *)(*(int *)(param_1 + 4) + 0x11c) = local_40 + local_30[2];
      iVar3 = *(int *)(param_1 + 4) + 0x114;
      FUN_005b3620(iVar3,iVar3,param_2[0xe]);
      iVar3 = *(int *)(param_1 + 4) + 0x114;
      FUN_005b37d0(iVar3,iVar3,param_2);
      *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x40000;
    }
  }
  return;
}

