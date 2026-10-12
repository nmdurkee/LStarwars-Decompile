/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41aef0; label: FUN_0041aef0
 */

undefined4 FUN_0041aef0(int param_1)

{
  if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && ((DAT_0086e4e3 & 1) != 0)) &&
      (DAT_00856980 != 0)) &&
     ((*(short *)(param_1 + 0x1064) == *(short *)(DAT_00856980 + 0x6c) ||
      (*(short *)(param_1 + 0x1064) == *(short *)(DAT_00856980 + 0x6e))))) {
    return 1;
  }
  return 0;
}

