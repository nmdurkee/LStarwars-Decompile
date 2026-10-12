/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e5c70; label: FUN_005e5c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5c70(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x1c] = 0x3f800000;
  in_ECX[0x1d] = 0x3f800000;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[0x1e] = 0x3f800000;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00765410;
  in_ECX[0x1f] = 0x40400000;
  in_ECX[0x21] = 0;
  in_ECX[0x20] = 3;
  in_ECX[0x1b] = 0x40a00000;
  in_ECX[0x1a] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x18] = 0x40066666;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0x3f800000;
  return;
}

