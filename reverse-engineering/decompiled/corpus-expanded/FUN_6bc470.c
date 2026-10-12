/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc470; label: FUN_006bc470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc470(int *param_1,int *param_2)

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
  local_20 = (int *)(in_ECX + 0xa58);
  *local_20 = *(int *)(in_ECX + 0xa5c);
  local_1c = (int *)(in_ECX + 0xa60);
  local_18 = 0;
  local_14 = *local_1c - *local_20;
  *(undefined4 *)(in_ECX + 0xa50) = 1;
  FUN_006b93b0(&local_10,&local_20);
  return;
}

