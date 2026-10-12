/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x742340; label: FUN_00742340
 */

void FUN_00742340(void)

{
  int in_ECX;
  
  switch((*(int *)(in_ECX + 4) << 4) >> 0x1c) {
  case 1:
    FUN_00741f90();
    return;
  case 2:
    FUN_00741fd0();
    return;
  case 3:
    FUN_00742010();
    return;
  default:
    return;
  }
}

