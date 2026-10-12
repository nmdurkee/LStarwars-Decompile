/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dcf00; label: FUN_004dcf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dcf00(void)

{
  short sVar1;
  
  if (DAT_00951b50 == 0) {
    sVar1 = FUN_006e6b90();
    DAT_008828fc[1] = sVar1;
    sVar1 = FUN_006e6b90();
    *DAT_008828fc = sVar1;
    return;
  }
  *(float *)(DAT_00882a88 + 0x28) = (float)(int)DAT_008828fc[1];
  *(float *)(DAT_00882a84 + 0x28) = (float)(int)*DAT_008828fc;
  return;
}

