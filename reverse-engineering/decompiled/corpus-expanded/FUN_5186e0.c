/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5186e0; label: FUN_005186e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005186e0(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (*param_3 * *param_3 + param_3[2] * param_3[2] < param_4 * param_4) {
    *param_3 = *(float *)(param_1 + 0x5c) - *param_2;
    fVar1 = *(float *)(param_1 + 100) - param_2[2];
    param_3[2] = fVar1;
    uVar2 = FUN_005be2d0(*param_3,fVar1);
    *param_3 = *(float *)(*(int *)(param_1 + 4) + 0x104) - *param_2;
    fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x10c) - param_2[2];
    param_3[2] = fVar1;
    uVar3 = FUN_005be2d0(*param_3,fVar1);
    iVar4 = FUN_005be5b0(uVar3,uVar2);
    iVar5 = *(int *)(param_1 + 4);
    if (*(float *)(iVar5 + 0x18c) <= 0.0) {
      if (iVar4 < 1) {
        *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) & 0xffff7fff;
      }
      else {
        *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) | 0x8000;
      }
    }
    else {
      if (((((*(ushort *)(iVar5 + 0x166) & 1) == 0) && ((*(ushort *)(iVar5 + 0x166) & 2) != 0)) ||
          (1.0 < *(float *)(param_1 + 0x1d8))) && (*(float *)(iVar5 + 0x18c) < _DAT_00801c74)) {
        *(uint *)(iVar5 + 0x1e8) =
             *(uint *)(iVar5 + 0x1e8) ^
             (~*(uint *)(iVar5 + 0x1e8) ^ *(uint *)(iVar5 + 0x1e8)) & 0x8000;
        *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c78 + _DAT_00801c74;
      }
      if ((*(uint *)(*(int *)(param_1 + 4) + 0x1e8) & 0x8000) == 0) {
        if (0 < iVar4) {
          iVar4 = iVar4 + -0x10000;
        }
      }
      else if (iVar4 < 0) {
        iVar4 = iVar4 + 0x10000;
      }
    }
    if (((*(byte *)((int)param_2 + 0x49) & 2) == 0) &&
       (*(float *)(*(int *)(param_1 + 4) + 0x18c) < _DAT_00801c74)) {
      *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c74;
    }
    iVar5 = FUN_006e6b90();
    if ((iVar5 < iVar4) || (iVar5 = -iVar5, iVar4 < iVar5)) {
      iVar4 = iVar5;
    }
    uVar2 = FUN_005be590(uVar2,iVar4);
    *param_3 = 0.0;
    param_3[1] = 0.0;
    param_3[2] = param_4;
    FUN_005b3620(param_3,param_3,uVar2);
    *(float *)(*(int *)(param_1 + 4) + 0x114) = *param_2 + *param_3;
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x118) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x108);
    *(float *)(*(int *)(param_1 + 4) + 0x11c) = param_2[2] + param_3[2];
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x40000;
  }
  return;
}

