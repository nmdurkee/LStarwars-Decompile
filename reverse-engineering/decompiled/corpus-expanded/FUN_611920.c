/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611920; label: FUN_00611920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076ab7c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

