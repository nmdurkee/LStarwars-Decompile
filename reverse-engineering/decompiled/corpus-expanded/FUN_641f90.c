/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641f90; label: FUN_00641f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00641f90(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined4 local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_98;
  local_8c = 0.01;
  iVar1 = *(int *)(DAT_02973a48 + 0x40);
  iVar2 = *(int *)(param_2 + 0xc);
  local_94 = *(float *)(iVar2 + 0x1c) - *(float *)(iVar2 + 0x18);
  if (local_94 < 5.0) {
    local_8c = 0.001;
  }
  *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) | 0x20;
  fVar3 = (float10)FUN_004f28e0();
  local_94 = (float)fVar3;
  local_88 = 0;
  local_90 = 0.0;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x70) & 0x40) == 0)) {
    FUN_0061f840(&local_88,&local_90);
    local_98 = _DAT_00810188 * local_90;
    local_94 = local_94 - local_98;
  }
  else {
    if (128.0 < (float)*(byte *)(iVar1 + 0x93)) {
      local_90 = local_8c * 10.0 * ((float)*(byte *)(iVar1 + 0x93) - 128.0);
    }
    if (*(byte *)(iVar1 + 0x93) < 0x80) {
      local_90 = local_8c * -10.0 * (128.0 - (float)*(byte *)(iVar1 + 0x93));
    }
    local_98 = (float)(uint)*(byte *)(iVar1 + 0x91);
    if (128.0 < (float)(int)local_98) {
      local_90 = local_8c * 0.1 * ((float)(int)local_98 - 128.0);
    }
    if (*(byte *)(iVar1 + 0x91) < 0x80) {
      local_98 = (float)(uint)*(byte *)(iVar1 + 0x91);
      local_90 = local_8c * -0.1 * (128.0 - (float)(int)local_98);
      local_94 = local_94 - local_90;
    }
    else {
      local_94 = local_94 - local_90;
    }
  }
  FUN_004f2740(local_84,*(undefined4 *)(iVar2 + 0x14),(double)local_94);
  FUN_0061e530(param_2,local_84);
  FUN_00641ed0(param_1,param_2,param_3);
  __security_check_cookie(local_4 ^ (uint)&local_98);
  return;
}

