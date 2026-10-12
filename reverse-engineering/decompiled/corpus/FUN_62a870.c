/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a870; label: FUN_0062a870
 */

void * FUN_0062a870(size_t *param_1)

{
  size_t _Size;
  int iVar1;
  void *_Dst;
  
  if ((param_1 != (size_t *)0x0) && (_Size = *param_1, _Size != 0)) {
    _Dst = (void *)param_1[1];
    iVar1 = 0;
    do {
      if ((*(byte *)((int)_Dst + 0x1fc) & 1) == 0) {
        _memset(_Dst,0,_Size);
        *(uint *)((int)_Dst + 0x1fc) = *(uint *)((int)_Dst + 0x1fc) | 1;
        *(char *)((int)_Dst + 0x28d) = (char)iVar1;
        return _Dst;
      }
      iVar1 = iVar1 + 1;
      _Dst = (void *)((int)_Dst + _Size);
    } while (iVar1 < 0x40);
  }
  return (void *)0x0;
}

