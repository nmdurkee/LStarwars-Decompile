/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54db40; label: FUN_0054db40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054db40(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_005b7d30(_DAT_0092505c,0x40a00000);
  uVar3 = (int)ROUND((fVar4 / (float10)5.0) * (float10)65536.0) & 0xffff;
  FUN_005b7d30(_DAT_00925064,0x3f000000);
  iVar2 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * 0.2 + 0.8;
  FUN_00596920(0);
  FUN_0054d820(param_1,*(undefined4 *)(param_1 + 0x5080),uVar3,fVar1);
  FUN_0054d820(param_1,&DAT_00926c58,uVar3,fVar1);
  thunk_FUN_005d05b0();
  return;
}

