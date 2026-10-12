/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f6ab0; label: FUN_005f6ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6ab0(int param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  iVar4 = param_1 * 0x380 + in_ECX;
  puVar2 = (undefined4 *)(iVar4 + 0x2b8);
  if (((*(int *)(iVar4 + 0x2b8) != *(int *)(iVar4 + 0x2b4)) ||
      (*(int *)(iVar4 + 0x2fc) != *(int *)(iVar4 + 0x2f8))) || (*(int *)(iVar4 + 0x374) != 0)) {
    FUN_005f5e30(iVar4);
    FUN_00603aa0(1);
    local_80 = 0x3f800000;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_6c = 0x3f800000;
    local_58 = 0x3f000000;
    local_48 = 0x3f000000;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_44 = 0x3f800000;
    FUN_005c1240(local_40,iVar4 + 0x80,&local_80);
    FUN_005fa330(local_40,&DAT_00806680);
    local_84 = 2;
    do {
      puVar1 = (undefined1 *)*puVar2;
      if (puVar1 != (undefined1 *)puVar2[-1]) {
        *puVar1 = 0x84;
        *(undefined4 *)(puVar1 + 4) = 0;
        puVar1[1] = 4;
        _DAT_0080e690 = 0;
        FUN_006e5340(7,1);
        FUN_006e5340(0xe,1);
        FUN_006e5340(0x17,4);
        DAT_00986ea0 = DAT_00806630;
        DAT_00986ea4 = DAT_00806634;
        DAT_00986ea8 = DAT_00806638;
        DAT_00986eac = DAT_0080663c;
        FUN_007412e0(0x38,&DAT_00806630);
        FUN_006033d0(puVar2[-1]);
        *puVar2 = puVar2[-1];
      }
      puVar2 = puVar2 + 0x11;
      local_84 = local_84 + -1;
    } while (local_84 != 0);
    iVar3 = 0;
    if (0 < *(int *)(iVar4 + 0x374)) {
      puVar2 = (undefined4 *)(iVar4 + 0x354);
      do {
        FUN_005f02e0(*puVar2);
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < *(int *)(iVar4 + 0x374));
    }
    FUN_00603aa0(0);
  }
  return;
}

