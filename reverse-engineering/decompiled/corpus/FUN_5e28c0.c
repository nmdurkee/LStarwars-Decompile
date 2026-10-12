/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e28c0; label: FUN_005e28c0
 */

void FUN_005e28c0(int *param_1)

{
  uint uVar1;
  
  DAT_00963f94 = *param_1 + 3U & 0xfffffffc;
  uVar1 = *param_1 + 3U & 0xfffffffc;
  *param_1 = uVar1 + 0x36b00;
  DAT_00963f88 = uVar1 + 0x36b00;
  uVar1 = *param_1 + 3U & 0xfffffffc;
  *param_1 = uVar1 + 2000;
  DAT_0096e568 = uVar1 + 2000;
  *param_1 = (*param_1 + 3U & 0xfffffffc) + 2000;
  return;
}

