/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6a60; label: FUN_004f6a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6a60(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = PTR_DAT_00800478 + 0x4c;
  pcVar4 = param_1;
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
      cVar1 = *pcVar3;
    }
  }
  *pcVar4 = '\0';
  pcVar3 = PTR_DAT_00800478 + 0x1ac;
  cVar1 = *param_1;
  pcVar4 = param_1;
  while (cVar1 != '\0') {
    pcVar4 = pcVar4 + 1;
    cVar1 = *pcVar4;
  }
  if (pcVar3 != (char *)0x0) {
    do {
      *pcVar4 = *pcVar3;
      cVar1 = *pcVar3;
      pcVar4 = pcVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  cVar1 = PTR_DAT_00800478[0x4c];
  iVar2 = 0;
  while (cVar1 != '\0') {
    cVar1 = PTR_DAT_00800478[iVar2 + 0x4d];
    iVar2 = iVar2 + 1;
  }
  FUN_004efdf0(PTR_DAT_00800478,param_1 + iVar2);
  return;
}

