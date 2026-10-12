/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54bbc0; label: FUN_0054bbc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054bbc0(float param_1,int param_2,int param_3,int param_4,char *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  if (param_2 == 0) {
    uVar1 = 0;
    uVar2 = FUN_006e6b90();
    fVar5 = extraout_ST0_00;
    if (param_3 == 0) {
      uVar3 = FUN_006e6b90();
      fVar5 = extraout_ST0_01;
      goto LAB_0054bc52;
    }
  }
  else {
    uVar1 = FUN_006e6b90();
    FUN_005b7d30((float)(extraout_ST0 / (float10)60.0),0x42700000);
    uVar2 = FUN_006e6b90();
    fVar5 = (float10)param_1;
  }
  FUN_005b7d30((float)fVar5,0x42700000);
  uVar3 = FUN_006e6b90();
  fVar5 = (float10)param_1;
LAB_0054bc52:
  FUN_005b7d30((float)fVar5,0x3f800000);
  uVar4 = FUN_006e6b90();
  if (param_5 != (char *)0x0) {
    if (param_2 != 0) {
      if (param_4 == 0) {
        _sprintf(param_5,"%i:%.2i:%.2i",uVar1,uVar2,uVar3);
        return;
      }
      _sprintf(param_5,"%i:%.2i:%.2i.%.2i",uVar1,uVar2,uVar3,uVar4);
      return;
    }
    if (param_3 != 0) {
      if (param_4 == 0) {
        _sprintf(param_5,"%i:%.2i",uVar2,uVar3);
        return;
      }
      _sprintf(param_5,"%i:%.2i.%.2i",uVar2,uVar3,uVar4);
      return;
    }
    if (param_4 != 0) {
      _sprintf(param_5,"%i.%.2i",uVar3,uVar4);
      return;
    }
    _sprintf(param_5,"%i",uVar3);
  }
  return;
}

