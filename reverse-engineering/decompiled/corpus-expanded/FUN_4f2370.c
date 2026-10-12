/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2370; label: FUN_004f2370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f2370(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    sVar1 = *param_1;
  }
  return iVar2;
}

