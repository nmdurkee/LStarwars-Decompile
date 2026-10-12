/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a87e0; label: FUN_006a87e0
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

