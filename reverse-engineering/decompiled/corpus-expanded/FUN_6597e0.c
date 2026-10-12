/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x6597e0; label: FUN_006597e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006597e0(int param_1)

{
  DAT_02962108 = DAT_02962108 + -1;
  if ((&DAT_0292fe18)[param_1 * 0xb5] != -1) {
    (&DAT_0292fe18)[param_1 * 0xb5] = 0xffffffff;
  }
  return;
}

