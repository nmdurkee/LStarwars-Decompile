/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2470; label: FUN_006e2470
 */

void FUN_006e2470(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_1[4];
  local_18 = *param_1;
  local_4 = param_1[5];
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  if (DAT_00973900 <= local_10) {
    local_10 = DAT_00973900;
  }
  if (DAT_00973904 <= local_c) {
    local_c = DAT_00973904;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0xbc))(*(int **)(in_ECX + 4),&local_18);
  *(undefined4 *)(in_ECX + 0x170) = *param_1;
  *(undefined4 *)(in_ECX + 0x174) = param_1[1];
  *(undefined4 *)(in_ECX + 0x178) = param_1[2];
  *(undefined4 *)(in_ECX + 0x17c) = param_1[3];
  *(undefined4 *)(in_ECX + 0x180) = param_1[4];
  *(undefined4 *)(in_ECX + 0x184) = param_1[5];
  return;
}

