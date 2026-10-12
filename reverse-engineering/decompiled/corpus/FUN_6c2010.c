/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c2010; label: FUN_006c2010
 */

void FUN_006c2010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f800;
  if (in_ECX[4] != 0) {
    *(undefined4 *)(in_ECX[4] + 0xc) = 0;
  }
  if (in_ECX[5] != 0) {
    *(undefined4 *)(in_ECX[5] + 0xc) = 0;
  }
  if (in_ECX[6] != 0) {
    *(undefined4 *)(in_ECX[6] + 0xc) = 0;
  }
  *in_ECX = &PTR_LAB_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x1c);
  }
  return;
}

