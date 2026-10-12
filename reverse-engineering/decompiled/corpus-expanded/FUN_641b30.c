/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641b30; label: FUN_00641b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00641b30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x20);
  }
  return;
}

