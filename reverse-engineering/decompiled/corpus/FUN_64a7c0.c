/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64a7c0; label: FUN_0064a7c0
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

