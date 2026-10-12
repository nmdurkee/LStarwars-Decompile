/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e68a0; label: FUN_005e68a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e68a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

