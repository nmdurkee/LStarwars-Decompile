/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4247d0; label: FUN_004247d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004247d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (&DAT_008568f0)[param_1];
  if (iVar2 != 1) {
    if (iVar2 != 0) {
      do {
        iVar1 = iVar2 + 1;
        iVar2 = 0;
      } while (iVar1 % 3 == 0);
    }
    return (int)DAT_00880760;
  }
  return (int)DAT_00880870;
}

