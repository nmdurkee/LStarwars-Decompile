/* Ghidra pseudocode, not original source.
 * ev_45200ba16e8ef520c819c849d12b8874968ca721432c6a61fa3b24bce95adf30
 * Entry: 0x696a60; label: FUN_00696a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00696a60(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}

