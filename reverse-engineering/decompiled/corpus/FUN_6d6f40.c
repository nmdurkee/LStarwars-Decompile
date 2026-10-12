/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6f40; label: FUN_006d6f40
 */

undefined4 FUN_006d6f40(int param_1,int param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (3 < *(int *)(in_ECX + 0x6558 + param_1 * 4) - 10U) {
    return 1;
  }
  if (param_3 == 7) {
    pcVar3 = (char *)(in_ECX + 0x4e13);
    cVar1 = *(char *)(in_ECX + 0x4e13);
    while (cVar1 != 0) {
      pcVar3 = pcVar3 + 1;
      if (param_4 == cVar1) {
        return 0;
      }
      cVar1 = *pcVar3;
    }
  }
  iVar6 = 0;
  if (0 < param_2) {
    iVar4 = in_ECX + 0x6358;
    piVar5 = (int *)(in_ECX + 0x6558);
    do {
      if (((iVar6 != param_1) && (*piVar5 != -1)) && (*piVar5 - 10U < 4)) {
        if (DAT_02975148 < '\0') {
          iVar2 = 0;
          do {
            if ((param_4 == *(short *)(iVar4 + 2 + iVar2 * 4)) &&
               (param_3 == *(byte *)(iVar4 + iVar2 * 4))) {
              return 0;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x20);
        }
        else {
          iVar2 = (int)DAT_02975148;
          if (-1 < iVar2) {
            pcVar3 = &DAT_02975148;
            do {
              pcVar3 = pcVar3 + 1;
              if ((param_4 == *(short *)(iVar4 + 2 + iVar2 * 4)) &&
                 (param_3 == *(byte *)(iVar4 + iVar2 * 4))) {
                return 0;
              }
              iVar2 = (int)*pcVar3;
            } while (-1 < iVar2);
          }
        }
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 0x80;
    } while (iVar6 < param_2);
  }
  return 1;
}

