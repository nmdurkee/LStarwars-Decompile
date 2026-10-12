/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41a4d0; label: FUN_0041a4d0
 */

int FUN_0041a4d0(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0093d7f4;
  if ((((param_1 != DAT_0093d7f0) && (iVar1 = DAT_0093d7f0, param_1 != DAT_0093d7f4)) ||
      (iVar1 == 0)) || ((*(byte *)(iVar1 + 0x1fc) & 0x80) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

