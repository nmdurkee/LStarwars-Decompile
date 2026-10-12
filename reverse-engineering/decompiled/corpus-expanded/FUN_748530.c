/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748530; label: FUN_00748530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
    FUN_006e85b0(*in_ECX);
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

