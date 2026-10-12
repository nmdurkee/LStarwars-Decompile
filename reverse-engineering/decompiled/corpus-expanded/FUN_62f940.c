/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f940; label: FUN_0062f940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062f940(void)

{
  if (DAT_029a99a0 != 0) {
    *(uint *)(DAT_029a99a0 + 0x168) = (uint)DAT_0291310c;
    DAT_029a99a0 = 0;
  }
  return;
}

