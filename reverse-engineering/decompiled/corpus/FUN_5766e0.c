/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5766e0; label: FUN_005766e0
 */

void FUN_005766e0(short *param_1)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  if ((DAT_009514b4 != (short *)0x0) && (DAT_009514c0 != 0)) {
    sVar2 = *DAT_009514b4;
    iVar4 = 0;
    if (sVar2 != -1) {
      psVar5 = DAT_009514b4;
      while (sVar2 != *param_1) {
        sVar2 = psVar5[0xe];
        psVar5 = psVar5 + 0xe;
        iVar4 = iVar4 + 1;
        if (sVar2 == -1) {
          return;
        }
      }
      iVar3 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
      if (iVar3 < DAT_009514c4) {
        puVar1 = (uint *)(DAT_009514c0 + iVar3 * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar4 & 0x1f);
      }
    }
  }
  return;
}

