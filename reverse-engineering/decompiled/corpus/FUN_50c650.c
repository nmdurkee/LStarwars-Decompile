/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50c650; label: FUN_0050c650
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050c650(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 float param_5,float param_6,undefined4 param_7,int param_8)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  iVar2 = DAT_00921ea0;
  if (DAT_00921ea0 == 0) {
    iVar2 = DAT_00921e8c;
  }
  if ((param_8 == 0) || (DAT_00921ea4 == 0)) {
    iVar2 = DAT_00921e8c;
    if (DAT_00921ea0 != 0) {
      iVar2 = DAT_00921ea0;
    }
    local_408 = 1.0;
  }
  else {
    local_408 = *(float *)(iVar2 + 0x14) / *(float *)(DAT_00921ea4 + 0x14);
    iVar2 = DAT_00921ea4;
  }
  FUN_005d0fb0(iVar2);
  fVar1 = local_408 * _DAT_008015b8 * param_6;
  local_408 = _DAT_008015b4 * param_5 * local_408;
  FUN_005d0fe0(iVar2,local_408,fVar1);
  FUN_0050c050(param_1,local_404,iVar2);
  fVar3 = (float10)FUN_005d0c50(iVar2,local_404);
  local_408 = (float)fVar3;
  FUN_005d1060(iVar2,param_7);
  FUN_005eabb0(iVar2,param_2,param_3,param_4);
  FUN_005f34e0(iVar2,local_404);
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

