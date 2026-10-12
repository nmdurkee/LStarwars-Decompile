/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d4d0; label: FUN_0074d4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

