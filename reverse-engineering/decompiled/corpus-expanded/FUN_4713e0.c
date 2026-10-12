/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x4713e0; label: FUN_004713e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004713e0(int param_1,float *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float **ppfVar5;
  undefined4 *puVar6;
  float local_12c [3];
  undefined4 local_120 [12];
  undefined4 local_f0;
  float local_ec;
  undefined4 local_e8;
  undefined1 local_dc [12];
  float *local_d0 [5];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_ac;
  undefined4 local_a4;
  code *local_8c;
  float local_44;
  undefined4 local_2c;
  
  *(byte *)(param_1 + 0x559) = *(byte *)(param_1 + 0x559) | 2;
  if (*(int *)(param_1 + 0x514) != 0) {
    if ((*(short *)(param_1 + 0x55e) == DAT_007f1984) &&
       (*(char *)(*(int *)(param_1 + 0x514) + 0x7b3) != '\0')) {
      if ((*(int *)(param_1 + 0x4b0) == 0) ||
         (((*(byte *)(param_1 + 0x559) & 1) == 0 ||
          (iVar3 = param_1 + 0x70, *(int *)(*(int *)(param_1 + 0x4b0) + 0x14) == 0)))) {
        iVar3 = param_1 + 0x48c;
      }
      FUN_00681f40("imp_C3PO_magnet_drop",iVar3);
    }
    FUN_00470e60();
    *(float *)(*(int *)(param_1 + 0x514) + 0x68) =
         ((*(float *)(param_1 + 0x48c) - *param_2) / _DAT_00925018) * 0.5;
    if (*(short *)(param_1 + 0x55e) == DAT_007f1984) {
      *(undefined4 *)(*(int *)(param_1 + 0x514) + 0x6c) = 0xbf800000;
    }
    *(float *)(*(int *)(param_1 + 0x514) + 0x70) =
         ((*(float *)(param_1 + 0x494) - param_2[2]) / _DAT_00925018) * 0.5;
    *(undefined1 *)(*(int *)(param_1 + 0x514) + 0x7b5) = 0xff;
    *(undefined4 *)(param_1 + 0x514) = 0;
    return;
  }
  iVar3 = *(int *)(param_1 + 0x52c);
  if (iVar3 != 0) {
    iVar1 = *(int *)(param_1 + 0x4b0);
    puVar2 = &DAT_00810210;
    ppfVar5 = local_d0;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppfVar5 = (float *)*puVar2;
      puVar2 = puVar2 + 1;
      ppfVar5 = ppfVar5 + 1;
    }
    puVar2 = (undefined4 *)(param_1 + 0x440);
    puVar6 = local_120;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    if (((iVar1 == 0) || ((*(byte *)(param_1 + 0x559) & 1) == 0)) ||
       (puVar2 = (undefined4 *)(param_1 + 0x70), *(int *)(iVar1 + 0x14) == 0)) {
      puVar2 = (undefined4 *)(param_1 + 0x48c);
    }
    local_f0 = *puVar2;
    local_e8 = puVar2[2];
    local_ec = *(float *)(param_1 + 0x544) + (float)puVar2[1];
    local_d0[0] = (float *)local_120;
    local_12c[0] = ((*(float *)(param_1 + 0x48c) - *param_2) / _DAT_00925018) * 0.5;
    local_12c[1] = -0.1;
    local_d0[2] = local_12c;
    local_12c[2] = ((*(float *)(param_1 + 0x494) - param_2[2]) / _DAT_00925018) * 0.5;
    FUN_005d0260(*(int *)(iVar3 + 0xa4) + 0x30,local_dc,&local_bc);
    local_b8 = local_bc;
    local_b4 = 0xc0c00000;
    local_ac = *(int *)(*(int *)(param_1 + 0x52c) + 0xa4) + 0x30;
    local_44 = _DAT_00925018;
    local_2c = 0x40400000;
    local_a4 = 0x311;
    local_8c = FUN_00470800;
    iVar3 = FUN_0064d270(local_d0);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x210) = *(undefined4 *)(param_1 + 0x52c);
    }
    *(undefined4 *)(param_1 + 0x52c) = 0;
  }
  return;
}

