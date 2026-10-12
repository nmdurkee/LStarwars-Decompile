/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x7484b0; label: FUN_007484b0
 */

void * FUN_007484b0(void)

{
  void *_Dst;
  undefined4 *in_ECX;
  
  _Dst = (void *)FUN_006ea018(in_ECX[1] + 1);
  _memcpy(_Dst,(void *)*in_ECX,in_ECX[1]);
  *(undefined1 *)((int)_Dst + in_ECX[1]) = 0;
  return _Dst;
}

