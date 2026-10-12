/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x426f60; label: FUN_00426f60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426f60(int param_1)

{
  FUN_00404e30(param_1);
  FUN_00426de0(param_1 + 0xc,0);
  *(undefined1 *)(param_1 + 0x28) = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x20) = _DAT_007f38fc;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}

