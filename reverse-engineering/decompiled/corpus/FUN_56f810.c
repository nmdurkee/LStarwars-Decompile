/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f810; label: FUN_0056f810
 */

void FUN_0056f810(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    _memset((void *)((int)param_2 + 0x80),-1,0x40);
    _memset((void *)((int)param_2 + 0x40),-1,0x40);
    _memset(param_2,0,0x40);
    _memset((void *)((int)param_2 + 0xc0),0,0x40);
  }
  return;
}

