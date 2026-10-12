/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d35f0; label: FUN_004d35f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004d35f0(int param_1)

{
  float fVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
    fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x1dc);
    return (float10)(fVar1 + fVar1);
  }
  return (float10)3.0;
}

