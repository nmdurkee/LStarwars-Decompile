/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47b450; label: FUN_0047b450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047b450(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined2 extraout_var;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  float10 extraout_ST0;
  float10 fVar10;
  float10 extraout_ST0_00;
  float local_10;
  undefined4 local_4;
  
  if (((((DAT_00879b14 == 1) || (DAT_00879b14 == 2)) || (DAT_00879b14 == 3)) || (DAT_00879b14 == 4))
     && (0.0 < _DAT_00950780)) {
    return;
  }
  local_10 = 1.0;
  if (((DAT_00879b14 == 1) || (DAT_00879b14 == 2)) || ((DAT_00879b14 == 3 || (DAT_00879b14 == 4))))
  {
    if (0.5 <= _DAT_00879510) {
      return;
    }
    iVar5 = FUN_006e6b90();
    local_10 = 1.0 - (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
    fVar10 = (float10)local_10;
    if (fVar10 <= extraout_ST0) {
      return;
    }
  }
  else {
    fVar10 = (float10)1.0;
  }
  if (DAT_0087950c == 0) {
    if (DAT_008794ec == -1) {
      FUN_0047af70((float)fVar10);
    }
    else {
      FUN_0047ab00((float)fVar10,0xffffffff,DAT_00879584);
    }
  }
  else {
    FUN_00475890((float)fVar10);
  }
  fVar3 = _DAT_007fc2d8;
  if (DAT_0087b6c8 != '\0') {
    fVar3 = 1.0;
  }
  FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,fVar3 * local_10,
               fVar3 * local_10,1,0);
  fVar3 = _DAT_007fc2d8;
  if (DAT_0087b6c9 != '\0') {
    fVar3 = 1.0;
  }
  FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,fVar3 * local_10,
               fVar3 * local_10,1,0);
  if (_DAT_00950678 < 0.0 == (_DAT_00950678 == 0.0)) {
    if (_DAT_00950678 < 1.0) {
      iVar5 = FUN_006e6b90();
      FUN_004763d0(0,(float)((extraout_ST0_00 - (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff]
                             ) * (float10)local_10));
    }
  }
  else {
    FUN_004763d0(1,local_10);
  }
  if (((0.0 < _DAT_00950678) || (DAT_00879b14 != 0)) || (local_10 != 1.0)) {
    return;
  }
  local_4 = 0x3eaa7efa;
  if (DAT_0087950c == 0) goto LAB_0047b9b0;
  if (DAT_00879584 == 4) {
    if ((*(int *)(&PTR_DAT_007fa100)[DAT_007fa188] != 0) &&
       ((&DAT_0086e0f4)[(uint)*(byte *)(*(int *)(&PTR_DAT_007fa100)[DAT_007fa188] + 0x7c) * 0xc] !=
        '\0')) {
LAB_0047b74f:
      local_4 = 0x3f800000;
    }
  }
  else if ((DAT_00879584 == 3) && (DAT_007fa1a0 == '\x01')) goto LAB_0047b74f;
  fVar3 = _DAT_007fc310 - 0.225;
  iVar8 = (-(uint)(DAT_009213e4 != 0) & 0xffffffc0) + 0xff;
  iVar9 = 0;
  iVar5 = DAT_00879584;
  do {
    fVar1 = 0.0;
    if ((&DAT_0087b6c8)[iVar9] != '\0') {
      fVar4 = _DAT_007fc31c;
      if (iVar9 == 0) {
        fVar4 = -_DAT_007fc31c;
      }
      if (iVar5 == 4) {
        uVar7 = 0x20;
      }
      else if (((iVar5 != 3) || (DAT_0087956c != 0)) || (uVar7 = 0x20, DAT_00879570 != 0)) {
        uVar7 = 0x80;
      }
      if (0.0 < (float)(&DAT_00856924)[iVar9]) {
        fVar1 = 0.015000001;
      }
      FUN_0050c780(&DAT_007533c8,(fVar4 - 0.05) - fVar1,fVar3,0x3f800000,0x3f000000,0x3f000000,
                   0x3f000000,0,iVar8,iVar8,iVar8,uVar7);
      fVar1 = 0.0;
      if (0.0 < (float)(&DAT_0085691c)[iVar9]) {
        fVar1 = 0.015000001;
      }
      FUN_0050c780(&DAT_007533c4,fVar4 + 0.05 + fVar1,fVar3,0x3f800000,0x3f000000,0x3f000000,
                   0x3f000000,0,iVar8,iVar8,iVar8,uVar7);
      fVar1 = 0.0;
      if (0.0 < (float)(&DAT_00856934)[iVar9]) {
        fVar1 = -0.021000002;
      }
      uVar6 = CONCAT31((int3)((uint)-DAT_00879584 >> 8),-(DAT_00879584 != 0)) & 0xffffff60;
      FUN_0050c780(PTR_DAT_007f3a18,fVar4,(fVar3 - -0.07) - fVar1,0x3f800000,0x3f000000,0x3f000000,
                   0x3f000000,0,iVar8,iVar8,iVar8,CONCAT31((int3)(uVar6 >> 8),(char)uVar6 + ' '));
      fVar2 = 0.0;
      fVar1 = (float)(&DAT_00856870)[iVar9];
      if (0.0 < fVar1) {
        fVar2 = -0.021000002;
      }
      uVar6 = CONCAT31((int3)(CONCAT22(extraout_var,
                                       (ushort)(0.0 < fVar1) << 8 | (ushort)NAN(fVar1) << 10 |
                                       (ushort)(fVar1 == 0.0) << 0xe) >> 8),(DAT_00879584 < 4) + -1)
              & 0xffffffa0;
      FUN_0050c780(PTR_DAT_007f3a1c,fVar4,(fVar3 - 0.07) + fVar2,0x3f800000,0x3f000000,0x3f000000,
                   0x3f000000,0,iVar8,iVar8,iVar8,CONCAT31((int3)(uVar6 >> 8),(char)uVar6 + -0x80));
      iVar5 = DAT_00879584;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
LAB_0047b9b0:
  FUN_004b79a0(DAT_0087b6c8,(int)DAT_00880868,local_4,0xffffffff,(int)DAT_0088086c,0xffffffff,
               0xffffffff,DAT_0087b6c9,(int)DAT_00880868,local_4,0xffffffff,(int)DAT_0088086c,
               0xffffffff,0xffffffff);
  return;
}

