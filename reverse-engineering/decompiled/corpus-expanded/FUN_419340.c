/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x419340; label: FUN_00419340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00419340(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_9c;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  if ((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x77e) != '\0') &&
     (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x78e) != '\0')) {
    puVar5 = (undefined4 *)(param_1 + 0x804);
    local_9c = 0;
    bVar2 = 0;
    iVar4 = 0x14;
    do {
      if (((1 << (bVar2 & 0x1f) &
           (uint)*(ushort *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf2)) != 0) &&
         (*(int *)(iVar4 + *(int *)(param_1 + 0x50)) != 0)) {
        iVar3 = local_9c + 0xe28;
        local_9c = local_9c + 1;
        local_8c = ((float)*(byte *)(iVar3 + param_1) / 255.0 - 0.5) * 0.5 *
                   *(float *)(param_1 + 0xdcc) + *(float *)(param_1 + 0xdcc);
        if (local_8c < 0.0 == (local_8c == 0.0)) {
          puVar6 = puVar5;
          puVar7 = local_80;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          local_88 = local_8c;
          local_84 = local_8c;
          FUN_005b4c30(local_80,&local_8c);
          FUN_00552bc0(0,0x77,local_80);
          FUN_00552bc0(0,0x78,local_80);
          if ((param_2 != 0) &&
             (iVar3 = FUN_00550490(local_80,*(undefined1 *)(param_1 + 0x107b),
                                   *(undefined4 *)(param_1 + 0x1014),
                                   *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                   local_40), iVar3 != 0)) {
            iVar3 = FUN_0057a390(0x77);
            if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar3 * 0x10) == '\0') {
              iVar3 = 0x77;
            }
            iVar1 = FUN_0057a390(0x78);
            if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar1 * 0x10) == '\0') {
              iVar1 = 0x77;
            }
            FUN_005d4690(0);
            FUN_00552bc0(0,iVar3,local_80);
            FUN_00552bc0(0,iVar1,local_80);
            FUN_005d46b0();
          }
        }
      }
      bVar2 = bVar2 + 1;
      iVar4 = iVar4 + 4;
      puVar5 = puVar5 + 0x10;
    } while (iVar4 < 0x54);
  }
  return;
}

