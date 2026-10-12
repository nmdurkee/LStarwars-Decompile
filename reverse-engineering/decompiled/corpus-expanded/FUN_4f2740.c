/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2740; label: FUN_004f2740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2740(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  _vsprintf(param_1,param_2,&stack0x0000000c);
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  return;
}

