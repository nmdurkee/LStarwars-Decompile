/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x599960; label: FUN_00599960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00599960(int param_1)

{
  char cVar1;
  
  if (((DAT_00802878 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802878)) &&
     ((cVar1 = *(char *)(param_1 + 0x7b3), cVar1 == '\x02' ||
      ((cVar1 == '\x03' || (cVar1 == '\x06')))))) {
    return 1;
  }
  return 0;
}

