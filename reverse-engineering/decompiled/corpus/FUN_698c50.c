/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698c50; label: FUN_00698c50
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

