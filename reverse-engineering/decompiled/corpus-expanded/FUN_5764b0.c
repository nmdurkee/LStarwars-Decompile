/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x5764b0; label: FUN_005764b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005764b0(int param_1)

{
  int iVar1;
  
  if ((((DAT_009514b8 == (short *)0x0) || (*DAT_009514b8 != param_1)) && (-1 < param_1)) &&
     (*(int *)(DAT_00926c20 + param_1 * 4) != 0)) {
    iVar1 = FUN_00576480(param_1);
    if (((iVar1 != 0) && (*(char *)(iVar1 + 0x14) == '\0')) && (*(float *)(iVar1 + 0x18) <= 0.0)) {
      return 1;
    }
  }
  return 0;
}

