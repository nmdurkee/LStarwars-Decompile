/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3380; label: FUN_004e3380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3380(void)

{
  if (((DAT_00951b50 == 0) && (DAT_008895fc != 0)) && (*(char *)(DAT_008895fc + 0x107f) < '\x01')) {
    if (DAT_0093b2a4 != 0) {
      FUN_004897f0((int)DAT_007f1968,0,0);
      return;
    }
    FUN_00489850((int)DAT_007f1968,0,0,"ep3_GeneralGrievous_Outro");
  }
  return;
}

