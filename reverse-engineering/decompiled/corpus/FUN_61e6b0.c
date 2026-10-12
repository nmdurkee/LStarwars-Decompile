/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61e6b0; label: FUN_0061e6b0
 */

undefined4 FUN_0061e6b0(int param_1,int param_2)

{
  int iVar1;
  undefined3 uVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_0080f5a0;
  iVar1 = DAT_0080f5a0;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == param_1) break;
    iVar1 = puVar3[2];
    puVar3 = puVar3 + 2;
  }
  uVar2 = (undefined3)((uint)iVar1 >> 8);
  if (param_2 != 0) {
    return CONCAT31(uVar2,*(undefined1 *)((int)puVar3 + 5));
  }
  return CONCAT31(uVar2,*(undefined1 *)(puVar3 + 1));
}

