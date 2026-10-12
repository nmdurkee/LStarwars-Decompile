/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a3eb0; label: FUN_006a3eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3eb0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x1ec);
    _free(param_1);
  }
  return;
}

