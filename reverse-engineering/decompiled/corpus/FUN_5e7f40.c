/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e7f40; label: FUN_005e7f40
 */

void FUN_005e7f40(uint param_1,uint *param_2)

{
  int iVar1;
  uint *in_ECX;
  uint uVar2;
  undefined4 local_414;
  undefined4 local_410;
  uint local_2d8;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  uint uStack_d0;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_414;
  in_ECX[2] = param_1;
  in_ECX[3] = 0;
  *in_ECX = *param_2 + 0xf & 0xfffffff0;
  uVar2 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar2;
  uVar2 = uVar2 + in_ECX[2] * 0xa0;
  *param_2 = uVar2;
  in_ECX[1] = uVar2;
  uVar2 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar2;
  *param_2 = uVar2 + in_ECX[2] * 4;
  if (DAT_0097383c == 0) {
    DAT_0097383c = FUN_005e4b20(1);
    DAT_00973840 = FUN_005e4b20(0);
    DAT_00973844 = FUN_005e4b20(0);
    _memset(&local_414,0,0x208);
    local_2d8 = local_2d8 | 0x40001;
    local_414 = 0x1000;
    local_410 = 0;
    FUN_00601230(DAT_00973840,&local_414);
    *(uint *)(DAT_00973840 + 0x40) = *(uint *)(DAT_00973840 + 0x40) & 0xffff3fff;
    *(uint *)(DAT_00973840 + 0x40) = *(uint *)(DAT_00973840 + 0x40) & 0xfffffffd | 0xd;
    *(uint *)(DAT_00973840 + 0x40) = *(uint *)(DAT_00973840 + 0x40) & 0xfff7ffff;
    *(uint *)(DAT_00973840 + 0x40) = *(uint *)(DAT_00973840 + 0x40) & 0xffffefff | 0x2000;
    iVar1 = DAT_00973840;
    FUN_00601030(DAT_00973840);
    *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
    _memset(&uStack_20c,0,0x208);
    uStack_d0 = uStack_d0 | 1;
    uStack_20c = 0x1000;
    uStack_208 = 0;
    FUN_00601230(DAT_0097383c,&uStack_20c);
    *(uint *)(DAT_0097383c + 0x40) = *(uint *)(DAT_0097383c + 0x40) & 0xffff3fff;
    *(uint *)(DAT_0097383c + 0x40) = *(uint *)(DAT_0097383c + 0x40) & 0xfffffffd | 0xd;
    *(uint *)(DAT_0097383c + 0x40) = *(uint *)(DAT_0097383c + 0x40) & 0xfff7ffff;
    *(uint *)(DAT_0097383c + 0x40) = *(uint *)(DAT_0097383c + 0x40) & 0xffffefff | 0x2000;
    iVar1 = DAT_0097383c;
    FUN_00601030(DAT_0097383c);
    *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
    *(uint *)(DAT_00973844 + 0x40) = *(uint *)(DAT_00973844 + 0x40) & 0xffff7fff | 0x4000;
    *(uint *)(DAT_00973844 + 0x40) = *(uint *)(DAT_00973844 + 0x40) & 0xfffffff1 | 1;
    *(uint *)(DAT_00973844 + 0x40) = *(uint *)(DAT_00973844 + 0x40) & 0xffffefff | 0x2000;
    iVar1 = DAT_00973844;
    FUN_00601030(DAT_00973844);
    *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_414);
  return;
}

