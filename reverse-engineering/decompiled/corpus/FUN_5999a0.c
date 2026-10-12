/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x5999a0; label: FUN_005999a0
 */

void FUN_005999a0(int param_1)

{
  char cVar1;
  
  if (((DAT_00802878 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802878)) &&
     ((cVar1 = *(char *)(param_1 + 0x7b3), cVar1 == '\x02' ||
      ((cVar1 == '\x03' || (cVar1 == '\x06')))))) {
    FUN_005980c0(param_1,1);
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  return;
}

