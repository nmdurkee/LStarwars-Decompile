/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630700; label: FUN_00630700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00630700(int param_1)

{
  if (DAT_0291311c != 0) {
    return *(undefined4 *)(DAT_0291311c + 4 + param_1 * 8);
  }
  return 0;
}

