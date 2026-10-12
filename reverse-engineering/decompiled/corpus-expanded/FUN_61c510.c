/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61c510; label: FUN_0061c510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061c510(float param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(int *)((int)param_1 + 8) == 0xf) {
    if (0.0 <= param_2) {
      param_1 = param_2;
    }
    else {
      param_1 = 0.0;
    }
    if (param_1 <= 1.0) {
      param_1 = param_2;
      if (param_2 < 0.0) {
        param_1 = 0.0;
      }
    }
    else {
      param_1 = 1.0;
    }
    fVar1 = 1.0;
    *(float *)(iVar2 + 0x74) = param_1;
    if (0.0 <= param_3) {
      param_1 = param_3;
    }
    else {
      param_1 = 0.0;
    }
    if ((param_1 <= 1.0) && (fVar1 = param_3, param_3 < 0.0)) {
      *(undefined4 *)(iVar2 + 0x78) = 0;
      return;
    }
    *(float *)(iVar2 + 0x78) = fVar1;
  }
  return;
}

