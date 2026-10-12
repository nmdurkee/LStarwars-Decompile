/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576460; label: FUN_00576460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00576460(void)

{
  if (DAT_009514b8 != (short *)0x0) {
    return (int)*DAT_009514b8;
  }
  return -1;
}

