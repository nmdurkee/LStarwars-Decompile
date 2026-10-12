/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bc510; label: FUN_006bc510
 */

void FUN_006bc510(int *param_1,int *param_2)

{
  int in_ECX;
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  int *local_c;
  undefined4 local_8;
  int local_4;
  
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
  local_4 = *param_2 - *param_1;
  if (*(int *)(in_ECX + 0x3c) == 0) {
    *(int *)(in_ECX + 0xa60) = *param_2;
    *(int *)(in_ECX + 0xa5c) = *param_2 + -0x20000;
  }
  *(undefined4 *)(in_ECX + 0xa58) = *(undefined4 *)(in_ECX + 0xa5c);
  local_20 = (int *)(in_ECX + 0xa58);
  local_1c = (int *)(in_ECX + 0xa60);
  local_18 = 0;
  local_14 = *local_1c - *local_20;
  FUN_006b9400(&local_10,&local_20);
  *(undefined4 *)(in_ECX + 0xa50) = 0;
  *(undefined2 *)(in_ECX + 0xa54) = 0xffff;
  return;
}

