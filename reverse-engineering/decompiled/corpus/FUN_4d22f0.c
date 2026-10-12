/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d22f0; label: FUN_004d22f0
 */

void FUN_004d22f0(undefined4 *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && ((byte *)*param_1 != (byte *)0x0)) {
    iVar2 = 0;
    pbVar1 = &DAT_00881261;
    while (((byte *)*param_1 != pbVar1 + -1 || ((*pbVar1 & 1) == 0))) {
      pbVar1 = pbVar1 + 0x88;
      iVar2 = iVar2 + 1;
      if (0x881ae0 < (int)pbVar1) {
        return;
      }
    }
    _memset(&DAT_00881260 + iVar2 * 0x88,0,0x88);
    *param_1 = 0;
  }
  return;
}

