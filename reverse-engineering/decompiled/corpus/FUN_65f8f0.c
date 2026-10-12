/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x65f8f0; label: FUN_0065f8f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f8f0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
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
  
  local_48 = _DAT_02961ff0 - 0.5;
  local_30 = 0xffffffff;
  local_44 = _DAT_02961ff4;
  local_c = 0xffffffff;
  local_40 = _DAT_02961ff8;
  local_24 = _DAT_02961ff0 + 0.5;
  local_20 = _DAT_02961ff4;
  local_1c = _DAT_02961ff8;
  FUN_005dbed0(&local_48,DAT_02961ffc,0);
  local_48 = _DAT_02961ff0;
  local_44 = _DAT_02961ff4 - 0.5;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_02961ff8;
  local_24 = _DAT_02961ff0;
  local_20 = _DAT_02961ff4 + 0.5;
  local_1c = _DAT_02961ff8;
  FUN_005dbed0(&local_48,DAT_02961ffc,0);
  local_48 = _DAT_02961ff0;
  local_44 = _DAT_02961ff4;
  local_30 = 0xffffffff;
  local_c = 0xffffffff;
  local_40 = _DAT_02961ff8 - 0.5;
  local_24 = _DAT_02961ff0;
  local_20 = _DAT_02961ff4;
  local_1c = _DAT_02961ff8 + 0.5;
  FUN_005dbed0(&local_48,DAT_02961ffc,0);
  local_60 = 0.0;
  local_5c = 0.5;
  local_58 = 0.0;
  FUN_005b3690(&local_60,&local_60,DAT_029629ec);
  FUN_005b3620(&local_60,&local_60,DAT_029629f0);
  local_48 = _DAT_02961ff0;
  local_44 = _DAT_02961ff4;
  local_40 = _DAT_02961ff8;
  local_30 = 0xff0000ff;
  local_24 = local_60 + _DAT_02961ff0;
  local_c = 0xff0000ff;
  local_20 = _DAT_02961ff4 + local_5c;
  local_1c = _DAT_02961ff8 + local_58;
  FUN_005dbed0(&local_48,DAT_02961ffc,0);
  if (DAT_02921884 == -1) {
    FUN_0065c160(&DAT_02961ff0,_DAT_02948ee8,_DAT_02948ee8,0xff0000ff,DAT_02961ffc,DAT_029629ec,
                 DAT_029629f0);
  }
  else {
    iVar2 = DAT_02962a14 + DAT_02921884 * 0x50;
    if (*(char *)(iVar2 + 0x27) == '\x03') {
      FUN_0065c160(&DAT_02961ff0,0x3f000000,0x3f000000,0xff0000ff,DAT_02961ffc,DAT_029629ec,
                   DAT_029629f0);
    }
    else {
      cVar1 = *(char *)(iVar2 + 0x25);
      if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
        FUN_0065bb50(_DAT_02961ff0,_DAT_02961ff4,_DAT_02961ff8,_DAT_02948ee8,0,_DAT_02948ee8,0,0,0,
                     DAT_029629ec,DAT_029629f0,0xff0000ff,DAT_02961ffc);
      }
      else {
        FUN_0065c2f0(&DAT_02961ff0,_DAT_02948ee8,0xff0000ff,DAT_02961ffc,DAT_029629ec,DAT_029629f0);
      }
    }
  }
  FUN_005db880(0x1720,0x9b0,0xdc0,0x410,0x80808080,DAT_02961fe8);
  FUN_005db880(0x1710,0x8f0,0xde0,0xc0,0x80000000,DAT_02961fe8);
  FUN_005db5b0(0x1710,0x9b0,0x1710,0xdc8,0x80000000,DAT_02961fe8);
  FUN_005db5b0(0x24f0,0x9b0,0x24f0,0xdc8,0x80000000,DAT_02961fe8);
  FUN_005db5b0(0x1710,0xdc8,0x24f0,0xdc8,0x80000000,DAT_02961fe8);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d1060(DAT_009738b8,0xe0e0e0e0);
  FUN_005f35e0(DAT_009738b8,0x17c0,0x988,0x10,"Info Box");
  FUN_005d1060(DAT_009738b8,0x80000000);
  if (DAT_00810a90 == -1) {
    if (DAT_029211ec == -1) {
      FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Curr Inst: <none>");
    }
    else {
      FUN_005da860(local_54,DAT_02962114,DAT_029211ec);
      uVar3 = FUN_005cfa50(local_54);
      FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Curr Inst: %s",uVar3);
    }
  }
  else {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xa50,0x10,"Copy Clump Mode");
  }
  if (DAT_00810a88 == 3) {
    if (DAT_02921884 == -1) {
      FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Clump Size: -");
    }
    else {
      FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Clump Size: %d/%d",
                   *(undefined4 *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14),DAT_02962a10);
    }
  }
  else {
    FUN_005f35e0(DAT_009738b8,0x17c0,0xaf0,0x10,"Base Size: %0.2f",(double)_DAT_02948ee8);
    FUN_005f35e0(DAT_009738b8,0x17c0,0xb90,0x10,"Clump Size: %d",DAT_0292318c);
  }
  FUN_005f35e0(DAT_009738b8,0x17c0,0xc30,0x10,"Used: %d/%d,%d/%d",DAT_029629d8,0x3000,DAT_029629e0,
               DAT_02962a08);
  if (DAT_029629f4 == 0) {
    pcVar4 = "Dpad Mode: Size";
  }
  else {
    if (DAT_029629f4 != 1) goto LAB_0065feac;
    pcVar4 = "Dpad Mode: Tilt";
  }
  FUN_005f35e0(DAT_009738b8,0x17c0,0xcd0,0x10,pcVar4);
LAB_0065feac:
  FUN_005f35e0(DAT_009738b8,0x17c0,0xd70,0x10,"%5.2f",(double)_DAT_02961ff0);
  FUN_005f35e0(DAT_009738b8,0x1c20,0xd70,0x10,"%5.2f",(double)_DAT_02961ff4);
  FUN_005f35e0(DAT_009738b8,0x2080,0xd70,0x10,"%5.2f",(double)_DAT_02961ff8);
  FUN_005d08c0();
  FUN_005d0a70();
  return;
}

