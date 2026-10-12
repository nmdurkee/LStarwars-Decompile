/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611190; label: FUN_00611190
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

