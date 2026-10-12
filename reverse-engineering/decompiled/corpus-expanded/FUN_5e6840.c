/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e6840; label: FUN_005e6840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e6840(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[0xb7] = 0;
  in_ECX[0xb8] = 0;
  in_ECX[0xb9] = 0;
  in_ECX[0xba] = 0;
  in_ECX[0xbb] = 0;
  in_ECX[0xbc] = 0;
  in_ECX[0x12] = 0x3f000000;
  in_ECX[0xbd] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[3] = 4;
  in_ECX[0x11] = 0;
  *in_ECX = &PTR_FUN_00765494;
  return;
}

