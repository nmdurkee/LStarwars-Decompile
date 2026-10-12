/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65cb00; label: FUN_0065cb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065cb00(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  size_t sVar5;
  undefined1 local_24 [12];
  char local_18 [19];
  undefined1 local_5;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  iVar3 = 0;
  pcVar1 = &DAT_02947df8;
  do {
    if (pcVar1[-0x44] != -1) {
      iVar3 = iVar3 + 1;
    }
    if (*pcVar1 != -1) {
      iVar3 = iVar3 + 1;
    }
    if (pcVar1[0x44] != -1) {
      iVar3 = iVar3 + 1;
    }
    if (pcVar1[0x88] != -1) {
      iVar3 = iVar3 + 1;
    }
    pcVar1 = pcVar1 + 0x110;
  } while ((int)pcVar1 < 0x2948ef8);
  FUN_006211c0(1);
  iVar2 = FUN_00621270(param_1,1);
  if (iVar2 != 0) {
    FUN_00621520(1);
    FUN_00621520(iVar3);
    puVar4 = &DAT_02947d9c;
    do {
      if (puVar4[0x18] != -1) {
        FUN_00621620(puVar4);
        FUN_006214d0(*(undefined4 *)(puVar4 + 0xc));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x10));
        FUN_006215a0(*(undefined2 *)(puVar4 + 0x14));
        FUN_006215a0(*(undefined2 *)(puVar4 + 0x16));
        FUN_00621600(puVar4[0x19]);
        FUN_00621600(puVar4[0x1a]);
        if (*(int *)(puVar4 + 0x1c) == -1) {
          local_18[0] = '\0';
        }
        else {
          FUN_005da860(local_24,DAT_02962114,*(int *)(puVar4 + 0x1c));
          sVar5 = 0x14;
          pcVar1 = (char *)FUN_005cfa50(local_24);
          _strncpy(local_18,pcVar1,sVar5);
        }
        local_5 = 0;
        FUN_00621440(local_18,0x14);
        if (*(int *)(puVar4 + 0x20) == -1) {
          local_18[0] = '\0';
        }
        else {
          FUN_005da860(local_24,DAT_02962114,*(int *)(puVar4 + 0x20));
          sVar5 = 0x14;
          pcVar1 = (char *)FUN_005cfa50(local_24);
          _strncpy(local_18,pcVar1,sVar5);
        }
        local_5 = 0;
        FUN_00621440(local_18,0x14);
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x24));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x28));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x2c));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x30));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x34));
        FUN_006214d0(*(undefined4 *)(puVar4 + 0x38));
        FUN_00621600(puVar4[0x3c]);
        FUN_00621600(puVar4[0x3d]);
        FUN_00621600(puVar4[0x3e]);
        FUN_00621600(puVar4[0x3f]);
      }
      puVar4 = puVar4 + 0x44;
    } while ((int)puVar4 < 0x2948e9c);
    FUN_006213e0();
    __security_check_cookie(local_4 ^ (uint)local_24);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

