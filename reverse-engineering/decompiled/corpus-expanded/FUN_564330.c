/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x564330; label: FUN_00564330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00564330(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076191c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

