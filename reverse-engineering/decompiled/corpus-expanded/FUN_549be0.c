/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549be0; label: FUN_00549be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549be0(undefined *param_1,float param_2)

{
  float *pfVar1;
  undefined *puVar2;
  undefined *puVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  float10 fVar8;
  undefined1 local_c [12];
  
  puVar7 = param_1;
  if (param_1 == (undefined *)0x0) {
    puVar7 = PTR_DAT_008021b4;
  }
  if (0.0 < *(float *)(puVar7 + 0x1d8)) {
    *(float *)(puVar7 + 0x1d8) = *(float *)(puVar7 + 0x1d8) - _DAT_00925018;
  }
  if (*(float *)(puVar7 + 0x1d8) <= 0.0) {
    if (param_2 <= 0.0) {
      param_2 = 0.0;
    }
  }
  else {
    param_2 = *(float *)(puVar7 + 0x1d4);
  }
  fVar8 = (float10)FUN_0054fad0(*(undefined4 *)(puVar7 + 0x1d0),param_2,
                                _DAT_00925018 + _DAT_00925018);
  *(float *)(puVar7 + 0x1d0) = (float)fVar8;
  fVar4 = _DAT_00802200;
  pfVar1 = (float *)(puVar7 + 0x1ac);
  puVar2 = puVar7 + 0x1a0;
  fVar8 = (float10)FUN_005b3c50(puVar2,pfVar1,0);
  if (fVar8 < (float10)fVar4 * (float10)fVar4) {
    *pfVar1 = 0.0;
    iVar5 = FUN_0054fa60();
    *(float *)(puVar7 + 0x1b0) = (float)iVar5 * 1.5259022e-05 * _DAT_008021fc;
    *(undefined4 *)(puVar7 + 0x1b4) = 0;
    uVar6 = FUN_0054fa60();
    FUN_005b3690(pfVar1,pfVar1,uVar6);
    *pfVar1 = *pfVar1 * 1.3333334;
  }
  param_1 = (undefined *)_DAT_00802204;
  if (0.0 < *(float *)(puVar7 + 0x1d8)) {
    param_1 = (undefined *)(_DAT_00802204 * *(float *)(puVar7 + 0x1dc));
  }
  FUN_0054fb80(puVar2,puVar2,pfVar1,param_1);
  param_1 = (undefined *)_DAT_00802208;
  if (0.0 < *(float *)(puVar7 + 0x1d8)) {
    param_1 = (undefined *)(_DAT_00802208 * *(float *)(puVar7 + 0x1dc));
  }
  puVar3 = puVar7 + 0x194;
  FUN_0054fb80(puVar3,puVar3,puVar2,param_1);
  FUN_005b3830(local_c,puVar3,*(undefined4 *)(puVar7 + 0x1d0));
  uVar6 = FUN_006e6b90();
  FUN_005b4dd0(puVar7 + 0xb8,uVar6);
  uVar6 = FUN_006e6b90();
  FUN_005b5060(puVar7 + 0xb8,uVar6);
  return;
}

