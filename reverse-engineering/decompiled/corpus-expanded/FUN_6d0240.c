/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6d0240; label: FUN_006d0240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d0240(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint *puVar5;
  int local_54;
  undefined4 local_50;
  undefined **local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0x10ac) == 0) {
    return 0;
  }
  local_50 = 0;
  local_54 = 0;
  puVar5 = (uint *)(in_ECX + 0x350);
  do {
    FUN_006b9450();
    _sprintf((char *)(in_ECX + 0x94c),"%s/%s.led",puVar5 + -0x21,puVar5 + -0x29);
    if (((*puVar5 & 2) != 0) && ((char *)(in_ECX + 0x94c) != (char *)0x0)) {
      iVar1 = *(int *)(in_ECX + 0xa5c);
      *(int *)(in_ECX + 0xa58) = iVar1;
      iVar2 = FUN_004f02d0(iVar1,*(int *)(in_ECX + 0xa60) - iVar1,1);
      if (iVar2 != 0) {
        local_34 = 0;
        local_30 = 0;
        local_3c = 0;
        local_2c = 0;
        local_40 = 2;
        local_48 = &PTR_FUN_0076f9ac;
        local_8 = 0;
        local_44 = 4;
        local_4 = iVar2;
        iVar3 = FUN_006c8480("StreamInfo");
        if (iVar3 != 0) {
          (*(code *)local_48[2])(&local_44,4,1);
          (**(code **)(local_54 + 0x1c))();
        }
        local_38 = local_54;
        FUN_006cb820(&local_48);
        uVar4 = FUN_004f6d10(iVar2);
        local_4 = 0;
        FUN_004f99e0(iVar2);
        iVar2 = FUN_004fa5f0(in_ECX + 0x94c,1);
        if (iVar2 != 0) {
          FUN_004f03d0(iVar2,iVar1,uVar4);
          FUN_004f99e0(iVar2);
          *puVar5 = *puVar5 | 4;
          local_50 = 1;
          goto LAB_006d03ab;
        }
        *puVar5 = *puVar5 & 0xfffffffb;
      }
      FUN_006b7c50(in_ECX + 0x94c);
    }
LAB_006d03ab:
    local_54 = local_54 + 1;
    puVar5 = puVar5 + 0x2a;
    if (9 < local_54) {
      FUN_006b9490();
      return local_50;
    }
  } while( true );
}

