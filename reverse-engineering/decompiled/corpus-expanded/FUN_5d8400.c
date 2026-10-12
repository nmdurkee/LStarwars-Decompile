/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8400; label: FUN_005d8400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d8400(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_0097396c != 0) {
    iVar1 = (&DAT_009716a4)[param_1];
    FUN_004f3bd0(*(int *)(iVar1 + 0x10) + param_2 * 8);
    *(undefined4 *)(*(int *)(iVar1 + 0x24) + param_2 * 4) = param_3;
  }
  return;
}

