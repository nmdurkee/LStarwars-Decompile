/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6caac0; label: FUN_006caac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006caac0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_2 + 0xc);
  *(int *)(iVar1 + 4) = param_2;
  iVar2 = FUN_006caa00();
  if (iVar2 == 0) {
    DAT_0081fad8 = 0;
    PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081faf0;
    uVar4 = DAT_0081fb00;
  }
  else {
    DAT_0081fad8 = 3;
    PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081fb70;
    uVar4 = DAT_0081fb80;
  }
  FUN_006c58a0(uVar4);
  piVar3 = DAT_0081fcfc;
  if (DAT_0081fcfc != (int *)0x0) {
    while (piVar3[2] != param_1) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) {
        return;
      }
    }
    piVar3[3] = iVar1;
  }
  return;
}

