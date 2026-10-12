/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a7120; label: FUN_005a7120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a7120(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    bVar1 = *(byte *)(iVar2 + 0xd0);
  }
  else {
    bVar1 = *(byte *)(iVar2 + 0xd0) & (byte)(1 << ((byte)param_2 & 0x1f));
  }
  if (bVar1 == 0) {
    return 0;
  }
  return 1;
}

