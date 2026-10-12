/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64a7c0; label: FUN_0064a7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064a7c0(int param_1)

{
  int iVar1;
  
  FUN_005b9d90(&DAT_008102e8);
  iVar1 = FUN_006e6b90();
  *(int *)(param_1 + 0x124) = iVar1 + *(int *)(param_1 + 0x10c);
  FUN_005b9d90(&DAT_008102e8);
  iVar1 = FUN_006e6b90();
  *(int *)(param_1 + 0x128) = iVar1 + *(int *)(param_1 + 0x110);
  FUN_005b9d90(&DAT_008102e8);
  iVar1 = FUN_006e6b90();
  *(int *)(param_1 + 300) = iVar1 + *(int *)(param_1 + 0x114);
  return;
}

