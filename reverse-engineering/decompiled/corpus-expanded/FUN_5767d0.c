/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x5767d0; label: FUN_005767d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005767d0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  if ((DAT_009514b4 != (short *)0x0) && (DAT_009514c0 != 0)) {
    sVar1 = *DAT_009514b4;
    psVar3 = DAT_009514b4;
    for (iVar4 = 0;
        (sVar1 != -1 && (iVar2 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5, iVar2 < DAT_009514c4))
        ; iVar4 = iVar4 + 1) {
      *(bool *)(psVar3 + 10) =
           (*(uint *)(DAT_009514c0 + iVar2 * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0;
      psVar3 = psVar3 + 0xe;
      sVar1 = *psVar3;
    }
  }
  return;
}

