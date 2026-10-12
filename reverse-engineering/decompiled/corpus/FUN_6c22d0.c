/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c22d0; label: FUN_006c22d0
 */

void FUN_006c22d0(byte param_1)

{
  char *pcVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa04;
  pcVar1 = (char *)in_ECX[4];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  pcVar1 = (char *)in_ECX[3];
  if (pcVar1 != (char *)0x0) {
    FUN_006334d0(pcVar1,(int)*pcVar1);
  }
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

