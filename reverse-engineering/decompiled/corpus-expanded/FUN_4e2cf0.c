/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e2cf0; label: FUN_004e2cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

