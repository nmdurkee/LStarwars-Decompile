/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x576960; label: FUN_00576960
 */

void FUN_00576960(int param_1)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  
  if ((param_1 != -1) && (DAT_009514b4 != (short *)0x0)) {
    sVar2 = *DAT_009514b4;
    psVar3 = DAT_009514b4;
    while (sVar2 != -1) {
      if (sVar2 == param_1) {
        if ((char)psVar3[10] != '\0') {
          return;
        }
        *(undefined1 *)(psVar3 + 10) = 1;
        FUN_005766e0();
        return;
      }
      psVar1 = psVar3 + 0xe;
      psVar3 = psVar3 + 0xe;
      sVar2 = *psVar1;
    }
  }
  return;
}

