/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9940; label: FUN_004f9940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f9940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  FUN_004ff4a0(param_1,param_2,param_3);
  _memset(&DAT_02983740,0,400);
  _memset(&DAT_0297dc60,0,0x3c0);
  DAT_0088ab48 = FUN_004ffa60();
  iVar1 = FUN_006db910();
  FUN_004f78b0(iVar1 == 0);
  DAT_0091ce60 = 0;
  DAT_00917844 = 0;
  _DAT_0088ab40 = 0xffffffff;
  _DAT_0088ab44 = 0xffffffff;
  return param_1;
}

