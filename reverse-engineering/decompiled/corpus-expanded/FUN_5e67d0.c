/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e67d0; label: FUN_005e67d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e67d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0x3f800000;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[8] = 0;
  in_ECX[2] = 0;
  in_ECX[6] = 0;
  *in_ECX = &PTR_FUN_0076543c;
  return;
}

