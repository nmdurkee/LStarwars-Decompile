/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec300; label: FUN_006ec300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ec300(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006fd100();
    return;
  }
  FUN_006f6968((double)in_ST0);
  FUN_006ec358();
  return;
}

