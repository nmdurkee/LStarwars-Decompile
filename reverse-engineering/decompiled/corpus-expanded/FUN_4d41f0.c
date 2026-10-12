/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d41f0; label: FUN_004d41f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d41f0(undefined4 param_1)

{
  float10 fVar1;
  
  if (DAT_00881aec != 0) {
    fVar1 = (float10)FUN_004f8100(param_1);
    *(float *)(DAT_00881aec + 0x24) = (float)fVar1;
  }
  return;
}

