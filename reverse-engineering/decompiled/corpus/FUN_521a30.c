/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x521a30; label: FUN_00521a30
 */

void * FUN_00521a30(void)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004f1440(DAT_009238e4 + 0x411f8);
  if (_Dst != (void *)0x0) {
    FUN_004f1410(DAT_009238e4 + 0x411f8,_Dst);
    _memset(_Dst,0,0x118);
    FUN_004f1310(DAT_009238e4 + 0x41200,_Dst);
  }
  return _Dst;
}

