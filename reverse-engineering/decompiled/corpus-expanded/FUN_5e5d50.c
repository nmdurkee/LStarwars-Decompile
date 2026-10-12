/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e5d50; label: FUN_005e5d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5d50(void)

{
  int in_ECX;
  
  FUN_00605ad0(*(undefined4 *)(in_ECX + 0x58));
  *(undefined4 *)(in_ECX + 0x58) = 0;
  FUN_00605ad0(*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}

