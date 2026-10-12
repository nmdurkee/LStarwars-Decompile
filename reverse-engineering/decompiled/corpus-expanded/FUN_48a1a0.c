/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a1a0; label: FUN_0048a1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a1a0(uint *param_1)

{
  DAT_0087b2cc = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_0087b2cc;
  *param_1 = *param_1 + 0x229e0;
  return;
}

