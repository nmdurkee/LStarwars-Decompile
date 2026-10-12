/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5765b0; label: FUN_005765b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005765b0(void)

{
  float fVar1;
  
  if (DAT_009514b8 != 0) {
    if ((*(float *)(DAT_009514b8 + 8) != 0.0) &&
       (fVar1 = *(float *)(DAT_009514b8 + 8) - 0.5, _DAT_009514c8 < fVar1)) {
      _DAT_009514c8 = fVar1;
      *(undefined4 *)(DAT_009514b8 + 0x18) = 0;
      return;
    }
    *(undefined4 *)(DAT_009514b8 + 0x18) = 0;
  }
  return;
}

