/* Ghidra pseudocode, not original source.
 * ev_65739642fe41f5b8b860334b2741f542947d362cd0074980e50397e4ea9361e6
 * Entry: 0x6da460; label: FUN_006da460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006da460(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_a0 [156];
  uint local_4;
  
  iVar1 = DAT_02975144;
  local_4 = DAT_00829570 ^ (uint)local_a0;
  iVar4 = 0;
  piVar3 = (int *)(DAT_02975144 + 0x4e34);
  while ((iVar2 = FUN_004f4900(iVar4), *piVar3 == 0 || ((iVar2 != -1 && (iVar2 != param_1))))) {
LAB_006da4c7:
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 0x5f;
    if (0xd < iVar4) {
LAB_006da52f:
      __security_check_cookie(local_4 ^ (uint)local_a0);
      return;
    }
  }
  iVar2 = FUN_006d43e0(3,iVar4,param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_006d43e0(3,iVar4,0xffffffff);
    if (iVar2 == 0) goto LAB_006da4c7;
    FUN_006d45f0(iVar2,iVar4,param_1,1,param_1);
    FUN_006d4070(iVar4,local_a0,1,param_1,param_1);
    FUN_006d38f0(iVar1,0x40,local_a0);
    FUN_006d9b10();
    FUN_006d45f0(local_a0,iVar4,param_1,0,0xffffffff);
  }
  FUN_004f47f0(param_1,iVar4);
  FUN_004f4340(iVar4,1);
  goto LAB_006da52f;
}

