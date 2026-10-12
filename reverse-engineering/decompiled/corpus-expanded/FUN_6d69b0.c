/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d69b0; label: FUN_006d69b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d69b0(undefined1 param_1,undefined1 param_2)

{
  if ((byte)(DAT_029755a3 + 1) != DAT_029755a2) {
    (&DAT_029755f8)[DAT_029755a3] = param_1;
    (&DAT_029756f8)[DAT_029755a3] = param_2;
    DAT_029755a3 = DAT_029755a3 + 1;
    return 1;
  }
  return 0;
}

