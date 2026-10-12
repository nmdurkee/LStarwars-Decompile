/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x743c50; label: FUN_00743c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00743c50(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  FUN_00742280(param_1);
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  puVar2 = (undefined1 *)(param_1 + 0x22);
  do {
    *puVar2 = (char)iVar1;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0xc;
  } while (iVar1 < 100);
  return;
}

