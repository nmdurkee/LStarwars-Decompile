/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49dc10; label: FUN_0049dc10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

