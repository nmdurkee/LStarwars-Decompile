/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4efec0; label: FUN_004efec0
 */

void FUN_004efec0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  cVar1 = *param_2;
  pcVar5 = param_2;
  pcVar4 = param_2;
  do {
    if (cVar1 == '\0') {
      *pcVar4 = '\0';
      return;
    }
    cVar1 = *(char *)(param_1 + 0x10);
    if ((((*pcVar5 == cVar1) && (pcVar5[1] == '.')) && (pcVar5[2] == '.')) &&
       (pcVar3 = pcVar5, pcVar5[3] == cVar1)) {
      do {
        pcVar2 = pcVar3;
        pcVar4 = pcVar2;
        if (pcVar2 <= param_2) goto LAB_004eff13;
        pcVar4 = pcVar2 + -1;
        if (pcVar2[-1] == cVar1) {
          pcVar5 = pcVar5 + 3;
          goto LAB_004eff13;
        }
        pcVar3 = pcVar4;
      } while (pcVar2[-1] != ':');
      pcVar5 = pcVar5 + 4;
      pcVar4 = pcVar2;
    }
LAB_004eff13:
    *pcVar4 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar4 = pcVar4 + 1;
    cVar1 = *pcVar5;
  } while( true );
}

