/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59a950; label: FUN_0059a950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059a950(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  fVar1 = *(float *)((int)param_1 + 0x150);
  fVar2 = *(float *)((int)param_1 + 0x144);
  fVar3 = *(float *)((int)param_1 + 0x158);
  fVar4 = *(float *)((int)param_1 + 0x14c);
  param_1 = 0.0;
  do {
    fVar5 = param_1 * (fVar1 - fVar2) * 0.015625 + *(float *)(iVar6 + 0x144);
    FUN_005dc050(fVar5,*(undefined4 *)(DAT_0093d7f0 + 0x84),*(undefined4 *)(iVar6 + 0x14c),fVar5,
                 *(undefined4 *)(DAT_0093d7f0 + 0x84),*(undefined4 *)(iVar6 + 0x158),0xff0000ff);
    param_1 = param_1 + 1.0;
  } while (param_1 < 64.0);
  param_1 = 0.0;
  do {
    fVar1 = param_1 * (fVar3 - fVar4) * 0.015625 + *(float *)(iVar6 + 0x14c);
    FUN_005dc050(*(undefined4 *)(iVar6 + 0x144),*(undefined4 *)(DAT_0093d7f0 + 0x84),fVar1,
                 *(undefined4 *)(iVar6 + 0x150),*(undefined4 *)(DAT_0093d7f0 + 0x84),fVar1,
                 0xff00ff00);
    param_1 = param_1 + 1.0;
  } while (param_1 < 64.0);
  return;
}

