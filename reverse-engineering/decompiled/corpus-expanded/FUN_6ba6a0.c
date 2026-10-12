/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba6a0; label: FUN_006ba6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

