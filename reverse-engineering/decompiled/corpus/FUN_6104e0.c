/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x6104e0; label: FUN_006104e0
 */

void * FUN_006104e0(uint param_1,int param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  void *_Dst;
  int in_ECX;
  
  puVar1 = *(uint **)(in_ECX + 8);
  _Dst = (void *)0x0;
  if (param_1 < **(int **)(in_ECX + 0xc) - *puVar1) {
    *puVar1 = (*puVar1 - 1) + param_2 & ~(param_2 - 1U);
    piVar2 = *(int **)(in_ECX + 8);
    _Dst = (void *)*piVar2;
    *piVar2 = *piVar2 + param_1;
    if (param_3 != 0) {
      _memset(_Dst,0,param_1);
    }
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + param_1;
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) - param_1;
    *(undefined4 *)(in_ECX + 0x10) = **(undefined4 **)(in_ECX + 8);
  }
  return _Dst;
}

