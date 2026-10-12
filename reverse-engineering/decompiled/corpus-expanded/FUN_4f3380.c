/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3380; label: FUN_004f3380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3380(char *param_1,char *param_2,int param_3,char *param_4)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (*param_2 == '\0') {
    *param_1 = '\0';
    return;
  }
  do {
    cVar1 = *(char *)(param_3 + iVar4);
    iVar5 = param_3 + iVar4;
    if (cVar1 != '\0') {
      do {
        cVar2 = param_2[iVar5 - param_3];
        if (((byte)(cVar2 + 0xbfU) < 0x1a) || ((byte)(cVar2 + 0x40U) < 0x20)) {
          cVar2 = cVar2 + ' ';
        }
        if (((byte)(cVar1 + 0xbfU) < 0x1a) || ((byte)(cVar1 + 0x40U) < 0x20)) {
          cVar1 = cVar1 + ' ';
        }
        if (cVar2 != cVar1) {
          iVar4 = 0;
          goto LAB_004f342c;
        }
        cVar1 = *(char *)(iVar5 + 1);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (cVar1 != '\0');
    }
    if (iVar4 == 0) {
LAB_004f342c:
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    else {
      param_2 = param_2 + iVar4;
      if (param_4 != (char *)0x0) {
        cVar1 = *param_4;
        pcVar3 = param_4;
        while (cVar1 != '\0') {
          pcVar3 = pcVar3 + 1;
          *param_1 = cVar1;
          param_1 = param_1 + 1;
          cVar1 = *pcVar3;
        }
      }
      iVar4 = 0;
    }
    if (*param_2 == '\0') {
      *param_1 = '\0';
      return;
    }
  } while( true );
}

