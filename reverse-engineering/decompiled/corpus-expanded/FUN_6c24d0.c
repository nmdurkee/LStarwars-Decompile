/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c24d0; label: FUN_006c24d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c24d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa4c;
  FUN_006c2350();
  FUN_006c23f0();
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x58);
  }
  return;
}

