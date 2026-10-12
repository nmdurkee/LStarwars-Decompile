/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x576670; label: FUN_00576670
 */

void FUN_00576670(void)

{
  short sVar1;
  short *psVar2;
  
  if (DAT_009514b4 != (short *)0x0) {
    sVar1 = *DAT_009514b4;
    psVar2 = DAT_009514b4;
    while (sVar1 != -1) {
      *(byte *)(psVar2 + 1) = *(byte *)(psVar2 + 1) & 0xfd;
      *(undefined1 *)(psVar2 + 10) = 0;
      psVar2 = psVar2 + 0xe;
      sVar1 = *psVar2;
    }
  }
  return;
}

