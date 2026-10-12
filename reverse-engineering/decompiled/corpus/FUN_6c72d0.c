/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c72d0; label: FUN_006c72d0
 */

void FUN_006c72d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f97c;
  if (in_ECX[5] != 0) {
    FUN_006334d0(in_ECX[5],in_ECX[3] << 4);
  }
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x18);
  }
  return;
}

