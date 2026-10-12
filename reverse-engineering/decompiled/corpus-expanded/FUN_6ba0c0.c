/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba0c0; label: FUN_006ba0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba0c0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_98;
  int local_88 [29];
  uint uStack_14;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_88;
  iVar2 = *(int *)(param_2 + 0xc);
  piVar4 = *(int **)(iVar2 + 0x10);
  iVar3 = *piVar4;
  while (iVar3 != 0) {
    iStack_98 = *(int *)(param_2 + 100);
    iVar3 = FUN_004f8b10(iVar3);
    if (iVar3 == 0) {
      iStack_98 = *piVar4;
      FUN_0061e530(param_2);
      __security_check_cookie(local_4 ^ (uint)local_88);
      return;
    }
    piVar1 = piVar4 + 2;
    piVar4 = piVar4 + 2;
    iVar3 = *piVar1;
  }
  iStack_98 = *(int *)(param_2 + 100);
  local_88[0] = FUN_004f29a0();
  piVar4 = *(int **)(iVar2 + 0x10);
  iVar3 = *piVar4;
  while( true ) {
    if (iVar3 == 0) {
      iStack_98 = 0;
      (**(code **)(**(int **)(iVar2 + 8) + 4))(*(undefined4 *)(iVar2 + 0xc),DAT_02973ab0,local_88);
      FUN_004f2740(&stack0xffffff6c,&DAT_0075c058,iStack_98);
      FUN_0061e530(param_2,&stack0xffffff6c);
      __security_check_cookie(uStack_14 ^ (uint)&iStack_98);
      return;
    }
    if (piVar4[1] == local_88[0]) break;
    piVar4 = piVar4 + 2;
    iVar3 = *piVar4;
  }
  iStack_98 = *piVar4;
  FUN_0061e530(param_2);
  __security_check_cookie(local_4 ^ (uint)local_88);
  return;
}

