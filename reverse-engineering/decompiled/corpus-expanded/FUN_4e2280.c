/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e2280; label: FUN_004e2280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e2280(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_00951b50 == 0) && (0.0 < *(float *)(DAT_0088901c + 0x28))) {
    iVar1 = FUN_0055ce20((int)DAT_007f19e0,1,1,1,0);
    if ((iVar1 != 0) && ((DAT_0088901c != 0 && (*(float *)(DAT_0088901c + 0x28) == 1.0)))) {
      FUN_004ba2d0(iVar1);
    }
  }
  uVar2 = FUN_005d0330(&DAT_0088902c);
  FUN_005ea570(&DAT_0088902c,uVar2);
  FUN_005cfc00(&DAT_0088902c,1);
  return;
}

