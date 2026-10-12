/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5c70; label: FUN_005e5c70
 */

void FUN_005e5c70(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x1c] = 0x3f800000;
  in_ECX[0x1d] = 0x3f800000;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[0x1e] = 0x3f800000;
  in_ECX[2] = 0;
  *in_ECX = &PTR_LAB_00765410;
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

