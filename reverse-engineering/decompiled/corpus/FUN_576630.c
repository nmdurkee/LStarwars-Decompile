/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x576630; label: FUN_00576630
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00576630(int param_1,int param_2)

{
  short *psVar1;
  
  if ((DAT_009514b4 != (short *)0x0) && (psVar1 = DAT_009514b4, *DAT_009514b4 != -1)) {
    while (*psVar1 != param_1) {
      psVar1 = psVar1 + 0xe;
      if (*psVar1 == -1) {
        return;
      }
    }
    if (param_2 == 1) {
      *(undefined1 *)(psVar1 + 10) = 0;
    }
    _DAT_009514c8 = 0;
  }
  return;
}

