/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499b60; label: FUN_00499b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

