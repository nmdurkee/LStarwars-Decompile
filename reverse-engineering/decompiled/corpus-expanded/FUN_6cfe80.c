/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cfe80; label: FUN_006cfe80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cfe80(undefined4 param_1,int *param_2,int *param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_264;
  int *local_260;
  int *local_25c;
  int local_258;
  int local_254;
  int *local_250;
  int *local_24c;
  undefined4 local_248;
  int local_244;
  undefined1 local_240 [28];
  undefined4 local_224;
  undefined4 local_a8;
  undefined1 local_a4 [32];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_264;
  local_260 = (int *)0x0;
  local_25c = (int *)0x0;
  local_250 = param_2;
  local_24c = param_3;
  local_248 = 0;
  local_244 = *param_3 - *param_2;
  local_264 = -1;
  if (*(int *)(in_ECX + 0x3c) == 0) {
    *(int *)(in_ECX + 0xa60) = *param_3;
    *(int *)(in_ECX + 0xa5c) = *param_3 + -0x20000;
  }
  iVar2 = FUN_004f1fc0(param_1,0x2f);
  iVar3 = FUN_004f1ff0(iVar2 + 1);
  FUN_004f1f40(local_a4,iVar2 + 1,iVar3 + -3);
  iVar2 = FUN_004f1ff0(param_1);
  FUN_004f1f40(local_84,param_1,iVar2 - iVar3);
  DAT_02973aa0 = FUN_006bc700(local_a4);
  if (DAT_02973aa0 != -1) {
    FUN_004f1f10(DAT_02973aa0 * 0xa8 + 0x2cc + in_ECX,local_84);
  }
  *(short *)(in_ECX + 0xa54) = DAT_02973aa0;
  local_260 = (int *)(in_ECX + 0xa58);
  *local_260 = *(int *)(in_ECX + 0xa5c);
  local_25c = (int *)(in_ECX + 0xa60);
  local_258 = 0;
  local_254 = *local_25c - *local_260;
  FUN_006bc5c0(param_1);
  if (*(int *)(in_ECX + 0xa50) == 0) {
    FUN_006b93b0(&local_250,&local_260);
  }
  iVar2 = *local_260;
  uVar4 = FUN_004fd5d0(in_ECX + 0x94c,iVar2,local_254);
  if (0 < (int)uVar4) {
    if (uVar4 < (uint)(*local_25c - *local_260)) {
      *local_260 = *local_260 + uVar4;
      local_258 = local_258 + uVar4;
      local_254 = local_254 - uVar4;
    }
    iVar2 = FUN_004f02d0(iVar2,uVar4,0);
    if (iVar2 != 0) {
      FUN_006c1e80(&local_250,&local_260);
      if (param_4 != 0) {
        local_224 = 0x200000;
      }
      FUN_006c8200(iVar2,4);
      iVar3 = FUN_006cb6f0(local_240);
      local_a8 = 0;
      FUN_004f99e0(iVar2);
      if (iVar3 == 0) {
        local_264 = -1;
      }
      else {
        puVar1 = (uint *)(DAT_02973aa0 * 0xa8 + 0x350 + in_ECX);
        *puVar1 = *puVar1 | 2;
        local_264 = (int)DAT_02973aa0;
        DAT_02973aa0 = -1;
      }
      goto LAB_006d00b1;
    }
  }
  FUN_006b7c50(in_ECX + 0x94c);
LAB_006d00b1:
  if (*(int *)(in_ECX + 0xa50) == 0) {
    FUN_006b9400(&local_250,&local_260);
  }
  __security_check_cookie(local_4 ^ (uint)&local_264);
  return;
}

