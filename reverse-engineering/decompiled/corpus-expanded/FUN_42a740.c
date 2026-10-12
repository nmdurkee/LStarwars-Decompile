/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a740; label: FUN_0042a740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0042a740(void)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((float10)_DAT_0087b99c <= fVar1) || (DAT_00856c08 != 0)) {
    fVar1 = (float10)1;
  }
  return fVar1;
}

