/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5765f0; label: FUN_005765f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005765f0(void)

{
  short sVar1;
  short *psVar2;
  
  if (DAT_009514b4 != (short *)0x0) {
    sVar1 = *DAT_009514b4;
    psVar2 = DAT_009514b4;
    while (sVar1 != -1) {
      psVar2[0xc] = 0;
      psVar2[0xd] = 0;
      psVar2 = psVar2 + 0xe;
      sVar1 = *psVar2;
    }
    _DAT_009514c8 = 0;
    DAT_009514bd = 2;
    _DAT_009514cc = 0;
    DAT_009514b8 = 0;
  }
  return;
}

