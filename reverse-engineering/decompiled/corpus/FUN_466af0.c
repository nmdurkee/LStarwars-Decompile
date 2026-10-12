/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x466af0; label: FUN_00466af0
 */

char * FUN_00466af0(int param_1)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  char *in_EDX;
  int iVar3;
  
  pcVar2 = in_EDX;
  if ((in_EDX != (char *)0x0) && (in_EAX != (char *)0x0)) {
    iVar3 = 0;
    while( true ) {
      if (param_1 + -1 <= iVar3) {
        return pcVar2;
      }
      cVar1 = *in_EAX;
      *in_EDX = cVar1;
      in_EDX = in_EDX + 1;
      in_EAX = in_EAX + 1;
      if (cVar1 == '_') break;
      iVar3 = iVar3 + 1;
      if (*in_EAX == '\0') {
        return pcVar2;
      }
    }
    return pcVar2;
  }
  return (char *)0x0;
}

