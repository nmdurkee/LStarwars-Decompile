/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576960; label: FUN_00576960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576960(int param_1)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  
  if ((param_1 != -1) && (DAT_009514b4 != (short *)0x0)) {
    sVar2 = *DAT_009514b4;
    psVar3 = DAT_009514b4;
    while (sVar2 != -1) {
      if (sVar2 == param_1) {
        if ((char)psVar3[10] != '\0') {
          return;
        }
        *(undefined1 *)(psVar3 + 10) = 1;
        FUN_005766e0();
        return;
      }
      psVar1 = psVar3 + 0xe;
      psVar3 = psVar3 + 0xe;
      sVar2 = *psVar1;
    }
  }
  return;
}

