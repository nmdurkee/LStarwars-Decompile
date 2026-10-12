/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627cf0; label: FUN_00627cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627cf0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xc);
  FUN_004f1f10(iVar1 + 0x4c,param_2 + 0x4c);
  if (*(code **)(iVar1 + 0x15c) != (code *)0x0) {
    (**(code **)(iVar1 + 0x15c))(*(undefined4 *)(param_1 + 0x40),iVar1,param_3);
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

