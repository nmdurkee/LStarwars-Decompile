/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d0240; label: FUN_006d0240
 */

undefined4 FUN_006d0240(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint *puVar5;
  int iStack_54;
  undefined4 uStack_50;
  undefined **ppuStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_8;
  int iStack_4;
  
  if (*(int *)(in_ECX + 0x10ac) == 0) {
    return 0;
  }
  uStack_50 = 0;
  iStack_54 = 0;
  puVar5 = (uint *)(in_ECX + 0x350);
  do {
    FUN_006b9450();
    _sprintf((char *)(in_ECX + 0x94c),"%s/%s.led",puVar5 + -0x21,puVar5 + -0x29);
    if (((*puVar5 & 2) != 0) && ((char *)(in_ECX + 0x94c) != (char *)0x0)) {
      iVar1 = *(int *)(in_ECX + 0xa5c);
      *(int *)(in_ECX + 0xa58) = iVar1;
      iVar2 = FUN_004f02d0(iVar1,*(int *)(in_ECX + 0xa60) - iVar1,1);
      if (iVar2 != 0) {
        uStack_34 = 0;
        uStack_30 = 0;
        uStack_3c = 0;
        uStack_2c = 0;
        uStack_40 = 2;
        ppuStack_48 = &PTR_LAB_0076f9ac;
        uStack_8 = 0;
        uStack_44 = 4;
        iStack_4 = iVar2;
        iVar3 = FUN_006c8480("StreamInfo");
        if (iVar3 != 0) {
          (*(code *)ppuStack_48[2])(&uStack_44,4,1);
          (**(code **)(iStack_54 + 0x1c))();
        }
        iStack_38 = iStack_54;
        FUN_006cb820(&ppuStack_48);
        uVar4 = FUN_004f6d10(iVar2);
        iStack_4 = 0;
        FUN_004f99e0(iVar2);
        iVar2 = FUN_004fa5f0(in_ECX + 0x94c,1);
        if (iVar2 != 0) {
          FUN_004f03d0(iVar2,iVar1,uVar4);
          FUN_004f99e0(iVar2);
          *puVar5 = *puVar5 | 4;
          uStack_50 = 1;
          goto LAB_006d03ab;
        }
        *puVar5 = *puVar5 & 0xfffffffb;
      }
      FUN_006b7c50(in_ECX + 0x94c);
    }
LAB_006d03ab:
    iStack_54 = iStack_54 + 1;
    puVar5 = puVar5 + 0x2a;
    if (9 < iStack_54) {
      FUN_006b9490();
      return uStack_50;
    }
  } while( true );
}

