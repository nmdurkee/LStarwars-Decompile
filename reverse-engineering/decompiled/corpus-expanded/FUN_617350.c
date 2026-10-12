/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617350; label: FUN_00617350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00617350(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 1) {
    *(undefined4 *)(in_ECX + 0x90) = param_2;
    *(undefined4 *)(in_ECX + 0x8c) = param_1;
    *(undefined4 *)(in_ECX + 0x94) = param_1;
    *(undefined4 *)(in_ECX + 8) = 1;
    return 0;
  }
  if (*(int *)(in_ECX + 4) != 2) {
    return 0xa0210000;
  }
  if (*(int *)(in_ECX + 0x94) < *(int *)(in_ECX + 0x8c)) {
    return 0xa0210001;
  }
  *(undefined4 *)(in_ECX + 0x90) = param_2;
  *(undefined4 *)(in_ECX + 0x94) = param_1;
  *(undefined4 *)(in_ECX + 8) = 1;
  return 0;
}

