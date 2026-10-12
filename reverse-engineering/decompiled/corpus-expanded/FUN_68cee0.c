/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68cee0; label: FUN_0068cee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068cee0(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0068cdb0(DAT_00810ad8);
  DAT_00810ad8 = 0xffffffff;
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

