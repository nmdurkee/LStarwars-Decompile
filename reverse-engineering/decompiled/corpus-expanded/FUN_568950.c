/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x568950; label: FUN_00568950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00568950(int param_1,int param_2)

{
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 != 0) {
    FUN_005b44e0(param_2);
    FUN_005b45a0(param_2,&DAT_00802518);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(undefined4 *)(param_2 + 0x38) = 0;
    FUN_005b4f70(param_2,*(undefined2 *)(param_1 + 0xe4));
    FUN_005b4dd0(param_2,*(undefined2 *)(param_1 + 0xe2));
    FUN_005b5060(param_2,*(undefined2 *)(param_1 + 0xe6));
    local_c = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x30);
    local_8 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x34);
    local_4 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x38);
    FUN_005b4900(param_2,&local_c);
  }
  return;
}

