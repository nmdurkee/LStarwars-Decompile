/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x6287a0; label: FUN_006287a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006287a0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (*(code **)(iVar1 + 0x60) != (code *)0x0) {
    (**(code **)(iVar1 + 0x60))(param_1,param_2,param_3);
  }
  if (*(int *)(iVar1 + 0x50) != 0) {
    FUN_0061a870(iVar1,*(int *)(iVar1 + 0x50));
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

