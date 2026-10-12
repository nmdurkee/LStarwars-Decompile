/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d990; label: FUN_0065d990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065d990(void)

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
  
  local_48 = _DAT_02924abc - 0.5;
  local_44 = _DAT_02924ac0;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_02924ac4;
  local_24 = _DAT_02924abc + 0.5;
  local_20 = _DAT_02924ac0;
  local_1c = _DAT_02924ac4;
  FUN_005dbed0(&local_48,DAT_02947d78,0);
  local_48 = _DAT_02924abc;
  local_44 = _DAT_02924ac0 - 0.5;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_02924ac4;
  local_24 = _DAT_02924abc;
  local_20 = _DAT_02924ac0 + 0.5;
  local_1c = _DAT_02924ac4;
  FUN_005dbed0(&local_48,DAT_02947d78,0);
  local_48 = _DAT_02924abc;
  local_44 = _DAT_02924ac0;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_02924ac4 - 0.5;
  local_24 = _DAT_02924abc;
  local_20 = _DAT_02924ac0;
  local_1c = _DAT_02924ac4 + 0.5;
  FUN_005dbed0(&local_48,DAT_02947d78,0);
  local_60 = _DAT_00810a28;
  local_5c = 0.0;
  local_58 = 0.0;
  FUN_005b3690(&local_60,&local_60,DAT_0296297c);
  FUN_005b3620(&local_60,&local_60,_DAT_02962980);
  local_48 = _DAT_02924abc;
  local_44 = _DAT_02924ac0;
  local_40 = _DAT_02924ac4;
  local_24 = local_60 + _DAT_02924abc;
  local_30 = 0xff0000ff;
  local_c = 0xff0000ff;
  local_20 = _DAT_02924ac0 + local_5c;
  local_1c = _DAT_02924ac4 + local_58;
  FUN_005dbed0(&local_48,DAT_02947d78,0);
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = _DAT_00810a2c;
  FUN_005b3690(&local_60,&local_60,DAT_0296297c);
  FUN_005b3620(&local_60,&local_60,_DAT_02962980);
  local_30 = 0xff0000ff;
  local_48 = _DAT_02924abc - local_60;
  local_44 = _DAT_02924ac0 - local_5c;
  local_40 = _DAT_02924ac4 - local_58;
  local_24 = _DAT_02924abc + local_60;
  local_20 = local_5c + _DAT_02924ac0;
  local_1c = _DAT_02924ac4 + local_58;
  local_c = 0xff0000ff;
  FUN_005dbed0(&local_48,DAT_02947d78,0);
  FUN_005db880(0x1720,0x9b0,0xdc0,0x410,0x80808080,DAT_02947c9c);
  FUN_005db880(0x1710,0x8f0,0xde0,0xc0,0x80000000,DAT_02947c9c);
  FUN_005db5b0(0x1710,0x9b0,0x1710,0xdc8,0x80000000,DAT_02947c9c);
  FUN_005db5b0(0x24f0,0x9b0,0x24f0,0xdc8,0x80000000,DAT_02947c9c);
  FUN_005db5b0(0x1710,0xdc8,0x24f0,0xdc8,0x80000000,DAT_02947c9c);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d1060(DAT_009738b8,0xe0e0e0e0);
  FUN_005f35e0(DAT_009738b8,0x17c0,0x988,0x10,"Info Box");
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (DAT_02920d80 == -1) {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Plank Inst: <none>");
  }
  else {
    FUN_005da860(local_54,DAT_02962114,DAT_02920d80);
    uVar1 = FUN_005cfa50(local_54);
    FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Plank Inst: %s",uVar1);
  }
  if (DAT_0292fdb4 == -1) {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"Post Inst: <none>");
  }
  else {
    FUN_005da860(local_54,DAT_02962114,DAT_0292fdb4);
    uVar1 = FUN_005cfa50(local_54);
    FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"Post Inst: %s",uVar1);
  }
  FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Planks (Interval): %d (%d)",_DAT_00810a30,
               _DAT_00810a34);
  FUN_005f35e0(DAT_009738b8,0x17c0,0xc30,0x10,"Used: %d/%d",DAT_02962974,0x40);
  FUN_005f35e0(DAT_009738b8,0x17c0,0xd70,0x10,"%5.2f",(double)_DAT_02924abc);
  FUN_005f35e0(DAT_009738b8,0x1c20,0xd70,0x10,"%5.2f",(double)_DAT_02924ac0);
  FUN_005f35e0(DAT_009738b8,0x2080,0xd70,0x10,"%5.2f",(double)_DAT_02924ac4);
  FUN_005d08c0();
  FUN_005d0a70();
  return;
}

