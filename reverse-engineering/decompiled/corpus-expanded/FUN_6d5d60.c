/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5d60; label: FUN_006d5d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d5d60(int param_1)

{
  if (-1 < param_1) {
    return *(int *)(param_1 * 0x17c + 0x4e34 + DAT_02975144) != 0;
  }
  return false;
}

