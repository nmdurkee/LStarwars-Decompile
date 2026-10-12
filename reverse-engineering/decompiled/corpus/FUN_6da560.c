/* Ghidra analysis pseudocode, not original source.
 * ev_7393eb289fae971e4c9d676939847dbe45fbc997f5b4ac5470a7ef95c2a601ec
 * Entry: 0x6da560; label: FUN_006da560
 */

void FUN_006da560(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  void *in_ECX;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  
  _memset((void *)((int)in_ECX + 0x4e34),0,0x14c8);
  _memset(in_ECX,0,0x2700);
  _memset((void *)((int)in_ECX + 0x2700),0,0x2700);
  _memset((void *)((int)in_ECX + 0x62fc),0,0x48);
  *(undefined4 *)((int)in_ECX + 0x68b0) = 0;
  _memset((void *)((int)in_ECX + 0x671c),0,0xc4);
  _memset((void *)((int)in_ECX + 0x6358),0,0x200);
  puVar1 = (undefined1 *)((int)in_ECX + 0x67f2);
  iVar4 = 0x20;
  do {
    puVar1[-2] = 0;
    *puVar1 = 0xff;
    puVar1[-1] = 0xff;
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1 = puVar1 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)((int)in_ECX + 0x67e4) = 0;
  FUN_006d3aa0();
  *(undefined4 *)((int)in_ECX + 0x4e00) = 0xffffffff;
  *(undefined1 *)((int)in_ECX + 0x671a) = 1;
  *(undefined4 *)((int)in_ECX + 0x4e08) = 0;
  *(undefined4 *)((int)in_ECX + 0x4e0c) = 0;
  iVar4 = 0;
  puVar1 = (undefined1 *)((int)in_ECX + 0x660c);
  do {
    *(undefined1 *)((int)in_ECX + iVar4 + 0x6345) = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[-0x94] = 0;
    puVar1[-0x96] = 0;
    puVar1[-0x95] = 0;
    iVar4 = iVar4 + 1;
    puVar1 = puVar1 + 10;
  } while (iVar4 < 0xe);
  *(undefined4 *)((int)in_ECX + 0x6608) = 0xffffffff;
  *(undefined1 *)((int)in_ECX + 0x67e0) = 0;
  *(undefined4 *)((int)in_ECX + 0x6604) = 0;
  *(undefined4 *)((int)in_ECX + 0x6354) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e12) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e13) = 0xff;
  puVar6 = (undefined2 *)((int)in_ECX + 0x4f24);
  iVar4 = 0xe;
  do {
    iVar5 = 0x20;
    puVar2 = puVar6;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar6 = puVar6 + 0xbe;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)((int)in_ECX + 0x6570) = 0x3dcccccd;
  *(undefined4 *)((int)in_ECX + 0x6568) = 0x1fff;
  *(undefined4 *)((int)in_ECX + 0x656c) = 0x20;
  *(undefined4 *)((int)in_ECX + 0x4e04) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e10) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e11) = 0;
  *(undefined1 *)((int)in_ECX + 0x67e1) = 0;
  FUN_006d96b0();
  if (DAT_029755a4 != (code *)0x0) {
    (*DAT_029755a4)();
  }
  FUN_006d9bd0();
  uVar3 = FUN_004f5240();
  switch(uVar3) {
  case 0:
    DAT_02975138 = &PTR_DAT_00820560;
    DAT_0297516c = &PTR_DAT_00820560;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00821910;
    return;
  case 1:
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__008211a0;
    break;
  case 2:
    DAT_02975138 = &PTR_s_BMD_Haut_00820aa0;
    DAT_0297516c = &PTR_s_BMD_Haut_00820aa0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00822080;
    return;
  case 3:
    DAT_02975138 = &PTR_DAT_00820d40;
    DAT_0297516c = &PTR_DAT_00820d40;
    PTR_PTR_00824f98 = (undefined *)&PTR_DAT_00822ae8;
    return;
  case 4:
    DAT_02975138 = &PTR_s_Steuerkreuz_oben_00820c60;
    DAT_0297516c = &PTR_s_Steuerkreuz_oben_00820c60;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__LEER__00822770;
    return;
  case 5:
    DAT_02975138 = &PTR_s_Tasto_direzionale_su_00820b80;
    DAT_0297516c = &PTR_s_Tasto_direzionale_su_00820b80;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__EMPTY__008223f8;
    return;
  case 6:
    DAT_02975138 = &PTR_s_Navigatiepad_Omhoog_00820640;
    DAT_0297516c = &PTR_s_Navigatiepad_Omhoog_00820640;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__008231d8;
    return;
  case 7:
    DAT_02975138 = &PTR_s_Direc__p__cima_008209c0;
    DAT_0297516c = &PTR_s_Direc__p__cima_008209c0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__008240b8;
    return;
  case 8:
    DAT_02975138 = &PTR_s_Hat_switch_Op_00820e20;
    DAT_0297516c = &PTR_s_Hat_switch_Op_00820e20;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__TOM__00822e60;
    return;
  default:
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00821558;
    break;
  case 10:
    DAT_02975138 = &PTR_DAT_008210c0;
    DAT_0297516c = &PTR_DAT_008210c0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__EMPTY__00821cc8;
    return;
  case 0xb:
    DAT_02975138 = &PTR_DAT_00820f00;
    DAT_0297516c = &PTR_DAT_00820f00;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00823590;
    return;
  case 0xc:
    DAT_02975138 = &PTR_DAT_00820fe0;
    DAT_0297516c = &PTR_DAT_00820fe0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00823948;
    return;
  case 0xe:
    DAT_02975138 = &PTR_s_Riktningsknapp_Upp_00820800;
    DAT_0297516c = &PTR_s_Riktningsknapp_Upp_00820800;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00824828;
    return;
  case 0xf:
    DAT_02975138 = &PTR_s_Hatteknapp_opp_00820720;
    DAT_0297516c = &PTR_s_Hatteknapp_opp_00820720;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00824470;
    return;
  case 0x10:
    DAT_02975138 = &PTR_s_Direc__p__cima_008209c0;
    DAT_0297516c = &PTR_s_Direc__p__cima_008209c0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00823d00;
    return;
  case 0x11:
    DAT_02975138 = &PTR_DAT_008208e0;
    DAT_0297516c = &PTR_DAT_008208e0;
    PTR_PTR_00824f98 = (undefined *)&PTR_s__empty__00824be0;
    return;
  }
  DAT_02975138 = &PTR_s_Hat_Up_00820480;
  DAT_0297516c = &PTR_s_Hat_Up_00820480;
  return;
}

