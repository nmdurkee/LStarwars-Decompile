/* Ghidra pseudocode, not original source.
 * ev_00f52e189c4008d6734275378e3b7e7cc775b5c4744fc695c4d739e43a001eb2
 * Entry: 0x634350; label: FUN_00634350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634350(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b5b4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

