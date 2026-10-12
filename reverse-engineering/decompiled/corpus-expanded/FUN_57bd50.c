/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57bd50; label: FUN_0057bd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057bd50(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 in_ECX;
  undefined2 *puVar3;
  int iVar4;
  uint *unaff_EDI;
  undefined1 local_200 [512];
  
  puVar3 = (undefined2 *)(in_EAX + 0x70);
  iVar4 = 6;
  _DAT_00951be4 = in_ECX;
  DAT_00951c38 = unaff_EDI;
  DAT_00951c4c = in_EAX;
  do {
    *puVar3 = 0xffff;
    puVar3 = puVar3 + 10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(byte *)(in_EAX + 0x18a) = *(byte *)(in_EAX + 0x18a) & 0xfc;
  *(undefined4 *)(in_EAX + 0x5c) = 0x41f00000;
  *(undefined2 *)(in_EAX + 0xea) = 0xffff;
  *(undefined4 *)(in_EAX + 0x18c) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x60) = 0x3f800000;
  *(undefined1 *)(in_EAX + 0xf3) = 2;
  *(undefined2 *)(in_EAX + 0xec) = 0xffff;
  *(undefined4 *)(in_EAX + 100) = 0;
  *(undefined4 *)(in_EAX + 0x50) = 3;
  *(undefined4 *)(in_EAX + 0x68) = 0;
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  *(undefined1 *)(in_EAX + 0x4c) = 0;
  *(undefined1 *)(in_EAX + 0xee) = 0;
  *(undefined1 *)(in_EAX + 0xf4) = 0;
  *(undefined1 *)(in_EAX + 0x104) = 0;
  *(undefined2 *)(in_EAX + 0xe8) = 0;
  *(undefined1 **)(in_EAX + 0x48) = local_200;
  *(undefined1 *)(in_EAX + 0xef) = 0xff;
  *(undefined1 *)(in_EAX + 0xf0) = 0xff;
  *(undefined1 *)(in_EAX + 0xf1) = 0xff;
  *(undefined1 *)(in_EAX + 0xf2) = 0xff;
  *(undefined4 *)(in_EAX + 0x148) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x150) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x158) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x160) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x170) = 0;
  *(undefined4 *)(in_EAX + 0x16c) = 0;
  *(undefined4 *)(in_EAX + 0x168) = 0;
  *(undefined4 *)(in_EAX + 0x164) = 0;
  *(undefined4 *)(in_EAX + 0x180) = 0;
  *(undefined4 *)(in_EAX + 0x17c) = 0;
  *(undefined4 *)(in_EAX + 0x178) = 0;
  *(undefined4 *)(in_EAX + 0x174) = 0;
  *(undefined4 *)(in_EAX + 0x184) = 0;
  *(undefined2 *)(in_EAX + 0x188) = 0;
  *(undefined1 *)(in_EAX + 0x18b) = 0;
  iVar4 = FUN_004fc860(param_1);
  if (iVar4 == 0) {
    FUN_0057a820(param_1);
    return;
  }
  DAT_00951c08 = 0;
  DAT_00951bf4 = 0;
  FUN_004f10e0(iVar4,&PTR_s_fpsec_00803e18);
  iVar1 = FUN_004fc5b0(iVar4);
  while (iVar1 != 0) {
    iVar1 = FUN_004f7fb0(iVar4);
    if (iVar1 != 0) {
      FUN_004fa020(iVar4);
    }
    iVar1 = FUN_004fc5b0(iVar4);
  }
  FUN_004fa300(iVar4);
  iVar4 = DAT_00951c4c;
  if (*(byte *)(DAT_00951c4c + 0xf1) < *(byte *)(DAT_00951c4c + 0xf0)) {
    *(byte *)(DAT_00951c4c + 0xf0) = *(byte *)(DAT_00951c4c + 0xf1);
  }
  if ((*(int *)(iVar4 + 0x184) != 0) && (*(short *)(iVar4 + 0x188) == 0)) {
    *(undefined4 *)(iVar4 + 0x184) = 0;
  }
  if (*(char *)(iVar4 + 0x4c) != '\0') {
    uVar2 = *unaff_EDI + 3 & 0xfffffffc;
    *unaff_EDI = uVar2;
    *(uint *)(iVar4 + 0x48) = uVar2;
    iVar4 = (uint)*(byte *)(iVar4 + 0x4c) * 0x10;
    FUN_004ef660(uVar2,local_200,iVar4);
    *unaff_EDI = *unaff_EDI + iVar4;
    return;
  }
  *(undefined4 *)(iVar4 + 0x48) = 0;
  return;
}

