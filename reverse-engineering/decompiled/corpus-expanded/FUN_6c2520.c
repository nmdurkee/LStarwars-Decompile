/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2520; label: FUN_006c2520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b5b4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

