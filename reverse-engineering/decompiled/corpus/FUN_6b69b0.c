/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b69b0; label: FUN_006b69b0
 */

void FUN_006b69b0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x60);
    _free(param_1);
  }
  return;
}

