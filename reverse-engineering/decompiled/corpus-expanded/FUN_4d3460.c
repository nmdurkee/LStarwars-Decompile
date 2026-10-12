/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3460; label: FUN_004d3460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d3460(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xcc4), iVar1 != 0))
  {
    FUN_004d2c40(param_1,iVar1);
    *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 0xf0) & 0xfffffffb;
  }
  return;
}

