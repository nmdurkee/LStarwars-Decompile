/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57bf50; label: FUN_0057bf50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0057bf50(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_3 != (int *)0x0) {
    *param_3 = -1;
  }
  if (param_2 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(DAT_029130e4 + 0x10)) {
      iVar3 = 0;
      do {
        iVar1 = FUN_004f8b10(param_1,*(undefined4 *)
                                      (*(short *)(*(int *)(DAT_029130e4 + 0x18) + iVar3) * 0x4c +
                                       0xc + DAT_0093b274));
        if (iVar1 == 0) {
          if (param_3 != (int *)0x0) {
            *param_3 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x18) + iVar2 * 0x54);
          }
          return iVar2 * 0x54 + *(int *)(DAT_029130e4 + 0x18);
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x54;
      } while (iVar2 < *(int *)(DAT_029130e4 + 0x10));
    }
    return 0;
  }
  piVar4 = &DAT_0093d7f0;
  do {
    iVar2 = *piVar4;
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x1fc) & 1) != 0)) {
      iVar3 = FUN_004f8b10(*(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xc),param_1);
      if (iVar3 == 0) {
        return iVar2;
      }
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x93d810);
  return 0;
}

