/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c24d0; label: FUN_006c24d0
 */

void FUN_006c24d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa4c;
  FUN_006c2350();
  FUN_006c23f0();
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x58);
  }
  return;
}

