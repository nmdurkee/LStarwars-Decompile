/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x6104e0; label: FUN_006104e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

