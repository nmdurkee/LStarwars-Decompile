/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c3b20; label: FUN_006c3b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c3b20(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  undefined4 uStack_168;
  undefined4 uStack_164;
  float fStack_160;
  undefined4 uStack_15c;
  undefined4 *puStack_158;
  undefined4 uStack_154;
  undefined4 uStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_bc [132];
  uint uStack_38;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&uStack_144;
  iVar2 = *(int *)(param_2 + 0xc);
  uStack_154 = 0;
  puStack_158 = &local_120;
  uStack_15c = DAT_02973abc;
  fStack_160 = *(float *)(iVar2 + 0xc);
  uStack_164 = 0x6c3b5f;
  (**(code **)(**(int **)(iVar2 + 8) + 4))();
  uStack_164 = *(undefined4 *)(param_2 + 100);
  uStack_168 = 0x6c3b68;
  fVar3 = (float10)FUN_004f28e0();
  fVar1 = (float)fVar3;
  if (param_2 == *(int *)(iVar2 + 0x10)) {
    fStack_100 = fVar1;
  }
  if (param_2 == *(int *)(iVar2 + 0x14)) {
    fStack_fc = fVar1;
  }
  if (param_2 == *(int *)(iVar2 + 0x18)) {
    fStack_f8 = fVar1;
  }
  if (((((*(int *)(iVar2 + 0x1c) != 0) || (*(int *)(iVar2 + 0x20) != 0)) ||
       (*(int *)(iVar2 + 0x24) != 0)) ||
      ((*(int *)(iVar2 + 0x28) != 0 || (*(int *)(iVar2 + 0x2c) != 0)))) ||
     (*(int *)(iVar2 + 0x30) != 0)) {
    uStack_164 = 0x6c3bc8;
    FUN_006b7df0();
    if (((*(int *)(iVar2 + 0x28) != 0) && (*(int *)(iVar2 + 0x2c) != 0)) &&
       (*(int *)(iVar2 + 0x30) != 0)) {
      uStack_164 = *(undefined4 *)(*(int *)(iVar2 + 0x28) + 100);
      uStack_168 = 0x6c3be4;
      fVar3 = (float10)FUN_004f28e0();
      fStack_140 = (float)fVar3;
      uStack_168 = *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 100);
      fVar3 = (float10)FUN_004f28e0();
      fStack_13c = (float)fVar3;
      fVar3 = (float10)FUN_004f28e0(*(undefined4 *)(*(int *)(iVar2 + 0x30) + 100));
      fStack_138 = (float)fVar3;
      uStack_134 = 0x3f800000;
      FUN_005b4a50(&uStack_f0,&fStack_140);
    }
    uStack_164 = *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 100);
    uStack_168 = 0x6c3c2f;
    FUN_004f28e0();
    uStack_168 = 0x6c3c3a;
    FUN_006e6b90();
    uStack_168 = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 100);
    FUN_004f28e0();
    FUN_006e6b90();
    FUN_004f28e0(*(undefined4 *)(*(int *)(iVar2 + 0x24) + 100));
    uStack_164 = 0x6c3c71;
    uStack_144 = FUN_006e6b90();
    uStack_164 = 0x6c3c80;
    FUN_006b8110();
    uStack_164 = 0x6c3c89;
    FUN_006b81f0();
    uStack_164 = 0x6c3c92;
    FUN_006b82d0();
    uStack_130 = uStack_f0;
    uStack_12c = uStack_ec;
    uStack_128 = uStack_e8;
    uStack_124 = uStack_e4;
    local_120 = uStack_e0;
    uStack_11c = uStack_dc;
    uStack_118 = uStack_d8;
    uStack_114 = uStack_d4;
    uStack_110 = uStack_d0;
    uStack_10c = uStack_cc;
    uStack_108 = uStack_c8;
    uStack_104 = uStack_c4;
  }
  uStack_164 = 0;
  uStack_168 = 0;
  uStack_f4 = 0x3f800000;
  (**(code **)(**(int **)(iVar2 + 8) + 8))(*(undefined4 *)(iVar2 + 0xc),DAT_02973abc,&uStack_130);
  FUN_004f2740(auStack_bc,&DAT_0076bd70,(double)fStack_160);
  FUN_0061e530(param_2,auStack_bc);
  __security_check_cookie(uStack_38 ^ (uint)&uStack_168);
  return;
}

