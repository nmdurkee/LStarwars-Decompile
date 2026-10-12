/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74aa10; label: FUN_0074aa10
 */

void * FUN_0074aa10(void)

{
  void *_Dst;
  undefined4 *in_ECX;
  
  _Dst = (void *)FUN_006ea018(in_ECX[1] + 1);
  _memcpy(_Dst,(void *)*in_ECX,in_ECX[1]);
  *(undefined1 *)((int)_Dst + in_ECX[1]) = 0;
  return _Dst;
}

