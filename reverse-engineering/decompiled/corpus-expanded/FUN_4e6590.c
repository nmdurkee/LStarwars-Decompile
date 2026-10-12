/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e6590; label: FUN_004e6590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e6590(void)

{
  int unaff_ESI;
  
  FUN_005cf5b0(*(undefined4 *)(unaff_ESI + 0x13c),&DAT_0087aad8,"small_pop_bit1",1);
  FUN_005cf5b0(*(undefined4 *)(unaff_ESI + 0x13c),&DAT_0087aae4,"small_pop_bit2",1);
  FUN_005cf5b0(*(undefined4 *)(unaff_ESI + 0x13c),&DAT_0087aaf0,"small_pop_bit3",1);
  FUN_005cf5b0(*(undefined4 *)(unaff_ESI + 0x13c),&DAT_0087aafc,"small_pop_bit4",1);
  return;
}

