/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b2d0; label: FUN_0055b2d0
 */

void FUN_0055b2d0(int *param_1)

{
  void *_Dst;
  size_t _Size;
  
  _Size = DAT_0093b278 * 0x10;
  _Dst = (void *)(*param_1 + 3U & 0xfffffffc);
  DAT_0093b27c = _Dst;
  *param_1 = (int)((int)_Dst + _Size);
  _memset(_Dst,0,_Size);
  return;
}

