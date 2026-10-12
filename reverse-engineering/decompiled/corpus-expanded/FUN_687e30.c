/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x687e30; label: FUN_00687e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00687e30(void)

{
  undefined4 uVar1;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [12];
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  local_48 = _DAT_0292fda8 - 0.5;
  local_30 = 0xffffffff;
  local_44 = _DAT_0292fdac;
  local_c = 0xffffffff;
  local_40 = _DAT_0292fdb0;
  local_24 = _DAT_0292fda8 + 0.5;
  local_20 = _DAT_0292fdac;
  local_1c = _DAT_0292fdb0;
  FUN_005dbed0(&local_48,DAT_029211f4,0);
  local_48 = _DAT_0292fda8;
  local_44 = _DAT_0292fdac - 0.5;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_0292fdb0;
  local_24 = _DAT_0292fda8;
  local_20 = _DAT_0292fdac + 0.5;
  local_1c = _DAT_0292fdb0;
  FUN_005dbed0(&local_48,DAT_029211f4,0);
  local_48 = _DAT_0292fda8;
  local_44 = _DAT_0292fdac;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_0292fdb0 - 0.5;
  local_24 = _DAT_0292fda8;
  local_20 = _DAT_0292fdac;
  local_1c = _DAT_0292fdb0 + 0.5;
  FUN_005dbed0(&local_48,DAT_029211f4,0);
  if (DAT_02961f7c != 0) {
    local_60 = 0.0;
    local_5c = 0.375;
    local_58 = 0.0;
    FUN_005b3690(&local_60,&local_60,DAT_0296210c);
    FUN_005b3620(&local_60,&local_60,DAT_02962110);
    local_48 = _DAT_0292fda8;
    local_30 = 0xff0000ff;
    local_44 = _DAT_0292fdac;
    local_c = 0xff0000ff;
    local_40 = _DAT_0292fdb0;
    local_24 = local_60 + _DAT_0292fda8;
    local_20 = _DAT_0292fdac + local_5c;
    local_1c = _DAT_0292fdb0 + local_58;
    FUN_005dbed0(&local_48,DAT_029211f4,0);
  }
  FUN_005db880(0x1720,0xa50,0xdc0,0x370,0x80808080,DAT_02921190);
  FUN_005db880(0x1710,0x990,0xde0,0xc0,0x80000000,DAT_02921190);
  FUN_005db5b0(0x1710,0xa50,0x1710,0xdc8,0x80000000,DAT_02921190);
  FUN_005db5b0(0x24f0,0xa50,0x24f0,0xdc8,0x80000000,DAT_02921190);
  FUN_005db5b0(0x1710,0xdc8,0x24f0,0xdc8,0x80000000,DAT_02921190);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d1060(DAT_009738b8,0xe0e0e0e0);
  FUN_005f35e0(DAT_009738b8,0x17c0,0xa28,0x10,"Info Box");
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (DAT_02923194 == -1) {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"Curr Spcl: <none>");
  }
  else {
    FUN_005da860(local_54,DAT_02962114,DAT_02923194);
    uVar1 = FUN_005cfa50(local_54);
    FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"Curr Spcl: %s",uVar1);
  }
  if (DAT_02962010 == -1) {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Params: No");
    goto LAB_006882cb;
  }
  FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Params: Yes");
  if (DAT_02961f7c == 0) {
    if (DAT_02924af8 == 0) goto LAB_006882cb;
    FUN_005f35e0(DAT_009738b8,0x1810,0xc30,0x10,"Sounds: %d (Max %d)",
                 (&DAT_0292fe20)[DAT_02962010 * 0xb5],8);
    if (DAT_02924afc == -1) {
      FUN_005f35e0(DAT_009738b8,0x1810,0xcd0,0x10,"Select Type: <none>");
      goto LAB_006882cb;
    }
    uVar1 = 0;
  }
  else {
    FUN_005f35e0(DAT_009738b8,0x1810,0xc30,0x10,"Particles: %d (Max %d)",
                 (&DAT_0292fe1c)[DAT_02962010 * 0xb5],8);
    if (DAT_02924ac8 == -1) {
      FUN_005f35e0(DAT_009738b8,0x1810,0xcd0,0x10,"Select Type: <none>");
      goto LAB_006882cb;
    }
    uVar1 = *(undefined4 *)(DAT_0296209c + DAT_02924ac8 * 4);
  }
  FUN_005f35e0(DAT_009738b8,0x1810,0xcd0,0x10,CONCAT44(uVar1,"Select Type: %s"));
LAB_006882cb:
  FUN_005f35e0(DAT_009738b8,0x17c0,0xd70,0x10,"%5.2f",(double)_DAT_0292fda8);
  FUN_005f35e0(DAT_009738b8,0x1c20,0xd70,0x10,"%5.2f",(double)_DAT_0292fdac);
  FUN_005f35e0(DAT_009738b8,0x2080,0xd70,0x10,"%5.2f",(double)_DAT_0292fdb0);
  FUN_005d08c0();
  FUN_005d0a70();
  return;
}

