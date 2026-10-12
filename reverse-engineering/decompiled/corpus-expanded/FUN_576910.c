/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576910; label: FUN_00576910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576910(int param_1)

{
  int iVar1;
  
  if ((DAT_009514b8 == (short *)0x0) || (*DAT_009514b8 != param_1)) {
    if ((param_1 < 0) || (*(int *)(DAT_00926c20 + param_1 * 4) == 0)) {
      DAT_009514b8 = (short *)0x0;
    }
    else {
      iVar1 = FUN_00576480(param_1);
      if (iVar1 != 0) {
        FUN_00576860();
        return;
      }
    }
  }
  return;
}

