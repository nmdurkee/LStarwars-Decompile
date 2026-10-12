/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578750; label: FUN_00578750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_00578750(undefined4 param_1)

{
  _memset(DAT_009519f4,0,0x80);
  _memset(DAT_009519ec,0,0x80);
  _DAT_00951b70 = 0;
  _DAT_009519f0 = param_1;
  return DAT_009519f4;
}

