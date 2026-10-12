/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bc990; label: FUN_006bc990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc990(void)

{
  FUN_0061e5d0(1);
  if (DAT_02973a7c != 0) {
    if (*(int *)(DAT_02973a7c + 0x40) != 0) {
      *(undefined4 *)(*(int *)(DAT_02973a7c + 0x40) + 0x3c) = 0;
    }
    if (*(int *)(DAT_02973a7c + 0x3c) != 0) {
      *(undefined4 *)(*(int *)(DAT_02973a7c + 0x3c) + 0x40) = 0;
    }
  }
  DAT_02973a88 = 1;
  return;
}

