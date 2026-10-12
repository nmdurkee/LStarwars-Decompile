/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e9020; label: FUN_005e9020
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e9020(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_005c9140();
  _DAT_00973870 = param_1;
  iVar2 = *param_2;
  uVar1 = iVar2 + 0xfU & 0xfffffff0;
  *param_2 = uVar1 + 0x10;
  DAT_00973880 = (undefined4 *)(iVar2 + 0xfU & 0xfffffff0);
  DAT_00973880[2] = uVar1 + 0x10;
  iVar2 = (*param_2 + 0xfU & 0xfffffff0) + param_1 * 0x30;
  *param_2 = iVar2;
  DAT_00973880[3] = iVar2;
  *param_2 = *param_2 + param_1;
  *(short *)(DAT_00973880 + 1) = (short)param_1;
  *DAT_00973880 = 0;
  return;
}

