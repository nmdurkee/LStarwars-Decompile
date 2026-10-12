/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611190; label: FUN_00611190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611190(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
  }
  uVar1 = FUN_00633440(3000,1);
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[2] = *param_1;
  return;
}

