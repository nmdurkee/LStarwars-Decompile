/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5ca0; label: FUN_006d5ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_006d5ca0(int param_1,int param_2,int param_3,int param_4)

{
  if (param_3 != 0) {
    return *(undefined1 *)(DAT_02975144 + 0x6358 + (param_4 * 0x20 + param_2) * 4);
  }
  return *(undefined1 *)(DAT_02975144 + 0x4ea2 + (param_1 * 0x5f + param_2) * 4);
}

