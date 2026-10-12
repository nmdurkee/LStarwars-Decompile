/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e63b0; label: FUN_004e63b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e63b0(int param_1)

{
  if (DAT_00951b50 == 0) {
    DAT_0088a408 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"snow_mob");
    DAT_0088a40c = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"snowmob_1");
  }
  _memset(&DAT_0088a410,0,0xc0);
  DAT_0088a530 = 0;
  return;
}

