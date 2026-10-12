/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9fb0; label: FUN_004c9fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c9fb0(int param_1)

{
  undefined **ppuVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  int local_14;
  code *local_10;
  undefined4 local_c;
  code *local_8;
  undefined1 *local_4;
  
  FUN_004c9db0();
  do {
  } while (DAT_00880578 != 3);
  FUN_0054b650(0x70d,&DAT_00924878,&DAT_0092487c);
  if ((DAT_007f39e4 == 0) && (DAT_00876580 == 0)) {
    FUN_0054b9d0(&PTR_DAT_007fd2c8,0,799);
    FUN_0054b9d0(&PTR_DAT_007fd800,800,0x70c);
  }
  else {
    FUN_0054b9d0(&PTR_DAT_007fe2d8,0,0x70c);
  }
  FUN_004cf4c0(&DAT_00924878,&DAT_0092487c);
  FUN_004cf3c0();
  DAT_0088057c = 1;
  if (param_1 != 0) {
    FUN_004c9bd0();
  }
  FUN_004fe390("stuff\\text\\badwords.txt",&DAT_00924878,DAT_0092487c);
  DAT_009248cc = FUN_00548a70("audio\\music.txt",&DAT_00924878,&DAT_0092487c);
  FUN_00652450(DAT_009248cc);
  FUN_006521b0(&DAT_00924878,DAT_0092487c,"Audio\\Audio.cfg");
  FUN_00565820(&DAT_00924878,DAT_0092487c);
  DAT_009519f4 = FUN_00552670(&DAT_00924878,&DAT_0092487c,0x80);
  DAT_009519ec = FUN_00552670(&DAT_00924878,&DAT_0092487c,0x80);
  _DAT_009519f0 = 0;
  FUN_0048a1a0(&DAT_00924878,DAT_0092487c);
  FUN_005b1080();
  FUN_005b11e0(&PTR_PTR_00802ea0);
  FUN_005b11e0(&PTR_PTR_00802ea8);
  FUN_005b11e0(&PTR_PTR_00802eb0);
  FUN_005b11e0(&PTR_PTR_00802eb8);
  DAT_0087b4d0 = &DAT_0095077c;
  FUN_00579e70(&DAT_007f44f8,&DAT_00924878,&DAT_0092487c,0x2ee,8000);
  FUN_00579bd0(&DAT_007f4358);
  FUN_004c9e10();
  _DAT_02913250 = DAT_00924878 + 0xf & 0xfffffff0;
  DAT_00924878 = _DAT_02913250 + 0x200;
  _DAT_02913268 = DAT_00924878 - _DAT_02913250;
  DAT_02913258 = &DAT_02913250;
  DAT_0291325c = &DAT_02913254;
  _DAT_02913264 = 0;
  _DAT_02913260 = 0;
  _DAT_02913254 = DAT_00924878;
  _memset(&DAT_0291326c,0,0x22c);
  FUN_005b16e0();
  if (DAT_00876580 == 0) {
    if (DAT_007f39e4 != 0) {
      FUN_0046a340();
      FUN_005a0480(&DAT_00924878,&DAT_0092487c,0x280,0xc);
      FUN_004642e0();
      FUN_00458440();
      DAT_00951c8c = &LAB_0042d740;
      DAT_00951c90 = FUN_0042d8e0;
      DAT_00951c94 = FUN_0042da00;
      DAT_00951c98 = FUN_0042da10;
      DAT_00951c9c = FUN_0042daa0;
      DAT_009543f0 = FUN_0042dca0;
      DAT_00951cc4 = FUN_0042dd50;
      DAT_00951ccc = FUN_0042dd80;
      DAT_00950bb8 = FUN_0042dda0;
      DAT_0093b1e8 = FUN_0042df30;
      goto LAB_004ca2c2;
    }
    FUN_0046a230(&DAT_00924878,&DAT_0092487c);
  }
  else {
    FUN_0046a150();
  }
  FUN_005a0480(&DAT_00924878,&DAT_0092487c,0x280,0xc);
  FUN_0045e2e0();
  FUN_00457f60();
LAB_004ca2c2:
  FUN_005b2380("movies\\movies.txt",&DAT_00924878,&DAT_0092487c);
  FUN_005c9ff0(FUN_005ca000);
  DAT_0093b274 = FUN_006307c0("chars\\chars.txt",&DAT_00924878,&DAT_0092487c,0x154,&DAT_0093b278,
                              0x120,&DAT_0093b284);
  FUN_0055b2d0(&DAT_00924878,&DAT_0092487c);
  FUN_0055b660("stuff\\icons\\",&DAT_00924878,&DAT_0092487c);
  FUN_00414340(&PTR_s_weirdo1_007f1b50);
  FUN_00599a10(&DAT_00924878,&DAT_0092487c);
  if (DAT_007f39e4 == 0) {
    DAT_007f1808 = DAT_007f17b8;
    DAT_007f180a = DAT_007f180c;
    ppuVar1 = &PTR_s_SuperJump_007f25a8;
  }
  else {
    DAT_007f1808 = DAT_007f185c;
    DAT_007f180a = DAT_007f1860;
    ppuVar1 = &PTR_DAT_007f25f0;
  }
  FUN_0055bbf0(ppuVar1);
  FUN_0056e000(&PTR_s_extratoggle_007f3d98);
  DAT_00802bd8 = (int)DAT_007f1808;
  DAT_00802bdc = (int)DAT_007f180a;
  FUN_0055c080(&PTR_s_weirdo_007f3a80,0x17);
  DAT_00951b78 = FUN_005788f0("levels\\levels.txt",&DAT_00924878,&DAT_0092487c,0x16d,&DAT_00951b84,
                              FUN_0048f520);
  FUN_0048da50(&PTR_s_losttemple_c_007fa790);
  DAT_00951354 = FUN_00572b00("levels\\areas.txt",&DAT_00924878,&DAT_0092487c,0x48,&DAT_00951360);
  FUN_0048f670();
  DAT_00956290 = FUN_0059b360("levels\\episodes.txt",&DAT_00924878,&DAT_0092487c,6,&DAT_00956294);
  FUN_0042abf0();
  FUN_0042e160();
  if (DAT_007f39e4 == 0) {
    FUN_0057a870("cut\\cutscenes.txt",&DAT_00924878,DAT_0092487c);
  }
  FUN_00630b40(&DAT_00924878,DAT_0092487c,DAT_0093b278,0x30,0xe9,0x400,DAT_0093b274,FUN_00595e00);
  FUN_006306e0(PTR_PTR_007fbec8,&PTR_DAT_007fbed0);
  DAT_0095df4c = FUN_005aafb0(&DAT_00924878,&DAT_0092487c,0x40);
  DAT_00924878 = DAT_00924878 + 0xf & 0xfffffff0;
  if (DAT_007f39e4 != 0) {
    FUN_00564a20("stuff\\starfield.gsc",&DAT_00924878,&DAT_0092487c);
  }
  FUN_0048a6a0();
  FUN_0048abf0();
  FUN_005b16c0();
  FUN_00578740();
  local_18 = 0x3b;
  local_17 = 0x3c;
  local_16 = 1;
  local_15 = 0;
  if (DAT_00921ea0 == 0) {
    local_14 = DAT_00921e8c;
  }
  else {
    local_14 = DAT_00921ea0;
  }
  local_4 = &local_18;
  local_10 = FUN_004c9e70;
  local_c = 0;
  local_8 = FUN_00401140;
  FUN_00421320(&local_14,&DAT_00924878,&DAT_0092487c);
  FUN_006d4dd0(FUN_0050c140);
  FUN_006d6d90(&LAB_004011b0);
  DAT_00924878 = DAT_00924878 + 0xf & 0xfffffff0;
  DAT_007fce84 = 1;
  return;
}

