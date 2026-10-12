/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b6a40; label: FUN_006b6a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006b6a40(int param_1,undefined4 param_2)

{
  int iVar1;
  int *_Dst;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  _Dst = _malloc(0x60);
  iVar2 = FUN_006a3bb0(param_2,8);
  *_Dst = iVar2;
  iVar2 = FUN_006a3bb0(param_2,0x10);
  _Dst[1] = iVar2;
  iVar2 = FUN_006a3bb0(param_2,0x10);
  _Dst[2] = iVar2;
  iVar2 = FUN_006a3bb0(param_2,6);
  _Dst[3] = iVar2;
  iVar2 = FUN_006a3bb0(param_2,8);
  _Dst[4] = iVar2;
  iVar2 = FUN_006a3bb0(param_2,4);
  iVar2 = iVar2 + 1;
  _Dst[5] = iVar2;
  if ((((0 < *_Dst) && (0 < _Dst[1])) && (0 < _Dst[2])) && (0 < iVar2)) {
    iVar4 = 0;
    if (0 < iVar2) {
      piVar3 = _Dst + 6;
      do {
        iVar2 = FUN_006a3bb0(param_2,8);
        *piVar3 = iVar2;
        if ((iVar2 < 0) || (*(int *)(iVar1 + 0x18) <= iVar2)) goto LAB_006b6aef;
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < _Dst[5]);
    }
    return _Dst;
  }
LAB_006b6aef:
  _memset(_Dst,0,0x60);
  _free(_Dst);
  return (int *)0x0;
}

