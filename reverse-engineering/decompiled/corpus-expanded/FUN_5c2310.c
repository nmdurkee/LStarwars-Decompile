/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2310; label: FUN_005c2310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2310(int param_1,char param_2)

{
  int in_ECX;
  
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 0x88 + in_ECX) != '\0') {
      *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + -1;
      *(undefined1 *)(param_1 + 0x88 + in_ECX) = 0;
    }
  }
  else if (*(char *)(param_1 + 0x88 + in_ECX) == '\0') {
    *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 1;
    *(undefined1 *)(param_1 + 0x88 + in_ECX) = 1;
    return;
  }
  return;
}

