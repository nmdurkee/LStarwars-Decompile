/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x423bc0; label: FUN_00423bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00423bc0(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar4 = param_1 + 0x70;
    psVar2 = (short *)(param_1 + 0x6c);
    iVar3 = 2;
    do {
      if ((*psVar2 != -1) && (iVar1 = *(int *)(*psVar2 * 0x4c + DAT_0093b274), iVar1 != -1)) {
        FUN_004f1f10(iVar4,*(undefined4 *)(DAT_00926c20 + iVar1 * 4));
        *(int *)(DAT_00926c20 + iVar1 * 4) = iVar4;
      }
      psVar2 = psVar2 + 1;
      iVar4 = iVar4 + 0x80;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

