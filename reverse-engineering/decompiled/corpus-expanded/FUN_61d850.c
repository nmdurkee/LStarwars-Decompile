/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61d850; label: FUN_0061d850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061d850(int param_1,float param_2)

{
  *(undefined4 *)(param_1 + 0x60) = 0x3c;
  *(float *)(param_1 + 0x50) = (param_2 - *(float *)(param_1 + 0x58)) / *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x54) = param_2;
  if (*(code **)(param_1 + 0x4c) != (code *)0x0) {
    (**(code **)(param_1 + 0x4c))(0,param_1,0);
  }
  return;
}

