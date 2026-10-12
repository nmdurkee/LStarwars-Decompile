/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576630; label: FUN_00576630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00576630(int param_1,int param_2)

{
  short *psVar1;
  
  if ((DAT_009514b4 != (short *)0x0) && (psVar1 = DAT_009514b4, *DAT_009514b4 != -1)) {
    while (*psVar1 != param_1) {
      psVar1 = psVar1 + 0xe;
      if (*psVar1 == -1) {
        return;
      }
    }
    if (param_2 == 1) {
      *(undefined1 *)(psVar1 + 10) = 0;
    }
    _DAT_009514c8 = 0;
  }
  return;
}

