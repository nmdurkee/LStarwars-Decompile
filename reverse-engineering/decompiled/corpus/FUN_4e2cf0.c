/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e2cf0; label: FUN_004e2cf0
 */

void FUN_004e2cf0(int param_1)

{
  DAT_0087aa20 = 0;
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"starfighter1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"starfighter2",1);
  if (DAT_0093b2a4 != 0) {
    DAT_0087aa20 = 2;
  }
  return;
}

