/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d5b00; label: FUN_004d5b00
 */

undefined4 FUN_004d5b00(int param_1)

{
  ushort *puVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x468c) != 0) {
    return 0;
  }
  iVar4 = FUN_006217e0();
  iVar5 = FUN_006217e0();
  iVar6 = 0;
  *(int *)(param_1 + 0x468c) = iVar5;
  if (0 < iVar5) {
    iVar5 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x4688) + iVar5,0x10);
      FUN_00621900(iVar5 + 0x10 + *(int *)(param_1 + 0x4688));
      FUN_00621900(iVar5 + 0x1c + *(int *)(param_1 + 0x4688));
      FUN_00621900(iVar5 + 0x28 + *(int *)(param_1 + 0x4688));
      uVar3 = FUN_00621890();
      *(undefined2 *)(iVar5 + 0x34 + *(int *)(param_1 + 0x4688)) = uVar3;
      uVar3 = FUN_00621890();
      *(undefined2 *)(iVar5 + 0x36 + *(int *)(param_1 + 0x4688)) = uVar3;
      cVar2 = FUN_006218e0();
      puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
      *puVar1 = *puVar1 ^ (cVar2 != '\0' ^ *(byte *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688))) & 1
      ;
      cVar2 = FUN_006218e0();
      puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
      *puVar1 = *puVar1 ^ (byte)((cVar2 != '\0') * '\x02' ^ (byte)*puVar1) & 2;
      cVar2 = FUN_006218e0();
      puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
      *puVar1 = *puVar1 ^ (byte)((cVar2 != '\0') * '\b' ^
                                *(byte *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688))) & 8;
      if (iVar4 < 2) {
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 | 0x10;
      }
      else {
        cVar2 = FUN_006218e0();
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 ^ (byte)((cVar2 != '\0') << 4 ^
                                  *(byte *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688))) & 0x10;
      }
      if (iVar4 < 3) {
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 & 0xffdf;
      }
      else {
        cVar2 = FUN_006218e0();
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 ^ (byte)((cVar2 != '\0') << 5 ^
                                  *(byte *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688))) & 0x20;
      }
      if (iVar4 < 4) {
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 | 4;
      }
      else {
        cVar2 = FUN_006218e0();
        puVar1 = (ushort *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688));
        *puVar1 = *puVar1 ^ (byte)((cVar2 != '\0') * '\x04' ^
                                  *(byte *)(iVar5 + 0x68 + *(int *)(param_1 + 0x4688))) & 4;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x7c;
    } while (iVar6 < *(int *)(param_1 + 0x468c));
  }
  return 1;
}

