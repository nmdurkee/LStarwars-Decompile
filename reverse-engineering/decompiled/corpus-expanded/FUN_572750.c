/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572750; label: FUN_00572750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00572750(float *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5170) != 0)) {
    *param_1 = *(float *)(*(int *)(iVar1 + 0x128) + 0xd0) + *param_1;
    param_1[2] = *(float *)(*(int *)(iVar1 + 0x128) + 0xd4) + param_1[2];
  }
  return 0;
}

