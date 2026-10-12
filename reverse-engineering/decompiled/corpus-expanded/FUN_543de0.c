/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543de0; label: FUN_00543de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543de0(void)

{
  DWORD DVar1;
  
  if (DAT_00924828 != 0) {
    DVar1 = GetTickCount();
    if (1000 < (int)(DVar1 - _DAT_009246f0)) {
      DAT_00924828 = 0;
      FUN_00543880();
      DAT_00924800 = 1;
    }
  }
  return;
}

