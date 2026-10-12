/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a73e0; label: FUN_006a73e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a73e0(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(ABS(*(float *)*param_1) < ABS(*(float *)*param_2));
  if (ABS(*(float *)*param_2) < ABS(*(float *)*param_1)) {
    return uVar1 - 1;
  }
  return uVar1;
}

