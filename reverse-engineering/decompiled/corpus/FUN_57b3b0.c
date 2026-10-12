/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57b3b0; label: FUN_0057b3b0
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

