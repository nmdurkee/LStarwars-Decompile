/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e6800; label: FUN_005e6800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e6800(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00765468;
  FUN_006069a0();
  return;
}

