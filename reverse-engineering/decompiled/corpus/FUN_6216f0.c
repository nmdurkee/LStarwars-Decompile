/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x6216f0; label: FUN_006216f0
 */

void FUN_006216f0(void *param_1,size_t param_2)

{
  int iVar1;
  size_t _Size;
  int iVar2;
  
  iVar2 = DAT_02900a5c;
  while (0 < (int)param_2) {
    _Size = 0x1000U - iVar2;
    if ((int)param_2 < (int)(0x1000U - iVar2)) {
      _Size = param_2;
    }
    _memcpy(param_1,&DAT_029110b8 + iVar2,_Size);
    iVar1 = DAT_0080f884;
    iVar2 = DAT_02900a5c + _Size;
    param_2 = param_2 - _Size;
    param_1 = (void *)((int)param_1 + _Size);
    DAT_02900a5c = iVar2;
    if ((((iVar2 == 0x1000) && (DAT_0080f884 != -1)) &&
        (_memset(&DAT_029110b8,0,0x1000), DAT_02912f3c != 0)) && (DAT_02912f3c == 1)) {
      FUN_004fb550(iVar1,&DAT_029110b8,0x1000);
      iVar2 = 0;
      DAT_02900a5c = 0;
    }
  }
  return;
}

