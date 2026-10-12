/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3730; label: FUN_006a3730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3730(int param_1)

{
  int iVar1;
  
  iVar1 = 8 - *(int *)(param_1 + 4);
  if (iVar1 < 8) {
    FUN_006a3570(param_1,0,iVar1);
  }
  return;
}

