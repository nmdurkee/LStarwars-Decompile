/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x678340; label: FUN_00678340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

