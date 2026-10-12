/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x6585a0; label: FUN_006585a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006585a0(undefined4 param_1)

{
  float10 fVar1;
  
  if (DAT_02962080 == 0) {
    return (float10)0;
  }
  fVar1 = (float10)FUN_005becc0(param_1,DAT_02962080,0);
  return fVar1;
}

