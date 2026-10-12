/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c3c0; label: FUN_0069c3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069c3c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    FUN_006a1630(param_1 + 0x94);
    FUN_006a1ae0(param_1 + 0x78);
    FUN_0069ee70(param_1 + 0x1e);
    if ((param_1[0x12] != 0) && (param_1[0xd] != 0)) {
      iVar2 = 0;
      if (0 < param_1[0xd]) {
        iVar1 = 0;
        iVar3 = 0;
        do {
          FUN_006a0180(param_1[0x12] + iVar3);
          FUN_006a00b0(param_1[0x13] + iVar1);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x20;
          iVar1 = iVar1 + 0x10;
        } while (iVar2 < param_1[0xd]);
      }
      _free((void *)param_1[0x12]);
      _free((void *)param_1[0x13]);
    }
    if ((void *)param_1[0xf] != (void *)0x0) {
      _free((void *)param_1[0xf]);
    }
    if ((void *)param_1[0x11] != (void *)0x0) {
      _free((void *)param_1[0x11]);
    }
    if ((void *)param_1[0x10] != (void *)0x0) {
      _free((void *)param_1[0x10]);
    }
    if ((void *)param_1[0xe] != (void *)0x0) {
      _free((void *)param_1[0xe]);
    }
    FUN_0069f420(param_1 + 6);
    if ((*param_1 != 0) && ((code *)param_1[0xb2] != (code *)0x0)) {
      (*(code *)param_1[0xb2])(*param_1);
    }
    _memset(param_1,0,0x2d0);
  }
  return 0;
}

