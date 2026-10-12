/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46ba20; label: FUN_0046ba20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046ba20(int param_1)

{
  if ((*(uint *)(param_1 + 0x144) & 0x200) != 0) {
    FUN_0046ae30();
    return;
  }
  return;
}

