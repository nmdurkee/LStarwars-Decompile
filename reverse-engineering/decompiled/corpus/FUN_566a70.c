/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x566a70; label: FUN_00566a70
 */

void FUN_00566a70(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    _memset(param_2,0,0x40);
    _memset((void *)((int)param_2 + 0x40),-1,0x40);
    _memset((void *)((int)param_2 + 0x80),-1,0x40);
    _memset((void *)((int)param_2 + 0xc0),0,0x40);
  }
  return;
}

