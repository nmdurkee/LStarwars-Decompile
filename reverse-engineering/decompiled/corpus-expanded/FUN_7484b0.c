/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x7484b0; label: FUN_007484b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

