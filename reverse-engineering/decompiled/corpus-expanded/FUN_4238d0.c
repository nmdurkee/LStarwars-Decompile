/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4238d0; label: FUN_004238d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004238d0(void)

{
  int iVar1;
  char in_CL;
  
  iVar1 = 0;
  do {
    if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar1] == in_CL) {
LAB_004238f0:
      if (0x25 < iVar1) {
        iVar1 = 0;
      }
      return iVar1;
    }
    if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar1 + 1] == in_CL) {
      iVar1 = iVar1 + 1;
      goto LAB_004238f0;
    }
    iVar1 = iVar1 + 2;
    if (0x25 < iVar1) {
      return 0;
    }
  } while( true );
}

