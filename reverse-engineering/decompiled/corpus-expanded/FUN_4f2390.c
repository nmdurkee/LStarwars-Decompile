/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2390; label: FUN_004f2390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_004f2390(short *param_1,short *param_2)

{
  short *psVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    iVar2 = (int)param_1 - (int)param_2;
    do {
      psVar1 = param_2;
      if (*param_2 != 0) {
        while ((*(short *)(iVar2 + (int)psVar1) != 0 && (*(short *)(iVar2 + (int)psVar1) == *psVar1)
               )) {
          psVar1 = psVar1 + 1;
          if (*psVar1 == 0) {
            return param_1;
          }
        }
      }
      if (*psVar1 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 2;
    } while (*param_1 != 0);
  }
  return (short *)0x0;
}

