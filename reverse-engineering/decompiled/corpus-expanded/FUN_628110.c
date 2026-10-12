/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x628110; label: FUN_00628110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00628110(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 extraout_EDX;
  
  if (DAT_02912f18 != 0) {
    iVar3 = DAT_02912b3c;
    if (*(int *)(param_2 + 0xc) == 9999) {
      puVar1 = (undefined1 *)FUN_004f1fc0(DAT_02912b3c + 0x198,0x2f);
      iVar3 = DAT_02912b3c;
      if (puVar1 == (undefined1 *)0x0) {
        *(undefined1 *)(DAT_02912b3c + 0x198) = 0;
        *(undefined2 *)(iVar3 + 0x56) = 1;
      }
      else {
        *puVar1 = 0;
        *(undefined2 *)(iVar3 + 0x56) = 1;
      }
    }
    if ((*(byte *)(*(int *)(param_2 + 0xc) * 0x118 + DAT_02912f18) & 8) != 0) {
      if (*(char *)(iVar3 + 0x198) != '\0') {
        FUN_004f1e80(iVar3 + 0x198,&DAT_0076afcc);
        iVar3 = DAT_02912b3c;
      }
      FUN_004f1e80(iVar3 + 0x198,*(int *)(param_2 + 0xc) * 0x118 + 0x18 + DAT_02912f18);
      iVar3 = DAT_02912b3c;
      *(undefined2 *)(DAT_02912b3c + 0x56) = 1;
    }
    pbVar2 = (byte *)(*(int *)(param_2 + 0xc) * 0x118 + DAT_02912f18);
    if ((*pbVar2 & 8) == 0) {
      FUN_004f1f10(iVar3 + 0x58,pbVar2 + 0x18);
      if (*(code **)(DAT_02912b3c + 0x4c) != (code *)0x0) {
        (**(code **)(DAT_02912b3c + 0x4c))(DAT_02912b44,DAT_02912b3c,param_3);
      }
    }
    FUN_006279f0(param_1);
    FUN_00624220(extraout_EDX);
  }
  return;
}

