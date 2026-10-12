/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74d690; label: FUN_0074d690
 */

/* WARNING: Removing unreachable block (ram,0x0074d6c1) */

void FUN_0074d690(void)

{
  rsize_t _DstSize;
  undefined4 *puVar1;
  void *_Src;
  void *_Dst;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 0x104);
  if (*(undefined4 **)(in_ECX + 0x108) < puVar3) {
    FUN_006e9fe6();
  }
  while( true ) {
    puVar1 = *(undefined4 **)(in_ECX + 0x108);
    if (puVar1 < *(undefined4 **)(in_ECX + 0x104)) {
      FUN_006e9fe6();
    }
    if (puVar1 <= puVar3) break;
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar3) {
      FUN_006e9fe6();
    }
    puVar1 = (undefined4 *)*puVar3;
    if (puVar1 != (undefined4 *)0x0) {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        *puVar1 = 0;
      }
      FUN_00748490();
      _free(puVar1);
    }
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar3) {
      FUN_006e9fe6();
    }
    puVar3 = puVar3 + 1;
  }
  _Src = *(void **)(in_ECX + 0x108);
  if (_Src < *(void **)(in_ECX + 0x104)) {
    FUN_006e9fe6();
  }
  _Dst = *(void **)(in_ECX + 0x104);
  if (*(void **)(in_ECX + 0x108) < _Dst) {
    FUN_006e9fe6();
  }
  if (_Dst != _Src) {
    iVar2 = *(int *)(in_ECX + 0x108) - (int)_Src >> 2;
    _DstSize = iVar2 * 4;
    if (0 < iVar2) {
      _memmove_s(_Dst,_DstSize,_Src,_DstSize);
    }
    *(void **)(in_ECX + 0x108) = (void *)(_DstSize + (int)_Dst);
  }
  return;
}

