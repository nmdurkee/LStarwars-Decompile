/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701c97; label: FUN_00701c97
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00701c97(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

