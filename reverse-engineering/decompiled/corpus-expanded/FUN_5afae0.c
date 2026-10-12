/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afae0; label: FUN_005afae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afae0(void)

{
  int in_EAX;
  
  *(byte *)(in_EAX + 0x23) = *(byte *)(in_EAX + 0x23) & 0xfb | 3;
  return;
}

