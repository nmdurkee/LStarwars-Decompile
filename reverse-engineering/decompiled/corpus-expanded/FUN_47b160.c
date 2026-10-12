/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47b160; label: FUN_0047b160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047b160(void)

{
  ushort uVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 fVar3;
  float10 extraout_ST0_00;
  undefined4 uVar4;
  float fVar5;
  float local_8;
  
  if ((((DAT_00879514 == 2) || (DAT_00879514 == 1)) || (DAT_00879514 == 3)) && (0.0 < _DAT_00950780)
     ) {
    return;
  }
  if ((DAT_00879514 == 4) && (0.0 < *(float *)(DAT_0087b4d0 + 4))) {
    return;
  }
  local_8 = 1.0;
  if (((DAT_00879514 == 2) || (DAT_00879514 == 1)) || ((DAT_00879514 == 3 || (DAT_00879514 == 4))))
  {
    if (0.5 <= _DAT_0087959c) {
      return;
    }
    iVar2 = FUN_006e6b90();
    local_8 = 1.0 - (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
    fVar3 = (float10)local_8;
    if (fVar3 <= extraout_ST0) {
      return;
    }
  }
  else {
    fVar3 = (float10)1.0;
  }
  uVar1 = *(ushort *)(DAT_008795a0 * 0x9c + DAT_00951354 + 0x7a);
  if ((uVar1 & 0x100) == 0) {
    if ((uVar1 & 4) == 0) {
      FUN_00478f30((float)fVar3,DAT_008795a0,DAT_0087951c);
    }
    else {
      FUN_0047ab00((float)fVar3,0xffffffff,0xffffffff);
    }
  }
  else {
    FUN_0047af70((float)fVar3);
  }
  fVar5 = _DAT_007fc2d8;
  if (DAT_0087b6c8 != '\0') {
    fVar5 = 1.0;
  }
  FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,fVar5 * local_8,
               fVar5 * local_8,1,0);
  fVar5 = _DAT_007fc2d8;
  if (DAT_0087b6c9 != '\0') {
    fVar5 = 1.0;
  }
  FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,fVar5 * local_8,
               fVar5 * local_8,1,0);
  if (_DAT_00950678 < 0.0 == (_DAT_00950678 == 0.0)) {
    if (1.0 <= _DAT_00950678) goto LAB_0047b3ca;
    iVar2 = FUN_006e6b90();
    fVar5 = (float)((extraout_ST0_00 - (float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff]) *
                   (float10)local_8);
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    fVar5 = local_8;
  }
  FUN_00475090(uVar4,fVar5);
LAB_0047b3ca:
  if (((_DAT_00950678 <= 0.0) && (DAT_00879514 == 0)) && (local_8 == 1.0)) {
    FUN_004b79a0(DAT_0087b6c8,(int)DAT_00880868,0x3f800000,0xffffffff,(int)DAT_0088086c,0xffffffff,
                 (int)DAT_00880e8c,DAT_0087b6c9,(int)DAT_00880868,0x3f800000,0xffffffff,
                 (int)DAT_0088086c,0xffffffff,(int)DAT_00880e8c);
    return;
  }
  return;
}

