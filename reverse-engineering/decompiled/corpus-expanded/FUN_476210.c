/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476210; label: FUN_00476210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476210(void)

{
  int iVar1;
  
  iVar1 = FUN_00574e20();
  if (iVar1 == -1) {
    iVar1 = FUN_0055f1a0();
    if (iVar1 == 0) {
      FUN_004a4900(0,&DAT_007fa1b4,_DAT_007fa1c0,4);
      return;
    }
  }
  FUN_004a48f0();
  return;
}

