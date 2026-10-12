/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e0f0; label: FUN_0056e0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0056e0f0(uint param_1)

{
  return *(uint *)(PTR_DAT_008032c4 + 8) & param_1;
}

