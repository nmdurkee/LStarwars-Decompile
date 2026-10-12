/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499be0; label: FUN_00499be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00499be0(int param_1)

{
  float fVar1;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_c = 0;
  if ((*(char *)(param_1 + 0x671) != -1) && (_DAT_007fc024 != 0.0)) {
    fVar1 = (*(float *)(param_1 + 0xc48) + 1.0) * _DAT_007fc024 * _DAT_0087b888;
    local_8 = local_c;
    local_4 = fVar1;
    FUN_005b35a0(&local_c,&local_c,*(undefined2 *)(param_1 + 0x694));
    FUN_005b3620(&local_c,&local_c,*(undefined2 *)(param_1 + 0x696));
    FUN_005b37d0(param_1 + 0xf18,param_1 + 0xf18,&local_c);
    return (float10)fVar1;
  }
  return (float10)0.0;
}

