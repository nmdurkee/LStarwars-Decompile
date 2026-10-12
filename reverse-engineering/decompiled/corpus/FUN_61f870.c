/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f870; label: FUN_0061f870
 */

undefined4 FUN_0061f870(int param_1)

{
  if (param_1 != 0) {
    if ((((*(byte *)(param_1 + 0x92) < 0x40) || (0xc0 < *(byte *)(param_1 + 0x92))) ||
        (*(byte *)(param_1 + 0x93) < 0x40)) || (0xc0 < *(byte *)(param_1 + 0x93))) {
      return 1;
    }
    if (((*(byte *)(param_1 + 0x90) < 0x40) || (0xc0 < *(byte *)(param_1 + 0x90))) ||
       ((*(byte *)(param_1 + 0x91) < 0x40 || (0xc0 < *(byte *)(param_1 + 0x91))))) {
      return 2;
    }
  }
  return 0;
}

