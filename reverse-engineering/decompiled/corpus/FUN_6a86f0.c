/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a86f0; label: FUN_006a86f0
 */

void FUN_006a86f0(void *param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)((int)param_1 + 0x30) != 0) {
    if (*(void **)((int)param_1 + 0x20) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x20));
    }
    if (*(void **)((int)param_1 + 8) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 8));
    }
    if (*(undefined4 **)((int)param_1 + 0x24) != (undefined4 *)0x0) {
      _free((void *)**(undefined4 **)((int)param_1 + 0x24));
      _free(*(void **)(*(int *)((int)param_1 + 0x24) + 4));
      _free(*(void **)(*(int *)((int)param_1 + 0x24) + 8));
      _free(*(void **)(*(int *)((int)param_1 + 0x24) + 0xc));
      puVar1 = *(undefined4 **)((int)param_1 + 0x24);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      _free(*(void **)((int)param_1 + 0x24));
    }
    if (*(undefined4 **)((int)param_1 + 0x28) != (undefined4 *)0x0) {
      _free((void *)**(undefined4 **)((int)param_1 + 0x28));
      _free(*(void **)(*(int *)((int)param_1 + 0x28) + 4));
      puVar1 = *(undefined4 **)((int)param_1 + 0x28);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      _free(*(void **)((int)param_1 + 0x28));
    }
    _memset(param_1,0,0x34);
  }
  return;
}

