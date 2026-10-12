/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693c40; label: FUN_00693c40
 */

void FUN_00693c40(void)

{
  int in_ECX;
  int *_Dst;
  int iVar1;
  
  iVar1 = 0;
  _Dst = (int *)(in_ECX + 0x130);
  do {
    _memset(_Dst,0,0x34);
    _Dst[0xc] = _Dst[0xc] & 0xfffffffe;
    _Dst[10] = 0;
    *_Dst = iVar1;
    _Dst[7] = 0x3f800000;
    _Dst[6] = 1;
    iVar1 = iVar1 + 1;
    _Dst[9] = -0x40800000;
    _Dst[0xb] = 0;
    _Dst = _Dst + 0xd;
  } while (iVar1 < 2);
  return;
}

