/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428b90; label: FUN_00428b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428b90(void)

{
  undefined4 uVar1;
  
  if (DAT_009250b0 == 0) {
    FUN_004f1f10(&DAT_0087b4c0,"BASLUS-21409");
    _DAT_00925018 = 0.016666668;
  }
  else {
    FUN_004f1f10(&DAT_0087b4c0,"BESLES-54221");
    _DAT_00925018 = 0.02;
  }
  _DAT_00925024 = 1.0 / _DAT_00925018;
  _DAT_0092501c = 0x3c888889;
  _DAT_00925054 = 0x3dcccccd;
  FUN_0050b850(6,FUN_00428b80,&DAT_008668c8,0x7e4c,1,FUN_004b7190);
  DAT_0093b0d8 = &DAT_008668cc;
  DAT_00951bd4 = &DAT_008668d9;
  DAT_0095136c = &DAT_0086e0f4;
  DAT_00956298 = &DAT_0086e454;
  DAT_0093b288 = &DAT_0086e5c0;
  DAT_0093b2b4 = &DAT_0086e4e0;
  DAT_009553d8 = &DAT_0086e55c;
  FUN_0054fa90();
  FUN_00548fb0(&DAT_00925028,0);
  FUN_00548fb0(&DAT_0092508c,0);
  FUN_0062a7b0(2);
  FUN_0062c7d0(FUN_00681e90);
  FUN_006dea60();
  FUN_00428b20();
  FUN_00547b20(&DAT_008668cc);
  FUN_00547ab0(&DAT_008668cc);
  DAT_00926c40 = FUN_004cf2d0;
  if (((DAT_0080235c != 0) && (DAT_0080235c != 0xd)) && (DAT_009250b0 != 0)) {
    uVar1 = FUN_004f5240();
    FUN_0054b580(uVar1);
  }
  FUN_00465dc0();
  FUN_0055ffb0(&DAT_0093d858,0xffffffff);
  FUN_0055ffb0(&DAT_00942a04,0xffffffff);
  DAT_0086e4cc = DAT_0086e4cc | 0x1000;
  _memset(&DAT_00955890,0,0x144);
  _memset(PTR_DAT_008021b4,0,0x230);
  FUN_00571850(&PTR_s_TRAINING_P_007f6410);
  FUN_00547850();
  if (DAT_00876580 != 0) {
    FUN_005ca3b0(1);
    DAT_00804d2c = 0;
  }
  return;
}

