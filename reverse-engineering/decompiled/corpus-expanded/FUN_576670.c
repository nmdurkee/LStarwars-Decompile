/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576670; label: FUN_00576670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576670(void)

{
  short sVar1;
  short *psVar2;
  
  if (DAT_009514b4 != (short *)0x0) {
    sVar1 = *DAT_009514b4;
    psVar2 = DAT_009514b4;
    while (sVar1 != -1) {
      *(byte *)(psVar2 + 1) = *(byte *)(psVar2 + 1) & 0xfd;
      *(undefined1 *)(psVar2 + 10) = 0;
      psVar2 = psVar2 + 0xe;
      sVar1 = *psVar2;
    }
  }
  return;
}

