/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d7350; label: FUN_006d7350
 */

bool FUN_006d7350(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = in_ECX + 0x6358;
  piVar2 = (int *)(in_ECX + 0x6558);
  do {
    if (iVar4 != param_2) {
      iVar1 = FUN_004f48e0(iVar4);
      if (-1 < iVar1) {
        *piVar2 = iVar1;
        FUN_004ef660(iVar3,iVar1 * 0x17c + 0x4ea2 + in_ECX,0x80);
      }
    }
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 0x80;
  } while (iVar4 < 3);
  iVar4 = 0;
  iVar3 = param_2;
  do {
    iVar1 = FUN_006d43e0(3,param_1,iVar3);
    if (iVar1 != 0) {
      FUN_006d45f0(iVar1,param_1,param_2,1,param_2);
      iVar3 = FUN_006d7040(param_2,3);
      return iVar3 == 0;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 3) {
      iVar3 = 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return false;
}

