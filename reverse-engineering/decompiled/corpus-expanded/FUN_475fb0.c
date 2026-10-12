/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x475fb0; label: FUN_00475fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00475fb0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_1 == 1)) && (((&DAT_007fa138)[DAT_007fa190 * 0xc] & 1) != 0)) {
    iVar1 = FUN_0055f1a0();
    if (iVar1 != 0) {
      *(int *)(&DAT_00951248 + param_1 * 4) = *(int *)(&DAT_00951248 + param_1 * 4) + 1;
      FUN_00475c60(param_1,0,param_2);
      return;
    }
    FUN_00475c60(param_1,0,0);
  }
  return;
}

