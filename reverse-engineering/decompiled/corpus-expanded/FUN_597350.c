/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597350; label: FUN_00597350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00597350(int param_1)

{
  if ((param_1 != 0) && (*(void **)(param_1 + 0x10ac) != (void *)0x0)) {
    _memset(*(void **)(param_1 + 0x10ac),0,0x110);
    *(undefined4 *)(param_1 + 0x10ac) = 0;
  }
  return;
}

