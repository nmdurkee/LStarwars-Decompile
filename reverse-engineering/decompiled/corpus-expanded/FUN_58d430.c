/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58d430; label: FUN_0058d430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058d430(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if ((cVar1 != -1) && ((cVar1 == DAT_00802864 || (cVar1 == DAT_00802868)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x10000;
  *(undefined4 *)(param_1 + 0xd3c) = 0x3f800000;
  *(undefined1 *)(param_1 + 0xe33) = 0;
  return;
}

