/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cdd40; label: FUN_006cdd40
 */

void FUN_006cdd40(byte param_1)

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

