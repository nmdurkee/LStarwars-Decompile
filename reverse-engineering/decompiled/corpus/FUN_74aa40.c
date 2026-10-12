/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74aa40; label: FUN_0074aa40
 */

void * FUN_0074aa40(int param_1)

{
  void *_Dst;
  undefined4 *in_ECX;
  
  _Dst = *(void **)(param_1 + 4);
  *(int *)(param_1 + 4) = in_ECX[1] + 1 + (int)_Dst;
  _memcpy(_Dst,(void *)*in_ECX,in_ECX[1]);
  *(undefined1 *)((int)_Dst + in_ECX[1]) = 0;
  return _Dst;
}

