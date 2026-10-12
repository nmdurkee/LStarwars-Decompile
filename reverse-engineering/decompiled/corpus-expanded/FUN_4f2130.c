/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2130; label: FUN_004f2130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f2130(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  if (param_3 != 0) {
    pcVar3 = param_1;
    if ((param_3 == -1) || (pcVar3 = param_2, param_3 == -2)) {
      param_3 = FUN_004f1ff0(pcVar3);
    }
    do {
      cVar1 = *param_1;
      cVar2 = *param_2;
      if (cVar2 < cVar1) {
        return 1;
      }
      if (cVar1 < cVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (((cVar1 != '\0') && (cVar2 != '\0')) && (param_3 != 0));
  }
  return 0;
}

