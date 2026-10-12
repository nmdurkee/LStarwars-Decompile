/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1630; label: FUN_006a1630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a1630(void *param_1)

{
  void *_Memory;
  int iVar1;
  undefined4 *puVar2;
  
  _Memory = *(void **)((int)param_1 + 0x68);
  FUN_006a15c0(param_1);
  if (*(void **)((int)param_1 + 0x44) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x44));
  }
  if (_Memory != (void *)0x0) {
    iVar1 = 0;
    puVar2 = (undefined4 *)((int)_Memory + 0xc);
    do {
      FUN_006a38e0(*puVar2);
      if (iVar1 != 7) {
        _free((void *)*puVar2);
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < 0xf);
    _free(_Memory);
  }
  _memset(param_1,0,0x70);
  return 0;
}

