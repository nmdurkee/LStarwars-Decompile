/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5767d0; label: FUN_005767d0
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

