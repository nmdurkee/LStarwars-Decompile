/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be000; label: FUN_006be000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be000(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_0081f9ec;
  *param_1 = DAT_0081f9e8;
  uVar2 = DAT_0081f9f0;
  param_1[1] = uVar1;
  uVar1 = DAT_0081f9f4;
  param_1[2] = uVar2;
  param_1[3] = uVar1;
  return;
}

