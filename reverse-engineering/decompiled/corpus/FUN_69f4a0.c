/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69f4a0; label: FUN_0069f4a0
 */

int FUN_0069f4a0(int *param_1,int param_2)

{
  size_t _Size;
  int iVar1;
  void *pvVar2;
  
  iVar1 = param_1[3];
  if (iVar1 != 0) {
    param_1[2] = param_1[2] - iVar1;
    if (0 < param_1[2]) {
      _memmove((void *)*param_1,(void *)(iVar1 + *param_1),param_1[2]);
    }
    param_1[3] = 0;
  }
  if (param_1[1] - param_1[2] < param_2) {
    _Size = param_1[2] + 0x1000 + param_2;
    if ((void *)*param_1 != (void *)0x0) {
      pvVar2 = _realloc((void *)*param_1,_Size);
      param_1[1] = _Size;
      *param_1 = (int)pvVar2;
      return (int)pvVar2 + param_1[2];
    }
    pvVar2 = _malloc(_Size);
    param_1[1] = _Size;
    *param_1 = (int)pvVar2;
  }
  return *param_1 + param_1[2];
}

