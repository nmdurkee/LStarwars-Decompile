/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7cf0; label: FUN_004f7cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f7cf0(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar1 = param_1;
  if ((param_2 != (char *)0x0) && (cVar3 = *param_2, cVar3 != '\0')) {
    do {
      *pcVar1 = cVar3;
      cVar3 = pcVar1[(int)(param_2 + (1 - (int)param_1))];
      pcVar1 = pcVar1 + 1;
    } while (cVar3 != '\0');
  }
  *pcVar1 = '\0';
  iVar2 = FUN_004f7c70();
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0xe) == '\x04') {
      return 1;
    }
    pcVar4 = &DAT_0090fba8;
    do {
      if ((pcVar4[0xe] == '\x04') && (pcVar4[0xd] == *(char *)(iVar2 + 0xd))) {
        pcVar1 = pcVar1 + ((int)pcVar4[0xf] - (int)*(char *)(iVar2 + 0xf));
        *pcVar1 = '\0';
        cVar3 = *pcVar4;
        while (cVar3 != '\0') {
          pcVar1 = pcVar1 + -1;
          pcVar4 = pcVar4 + 1;
          *pcVar1 = cVar3;
          cVar3 = *pcVar4;
        }
        return 1;
      }
      pcVar4 = pcVar4 + 0x10;
    } while (pcVar4 != (char *)0x0);
  }
  return 0;
}

