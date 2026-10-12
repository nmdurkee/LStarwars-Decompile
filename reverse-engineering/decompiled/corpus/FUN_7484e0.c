/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x7484e0; label: FUN_007484e0
 */

void FUN_007484e0(size_t param_1)

{
  void *_Dst;
  size_t _Size;
  undefined4 *in_ECX;
  
  _Dst = (void *)FUN_006ea018(param_1);
  _Size = in_ECX[1];
  if ((int)param_1 <= (int)in_ECX[1]) {
    _Size = param_1;
  }
  _memcpy(_Dst,(void *)*in_ECX,_Size);
  _free((void *)*in_ECX);
  *in_ECX = _Dst;
  in_ECX[2] = param_1;
  if ((int)param_1 < (int)in_ECX[1]) {
    in_ECX[1] = param_1;
  }
  return;
}

