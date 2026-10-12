/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x540c40; label: FUN_00540c40
 */

void FUN_00540c40(int *param_1)

{
  int iVar1;
  ushort *puVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar4 = 2;
  do {
    bVar3 = (byte)uVar4;
    if (((&DAT_009242c8)[uVar4 - 2 >> 5] & 1 << (bVar3 - 2 & 0x1f)) != 0) {
      puVar2 = (ushort *)(iVar5 + 0x68 + *param_1);
      *puVar2 = *puVar2 & 0xfeff;
    }
    if (((&DAT_009242c8)[uVar4 - 1 >> 5] & 1 << (bVar3 - 1 & 0x1f)) != 0) {
      puVar2 = (ushort *)(iVar5 + 0x1a4 + *param_1);
      *puVar2 = *puVar2 & 0xfeff;
    }
    if (((&DAT_009242c8)[uVar4 >> 5] & 1 << (bVar3 & 0x1f)) != 0) {
      puVar2 = (ushort *)(iVar5 + 0x2e0 + *param_1);
      *puVar2 = *puVar2 & 0xfeff;
    }
    if (((&DAT_009242c8)[uVar4 + 1 >> 5] & 1 << ((byte)(uVar4 + 1) & 0x1f)) != 0) {
      puVar2 = (ushort *)(iVar5 + 0x41c + *param_1);
      *puVar2 = *puVar2 & 0xfeff;
    }
    iVar1 = uVar4 + 2;
    iVar5 = iVar5 + 0x4f0;
    uVar4 = uVar4 + 4;
  } while (iVar1 < 0x40);
  return;
}

