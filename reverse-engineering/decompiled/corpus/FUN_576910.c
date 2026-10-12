/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x576910; label: FUN_00576910
 */

void FUN_00576910(int param_1)

{
  int iVar1;
  
  if ((DAT_009514b8 == (short *)0x0) || (*DAT_009514b8 != param_1)) {
    if ((param_1 < 0) || (*(int *)(DAT_00926c20 + param_1 * 4) == 0)) {
      DAT_009514b8 = (short *)0x0;
    }
    else {
      iVar1 = FUN_00576480(param_1);
      if (iVar1 != 0) {
        FUN_00576860();
        return;
      }
    }
  }
  return;
}

