/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639570; label: FUN_00639570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639570(undefined4 param_1,int param_2)

{
  *(uint *)(&DAT_0291350c + *(int *)(param_2 + 0xc) * 4) = *(byte *)(param_2 + 0x11) & 1;
  return;
}

