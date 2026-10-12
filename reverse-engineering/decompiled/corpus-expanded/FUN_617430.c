/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617430; label: FUN_00617430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00617430(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xac) != 0;
}

