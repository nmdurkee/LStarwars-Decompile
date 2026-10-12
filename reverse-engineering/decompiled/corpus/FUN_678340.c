/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x678340; label: FUN_00678340
 */

void FUN_00678340(void)

{
  char cVar1;
  
  if ((*(int *)(DAT_0292186c + 0x90) != 0) && (*(short *)(DAT_0292186c + 0x6c) != -1)) {
    cVar1 = *(char *)(*(int *)(DAT_0292186c + 0x90) + 0x60);
    if (cVar1 != '\0') {
      DAT_02947bd8 = cVar1;
    }
    cVar1 = *(char *)(*(int *)(DAT_0292186c + 0x90) + 0x61);
    if (cVar1 != '\0') {
      DAT_02947bd9 = cVar1;
    }
    cVar1 = *(char *)(*(int *)(DAT_0292186c + 0x90) + 0x62);
    if (cVar1 != '\0') {
      DAT_02947bda = cVar1;
    }
    cVar1 = *(char *)(*(int *)(DAT_0292186c + 0x90) + 99);
    if (cVar1 != '\0') {
      DAT_02947bdb = cVar1;
    }
  }
  return;
}

