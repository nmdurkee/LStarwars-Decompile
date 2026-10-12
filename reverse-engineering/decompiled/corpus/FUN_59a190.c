/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59a190; label: FUN_0059a190
 */

undefined4 FUN_0059a190(int param_1)

{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = 0;
  if (0 < DAT_00951360) {
    pcVar3 = (char *)(param_1 + 4);
    pbVar2 = (byte *)(DAT_00951354 + 0x7a);
    do {
      if (((*pbVar2 & 0x10) != 0) && (*pcVar3 == '\0')) {
        return 0;
      }
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar2 + 0x9c;
      pcVar3 = pcVar3 + 0xc;
    } while (iVar1 < DAT_00951360);
  }
  return 1;
}

