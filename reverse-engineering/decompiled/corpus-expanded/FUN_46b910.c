/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46b910; label: FUN_0046b910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b910(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  
  if ((0.0 < _DAT_00879364) || (fVar3 = (float10)FUN_005bec80(param_1 + 0x80), (float)fVar3 <= 0.0))
  {
    return;
  }
  iVar2 = FUN_006e6b90();
  uVar1 = (&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
  if (DAT_0093b338 != 0) {
    FUN_00651470("PickupCoin",param_1 + 0x30,uVar1);
    _DAT_00879364 = 0.1;
    return;
  }
  if ((0xb6 < *(short *)(param_1 + 0x13e)) && (*(short *)(param_1 + 0x13e) < 0xbb)) {
    FUN_00651470("CoinDropS",param_1 + 0x30,uVar1);
    return;
  }
  FUN_00651470("CoinDropG",param_1 + 0x30,uVar1);
  return;
}

