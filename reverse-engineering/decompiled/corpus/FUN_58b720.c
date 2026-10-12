/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b720; label: FUN_0058b720
 */

uint FUN_0058b720(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x1fc) >> 7 & 1) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0x804;
    }
    if ((*(uint *)(param_1 + 0x1f8) & 0x10001) != 0) {
      return uVar1 | 0x10;
    }
    if ((*(uint *)(param_1 + 0x1f8) & 4) != 0) {
      return uVar1 | 0x20;
    }
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}

