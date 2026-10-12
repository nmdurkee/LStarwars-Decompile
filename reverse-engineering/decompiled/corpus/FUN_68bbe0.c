/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68bbe0; label: FUN_0068bbe0
 */

void FUN_0068bbe0(int param_1)

{
  if ((&DAT_02924b60)[param_1 * 0x16] != -1) {
    if ((&DAT_02924b60)[param_1 * 0x16] != 99999) {
      FUN_00684400(&DAT_02924b60 + param_1 * 0x16);
    }
    DAT_02962a2c = DAT_02962a2c + -1;
    (&DAT_02924b60)[param_1 * 0x16] = 0xffffffff;
  }
  return;
}

