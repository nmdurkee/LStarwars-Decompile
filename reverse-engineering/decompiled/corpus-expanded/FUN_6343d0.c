/* Ghidra pseudocode, not original source.
 * ev_00f52e189c4008d6734275378e3b7e7cc775b5c4744fc695c4d739e43a001eb2
 * Entry: 0x6343d0; label: FUN_006343d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006343d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x10);
  }
  return;
}

