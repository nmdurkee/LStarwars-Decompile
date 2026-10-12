/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2220; label: FUN_004f2220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f2220(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  }
  iVar2 = 0;
  if (param_2 != (short *)0x0) {
    do {
      if (param_3 == 0) {
        return iVar2;
      }
      *param_1 = *param_2;
      sVar1 = *param_2;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
    } while (sVar1 != 0);
  }
  return iVar2;
}

