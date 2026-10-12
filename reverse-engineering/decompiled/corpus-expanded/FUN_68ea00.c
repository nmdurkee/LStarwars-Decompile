/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68ea00; label: FUN_0068ea00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068ea00(char param_1)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  *(undefined4 *)(&DAT_02948eb0 + param_1 * 4) = 0;
  (&DAT_02924b10)[param_1] = 0;
  piVar2 = &DAT_02924b60;
  iVar3 = 1;
  local_4 = in_ECX;
  do {
    if ((*(char *)((int)piVar2 + 0x41) == param_1) && (*piVar2 != -1)) {
      if (*piVar2 != 99999) {
        FUN_00684400(piVar2);
      }
      DAT_02962a2c = DAT_02962a2c + -1;
      *piVar2 = -1;
    }
    piVar2 = piVar2 + 0x16;
  } while ((int)piVar2 < 0x292fb60);
  iVar4 = DAT_0296209c;
  if (1 < DAT_02962098) {
    do {
      if ((*(int *)(iVar4 + iVar3 * 4) != 0) &&
         (iVar1 = *(int *)(iVar4 + iVar3 * 4), *(char *)(iVar1 + 0x11) == param_1)) {
        iVar4 = 0;
        *(undefined1 *)(iVar1 + 0x13) = 1;
        if (0 < DAT_02962094) {
          iVar1 = 0;
          do {
            if (*(short *)(DAT_029620a4 + 0x182 + iVar1) == iVar3) {
              local_4 = iVar4;
              FUN_00684400(&local_4);
            }
            iVar4 = iVar4 + 1;
            iVar1 = iVar1 + 0x330;
          } while (iVar4 < DAT_02962094);
        }
        FUN_00655730(*(undefined4 *)(DAT_0296209c + iVar3 * 4));
        if (*(int *)(*(int *)(DAT_0296209c + iVar3 * 4) + 0x2a8) != 0) {
          DAT_02924b44 = DAT_02924b44 + -1;
          *(undefined4 *)(DAT_02962090 + DAT_02924b44 * 4) =
               *(undefined4 *)(*(int *)(DAT_0296209c + iVar3 * 4) + 0x2a8);
          *(undefined4 *)(*(int *)(DAT_0296209c + iVar3 * 4) + 0x2a8) = 0;
        }
        *(undefined4 *)(DAT_0296209c + iVar3 * 4) = 0;
        DAT_02962a24 = DAT_02962a24 + -1;
        iVar4 = DAT_0296209c;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_02962098);
  }
  return;
}

