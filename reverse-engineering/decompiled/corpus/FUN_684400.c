/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684400; label: FUN_00684400
 */

void FUN_00684400(int *param_1)

{
  char *pcVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  short *psVar5;
  
  if ((*param_1 != -1) &&
     (pcVar1 = (char *)(*param_1 * 0x330 + 0x185 + DAT_029620a4), *pcVar1 == '\0')) {
    *pcVar1 = '\x01';
    if (DAT_029211e8 < DAT_02962094) {
      iVar4 = DAT_029211e8;
      do {
        if ((int)*(short *)(DAT_02962084 + iVar4 * 2) == *param_1) {
          *(undefined1 *)(*param_1 * 0x330 + 0x185 + DAT_029620a4) = 0;
          *param_1 = -1;
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_02962094);
    }
    iVar4 = DAT_029620a4 + *param_1 * 0x330;
    sVar2 = *(short *)(iVar4 + 0x182);
    if (sVar2 == 0) {
      *(undefined1 *)(iVar4 + 0x185) = 0;
      return;
    }
    iVar4 = *(int *)(DAT_0296209c + sVar2 * 4);
    FUN_006553f0(param_1);
    bVar3 = false;
    psVar5 = (short *)(iVar4 + 0x3d0);
    iVar4 = 8;
    do {
      if ((int)*psVar5 == *param_1) {
        bVar3 = true;
        *psVar5 = -1;
      }
      psVar5 = psVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (!bVar3) {
      FUN_00656010(*param_1 * 0x330 + DAT_029620a4);
    }
    *(undefined2 *)(*param_1 * 0x330 + 0x182 + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x32a + DAT_029620a4) = 0xffff;
    DAT_029211e8 = DAT_029211e8 + -1;
    *(short *)(DAT_02962084 + DAT_029211e8 * 2) = (short)*param_1;
    *(undefined1 *)(*param_1 * 0x330 + 0x185 + DAT_029620a4) = 0;
    *param_1 = -1;
  }
  return;
}

