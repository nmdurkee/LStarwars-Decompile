/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46a450; label: FUN_0046a450
 */

undefined4
FUN_0046a450(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  float local_60;
  int local_5c;
  uint local_54;
  uint local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_60 = 1e+09;
  local_54 = 0;
  local_50 = 0;
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) && (param_3 != 0)) &&
     (uVar1 = FUN_0058b720(param_3), (uVar1 & 0x800) != 0)) {
    iVar5 = *param_1;
    local_5c = 0;
    if (0 < *DAT_0093b268) {
      puVar2 = (undefined4 *)(DAT_0093b268[2] + 0x70);
      uVar3 = local_c;
      uVar4 = local_8;
      do {
        if (((code *)*puVar2 != (code *)0x0) &&
           (uVar1 = (*(code *)*puVar2)(iVar5,&local_4c,&local_48,&local_3c,param_3,param_4,param_5,
                                       param_6,param_7,param_8,param_9,param_10), uVar1 != 0)) {
          if (uVar1 == *(uint *)(param_3 + 0xcc8)) {
            uStack_24 = local_48;
            uStack_20 = uStack_44;
            uStack_1c = uStack_40;
            uStack_18 = local_3c;
            uStack_14 = uStack_38;
            uStack_10 = uStack_34;
            local_50 = uVar1;
          }
          else if (local_4c < local_60) {
            local_60 = local_4c;
            uStack_4 = uStack_40;
            uStack_30 = local_3c;
            uStack_2c = uStack_38;
            uStack_28 = uStack_34;
            uVar3 = local_48;
            uVar4 = uStack_44;
            local_54 = uVar1;
          }
        }
        local_5c = local_5c + 1;
        puVar2 = puVar2 + 0x27;
        iVar5 = iVar5 + 0x14;
      } while (local_5c < *DAT_0093b268);
      if (local_54 != 0) {
        *(uint *)(param_3 + 0xe20) = *(uint *)(param_3 + 0xe20) | 0x800;
        *(undefined4 *)(param_3 + 0xc80) = uVar3;
        *(undefined4 *)(param_3 + 0xc84) = uVar4;
        *(undefined4 *)(param_3 + 0xc88) = uStack_4;
        *(undefined4 *)(param_3 + 0xc8c) = uStack_30;
        *(undefined4 *)(param_3 + 0xc90) = uStack_2c;
        *(undefined4 *)(param_3 + 0xc94) = uStack_28;
        *(uint *)(param_3 + 0xcc8) = ~-(uint)(DAT_00951288 != 0) & local_54;
        return 1;
      }
      if (local_50 != 0) {
        *(uint *)(param_3 + 0xe20) = *(uint *)(param_3 + 0xe20) | 0x800;
        *(undefined4 *)(param_3 + 0xc80) = uStack_24;
        *(undefined4 *)(param_3 + 0xc84) = uStack_20;
        *(undefined4 *)(param_3 + 0xc88) = uStack_1c;
        *(undefined4 *)(param_3 + 0xc8c) = uStack_18;
        *(undefined4 *)(param_3 + 0xc90) = uStack_14;
        *(undefined4 *)(param_3 + 0xc94) = uStack_10;
        *(uint *)(param_3 + 0xcc8) = ~-(uint)(DAT_00951288 != 0) & local_50;
        return 1;
      }
    }
  }
  return 0;
}

