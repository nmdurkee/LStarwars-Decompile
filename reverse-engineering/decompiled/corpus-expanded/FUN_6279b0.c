/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x6279b0; label: FUN_006279b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006279b0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x40) != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  while (iVar1 != 0) {
    param_1 = *(int *)(param_1 + 0x3c);
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  *(int *)(param_2 + 0x40) = param_1;
  *(int *)(param_1 + 0x3c) = param_2;
  FUN_006271a0(param_2);
  return 1;
}

