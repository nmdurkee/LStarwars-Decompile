/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545540; label: FUN_00545540
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545540(void)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  _DAT_02983a54 = 0;
  _DAT_02983a58 = 0;
  _DAT_02983a4c = 0;
  DAT_02983a50 = 0;
  uVar1 = FUN_0066cbc0();
  iVar4 = 0;
  if (0 < DAT_00924838) {
    iVar5 = 0;
    iVar2 = DAT_00924840;
    do {
      iVar6 = 0;
      if (*(short *)(iVar5 + iVar2) != 0) {
        FUN_0066cbb0(*(undefined4 *)(iVar5 + 0xc + iVar2));
        psVar3 = *(short **)(iVar5 + 0x18 + DAT_00924840);
        iVar2 = DAT_00924840;
        if (0 < *(short *)(iVar5 + 0x2a + DAT_00924840)) {
          do {
            if (*psVar3 != -1) {
              FUN_0067c930((int)*psVar3);
              iVar2 = DAT_00924840;
            }
            iVar6 = iVar6 + 1;
            psVar3 = psVar3 + 1;
          } while (iVar6 < *(short *)(iVar5 + 0x2a + iVar2));
        }
        *(undefined2 *)(iVar5 + iVar2) = 0;
        iVar2 = DAT_00924840;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x40;
    } while (iVar4 < DAT_00924838);
  }
  FUN_0066cbb0(uVar1);
  return;
}

