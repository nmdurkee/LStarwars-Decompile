/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518670; label: FUN_00518670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00518670(void)

{
  byte *pbVar1;
  
  pbVar1 = &DAT_009222b1;
  do {
    if ((pbVar1[-1] != 0) && ((*pbVar1 & 4) != 0)) {
      _memset(pbVar1 + -0x49,0,0x58);
    }
    pbVar1 = pbVar1 + 0x58;
  } while ((int)pbVar1 < 0x9238b1);
  return;
}

