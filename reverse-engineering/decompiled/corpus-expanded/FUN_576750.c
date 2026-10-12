/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576750; label: FUN_00576750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576750(void)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  if ((DAT_009514b4 != (short *)0x0) && (DAT_009514c0 != 0)) {
    iVar5 = 0;
    sVar2 = *DAT_009514b4;
    psVar4 = DAT_009514b4;
    iVar6 = DAT_009514c0;
    while (sVar2 != -1) {
      iVar3 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
      if ((char)psVar4[10] == '\0') {
        if (iVar3 < DAT_009514c4) {
          puVar1 = (uint *)(iVar6 + iVar3 * 4);
          *puVar1 = *puVar1 & ~(1 << ((byte)iVar5 & 0x1f));
          iVar6 = DAT_009514c0;
        }
      }
      else if (iVar3 < DAT_009514c4) {
        puVar1 = (uint *)(iVar6 + iVar3 * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar5 & 0x1f);
        iVar6 = DAT_009514c0;
      }
      psVar4 = psVar4 + 0xe;
      iVar5 = iVar5 + 1;
      sVar2 = *psVar4;
    }
  }
  return;
}

