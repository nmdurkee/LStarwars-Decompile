/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cace0; label: FUN_006cace0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cace0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0xc);
  FUN_006caa00();
  if ((((param_2 == *(int *)(iVar1 + 4)) || (param_2 == *(int *)(iVar1 + 0x10))) ||
      (param_2 == *(int *)(iVar1 + 0x14))) || (param_2 == *(int *)(iVar1 + 0x18))) {
    DAT_0081fad8 = 3;
    PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081fb70;
    FUN_006c58a0(DAT_0081fb80);
  }
  if (((param_2 == *(int *)(iVar1 + 0x1c)) || (param_2 == *(int *)(iVar1 + 0x20))) ||
     (param_2 == *(int *)(iVar1 + 0x24))) {
    DAT_0081fad8 = 4;
    PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081fbf0;
    FUN_006c58a0(DAT_0081fc00);
  }
  if (((param_2 == *(int *)(iVar1 + 0x28)) || (param_2 == *(int *)(iVar1 + 0x2c))) ||
     (param_2 == *(int *)(iVar1 + 0x30))) {
    DAT_0081fad8 = 5;
    PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081fc70;
    FUN_006c58a0(DAT_0081fc80);
  }
  piVar2 = DAT_0081fcfc;
  if (DAT_0081fcfc != (int *)0x0) {
    while (piVar2[2] != param_1) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
    piVar2[3] = iVar1;
  }
  return;
}

