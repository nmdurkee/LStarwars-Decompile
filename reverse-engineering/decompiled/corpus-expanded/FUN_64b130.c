/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64b130; label: FUN_0064b130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0064b130(int param_1)

{
  return (uint)(&DAT_02913a58 + param_1 * 0x178) & -(uint)((&DAT_02913a58)[param_1 * 0x178] != '\0')
  ;
}

