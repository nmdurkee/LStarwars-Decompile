/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6d00f0; label: FUN_006d00f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d00f0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
                 int *param_6)

{
  int iVar1;
  int in_ECX;
  int *local_1c4;
  int *local_1c0;
  int *local_1bc;
  undefined4 local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined **local_1a0 [2];
  undefined4 local_198;
  undefined4 local_194;
  undefined4 *local_18c;
  int **local_188;
  undefined4 local_184;
  undefined4 local_120;
  undefined4 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1c4;
  local_1c4 = param_6;
  *(undefined1 *)(in_ECX + 0x2a0) = 1;
  local_1b0 = 0;
  local_1ac = 0;
  local_1c0 = param_3;
  local_1bc = param_4;
  local_1b8 = 0;
  local_1b4 = *param_4 - *param_3;
  if (*(int *)(in_ECX + 0xa50) == 0) {
    FUN_006b93b0(&local_1b0,&local_1c0);
  }
  iVar1 = FUN_004f02d0(*param_5,*local_1c4 - *param_5,0);
  if (iVar1 != 0) {
    local_188 = &local_1c0;
    local_18c = &local_1b0;
    local_194 = 0;
    local_184 = 0;
    local_198 = 1;
    local_1a0[0] = &PTR_FUN_0076f988;
    local_120 = 0;
    local_8 = 0;
    local_1c = 0;
    local_c = 0;
    FUN_006c8200(iVar1,4);
    local_184 = 0x400000;
    FUN_006cb6f0(local_1a0);
    local_8 = 0;
    FUN_004f99e0(iVar1);
  }
  if (*(int *)(in_ECX + 0xa50) == 0) {
    FUN_006b9400(&local_1b0,&local_1c0);
  }
  *(undefined1 *)(in_ECX + 0x2a0) = 0;
  __security_check_cookie(local_4 ^ (uint)&local_1c4);
  return;
}

