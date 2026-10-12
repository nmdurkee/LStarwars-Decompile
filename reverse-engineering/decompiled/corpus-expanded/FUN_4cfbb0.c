/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4cfbb0; label: FUN_004cfbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cfbb0(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  float **ppfVar7;
  undefined4 *puVar8;
  float *pfVar9;
  float local_148 [3];
  undefined4 local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130 [4];
  undefined1 local_120 [16];
  undefined1 local_110 [16];
  float local_100 [2];
  float local_f8;
  undefined1 local_ec [12];
  float *local_e0 [3];
  int local_d4;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  int local_bc;
  undefined4 local_b4;
  code *local_a4;
  code *local_a0;
  code *local_9c;
  code *local_94;
  code *local_8c;
  undefined4 local_54;
  undefined4 local_3c;
  undefined1 local_1c;
  undefined1 local_14 [16];
  
  puVar6 = &DAT_00810210;
  ppfVar7 = local_e0;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppfVar7 = (float *)*puVar6;
    puVar6 = puVar6 + 1;
    ppfVar7 = ppfVar7 + 1;
  }
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe9e) != '\0') {
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      FUN_00576960(0x2b8);
    }
    iVar4 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x112);
    bVar1 = false;
    if ((iVar4 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar4 * 4) == 0)) {
      FUN_005b4500(local_130,param_1 + 0x80);
    }
    else {
      if ((*(short *)(param_1 + 0x1064) == DAT_007f19e0) && (*(short *)(param_1 + 0x7aa) == 0x6e)) {
        uVar2 = FUN_0054fa60();
        FUN_005b4670(local_130,uVar2);
        uVar2 = FUN_0054fa60();
        FUN_005b5160(local_130,uVar2);
        uVar2 = FUN_0054fa60();
        FUN_005b4cf0(local_130,uVar2);
        FUN_005b4900(local_130,iVar4 * 0x40 + 0x834 + param_1);
      }
      else {
        puVar6 = (undefined4 *)(iVar4 * 0x40 + 0x804 + param_1);
        puVar8 = local_130;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        FUN_005b3b30(local_130,local_130);
        FUN_005b3b30(local_120,local_120);
        FUN_005b3b30(local_110,local_110);
      }
      local_13c = *(undefined4 *)(param_1 + 0x80);
      local_138 = (*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * 0.75 +
                  *(float *)(param_1 + 0x17c);
      local_134 = *(undefined4 *)(param_1 + 0x88);
      FUN_005b3800(local_ec,local_100,&local_13c);
      iVar4 = FUN_0067b430(&local_13c,local_ec,0,0x3f800000,0,DAT_008034c4 | 0x1f);
      if (iVar4 != 0) {
        bVar1 = true;
      }
    }
    pfVar9 = (float *)(param_1 + 0x80);
    local_148[0] = *(float *)(param_1 + 0x68) +
                   (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1] * 2.0;
    local_148[1] = 2.0;
    local_148[2] = (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff]
                   * 2.0 + *(float *)(param_1 + 0x70);
    if (bVar1) {
      uVar3 = FUN_005be2d0(*pfVar9 - local_100[0],*(float *)(param_1 + 0x88) - local_f8);
      local_148[0] = (float)(&DAT_029899a0)[(uVar3 & 0xffff) >> 1] * 2.0;
      local_148[2] = (float)(&DAT_029899a0)[(int)((uVar3 & 0xffff) + 0x4000) >> 1 & 0x7fff] * 2.0;
      local_100[0] = *pfVar9;
      local_f8 = *(float *)(param_1 + 0x88);
    }
    local_e0[2] = local_148;
    local_e0[0] = (float *)local_130;
    FUN_005d0260(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe90,local_14,&local_cc);
    local_c8 = local_cc;
    local_cc = local_cc * 0.75;
    local_c4 = 0xc0a00000;
    local_bc = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe90;
    local_54 = _DAT_00925018;
    local_b4 = 0x8000292;
    local_3c = 0x41200000;
    local_d4 = param_1;
    local_1c = 1;
    local_94 = FUN_00571c50;
    local_8c = FUN_004cf9f0;
    local_a4 = FUN_004cf680;
    local_9c = FUN_004cfb30;
    local_a0 = FUN_0042cf20;
    iVar4 = FUN_0064d270(local_e0);
    if (iVar4 != 0) {
      uVar3 = FUN_0058b720(param_1);
      *(undefined4 *)(iVar4 + 0x21c) = 0x49f42400;
      *(uint *)(iVar4 + 0x144) = *(uint *)(iVar4 + 0x144) & 0xfffc7fff;
      *(uint *)(iVar4 + 0x218) = uVar3 & 0xffff;
      *(undefined1 *)(iVar4 + 0x206) = 0;
      *(code **)(iVar4 + 0x1c4) = FUN_004cf820;
    }
    FUN_00681f40("ThrowDet",pfVar9);
    FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),2,0);
  }
  return;
}

