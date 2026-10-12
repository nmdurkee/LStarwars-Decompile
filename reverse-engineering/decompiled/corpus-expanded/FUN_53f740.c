/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f740; label: FUN_0053f740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053f740(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0xdc + ((int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

