/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a15c0; label: FUN_006a15c0
 */

void FUN_006a15c0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *_Memory;
  void *pvVar2;
  
  _Memory = *(undefined4 **)(param_1 + 0x54);
  while (_Memory != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_Memory[1];
    _free((void *)*_Memory);
    *_Memory = 0;
    _Memory[1] = 0;
    _free(_Memory);
    _Memory = puVar1;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    pvVar2 = _realloc(*(void **)(param_1 + 0x44),*(int *)(param_1 + 0x4c) + *(int *)(param_1 + 0x50)
                     );
    *(void **)(param_1 + 0x44) = pvVar2;
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}

