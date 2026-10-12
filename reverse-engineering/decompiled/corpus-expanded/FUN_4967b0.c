/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x4967b0; label: FUN_004967b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004967b0(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  if (DAT_00921d24 == 0) {
    uVar3 = _DAT_007fc2d8;
    if (DAT_0087b6c8 != '\0') {
      uVar3 = 0x3f800000;
    }
    FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,uVar3,uVar3,1,0
                );
    uVar3 = _DAT_007fc2d8;
    if (DAT_0087b6c9 != '\0') {
      uVar3 = 0x3f800000;
    }
    FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,uVar3,uVar3,1,0)
    ;
    FUN_004b79a0(DAT_0087b6c8,0xffffffff,0x3f800000,0xffffffff,(int)DAT_00880824,0xffffffff,
                 (int)DAT_00880e8c,DAT_0087b6c9,0xffffffff,0x3f800000,0xffffffff,(int)DAT_00880824,
                 0xffffffff,(int)DAT_00880e8c);
    FUN_005b7d30(_DAT_00925030,0x3f000000);
    fVar5 = (float10)FUN_005b7d30(_DAT_00925030,0x3f000000);
    iVar4 = (-(uint)(DAT_009213e4 != 0) & 0xffffffc0) + 0xff;
    fVar1 = (float)(&DAT_029899a0)
                   [(uint)(int)ROUND((fVar5 + fVar5) * (float10)65536.0) >> 1 & 0x7fff] * 0.05;
    uVar3 = FUN_006e6b90();
    if (0.0 < _DAT_00879b44) {
      FUN_006e6b90();
      uVar3 = FUN_006e6b90();
    }
    if (DAT_0087b6c8 != '\0') {
      fVar2 = 0.5 - fVar1;
      FUN_0050c780("[[lb]]",-_DAT_007fc31c,_DAT_007face0 + _DAT_007fc310,0x3f800000,fVar2,fVar2,
                   fVar2,0,0xff,0xff,0xff,uVar3);
      fVar2 = fVar1 + 0.5;
      FUN_0050c780("[[rb]]",-_DAT_007fc31c,_DAT_007face4 + _DAT_007fc310,0x3f800000,fVar2,fVar2,
                   fVar2,0,0xff,0xff,0xff,uVar3);
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880868 * 4),-_DAT_007fc31c,
                   _DAT_007face8 + _DAT_007fc310,0x3f800000,0x3e99999a,0x3e99999a,0x3e99999a,0,iVar4
                   ,iVar4,iVar4,0x3e19999a,1,0,0,uVar3);
    }
    if (DAT_0087b6c9 != '\0') {
      fVar2 = 0.5 - fVar1;
      FUN_0050c780("[[lb]]",_DAT_007fc31c,_DAT_007face0 + _DAT_007fc310,0x3f800000,fVar2,fVar2,fVar2
                   ,0,0xff,0xff,0xff,uVar3);
      fVar1 = fVar1 + 0.5;
      FUN_0050c780("[[rb]]",_DAT_007fc31c,_DAT_007face4 + _DAT_007fc310,0x3f800000,fVar1,fVar1,fVar1
                   ,0,0xff,0xff,0xff,uVar3);
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880868 * 4),_DAT_007fc31c,
                   _DAT_007face8 + _DAT_007fc310,0x3f800000,0x3e99999a,0x3e99999a,0x3e99999a,0,iVar4
                   ,iVar4,iVar4,0x3e19999a,1,0,0,uVar3);
    }
  }
  return;
}

