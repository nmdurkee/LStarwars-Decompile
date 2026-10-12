/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4daaf0; label: FUN_004daaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004daaf0(void)

{
  int iVar1;
  
  FUN_004da6c0(_DAT_00925018);
  if (DAT_00882a70 == 3) {
    iVar1 = FUN_0055c690();
    if ((iVar1 != 0) && (DAT_0087b098 != 0)) {
      DAT_00802c60 = (int)*(short *)(DAT_0087b098 + 0x62);
      return;
    }
    if (DAT_0087b09c != 0) {
      DAT_00802c60 = (int)*(short *)(DAT_0087b09c + 0x62);
    }
  }
  return;
}

