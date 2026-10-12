/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d05b0; label: FUN_005d05b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d05b0(void)

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

