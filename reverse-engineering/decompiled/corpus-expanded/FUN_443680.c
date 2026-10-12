/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443680; label: FUN_00443680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00443680(void)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (fVar1 < (float10)_DAT_00950780) {
    fVar1 = (float10)1;
  }
  return fVar1;
}

