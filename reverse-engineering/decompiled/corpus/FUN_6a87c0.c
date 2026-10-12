/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a87c0; label: FUN_006a87c0
 */

void FUN_006a87c0(void *param_1)

{
  if (*(int *)((int)param_1 + 0x30) != 0) {
    FUN_006a86f0(param_1);
    _free(param_1);
  }
  return;
}

