/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cf1e0; label: FUN_006cf1e0
 */

void * FUN_006cf1e0(undefined4 *param_1)

{
  uint *puVar1;
  int *piVar2;
  void *_Dst;
  
  puVar1 = (uint *)*param_1;
  if (*(int *)param_1[1] - *puVar1 < 0x45) {
    return (void *)0x0;
  }
  *puVar1 = *puVar1 + 0xf & 0xfffffff0;
  piVar2 = (int *)*param_1;
  _Dst = (void *)*piVar2;
  *piVar2 = *piVar2 + 0x44;
  _memset(_Dst,0,0x44);
  param_1[2] = param_1[2] + 0x44;
  param_1[3] = param_1[3] + -0x44;
  if (_Dst != (void *)0x0) {
    *(undefined4 *)((int)_Dst + 0x38) = 0;
    *(undefined4 *)((int)_Dst + 0x3c) = 0;
    *(undefined4 *)((int)_Dst + 0x40) = 0;
    return _Dst;
  }
  return (void *)0x0;
}

