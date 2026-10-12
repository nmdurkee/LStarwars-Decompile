/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63e290; label: FUN_0063e290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063e290(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 in_ECX;
  
  FUN_006be5c0("Light",in_ECX,0x8400000);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = FUN_00633440(0x10,1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_006ba1f0();
    }
    FUN_006c5da0("String",&DAT_00758a60,0x80000002,0x40,0x10000002,uVar3,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006c5da0("Short","LEDFile",0x80,0,0x10000100,0,0);
  }
  FUN_006c67e0(uVar3);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_0076b64c;
      puVar4[4] = &PTR_s_AMBIENT_0080fd98;
    }
    FUN_006c5da0(&DAT_0076be6c,&DAT_00763b1c,0x80000004,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_00633440(0x10,1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_006ba3b0();
    }
    uVar3 = FUN_006c5da0("Colour3","Hi Col",0x24,0,0,uVar3,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_00633440(0x10,1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_006ba3b0();
    }
    uVar3 = FUN_006c5da0("Colour3","Lo Col",0x30,0,0,uVar3,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0076bd7c;
      puVar1[6] = 0x3dcccccd;
      puVar1[7] = 0x42fe0000;
      puVar1[4] = DAT_02973ab4;
      puVar1[5] = &DAT_0076bd70;
    }
    uVar3 = FUN_006c5da0("Float","Multiplier",0x6c,0,0,puVar1,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0076bd7c;
      puVar1[6] = 0xce6e6b28;
      puVar1[7] = 0x4e6e6b28;
      puVar1[4] = DAT_02973ab4;
      puVar1[5] = &DAT_0076bd70;
    }
    uVar3 = FUN_006c5da0("Float","High Time",0x44,0,0,puVar1,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0076bd7c;
      puVar1[6] = 0xce6e6b28;
      puVar1[7] = 0x4e6e6b28;
      puVar1[4] = DAT_02973ab4;
      puVar1[5] = &DAT_0076bd70;
    }
    uVar3 = FUN_006c5da0("Float","High Rand",0x48,0,0,puVar1,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0076bd7c;
      puVar1[6] = 0xce6e6b28;
      puVar1[7] = 0x4e6e6b28;
      puVar1[4] = DAT_02973ab4;
      puVar1[5] = &DAT_0076bd70;
    }
    uVar3 = FUN_006c5da0("Float","Low Time",0x4c,0,0,puVar1,0);
  }
  FUN_006c67e0(uVar3);
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0076bd7c;
      puVar1[6] = 0xce6e6b28;
      puVar1[7] = 0x4e6e6b28;
      puVar1[4] = DAT_02973ab4;
      puVar1[5] = &DAT_0076bd70;
    }
    uVar3 = FUN_006c5da0("Float","Low Rand",0x50,0,0,puVar1,0);
  }
  FUN_006c67e0(uVar3);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = FUN_00633440(0x34,1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_006b9a70();
    }
    FUN_006c5da0("VuMtx","Pos/Rot",0x80000003,0,0x18,uVar3,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_0076bd7c;
      puVar4[6] = 0xce6e6b28;
      puVar4[7] = 0x4e6e6b28;
      puVar4[4] = DAT_02973ab4;
      puVar4[5] = &DAT_0076bd70;
    }
    FUN_006c5da0("Float","Inner",0x80000008,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_0076bd7c;
      puVar4[6] = 0xce6e6b28;
      puVar4[7] = 0x4e6e6b28;
      puVar4[4] = DAT_02973ab4;
      puVar4[5] = &DAT_0076bd70;
    }
    FUN_006c5da0("Float","Outer",0x80000009,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x18,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[4] = &PTR_PTR_0081f954;
      *puVar4 = &PTR_FUN_0076b668;
      puVar4[5] = 0xffff;
    }
    FUN_006c5da0(&DAT_0076be6c,"Associate IDs",0x8000000a,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x18,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[4] = &PTR_PTR_0081f954;
      *puVar4 = &PTR_FUN_0076b668;
      puVar4[5] = 0xffff;
    }
    FUN_006c5da0(&DAT_0076be6c,"Exclude IDs",0x8000000b,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[6] = 0;
      puVar4[7] = 0x10;
      *puVar4 = &PTR_FUN_0076bd58;
      puVar4[4] = DAT_02973ab0;
      puVar4[5] = &DAT_0075c058;
    }
    FUN_006c5da0(&DAT_0076be6c,"User ID",0x8000000c,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[6] = 0;
      puVar4[7] = 0xff;
      *puVar4 = &PTR_FUN_0076bd58;
      puVar4[4] = DAT_02973ab0;
      puVar4[5] = &DAT_0075c058;
    }
    FUN_006c5da0(&DAT_0076be6c,"Group ID",0x8000000d,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x20,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[6] = 0;
      puVar4[7] = 0x20;
      *puVar4 = &PTR_FUN_0076bd58;
      puVar4[4] = DAT_02973ab0;
      puVar4[5] = &DAT_0075c058;
    }
    FUN_006c5da0(&DAT_0076be6c,"Modifier Id",0x8000000e,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_0076b64c;
      puVar4[4] = &PTR_PTR_0081f954;
    }
    FUN_006c5da0(&DAT_0076be6c,"Cast Shadows",0x80000006,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
  }
  FUN_006c67e0(puVar1);
  puVar1 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_0076b64c;
      puVar4[4] = &PTR_PTR_0081f954;
    }
    FUN_006c5da0(&DAT_0076be6c,"Specular",0x80000007,0,0,puVar4,0);
    *puVar1 = &PTR_FUN_0076b780;
    FUN_006c67e0(puVar1);
    return;
  }
  FUN_006c67e0(0);
  return;
}

