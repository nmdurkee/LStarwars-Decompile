/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4252c0; label: FUN_004252c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004252c0(void)

{
  DAT_0087a9d0 = 0x3f19999a;
  DAT_0087a929 = 1;
  FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
  FUN_00509760();
  FUN_00548fb0(&DAT_00925044,0);
  DAT_008568f0 = 2;
  DAT_008568f4 = 2;
  if (DAT_0093b338 != 0) {
    DAT_00951b80 = DAT_00951b94;
    DAT_0093b29c = 1;
    DAT_0093b2a4 = 1;
    DAT_00855f7c = 1;
    DAT_0087a9c8 = 1;
    DAT_0093b338 = 2;
  }
  return;
}

