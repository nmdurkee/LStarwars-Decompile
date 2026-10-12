/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48afe0; label: FUN_0048afe0
 */

void FUN_0048afe0(void)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined2 *local_10c;
  undefined4 *local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  uVar5 = DAT_00951ba0;
  uVar3 = DAT_00803784;
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  if (DAT_00803784 != 0xffffffff) {
    if (DAT_00803784 != DAT_0095121c) {
      DAT_00924890 = DAT_00924890 + 3 & 0xfffffffc;
      FUN_004f1f10(local_104,"levels\\");
      iVar7 = uVar3 * 0x9c;
      FUN_004f1e80(local_104,iVar7 + DAT_00951354);
      FUN_004f1e80(local_104,&DAT_0075a204);
      FUN_004f1e80(local_104,iVar7 + 0x40 + DAT_00951354);
      FUN_004f1e80(local_104,&DAT_0075a1fc);
      FUN_006d34c0(*(char *)(iVar7 + 0x86 + DAT_00951354) + 1);
      DAT_0092489c = FUN_005ef7f0(&DAT_00924890,DAT_00924894,local_104);
      FUN_006d34c0(0);
      if ((DAT_0092489c != 0) && (*(int *)(DAT_0092489c + 0x110) != 0)) {
        puVar1 = (uint *)(*(int *)(DAT_0092489c + 0x110) + 0x74);
        *puVar1 = *puVar1 | 0x10;
      }
    }
    if (((*(byte *)(uVar3 * 0x9c + 0x7a + DAT_00951354) & 5) != 0) && (uVar3 != DAT_0095121c)) {
      DAT_00924890 = DAT_00924890 + 3 & 0xfffffffc;
      DAT_00924898 = FUN_005ef7f0(&DAT_00924890,DAT_00924894,"stuff\\vehicle_things.gsc");
      if ((DAT_00924898 != 0) && (*(int *)(DAT_00924898 + 0x110) != 0)) {
        puVar1 = (uint *)(*(int *)(DAT_00924898 + 0x110) + 0x74);
        *puVar1 = *puVar1 | 0x10;
      }
    }
  }
  if (((DAT_00951364 != 0) && (uVar3 == *(byte *)(DAT_00951364 + 0x7c))) && (uVar3 != DAT_0095121c))
  {
    DAT_00924890 = DAT_00924890 + 0x3f & 0xffffffc0;
    DAT_009248a0 = FUN_005ef7f0(&DAT_00924890,DAT_00924894,"stuff\\icons\\starwars_icons_all.gsc");
    if ((DAT_009248a0 != 0) && (*(int *)(DAT_009248a0 + 0x110) != 0)) {
      puVar1 = (uint *)(*(int *)(DAT_009248a0 + 0x110) + 0x74);
      *puVar1 = *puVar1 | 0x10;
    }
  }
  if (DAT_0087a9c8 == 0) {
    if ((uVar3 == 0xffffffff) || (uVar3 != DAT_0095121c)) {
      FUN_0048af40(&local_10c);
      if (local_108 != (undefined4 *)0x0) goto LAB_0048b2d8;
    }
    else {
      local_108 = (undefined4 *)0x0;
      local_10c = (undefined2 *)0x0;
    }
    DAT_0087aa30 = 2;
    goto LAB_0048b263;
  }
  if ((*(byte *)(uVar3 * 0x9c + 0x7a + DAT_00951354) & 1) == 0) {
    if ((DAT_00951078 < 2) || (DAT_00951154 != 0)) {
      iVar6 = (int)DAT_007f180a;
      iVar7 = (int)DAT_007f1808;
    }
    else {
      iVar6 = (int)DAT_0095125c;
      iVar7 = (int)DAT_00951258;
    }
  }
  else {
    iVar6 = (int)DAT_0095125c;
    iVar7 = (int)DAT_00951258;
  }
  FUN_00489150(iVar7,iVar6,uVar3,uVar5,0);
  local_108 = &DAT_0087a840;
  local_10c = &DAT_00951090;
  DAT_0087a9c8 = 0;
LAB_0048b2d8:
  puVar4 = local_108;
  DAT_00951370 = local_108;
  FUN_0055b6e0(local_108,1,&DAT_00924890,&DAT_00924894);
  if ((DAT_00951364 == 0) || (uVar3 != *(byte *)(DAT_00951364 + 0x7c))) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  FUN_00592760(DAT_00856980,uVar5);
  if ((DAT_0087b02c == 0) || (uVar3 != *(byte *)(DAT_0087b02c + 0x7c))) {
    if (((uVar3 != 0xffffffff) && ((*(byte *)(uVar3 * 0x9c + 0x7a + DAT_00951354) & 0x62) == 0)) &&
       ((((cVar2 = *(char *)(uVar3 * 0x9c + DAT_00951354 + 0x86), -1 < cVar2 && (cVar2 < '\x03')) ||
         ((DAT_0087b020 != 0 && (uVar3 == *(byte *)(DAT_0087b020 + 0x7c))))) ||
        (((DAT_0087af5c != 0 && (uVar3 == *(byte *)(DAT_0087af5c + 0x7c))) ||
         ((DAT_0087b01c != 0 && (uVar3 == *(byte *)(DAT_0087b01c + 0x7c))))))))) {
      pcVar8 = "stuff\\char_lsw1.ptl";
      goto LAB_0048b398;
    }
  }
  else {
    pcVar8 = "levels\\losttemple\\losttemple.ptl";
LAB_0048b398:
    FUN_005a8150(pcVar8);
  }
  DAT_029130ec = (uint)(DAT_009553cc == 0);
  FUN_0062d500();
  DAT_0087aa30 = 1;
  FUN_0055bdc0(puVar4,0,&DAT_00924890,&DAT_00924894,1,uVar3);
  DAT_0087aa30 = 2;
  FUN_0055b460(puVar4,&DAT_00924890,DAT_00924894);
  if ((DAT_00951364 == 0) || (uVar3 != *(byte *)(DAT_00951364 + 0x7c))) {
    FUN_00592a70(DAT_00856980,puVar4);
  }
  FUN_00593570(DAT_00856980);
LAB_0048b263:
  if (local_10c != (undefined2 *)0x0) {
    DAT_00951374 = local_10c;
  }
  if (DAT_0087b2e0 != 0) {
    DAT_0093d848 = DAT_00951ba0;
    DAT_0093d840 = 0;
    FUN_00560630(0);
  }
  DAT_007fa5f0 = 1;
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

