/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d60d0; label: FUN_006d60d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d60d0(int param_1)

{
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xfffffffb;
  return;
}

