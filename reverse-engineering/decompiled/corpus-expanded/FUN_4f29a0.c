/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f29a0; label: FUN_004f29a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f29a0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  cVar1 = *param_1;
  iVar4 = 0;
  iVar2 = 0;
  pcVar3 = param_1 + 1;
  if (cVar1 == '-') {
    cVar1 = *pcVar3;
    iVar2 = -1;
    pcVar3 = param_1 + 2;
  }
  while (('/' < cVar1 && (cVar1 < ':'))) {
    iVar4 = cVar1 + -0x30 + iVar4 * 10;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  }
  if (iVar2 != 0) {
    return iVar2 * iVar4;
  }
  return iVar4;
}

