/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61ad60; label: FUN_0061ad60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ad60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float *extraout_ECX;
  
  FUN_00618000(param_2,param_3,param_4,(undefined4 *)(param_1 + 0x5c));
  *(float *)(param_1 + 0x4c) = *extraout_ECX / 360.0;
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x5c);
  return;
}

