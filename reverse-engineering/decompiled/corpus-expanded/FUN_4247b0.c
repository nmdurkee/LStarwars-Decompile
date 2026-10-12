/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4247b0; label: FUN_004247b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004247b0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = (&DAT_008568f0)[in_EAX];
  do {
    iVar1 = iVar2 + 1;
    iVar2 = 0;
  } while (iVar1 % 3 == 0);
  return;
}

