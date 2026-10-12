/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a86f0; label: FUN_006a86f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

