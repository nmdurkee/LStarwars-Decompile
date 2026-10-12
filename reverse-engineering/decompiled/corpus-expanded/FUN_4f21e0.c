/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f21e0; label: FUN_004f21e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f21e0(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  }
  if (param_2 != (short *)0x0) {
    do {
      *param_1 = *param_2;
      sVar1 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (sVar1 != 0);
  }
  return;
}

