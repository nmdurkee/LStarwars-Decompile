/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x413a20; label: FUN_00413a20
 */

void FUN_00413a20(int param_1)

{
  int iVar1;
  
  FUN_00412580(param_1);
  FUN_00411980(param_1);
  iVar1 = 0;
  do {
    *(undefined4 *)(iVar1 + 0x38d0 + *(int *)(param_1 + 0x511c)) = 0;
    iVar1 = iVar1 + 0x530;
  } while (iVar1 < 0x53000);
  if (*(int *)(param_1 + 0x128) == DAT_0087b0f8) {
    FUN_0040f920(param_1,*(int *)(param_1 + 0x511c) + 0x34d0,0x100);
  }
  FUN_004100b0();
  return;
}

