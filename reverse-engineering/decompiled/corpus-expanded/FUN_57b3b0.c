/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57b3b0; label: FUN_0057b3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057b3b0(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  if (DAT_00951bf4 < 2) {
    fVar2 = (float10)FUN_004f8100(param_1);
    fVar1 = (float)fVar2;
    *(float *)(DAT_00951bf4 * 0x10 + 0x164 + DAT_00951c4c) = fVar1;
    if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
      fVar2 = (float10)FUN_004f8100(param_1);
      fVar1 = (float)fVar2;
      *(float *)(DAT_00951bf4 * 0x10 + 0x168 + DAT_00951c4c) = fVar1;
      if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
        fVar2 = (float10)FUN_004f8100(param_1);
        fVar1 = (float)fVar2;
        *(float *)(DAT_00951bf4 * 0x10 + 0x16c + DAT_00951c4c) = fVar1;
        if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
          fVar2 = (float10)FUN_004f8100(param_1);
          fVar1 = (float)fVar2;
          *(float *)((DAT_00951bf4 + 0x17) * 0x10 + DAT_00951c4c) = fVar1;
          if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
            DAT_00951bf4 = DAT_00951bf4 + 1;
          }
        }
      }
    }
  }
  return;
}

