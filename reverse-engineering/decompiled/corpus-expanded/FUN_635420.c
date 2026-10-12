/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635420; label: FUN_00635420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00635420(int param_1,int param_2)

{
  int in_ECX;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(in_ECX + 4);
  local_8 = param_1;
  local_4 = 0;
  FUN_006c94a0(&local_c,*(undefined4 *)(param_1 + 8));
  if (*(int *)(param_1 + 0x14) == 1) {
    FUN_00623e00(param_1 + 0x20,*(undefined4 *)(param_1 + 0x1c),
                 *(uint *)(param_1 + 8) & 0xffffff | 0x80000000,0x10,0);
    if (param_2 != 0) {
      FUN_00623fc0(param_1 + 0x20,*(undefined4 *)(param_1 + 0x1c),0xffffffff,0);
    }
  }
  return;
}

