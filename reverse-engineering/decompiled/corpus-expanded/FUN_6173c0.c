/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x6173c0; label: FUN_006173c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006173c0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x94) < param_1) {
    return 0xa0210001;
  }
  *(int *)(in_ECX + 0x8c) = param_1;
  *(undefined4 *)(in_ECX + 8) = 1;
  return 0;
}

