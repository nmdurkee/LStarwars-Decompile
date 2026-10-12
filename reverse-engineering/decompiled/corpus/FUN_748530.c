/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x748530; label: FUN_00748530
 */

void FUN_00748530(char *param_1,size_t param_2)

{
  void *_Dst;
  size_t _Size;
  int *in_ECX;
  size_t sVar1;
  
  if (in_ECX[2] < (int)(in_ECX[1] + param_2)) {
    sVar1 = (int)((in_ECX[1] + param_2) * 3) / 2;
    _Dst = (void *)FUN_006ea018(sVar1);
    _Size = in_ECX[1];
    if ((int)sVar1 <= in_ECX[1]) {
      _Size = sVar1;
    }
    _memcpy(_Dst,(void *)*in_ECX,_Size);
    _free((void *)*in_ECX);
    *in_ECX = (int)_Dst;
    in_ECX[2] = sVar1;
    if ((int)sVar1 < in_ECX[1]) {
      in_ECX[1] = sVar1;
    }
  }
  _strncpy((char *)(*in_ECX + in_ECX[1]),param_1,param_2);
  in_ECX[1] = in_ECX[1] + param_2;
  return;
}

