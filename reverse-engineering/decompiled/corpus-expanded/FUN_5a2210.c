/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2210; label: FUN_005a2210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005a2210(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_004f8b10((&PTR_s_water_00805864)[iVar2],param_1);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return -1;
}

