/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x4302e0; label: FUN_004302e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004302e0(int param_1,float param_2,float param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 *local_110 [3];
  int local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e4;
  code *local_dc;
  code *local_c4;
  code *local_bc;
  undefined4 local_84;
  undefined4 local_48 [13];
  float local_14;
  
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  iVar1 = FUN_005cfac0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe60);
  if (iVar1 != 0) {
    FUN_005b4500(local_48,param_1 + 0x80);
    local_14 = local_14 + param_2;
    puVar3 = &DAT_00810210;
    ppuVar4 = local_110;
    for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    local_fc = 0x3dcccccd;
    local_f8 = 0x3dcccccd;
    local_110[0] = local_48;
    local_110[2] = &local_11c;
    local_84 = _DAT_00925018;
    local_ec = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe60;
    local_f4 = 0xc0000000;
    local_e4 = 0x313;
    local_104 = param_1;
    local_bc = FUN_004302c0;
    local_dc = FUN_00430280;
    local_c4 = FUN_004301b0;
    iVar1 = FUN_0064d270(local_110);
    if (iVar1 != 0) {
      uVar2 = FUN_0058b720(param_1);
      *(uint *)(iVar1 + 0x218) = uVar2 & 0xffff;
      if (param_3 <= 0.0) {
        param_3 = 0.0;
        *(undefined4 *)(iVar1 + 0x1b0) = 0;
        *(undefined4 *)(iVar1 + 0x1d0) = 0;
      }
      *(float *)(iVar1 + 0x20c) = param_3;
      *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffffefff;
      *(undefined1 *)(param_1 + 0x406) = 3;
    }
  }
  return;
}

