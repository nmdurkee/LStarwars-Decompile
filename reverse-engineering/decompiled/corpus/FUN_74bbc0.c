/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74bbc0; label: FUN_0074bbc0
 */

void FUN_0074bbc0(void)

{
  size_t _Size;
  void *_Dst;
  undefined4 *puVar1;
  int in_ECX;
  
  _Size = *(size_t *)(in_ECX + 0x128);
  if (0 < (int)_Size) {
    _Dst = *(void **)(*(int *)(in_ECX + 0x11c) + 4);
    *(size_t *)(*(int *)(in_ECX + 0x11c) + 4) = (int)_Dst + _Size;
    _memcpy(_Dst,*(void **)(in_ECX + 0x124),_Size);
    puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4);
    *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4) = puVar1 + 4;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 7;
      puVar1[1] = 0;
      puVar1[2] = _Dst;
      puVar1[3] = _Size;
    }
    if (*(undefined4 **)(in_ECX + 0x118) == (undefined4 *)0x0) {
      *(undefined4 **)(in_ECX + 0x114) = puVar1;
    }
    else {
      **(undefined4 **)(in_ECX + 0x118) = puVar1;
    }
    *(undefined4 **)(in_ECX + 0x118) = puVar1 + 1;
    *(undefined4 *)(in_ECX + 0x128) = 0;
  }
  return;
}

