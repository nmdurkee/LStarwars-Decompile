/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc750; label: FUN_004fc750
 */

int FUN_004fc750(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_4;
  
  iVar3 = FUN_004f1240();
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x52c) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x51c) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x570) = 0xffffffff;
    *(int *)(iVar3 + 0x50c) = iVar3 + 0x108;
    *(undefined4 *)(iVar3 + 4) = param_1;
    *(undefined4 *)(iVar3 + 0x57c) = 0;
    *(undefined4 *)(iVar3 + 0x580) = 0;
    *(int *)(iVar3 + 0x510) = iVar3 + 0x30a;
    *(undefined4 *)(iVar3 + 0x514) = 0x200;
    *(undefined4 *)(iVar3 + 0x518) = 0x200;
    local_4 = 0;
    FUN_004fb550(param_1,&local_4,2);
    sVar2 = (short)local_4;
    *(undefined1 *)(iVar3 + 0x578) = 0;
    *(undefined1 *)(iVar3 + 0x579) = 0;
    if (sVar2 == -2) {
      *(undefined1 *)(iVar3 + 0x578) = 2;
    }
    else if (sVar2 == -0x101) {
      *(undefined1 *)(iVar3 + 0x578) = 1;
    }
    else if (sVar2 == -0x4411) {
      cVar1 = FUN_004fb7f0(param_1);
      if (cVar1 == -0x41) {
        *(undefined1 *)(iVar3 + 0x579) = 1;
      }
    }
    else if (sVar2 == -0x1045) {
      cVar1 = FUN_004fb7f0(param_1);
      if (cVar1 == -0x41) {
        *(undefined1 *)(iVar3 + 0x579) = 2;
      }
    }
    if ((*(char *)(iVar3 + 0x578) == '\0') && (*(char *)(iVar3 + 0x579) == '\0')) {
      FUN_004f6de0(param_1,0,0,0);
    }
    uVar4 = FUN_004f6b40(param_1);
    *(undefined4 *)(iVar3 + 0x574) = uVar4;
  }
  return iVar3;
}

