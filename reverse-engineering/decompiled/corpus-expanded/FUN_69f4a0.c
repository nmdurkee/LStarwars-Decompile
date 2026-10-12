/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69f4a0; label: FUN_0069f4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

