/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ec390; label: FUN_004ec390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ec390(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0095df4c != 0) {
    iVar1 = FUN_005aac00(DAT_0095df4c,"Boba_Dead",0);
    if ((iVar1 != 0) && (*(float *)(iVar1 + 0x28) == 0.0)) {
      iVar2 = FUN_0055ce20((int)DAT_007f1908,1,1,1,0);
      if (DAT_0095df4c != 0) {
        iVar1 = FUN_005aac00(DAT_0095df4c,"BobaFightStarted",0);
      }
      if (((iVar2 != 0) && (iVar1 != 0)) && (*(float *)(iVar1 + 0x28) == 1.0)) {
        FUN_004ba2d0(iVar2);
      }
      return;
    }
  }
  FUN_004ba2d0();
  return;
}

