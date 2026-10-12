/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b8630; label: FUN_006b8630
 */

void * FUN_006b8630(uint param_1,int param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  void *_Dst;
  undefined4 *in_ECX;
  
  puVar1 = (uint *)*in_ECX;
  _Dst = (void *)0x0;
  if (param_1 < *(int *)in_ECX[1] - *puVar1) {
    *puVar1 = param_2 + -1 + *puVar1 & ~(param_2 - 1U);
    piVar2 = (int *)*in_ECX;
    _Dst = (void *)*piVar2;
    *piVar2 = *piVar2 + param_1;
    if (param_3 != 0) {
      _memset(_Dst,0,param_1);
    }
    in_ECX[2] = in_ECX[2] + param_1;
    in_ECX[3] = in_ECX[3] - param_1;
  }
  return _Dst;
}

