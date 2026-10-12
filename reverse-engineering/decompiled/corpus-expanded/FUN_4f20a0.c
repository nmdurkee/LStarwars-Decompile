/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f20a0; label: FUN_004f20a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_004f20a0(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (*param_1 != '\0') {
    iVar2 = (int)param_1 - (int)param_2;
    do {
      pcVar1 = param_2;
      if (*param_2 != '\0') {
        while ((pcVar1[iVar2] != '\0' && (pcVar1[iVar2] == *pcVar1))) {
          pcVar1 = pcVar1 + 1;
          if (*pcVar1 == '\0') {
            return param_1;
          }
        }
      }
      if (*pcVar1 == '\0') {
        return param_1;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
    } while (*param_1 != '\0');
  }
  return (char *)0x0;
}

