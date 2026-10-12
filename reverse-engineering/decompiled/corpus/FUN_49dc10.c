/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49dc10; label: FUN_0049dc10
 */

void FUN_0049dc10(void)

{
  int unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 0xe32) = 1;
  FUN_00547f30();
  *(undefined4 *)(unaff_ESI + 0x6c) =
       *(undefined4 *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x2c);
  if ((*(char *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x116) == '\x02') &&
     (*(char *)(unaff_ESI + 0x7b5) != '\a')) {
    FUN_0058d480();
  }
  *(undefined4 *)(unaff_ESI + 0xd64) = 0;
  return;
}

