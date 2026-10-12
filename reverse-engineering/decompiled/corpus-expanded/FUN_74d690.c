/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d690; label: FUN_0074d690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0074d6c1) */

void FUN_0074d690(void)

{
  rsize_t _DstSize;
  undefined4 *puVar1;
  int *piVar2;
  void *_Src;
  void *_Dst;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 0x104);
  if (*(undefined4 **)(in_ECX + 0x108) < puVar4) {
    FUN_006e9fe6();
  }
  while( true ) {
    puVar1 = *(undefined4 **)(in_ECX + 0x108);
    if (puVar1 < *(undefined4 **)(in_ECX + 0x104)) {
      FUN_006e9fe6();
    }
    if (puVar1 <= puVar4) break;
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar4) {
      FUN_006e9fe6();
    }
    piVar2 = (int *)*puVar4;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        thunk_FUN_006e85b0(*piVar2);
        *piVar2 = 0;
      }
      FUN_00748490();
      FUN_006e85b0(piVar2);
    }
    if (*(undefined4 **)(in_ECX + 0x108) <= puVar4) {
      FUN_006e9fe6();
    }
    puVar4 = puVar4 + 1;
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
    iVar3 = *(int *)(in_ECX + 0x108) - (int)_Src >> 2;
    _DstSize = iVar3 * 4;
    if (0 < iVar3) {
      _memmove_s(_Dst,_DstSize,_Src,_DstSize);
    }
    *(void **)(in_ECX + 0x108) = (void *)(_DstSize + (int)_Dst);
  }
  return;
}

