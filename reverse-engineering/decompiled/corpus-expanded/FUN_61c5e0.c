/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61c5e0; label: FUN_0061c5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061c5e0(int param_1,int param_2,int param_3,int param_4)

{
  if (*(int *)(param_1 + 8) == 0xf) {
    if (param_2 != 0) {
      FUN_004f1f10(param_1 + 0x90,param_2);
    }
    if (param_3 != 0) {
      FUN_004f1f10(param_1 + 0xa0,param_3);
    }
    if (param_4 != 0) {
      FUN_004f1f10(param_1 + 0xb0,param_4);
    }
  }
  return;
}

