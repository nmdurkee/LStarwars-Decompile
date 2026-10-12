/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7c70; label: FUN_004f7c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_004f7c70(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  char *in_ECX;
  char *pcVar3;
  
  if ((in_EAX == 0) && (*in_ECX != '\0')) {
    in_EAX = 0;
    do {
      in_EAX = in_EAX + 1;
    } while (in_ECX[in_EAX] != '\0');
  }
  pcVar3 = &DAT_0090fba8;
  cVar1 = DAT_0090fba8;
  while( true ) {
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    iVar2 = FUN_004f77d0(in_ECX + in_EAX);
    if (iVar2 != 0) break;
    pcVar3 = pcVar3 + 0x10;
    cVar1 = *pcVar3;
  }
  return pcVar3;
}

