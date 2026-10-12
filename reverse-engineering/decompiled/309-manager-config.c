/* ev_9563b7b50855ed2f3bd6f2ad76f91288a9e19d654f9e0f7e567e4aebe4ba1e14 */

float10 FUN_006d5b30(int param_1)

{
  float fVar1;
  
  fVar1 = (*(float *)(DAT_02975144 + 0x6314 + param_1 * 4) -
          *(float *)(DAT_02975144 + 0x6320 + param_1 * 4)) * 0.125 +
          *(float *)(DAT_02975144 + 0x6320 + param_1 * 4);
  *(float *)(DAT_02975144 + 0x6320 + param_1 * 4) = fVar1;
  fVar1 = fVar1 * 4.0;
  if (ABS(fVar1) < 0.01) {
    fVar1 = 0.0;
  }
  return (float10)fVar1;
}

