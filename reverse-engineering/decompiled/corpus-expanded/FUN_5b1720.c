/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1720; label: FUN_005b1720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1720(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_0095e418 = 0;
  *in_ECX = &PTR_FUN_00763f18;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x24);
  }
  return;
}

