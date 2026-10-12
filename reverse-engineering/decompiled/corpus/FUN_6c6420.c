/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6420; label: FUN_006c6420
 */

void FUN_006c6420(uint param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *_Memory;
  int iVar3;
  
  _Memory = (int *)*in_ECX;
  if (_Memory != (int *)0x0) {
    do {
      (**(code **)(**(int **)(_Memory[2] + 0x14) + 0x24))(_Memory[3]);
      if ((param_1 & 2) == 0) {
        iVar1 = _Memory[2];
        iVar2 = _Memory[3];
        iVar3 = 0;
        if (0 < DAT_02973bbc) {
          do {
            (**(code **)(**(int **)(DAT_02973b98 + iVar3 * 4) + 0xc))(iVar2,iVar1,param_1);
            iVar3 = iVar3 + 1;
          } while (iVar3 < DAT_02973bbc);
        }
      }
      if (*_Memory == 0) {
        in_ECX[1] = _Memory[1];
      }
      else {
        *(int *)(*_Memory + 4) = _Memory[1];
      }
      if ((int *)_Memory[1] == (int *)0x0) {
        *in_ECX = *_Memory;
      }
      else {
        *(int *)_Memory[1] = *_Memory;
      }
      *_Memory = 0;
      _Memory[1] = 0;
      in_ECX[2] = in_ECX[2] + -1;
      _free(_Memory);
      _Memory = (int *)*in_ECX;
    } while (_Memory != (int *)0x0);
  }
  return;
}

