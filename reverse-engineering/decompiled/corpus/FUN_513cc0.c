/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x513cc0; label: FUN_00513cc0
 */

undefined4 * FUN_00513cc0(int param_1,uint *param_2)

{
  size_t sVar1;
  int iVar2;
  int *in_EAX;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_c;
  
  if (((in_EAX != (int *)0x0) && (param_2 != (uint *)0x0)) && (*in_EAX + 0x24U < *param_2)) {
    uVar5 = *in_EAX + 0xf;
    puVar7 = (undefined4 *)(uVar5 & 0xfffffff0);
    *in_EAX = (uVar5 & 0xfffffff0) + 0x24;
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = 0;
    puVar7[3] = 0;
    puVar7[4] = 0;
    puVar7[5] = 0;
    puVar7[6] = 0;
    puVar7[7] = 0;
    puVar7[8] = 0;
    if (puVar7 != (undefined4 *)0x0) {
      uVar3 = FUN_00513100(*(undefined4 *)(param_1 + 0x18),param_2);
      puVar7[6] = uVar3;
      FUN_00513990(param_1 + 8,puVar7 + 2);
      FUN_00513b30(param_1 + 0x10,puVar7 + 4);
      for (iVar4 = FUN_004f1440(param_1 + 0x1c); iVar4 != 0;
          iVar4 = FUN_004f1460(param_1 + 0x1c,iVar4)) {
        if (*in_EAX + 0x24U < *param_2) {
          uVar5 = *in_EAX + 0xf;
          puVar8 = (undefined4 *)(uVar5 & 0xfffffff0);
          *in_EAX = (uVar5 & 0xfffffff0) + 0x24;
          *puVar8 = 0;
          puVar8[1] = 0;
          puVar8[2] = 0;
          puVar8[3] = 0;
          puVar8[4] = 0;
          puVar8[5] = 0;
          puVar8[6] = 0;
          puVar8[7] = 0;
          puVar8[8] = 0;
          if (puVar8 != (undefined4 *)0x0) {
            iVar2 = *(int *)(iVar4 + 8);
            local_c = (void *)0x0;
            if ((iVar2 != 0) && (iVar6 = FUN_004f1ff0(iVar2), iVar6 != 0)) {
              sVar1 = iVar6 + 1;
              local_c = (void *)0x0;
              if (*in_EAX + sVar1 < *param_2) {
                local_c = (void *)(*in_EAX + 0xfU & 0xfffffff0);
                *in_EAX = (*in_EAX + 0xfU & 0xfffffff0) + sVar1;
                _memset(local_c,0,sVar1);
              }
              else {
                FUN_00512850();
              }
              FUN_004f1f10(local_c,iVar2);
            }
            puVar8[2] = local_c;
            iVar2 = *(int *)(iVar4 + 0x10);
            local_c = (void *)0x0;
            if ((iVar2 != 0) && (iVar6 = FUN_004f1ff0(iVar2), iVar6 != 0)) {
              sVar1 = iVar6 + 1;
              local_c = (void *)0x0;
              if (*in_EAX + sVar1 < *param_2) {
                local_c = (void *)(*in_EAX + 0xfU & 0xfffffff0);
                *in_EAX = (*in_EAX + 0xfU & 0xfffffff0) + sVar1;
                _memset(local_c,0,sVar1);
              }
              else {
                FUN_00512850();
              }
              FUN_004f1f10(local_c,iVar2);
            }
            puVar8[4] = local_c;
            puVar8[6] = puVar8[6] ^ (puVar8[6] ^ *(uint *)(iVar4 + 0x18)) & 1;
            puVar8[6] = (*(uint *)(iVar4 + 0x18) ^ puVar8[6]) & 2 ^ puVar8[6];
            FUN_00513990(iVar4 + 0x1c,puVar8 + 7);
            FUN_004f1310(puVar7 + 7,puVar8);
          }
        }
        else {
          FUN_00512850();
        }
      }
    }
    return puVar7;
  }
  puVar7 = (undefined4 *)FUN_00512850();
  return puVar7;
}

