/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6ba6a0; label: FUN_006ba6a0
 */

void FUN_006ba6a0(undefined4 param_1)

{
  if (DAT_02973a10 == 0) {
    DAT_02973a10 = FUN_005e4d40(1);
    *(uint *)(DAT_02973a10 + 0x40) = *(uint *)(DAT_02973a10 + 0x40) & 0xffffefff | 0x2000;
    *(uint *)(DAT_02973a10 + 0x40) = *(uint *)(DAT_02973a10 + 0x40) & 0xfffffff1 | 1;
    FUN_005e4b00(DAT_02973a10);
    DAT_02973a14 = FUN_005e4d40(1);
    *(uint *)(DAT_02973a14 + 0x40) = *(uint *)(DAT_02973a14 + 0x40) & 0xffffefff | 0x2000;
    *(uint *)(DAT_02973a14 + 0x40) = *(uint *)(DAT_02973a14 + 0x40) | 0xc000;
    *(uint *)(DAT_02973a14 + 0x40) = *(uint *)(DAT_02973a14 + 0x40) & 0xfffffff1 | 1;
    FUN_005e4b00(DAT_02973a14);
    DAT_02973a64 = param_1;
    DAT_02973a60 = 1;
    return;
  }
  DAT_02973a64 = param_1;
  DAT_02973a60 = 1;
  return;
}

