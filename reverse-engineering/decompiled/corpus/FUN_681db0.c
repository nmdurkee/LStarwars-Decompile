/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x681db0; label: FUN_00681db0
 */

void FUN_00681db0(int *param_1,code *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  while (iVar2 != -1) {
    param_1 = param_1 + 1;
    if (-1 < iVar2) {
      (*param_2)(iVar2);
      iVar2 = (int)*(short *)(iVar2 * 0x40 + 0x14 + DAT_02947b74);
      if (iVar2 != -1) {
        sVar1 = *(short *)(&DAT_02920d8a + iVar2 * 8);
        iVar3 = 0;
        if (0 < sVar1) {
          do {
            (*param_2)((int)*(short *)(&DAT_02921260 +
                                      (*(short *)(&DAT_02920d88 + iVar2 * 8) + iVar3) * 2));
            iVar3 = iVar3 + 1;
          } while (iVar3 < sVar1);
        }
      }
    }
    iVar2 = *param_1;
  }
  return;
}

