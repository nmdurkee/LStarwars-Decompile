/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x419550; label: FUN_00419550
 */

void FUN_00419550(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80 [12];
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  undefined1 local_40 [64];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  iVar3 = (int)*(char *)(iVar4 + 0x110);
  if ((iVar3 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) != 0)) {
    iVar2 = -1;
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x40) == 0) {
      if ((*(byte *)(iVar4 + 0x94) & 0x80) != 0) {
        iVar2 = 0xe;
      }
      fVar1 = *(float *)(param_1 + 0xd38);
      puVar5 = (undefined4 *)(iVar3 * 0x40 + 0x804 + param_1);
      puVar6 = local_80;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      if (fVar1 != 1.0) {
        local_98 = *(undefined4 *)(param_1 + 0xd38);
        local_94 = local_98;
        local_90 = local_98;
        FUN_005b4c30(local_80,&local_98);
      }
      if (iVar2 == -1) {
        return;
      }
    }
    else {
      local_8c = *(float *)(param_1 + 0xd38) * *(float *)(param_1 + 0xa8);
      iVar2 = 0x19;
      local_88 = local_8c;
      local_84 = local_8c;
      FUN_005b45a0(local_80,&local_8c);
      FUN_00414170();
      iVar4 = iVar3 * 0x40 + param_1;
      local_50 = *(undefined4 *)(iVar4 + 0x834);
      local_4c = *(float *)(iVar4 + 0x838);
      local_48 = *(undefined4 *)(iVar4 + 0x83c);
      if ((*(char *)(param_1 + 0x283) == '\t') && (local_4c < *(float *)(param_1 + 0x220))) {
        local_4c = *(float *)(param_1 + 0x220);
      }
    }
    iVar4 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar2 * 0x10;
    if (*(char *)(iVar4 + 0xe) != '\0') {
      FUN_005f33b0(iVar4,local_80);
      iVar4 = FUN_0057a390(iVar2);
      if ((((iVar4 != -1) &&
           (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar4 * 0x10) != '\0')) &&
          (param_2 != 0)) &&
         (iVar3 = FUN_00550490(local_80,*(undefined1 *)(param_1 + 0x107b),
                               *(undefined4 *)(param_1 + 0x1014),
                               *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40),
         iVar3 != 0)) {
        FUN_005d4690(0);
        FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar4 * 0x10,local_40);
        FUN_005d46b0();
      }
    }
  }
  return;
}

