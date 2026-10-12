/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x613610; label: FUN_00613610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613610(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_108;
  undefined1 auStack_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = param_3;
  for (piVar1 = *(int **)(param_1 + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if ((piVar1[7] & 0x80000000U) == 0) {
      if (piVar1[9] == (uint)*(ushort *)(in_ECX + 0xc)) {
        iVar4 = FUN_006be710(piVar1[3]);
        iVar3 = piVar1[6];
        if (iVar3 < 1) {
          iVar3 = *(int *)(iVar4 + 4);
        }
        (**(code **)(*piVar1 + 4))(param_2,piVar1[3],auStack_104,0x100);
        FUN_00611f60(auStack_104,iVar3,local_108);
      }
    }
    else {
      uVar2 = FUN_006be7f0(piVar1[3]);
      iVar3 = (**(code **)*piVar1)(param_2);
      if (iVar3 != 0) {
        FUN_00613610(uVar2,iVar3,local_108);
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

