/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5ea390; label: FUN_005ea390
 */

void FUN_005ea390(int param_1,int param_2,float param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x34) + param_2);
  iVar2 = *(int *)(DAT_00973880 + 8);
  FUN_005ce350(param_1,param_3 - 1.0,iVar2,param_2,0);
  if ((bVar1 & 1) == 0) {
    FUN_005b44e0(param_4);
  }
  else {
    local_c = FUN_006e6b90();
    local_8 = FUN_006e6b90();
    local_4 = FUN_006e6b90();
    thunk_FUN_005b5300(param_4,&local_c);
  }
  if ((bVar1 & 8) != 0) {
    thunk_FUN_005b4c30(param_4,iVar2 + 0x18);
  }
  FUN_005b4900(param_4,iVar2);
  *(float *)(param_4 + 8) = -*(float *)(param_4 + 8);
  *(float *)(param_4 + 0x18) = -*(float *)(param_4 + 0x18);
  *(float *)(param_4 + 0x20) = -*(float *)(param_4 + 0x20);
  *(float *)(param_4 + 0x24) = -*(float *)(param_4 + 0x24);
  *(float *)(param_4 + 0x2c) = -*(float *)(param_4 + 0x2c);
  *(float *)(param_4 + 0x38) = -*(float *)(param_4 + 0x38);
  return;
}

