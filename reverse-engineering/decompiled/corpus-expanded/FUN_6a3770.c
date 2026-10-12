/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3770; label: FUN_006a3770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3770(int param_1,code *param_2,int param_3)

{
  size_t _NewSize;
  void *pvVar1;
  void *unaff_EBX;
  int iVar2;
  int *unaff_ESI;
  size_t _Size;
  
  _Size = (int)(param_1 + (param_1 >> 0x1f & 7U)) >> 3;
  if (unaff_ESI[1] == 0) {
    if (unaff_ESI[4] <= (int)(*unaff_ESI + _Size + 1)) {
      _NewSize = *unaff_ESI + _Size + 0x100;
      unaff_ESI[4] = _NewSize;
      pvVar1 = _realloc((void *)unaff_ESI[2],_NewSize);
      unaff_ESI[2] = (int)pvVar1;
      unaff_ESI[3] = *unaff_ESI + (int)pvVar1;
    }
    _memmove((void *)unaff_ESI[3],unaff_EBX,_Size);
    unaff_ESI[3] = unaff_ESI[3] + _Size;
    *unaff_ESI = *unaff_ESI + _Size;
    *(undefined1 *)unaff_ESI[3] = 0;
  }
  else {
    iVar2 = 0;
    if (0 < (int)_Size) {
      do {
        (*param_2)();
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)_Size);
    }
  }
  if (param_1 + _Size * -8 != 0) {
    if (param_3 != 0) {
      (*param_2)();
      return;
    }
    (*param_2)();
  }
  return;
}

