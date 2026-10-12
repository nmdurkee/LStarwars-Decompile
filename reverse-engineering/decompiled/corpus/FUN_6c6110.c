/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6110; label: FUN_006c6110
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6110(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  DAT_02973aa8 = *(int *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 0x1c) = DAT_02973aa8 + 1;
  iVar2 = *(int *)(in_ECX + 4);
  *(undefined **)(iVar2 + DAT_02973aa8 * 0xc) = &DAT_0076da5c;
  *(undefined4 *)(iVar2 + 4 + DAT_02973aa8 * 0xc) = 1;
  *(undefined1 **)(iVar2 + 8 + DAT_02973aa8 * 0xc) = &LAB_006c5d20;
  DAT_02973aac = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973aac + 1;
  *(char **)(iVar2 + DAT_02973aac * 0xc) = "Short";
  *(undefined4 *)(iVar2 + 4 + DAT_02973aac * 0xc) = 2;
  *(undefined1 **)(iVar2 + 8 + DAT_02973aac * 0xc) = &LAB_006c5d40;
  DAT_02973ab0 = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973ab0 + 1;
  *(undefined **)(iVar2 + DAT_02973ab0 * 0xc) = &DAT_0076be6c;
  iVar2 = iVar2 + DAT_02973ab0 * 0xc;
  *(undefined4 *)(iVar2 + 4) = 4;
  *(undefined1 **)(iVar2 + 8) = &LAB_006c5d60;
  DAT_02973ab4 = *(int *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 0x1c) = DAT_02973ab4 + 1;
  iVar2 = *(int *)(in_ECX + 4);
  *(char **)(iVar2 + DAT_02973ab4 * 0xc) = "Float";
  *(undefined4 *)(iVar2 + 4 + DAT_02973ab4 * 0xc) = 4;
  *(undefined1 **)(iVar2 + 8 + DAT_02973ab4 * 0xc) = &LAB_006c5d80;
  DAT_02973ab8 = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973ab8 + 1;
  *(char **)(iVar2 + DAT_02973ab8 * 0xc) = "VuVec";
  *(undefined4 *)(iVar2 + 4 + DAT_02973ab8 * 0xc) = 0x10;
  *(undefined1 **)(iVar2 + 8 + DAT_02973ab8 * 0xc) = &LAB_006be0b0;
  DAT_02973abc = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973abc + 1;
  *(char **)(iVar2 + DAT_02973abc * 0xc) = "VuMtx";
  *(undefined1 **)(iVar2 + 8 + DAT_02973abc * 0xc) = &LAB_006be0d0;
  *(undefined4 *)(iVar2 + DAT_02973abc * 0xc + 4) = 0x40;
  _DAT_02973ac0 = *(int *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 0x1c) = _DAT_02973ac0 + 1;
  puVar1 = (undefined4 *)(*(int *)(in_ECX + 4) + _DAT_02973ac0 * 0xc);
  *puVar1 = &DAT_0076fae0;
  puVar1[1] = 4;
  puVar1[2] = &LAB_006c5d60;
  DAT_02973ac4 = *(int *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 0x1c) = DAT_02973ac4 + 1;
  iVar2 = *(int *)(in_ECX + 4);
  *(char **)(iVar2 + DAT_02973ac4 * 0xc) = "String";
  *(undefined4 *)(iVar2 + 4 + DAT_02973ac4 * 0xc) = 0xffffffff;
  *(undefined1 **)(iVar2 + 8 + DAT_02973ac4 * 0xc) = &LAB_006be130;
  DAT_02973ac8 = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973ac8 + 1;
  *(char **)(iVar2 + DAT_02973ac8 * 0xc) = "Colour3";
  *(undefined1 **)(iVar2 + 8 + DAT_02973ac8 * 0xc) = &LAB_006be170;
  *(undefined4 *)(iVar2 + DAT_02973ac8 * 0xc + 4) = 0xc;
  DAT_02973acc = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973acc + 1;
  *(undefined4 *)(iVar2 + 4 + DAT_02973acc * 0xc) = 0xc;
  *(char **)(iVar2 + DAT_02973acc * 0xc) = "NuHSpecial";
  *(undefined1 **)(iVar2 + 8 + DAT_02973acc * 0xc) = &LAB_006be190;
  DAT_02973ad0 = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  *(int *)(in_ECX + 0x1c) = DAT_02973ad0 + 1;
  *(undefined4 *)(iVar2 + 4 + DAT_02973ad0 * 0xc) = 0xc;
  *(char **)(iVar2 + DAT_02973ad0 * 0xc) = "NuVec";
  *(undefined1 **)(iVar2 + 8 + DAT_02973ad0 * 0xc) = &LAB_006be0f0;
  DAT_02973ad4 = *(int *)(in_ECX + 0x1c);
  *(int *)(in_ECX + 0x1c) = DAT_02973ad4 + 1;
  puVar1 = (undefined4 *)(*(int *)(in_ECX + 4) + DAT_02973ad4 * 0xc);
  puVar1[1] = 0x40;
  *puVar1 = "NuMtx";
  puVar1[2] = &LAB_006be110;
  return;
}

