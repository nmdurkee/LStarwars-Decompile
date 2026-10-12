/* Ghidra pseudocode, not original source.
 * ev_bde5c5f75e817edbac891f5cdb42210190c78104eb02ca0378b00d023a3e9188
 * Entry: 0x6f6533; label: FUN_006f6533
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006f6533(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

