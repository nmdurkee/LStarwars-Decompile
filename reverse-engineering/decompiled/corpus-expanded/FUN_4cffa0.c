/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4cffa0; label: FUN_004cffa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cffa0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  undefined4 local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130 [4];
  undefined1 local_120 [16];
  undefined1 local_110 [16];
  undefined1 local_100 [20];
  undefined1 local_ec [12];
  undefined4 *local_e0 [3];
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
  
  puVar5 = &DAT_00810210;
  ppuVar6 = local_e0;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar6 = (undefined4 *)*puVar5;
    puVar5 = puVar5 + 1;
    ppuVar6 = ppuVar6 + 1;
  }
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe9e) != '\0') {
    iVar3 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x112);
    if ((iVar3 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) == 0)) {
      FUN_005b4500(local_130,param_1 + 0x80);
    }
    else {
      if ((*(short *)(param_1 + 0x1064) == DAT_007f19e0) && (*(short *)(param_1 + 0x7aa) == 0x6e)) {
        uVar1 = FUN_0054fa60();
        FUN_005b4670(local_130,uVar1);
        uVar1 = FUN_0054fa60();
        FUN_005b5160(local_130,uVar1);
        uVar1 = FUN_0054fa60();
        FUN_005b4cf0(local_130,uVar1);
        FUN_005b4900(local_130,iVar3 * 0x40 + 0x834 + param_1);
      }
      else {
        puVar5 = (undefined4 *)(iVar3 * 0x40 + 0x804 + param_1);
        puVar7 = local_130;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
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
      FUN_0067b430(&local_13c,local_ec,0,0x3f800000,0,DAT_008034c4 | 0x1f);
    }
    local_e0[2] = (undefined4 *)param_2;
    local_e0[0] = local_130;
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
    iVar3 = FUN_0064d270(local_e0);
    if (iVar3 != 0) {
      uVar2 = FUN_0058b720(param_1);
      *(undefined4 *)(iVar3 + 0x21c) = 0x49f42400;
      *(uint *)(iVar3 + 0x144) = *(uint *)(iVar3 + 0x144) & 0xfffc7fff;
      *(uint *)(iVar3 + 0x218) = uVar2 & 0xffff;
      *(undefined1 *)(iVar3 + 0x206) = 0;
      *(code **)(iVar3 + 0x1c4) = FUN_004cf820;
    }
    FUN_00681f40("ThrowDet",param_1 + 0x80);
    FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),2,0);
  }
  return;
}

