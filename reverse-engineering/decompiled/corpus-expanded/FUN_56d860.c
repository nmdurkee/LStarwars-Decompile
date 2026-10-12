/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56d860; label: FUN_0056d860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d860(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0x38 + ((int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

