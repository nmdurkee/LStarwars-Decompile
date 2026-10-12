/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x538cb0; label: FUN_00538cb0
 */

int FUN_00538cb0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(DAT_009238e4 + 0x4868);
  if (((*(int *)(iVar1 + 0x20) != 0) && (*(int *)(iVar1 + 0x24) != 0)) &&
     (*(int *)(iVar1 + 0x20) != *(int *)(iVar1 + 0x24))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_005337e0,
                         "Disconnect current path node??");
    if (iVar1 != 0) {
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_00533730,&DAT_0075f2d0);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00533730,&PTR_DAT_0075f2d4);
      FUN_00618e10(iVar1,uVar2);
      return iVar1;
    }
  }
  return 0;
}

