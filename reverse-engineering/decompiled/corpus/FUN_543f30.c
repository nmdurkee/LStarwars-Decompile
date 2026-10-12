/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x543f30; label: FUN_00543f30
 */

void FUN_00543f30(void)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  int iVar5;
  int local_8;
  
  uVar1 = FUN_0066cbc0();
  pcVar4 = &DAT_02984546;
  local_8 = 8;
  do {
    if (pcVar4[-0xae6] != '\0') {
      FUN_0066cbb0(*(undefined4 *)(pcVar4 + -0xade));
      iVar5 = 0;
      if ('\0' < *pcVar4) {
        psVar3 = (short *)(pcVar4 + -0x32);
        do {
          iVar2 = FUN_005cfac0(pcVar4 + -0x5a);
          if (iVar2 != 0) {
            FUN_0067c930((int)*psVar3);
          }
          iVar5 = iVar5 + 1;
          psVar3 = psVar3 + 1;
        } while (iVar5 < *pcVar4);
      }
      pcVar4[-0xae6] = '\0';
    }
    pcVar4 = pcVar4 + 0xb0c;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_0066cbb0(uVar1);
  return;
}

