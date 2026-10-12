/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8a60; label: FUN_005f8a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f8a60(int param_1)

{
  return *(undefined4 *)(&DAT_028492f0 + param_1 * 4);
}

