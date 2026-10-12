/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x5765f0; label: FUN_005765f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005765f0(void)

{
  short sVar1;
  short *psVar2;
  
  if (DAT_009514b4 != (short *)0x0) {
    sVar1 = *DAT_009514b4;
    psVar2 = DAT_009514b4;
    while (sVar1 != -1) {
      psVar2[0xc] = 0;
      psVar2[0xd] = 0;
      psVar2 = psVar2 + 0xe;
      sVar1 = *psVar2;
    }
    _DAT_009514c8 = 0;
    DAT_009514bd = 2;
    _DAT_009514cc = 0;
    DAT_009514b8 = 0;
  }
  return;
}

