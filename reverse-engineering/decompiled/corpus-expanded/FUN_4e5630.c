/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5630; label: FUN_004e5630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e5630(void)

{
  if (DAT_0093b2a4 == 0) {
    if (DAT_0087b1d8 != 0) {
      DAT_00802c60 = (int)*(short *)(DAT_0087b1d8 + 0x62);
      return;
    }
  }
  else if (DAT_0087b1d8 != 0) {
    DAT_00802c60 = (int)*(short *)(DAT_0087b1d8 + 0x62);
  }
  return;
}

