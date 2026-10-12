/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ee70; label: FUN_0040ee70
 */

void * FUN_0040ee70(uint *param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *_Dst;
  
  pvVar1 = (void *)*param_1;
  pvVar3 = (void *)(param_1[2] * 0x60 + (int)pvVar1);
  for (_Dst = pvVar3; pvVar2 = pvVar1, _Dst < (void *)(param_1[1] * 0x60 + (int)pvVar1);
      _Dst = (void *)((int)_Dst + 0x60)) {
    if (*(float *)((int)_Dst + 0x50) == 0.0) goto LAB_0040eec7;
  }
  while( true ) {
    _Dst = pvVar2;
    if (pvVar3 <= _Dst) {
      return (void *)0x0;
    }
    if (*(float *)((int)_Dst + 0x50) == 0.0) break;
    pvVar2 = (void *)((int)_Dst + 0x60);
  }
LAB_0040eec7:
  param_1[2] = ((int)_Dst - (int)pvVar1) / 0x60;
  _memset(_Dst,0,0x60);
  return _Dst;
}

