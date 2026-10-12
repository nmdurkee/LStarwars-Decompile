/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627d40; label: FUN_00627d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627d40(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xc);
  FUN_004f1f10(*(undefined4 *)(iVar1 + 100),param_2 + 0x4c);
  if (*(code **)(iVar1 + 0x78) != (code *)0x0) {
    (**(code **)(iVar1 + 0x78))(*(undefined4 *)(param_1 + 0x40),iVar1,param_3);
  }
  iVar1 = *(int *)(param_1 + 0x40);
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  if (iVar1 != 0) {
    FUN_006271a0(iVar1);
  }
  return;
}

