/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578da0; label: FUN_00578da0
 */

int FUN_00578da0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_00951b84) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(iVar3 + 0x40 + DAT_00951b78,param_1);
      if (iVar1 == 0) {
        if (param_2 != (int *)0x0) {
          *param_2 = iVar2;
        }
        return iVar2 * 0x130 + DAT_00951b78;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x130;
    } while (iVar2 < DAT_00951b84);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  return 0;
}

