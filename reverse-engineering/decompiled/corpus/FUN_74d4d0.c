/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74d4d0; label: FUN_0074d4d0
 */

void FUN_0074d4d0(int *param_1,int param_2,void *param_3,int param_4,void *param_5)

{
  rsize_t _DstSize;
  int iVar1;
  int in_ECX;
  
  if ((param_2 == 0) || (param_2 != param_4)) {
    FUN_006e9fe6();
  }
  if (param_3 != param_5) {
    iVar1 = *(int *)(in_ECX + 8) - (int)param_5 >> 2;
    _DstSize = iVar1 * 4;
    if (0 < iVar1) {
      _memmove_s(param_3,_DstSize,param_5,_DstSize);
    }
    *(void **)(in_ECX + 8) = (void *)(_DstSize + (int)param_3);
  }
  param_1[1] = (int)param_3;
  *param_1 = param_2;
  return;
}

