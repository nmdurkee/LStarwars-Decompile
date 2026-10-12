/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x499b60; label: FUN_00499b60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00499b60(void)

{
  uint uVar1;
  undefined4 local_4;
  
  uVar1 = 0;
  _DAT_0087b888 = 0.0;
  local_4 = 0;
  if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
    uVar1 = 1;
    _DAT_0087b888 = *(float *)(DAT_0093d7f0 + 0xc44) + 0.0;
    local_4 = 1;
  }
  if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
    uVar1 = uVar1 + 1;
    _DAT_0087b888 = *(float *)(DAT_0093d7f4 + 0xc44) + _DAT_0087b888;
    local_4 = uVar1;
  }
  if (1 < uVar1) {
    _DAT_0087b888 = (1.0 / (float)local_4) * _DAT_0087b888;
  }
  return;
}

