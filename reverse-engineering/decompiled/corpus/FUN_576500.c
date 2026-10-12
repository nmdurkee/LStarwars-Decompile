/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x576500; label: FUN_00576500
 */

undefined1 FUN_00576500(int param_1)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  
  if (DAT_009514b4 != (short *)0x0) {
    sVar2 = *DAT_009514b4;
    psVar3 = DAT_009514b4;
    while (sVar2 != -1) {
      if (sVar2 == param_1) {
        return (char)psVar3[10];
      }
      psVar1 = psVar3 + 0xe;
      psVar3 = psVar3 + 0xe;
      sVar2 = *psVar1;
    }
  }
  return 0;
}

