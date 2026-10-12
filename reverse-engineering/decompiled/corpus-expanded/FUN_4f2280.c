/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2280; label: FUN_004f2280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f2280(short *param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != (short *)0x0) {
    do {
      *param_1 = *param_2;
      sVar1 = *param_2;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (sVar1 != 0);
    return iVar2;
  }
  *param_1 = 0;
  return iVar2;
}

