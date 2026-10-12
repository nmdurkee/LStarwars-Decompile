/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2050; label: FUN_004f2050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2050(char *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  if (param_2 == 0) {
    return;
  }
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return;
    }
    iVar5 = iVar5 + 1;
    bVar2 = param_1[iVar3 + 1];
    iVar4 = iVar3;
    while ((iVar3 = iVar4 + 1, 0x7f < bVar2 && (bVar2 < 0xc0))) {
      bVar2 = param_1[iVar4 + 2];
      iVar4 = iVar3;
    }
    if (param_2 == iVar5) break;
    cVar1 = param_1[iVar3];
  }
  return;
}

