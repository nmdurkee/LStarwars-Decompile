/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b660; label: FUN_0055b660
 */

void FUN_0055b660(int param_1,int *param_2)

{
  size_t _Size;
  void *_Dst;
  int iVar1;
  
  _Size = DAT_0093b278 * 4;
  _Dst = (void *)(*param_2 + 3U & 0xfffffffc);
  DAT_0093b270 = _Dst;
  *param_2 = (int)((int)_Dst + _Size);
  _memset(_Dst,0,_Size);
  if (param_1 != 0) {
    iVar1 = FUN_004f1ff0(param_1);
    if (iVar1 < 0x40) {
      FUN_004f1f10(s_stuff_icons__00802928,param_1);
    }
  }
  return;
}

