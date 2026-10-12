/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdb00; label: FUN_006bdb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bdb00(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  if (DAT_02973aa4 != 0) {
    if (*(int **)(param_2 + 0xc) == (int *)0x0) {
      puVar1 = &DAT_00763b90;
    }
    else {
      puVar1 = (undefined *)(**(code **)(**(int **)(param_2 + 0xc) + 0xc))();
    }
    FUN_0061e530(*(undefined4 *)(DAT_02973aa4 + 4),puVar1);
    FUN_006ba280(puVar1);
  }
  return;
}

