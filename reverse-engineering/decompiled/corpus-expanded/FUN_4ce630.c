/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4ce630; label: FUN_004ce630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ce630(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  int local_48;
  int local_44;
  undefined4 local_40 [16];
  
  if ((*(int *)((int)param_1 + 0x4680) != 0) &&
     (local_44 = 0, 0 < *(int *)(PTR_DAT_00802c54 + 0x4684))) {
    puVar6 = (ushort *)(*(int *)((int)param_1 + 0x4680) + 0x74);
    do {
      param_1 = puVar6 + 4;
      puVar4 = puVar6 + -0xc;
      local_48 = 2;
      puVar5 = puVar6;
      do {
        uVar1 = FUN_00550070(*puVar5,puVar5[2],0x40a00000);
        *puVar5 = uVar1;
        iVar2 = FUN_005cfac0(puVar4);
        if (iVar2 != 0) {
          puVar7 = param_1;
          puVar8 = local_40;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar8 = *(undefined4 *)puVar7;
            puVar7 = puVar7 + 2;
            puVar8 = puVar8 + 1;
          }
          uVar3 = (uint)*puVar5;
          if ((puVar6[-0x14] & 8) != 0) {
            uVar3 = -uVar3;
          }
          FUN_005b4dd0(local_40,uVar3);
          FUN_005ea570(puVar4,local_40);
          FUN_005ea660(puVar4);
        }
        param_1 = param_1 + 0x20;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 6;
        local_48 = local_48 + -1;
      } while (local_48 != 0);
      local_44 = local_44 + 1;
      puVar6 = puVar6 + 0x7e;
    } while (local_44 < *(int *)(PTR_DAT_00802c54 + 0x4684));
  }
  return;
}

