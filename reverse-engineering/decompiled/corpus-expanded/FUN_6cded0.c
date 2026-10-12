/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cded0; label: FUN_006cded0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cded0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar4 = (undefined4 *)(DAT_02973b90 + DAT_02973bac * 0x18);
  DAT_02973bac = DAT_02973bac + 1;
  *puVar4 = "SceneObject";
  puVar4[5] = in_ECX;
  puVar4[1] = 0x100;
  if (in_ECX != 0) {
    *(undefined4 **)(in_ECX + 4) = puVar4;
  }
  iVar2 = FUN_00633440(0x28,1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006c5da0("Placeable","Placeable",0,0,0,0,0);
  }
  FUN_006c67e0(uVar3);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_0076f960;
      puVar5[4] = 0;
    }
    FUN_006c5da0("NuHSpecial","Object",0x80000008,0,0,puVar5,0);
    *puVar4 = &PTR_FUN_0076fb54;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_0076b64c;
      puVar5[4] = &PTR_PTR_0081f954;
    }
    FUN_006c5da0(&DAT_0076be6c,"Visible",0x80000009,0,0,puVar5,0);
    *puVar4 = &PTR_FUN_0076fb54;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_00633440(0x14,1);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_0076b64c;
      puVar5[4] = &PTR_PTR_0081f954;
    }
    FUN_006c5da0(&DAT_0076be6c,"Collision",0x8000000a,0,0,puVar5,0);
    *puVar4 = &PTR_FUN_0076fb54;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_006c5da0(&DAT_0076be6c,"Attributes",0x80000002,0,0x10400000,0,0);
    *puVar4 = &PTR_FUN_0076fc4c;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_006c5da0("Short","LEDFile",0x80000001,0,0x10400000,0,0);
    *puVar4 = &PTR_FUN_0076fc4c;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_006c5da0("String",&DAT_00758a60,0x80000003,0xfa,0x10400000,0,0);
    *puVar4 = &PTR_FUN_0076fc4c;
  }
  FUN_006c67e0(puVar4);
  puVar4 = (undefined4 *)FUN_00633440(0x28,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_006c5da0("VuMtx",&PTR_DAT_0076ed6c,0x80000006,0,0x10400000,0,0);
    *puVar4 = &PTR_FUN_0076fc4c;
  }
  FUN_006c67e0(puVar4);
  iVar1 = DAT_02973b00;
  iVar2 = DAT_02973b00 * 8;
  DAT_02973b00 = DAT_02973b00 + 1;
  *(char **)(&DAT_02973b08 + iVar2) = "Scene Object";
  (&DAT_02973b0c)[iVar1 * 2] = in_ECX;
  *(int *)(in_ECX + 8) = DAT_02973b00;
  iVar2 = in_ECX + 0xc;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(int *)(in_ECX + 0x14) = DAT_02973af8;
  if (DAT_02973af8 != 0) {
    *(int *)(DAT_02973af8 + 4) = iVar2;
  }
  if (DAT_02973af4 == 0) {
    DAT_02973af4 = iVar2;
  }
  _DAT_02973afc = _DAT_02973afc + 1;
  DAT_02973af8 = iVar2;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  return;
}

