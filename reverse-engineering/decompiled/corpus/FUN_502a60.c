/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502a60; label: FUN_00502a60
 */

uint * FUN_00502a60(void)

{
  int *piVar1;
  int in_EAX;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint *unaff_EDI;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(in_EAX + 0x18);
  iVar6 = 0;
  puVar2 = (uint *)0x0;
  if (((piVar1 != (int *)0x0) && ((short)piVar1[1] != 0)) && (unaff_EDI != (uint *)0x0)) {
    puVar2 = (uint *)(*unaff_EDI + 0xf & 0xfffffff0);
    *unaff_EDI = (uint)(puVar2 + 1);
    *puVar2 = 0;
    uVar3 = *unaff_EDI + 0xf & 0xfffffff0;
    *unaff_EDI = uVar3;
    *puVar2 = uVar3;
    *unaff_EDI = *unaff_EDI + (uint)*(ushort *)(piVar1 + 1) * 0x18;
    _memset((void *)*puVar2,0,(uint)*(ushort *)(piVar1 + 1) * 0x18);
    local_4 = 0;
    if ((short)piVar1[1] != 0) {
      local_8 = 0;
      do {
        puVar4 = (undefined4 *)(*puVar2 + local_8);
        iVar5 = *piVar1 + iVar6;
        *(undefined1 *)((int)puVar4 + 0x16) = 0xff;
        *(undefined1 *)((int)puVar4 + 0x15) = 0xff;
        if ((*(byte *)(iVar5 + 0x5c) & 2) == 0) {
          *puVar4 = *(undefined4 *)(iVar5 + 0x50);
        }
        else if (DAT_009213a4 != (code *)0x0) {
          (*DAT_009213a4)(iVar5,puVar4);
        }
        local_8 = local_8 + 0x18;
        local_4 = local_4 + 1;
        iVar6 = iVar6 + 100;
      } while (local_4 < (int)(uint)*(ushort *)(piVar1 + 1));
    }
  }
  return puVar2;
}

