/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a87e0; label: FUN_006a87e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a87e0(void *param_1)

{
  if (*(void **)((int)param_1 + 0x10) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x10));
  }
  if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x14));
  }
  if (*(void **)((int)param_1 + 0x18) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x18));
  }
  if (*(void **)((int)param_1 + 0x1c) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x1c));
  }
  if (*(void **)((int)param_1 + 0x20) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x20));
  }
  _memset(param_1,0,0x2c);
  return;
}

