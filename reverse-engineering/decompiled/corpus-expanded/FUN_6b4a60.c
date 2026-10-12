/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4a60; label: FUN_006b4a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b4a60(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x520);
    _free(param_1);
  }
  return;
}

