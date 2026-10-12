/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3340; label: FUN_004e3340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3340(void)

{
  if (DAT_00951b50 == 0) {
    DAT_008895fc = FUN_0055ce20((int)DAT_007f1968,1,1,0,0);
    if (DAT_008895fc != 0) {
      FUN_004ba2d0();
      return;
    }
  }
  return;
}

