/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59b760; label: FUN_0059b760
 */

int FUN_0059b760(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  short *psVar6;
  int local_4;
  
  local_4 = 0;
  iVar2 = 0;
  if (0 < DAT_00956294) {
    psVar6 = (short *)(DAT_00956290 + 4);
    iVar1 = DAT_00956294;
    do {
      uVar5 = 0;
      if (DAT_0095136c != 0) {
        psVar4 = psVar6;
        for (uVar3 = (uint)*(byte *)((int)psVar6 + 0x15); uVar3 != 0; uVar3 = uVar3 - 1) {
          if (*(char *)(DAT_0095136c + 1 + *psVar4 * 0xc) != '\0') {
            uVar5 = uVar5 + 1;
          }
          psVar4 = psVar4 + 1;
        }
        if (uVar5 == *(byte *)((int)psVar6 + 0x15)) {
          local_4 = local_4 + 1;
        }
      }
      psVar6 = psVar6 + 0xe;
      iVar1 = iVar1 + -1;
      iVar2 = local_4;
    } while (iVar1 != 0);
  }
  return iVar2;
}

