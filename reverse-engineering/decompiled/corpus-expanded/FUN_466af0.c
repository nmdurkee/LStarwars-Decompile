/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466af0; label: FUN_00466af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

