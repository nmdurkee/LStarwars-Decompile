/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x698c50; label: FUN_00698c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698c50(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *_Dst;
  
  _Dst = (int *)(in_ECX + 0xc);
  iVar2 = 0x40;
  do {
    if (*_Dst != 0) {
      piVar1 = (int *)_Dst[1];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      (**(code **)(*(int *)*_Dst + 0x48))((int *)*_Dst);
      (**(code **)(*(int *)*_Dst + 8))((int *)*_Dst);
      *_Dst = 0;
      _Dst[1] = 0;
      *(int *)(in_ECX + 0xd10) = *(int *)(in_ECX + 0xd10) + -1;
    }
    _memset(_Dst,0,0x34);
    _Dst = _Dst + 0xd;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

