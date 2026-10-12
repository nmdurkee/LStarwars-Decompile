/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x596950; label: thunk_FUN_005d05b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005d05b0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_00966384 != 0) {
    do {
      piVar1 = &DAT_0096d9d0 + iVar2;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*piVar1 + 0x824) = 0;
    } while (iVar2 != DAT_00966384);
  }
  DAT_00966384 = 0;
  DAT_009715a0 = 0;
  return;
}

