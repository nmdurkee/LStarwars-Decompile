/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x589230; label: FUN_00589230
 */

void FUN_00589230(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x54) = (float)((fVar1 * (float10)3.1415927410125732) / (float10)180.0);
  return;
}

