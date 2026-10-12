/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x6174c0; label: FUN_006174c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006174c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x4b0);
}

