/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x40ee70; label: FUN_0040ee70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

