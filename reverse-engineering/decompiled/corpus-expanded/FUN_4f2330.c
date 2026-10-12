/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2330; label: FUN_004f2330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_004f2330(short *param_1,short param_2)

{
  short *psVar1;
  
  psVar1 = param_1;
  if (*param_1 != 0) {
    do {
      psVar1 = psVar1 + 1;
    } while (*psVar1 != 0);
    if (psVar1 < param_1) {
      return (short *)0x0;
    }
  }
  do {
    if (*psVar1 == param_2) {
      return psVar1;
    }
    psVar1 = psVar1 + -1;
  } while (param_1 <= psVar1);
  return (short *)0x0;
}

