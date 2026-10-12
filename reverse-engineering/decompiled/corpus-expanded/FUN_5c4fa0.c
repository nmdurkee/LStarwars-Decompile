/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c4fa0; label: FUN_005c4fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4fa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

