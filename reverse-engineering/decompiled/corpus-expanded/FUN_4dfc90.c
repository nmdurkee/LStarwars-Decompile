/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfc90; label: FUN_004dfc90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dfc90(int param_1)

{
  uint *puVar1;
  
  FUN_004dddf0(param_1);
  DAT_00888fd4 = FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"ep2_droidfactory_conveyor",0);
  if ((DAT_00888fd4 != 0) && (*(int *)(DAT_00888fd4 + 4) != 0)) {
    puVar1 = (uint *)(*(int *)(DAT_00888fd4 + 4) + 0x88);
    *puVar1 = *puVar1 | 2;
    puVar1 = (uint *)(*(int *)(DAT_00888fd4 + 4) + 0x88);
    *puVar1 = *puVar1 | 8;
  }
  DAT_00882b44 = FUN_005aac00(DAT_0095df4c,"conveyor_stop",0);
  return;
}

