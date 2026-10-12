/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4cf9f0; label: FUN_004cf9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cf9f0(undefined4 *param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar3 = FUN_00571c80(param_1);
  uVar1 = param_1[0x51];
  bVar2 = false;
  puVar5 = param_1;
  puVar6 = local_80;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  if (((uVar1 & 0x20000) != 0) && ((float)param_1[0x87] != 2e+06)) {
    iVar4 = FUN_00550490(local_80,2,param_1[0x87],
                         *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40);
    if (iVar4 != 0) {
      bVar2 = true;
    }
  }
  iVar4 = *(int *)(PTR_DAT_00802c54 + 0x2ac0);
  if ((*(char *)(iVar4 + 0xeae) == '\0') || (*(char *)(iVar4 + 0xebe) == '\0')) {
    iVar3 = -1;
  }
  else {
    iVar3 = 0xeb - (uint)(iVar3 != 0);
    FUN_005f33b0(iVar3 * 0x10 + iVar4,local_80);
  }
  if (bVar2) {
    FUN_005d4690(1);
    if (param_1[0x55] != 0) {
      FUN_005f33b0(param_1 + 0x52,local_40);
    }
    if (iVar3 != -1) {
      FUN_005f33b0(iVar3 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),local_40);
    }
    FUN_005d46b0();
  }
  return 1;
}

