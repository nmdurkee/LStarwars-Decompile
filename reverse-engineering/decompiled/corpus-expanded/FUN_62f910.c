/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f910; label: FUN_0062f910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062f910(int param_1)

{
  DAT_029a99a0 = param_1;
  if (param_1 != 0) {
    DAT_0291310c = *(undefined1 *)(param_1 + 0x168);
    *(undefined4 *)(param_1 + 0x168) = 1;
  }
  return;
}

