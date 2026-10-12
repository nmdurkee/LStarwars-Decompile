/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x581fb0; label: FUN_00581fb0
 */

undefined4
FUN_00581fb0(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_3;
  iVar4 = param_2;
  local_1c = *(undefined4 *)(param_2 + 0x80);
  local_18 = *(undefined4 *)(param_2 + 0x84);
  local_14 = *(undefined4 *)(param_2 + 0x88);
  param_2 = 2;
  uVar1 = param_6;
  do {
    if (((param_1[0x3c] & 0x200U) == 0) || (param_2 == 1)) {
      local_28 = *(undefined4 *)(iVar2 + param_2 * 0xc);
      iVar3 = iVar2 + param_2 * 0xc;
      local_24 = *(undefined4 *)(iVar3 + 4);
      local_20 = *(undefined4 *)(iVar3 + 8);
      if (((param_1[0x3c] & 0x8000000U) != 0) &&
         (*(float *)(*param_1 + 0x24) < (float)param_1[0x32] !=
          (*(float *)(*param_1 + 0x24) == (float)param_1[0x32]))) {
        local_18 = 0;
        local_24 = 0;
      }
      iVar3 = FUN_0054fce0(&local_1c,*(undefined4 *)(iVar4 + 0x1dc),*(undefined4 *)(iVar4 + 0x1e0),
                           &local_28,uVar1,uVar1);
      uVar1 = param_6;
      if (iVar3 != 0) {
        local_30 = (int)(param_1 + -0x25473a) / 0x138 & 0xffff;
        local_2c = (iVar4 - DAT_0093d504) / 0x10d8 & 0xffff;
        puVar5 = &DAT_028683e0;
        break;
      }
    }
    param_2 = param_2 + -1;
    if (param_2 < 0) {
      return 0;
    }
  } while( true );
  while (puVar5 = puVar5 + 0x4b4, puVar5 != &DAT_028febe0) {
    if (*(int *)(puVar5 + 0x4b0) == 0) {
      *(undefined4 *)(puVar5 + 0x4b0) = 1;
      goto LAB_0058210d;
    }
  }
  puVar5 = (undefined *)0x0;
LAB_0058210d:
  local_8 = 0x20;
  local_4 = 0x20;
  local_10 = 1;
  local_c = puVar5;
  if (puVar5 != (undefined *)0x0) {
    FUN_004ef660(puVar5 + 0x20,&local_30,2);
    FUN_00621180(puVar5 + 0x20);
    FUN_004ef660(puVar5 + 0x22,&local_2c,2);
    FUN_00621180(puVar5 + 0x22);
    puVar6 = puVar5 + 0x24;
    FUN_004ef660(puVar6,iVar2,0xc);
    iVar4 = 3;
    do {
      FUN_00621190(puVar6);
      puVar6 = puVar6 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar6 = puVar5 + 0x30;
    FUN_004ef660(puVar6,iVar2 + 0xc,0xc);
    iVar4 = 3;
    do {
      FUN_00621190(puVar6);
      puVar6 = puVar6 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar6 = puVar5 + 0x3c;
    FUN_004ef660(puVar6,iVar2 + 0x18,0xc);
    iVar4 = 3;
    do {
      FUN_00621190(puVar6);
      puVar6 = puVar6 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_004ef660(puVar5 + 0x48,&param_2,4);
    FUN_00621190(puVar5 + 0x48);
    FUN_004ef660(puVar5 + 0x4c,&DAT_00951b50,4);
    FUN_00621190(puVar5 + 0x4c);
    local_4 = 0x50;
  }
  FUN_005811f0(&local_10);
  if (local_c != (undefined *)0x0) {
    if (1 < *(uint *)(local_c + 0x4b0)) {
      *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
      return 1;
    }
    *(undefined4 *)(local_c + 0x4b0) = 0;
  }
  return 1;
}

