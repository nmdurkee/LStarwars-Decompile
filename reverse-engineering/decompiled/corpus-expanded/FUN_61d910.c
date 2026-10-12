/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61d910; label: FUN_0061d910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0061d910(float *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_1[5];
  fVar2 = (_DAT_0080f550 - *param_1) / param_1[2];
  if (fVar2 <= 0.0) {
    param_1 = (float *)0x0;
  }
  else {
    param_1 = (float *)0x3f800000;
    if (fVar2 < 1.0) {
      param_1 = (float *)fVar2;
    }
  }
  fVar2 = *(float *)((int)fVar1 + 0x5c) * (float)param_1;
  *(undefined4 *)((int)fVar1 + 0x60) = 0x3c;
  *(float *)((int)fVar1 + 0x50) =
       (fVar2 - *(float *)((int)fVar1 + 0x58)) / *(float *)((int)fVar1 + 0x5c);
  *(float *)((int)fVar1 + 0x54) = fVar2;
  if (*(code **)((int)fVar1 + 0x4c) != (code *)0x0) {
    (**(code **)((int)fVar1 + 0x4c))(0,fVar1,0);
  }
  return DAT_02912ec4 >> 6 & 1;
}

