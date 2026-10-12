/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6c40; label: FUN_006d6c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d6c40(int param_1)

{
  if (((&DAT_029751a0)[param_1 + DAT_029755a1 * 0x100] != '\0') &&
     ((&DAT_029751a0)[param_1 + ((int)DAT_029755a1 ^ 1U) * 0x100] !=
      (&DAT_029751a0)[param_1 + DAT_029755a1 * 0x100])) {
    return 1;
  }
  return 0;
}

